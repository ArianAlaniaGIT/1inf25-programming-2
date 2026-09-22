//
// Created by arian on 22/01/2026.
//

#include "GestorStreamers.h"

GestorStreamers::GestorStreamers()
{
    inicializa();
}

void GestorStreamers::inicializa()
{
    streamers_gratuitos = nullptr;
    streamers_pagados = nullptr;
    cantidad_gratuitos = 0;
    cantidad_pagados = 0;
}

int GestorStreamers::get_cantidad_gratuitos() const
{
    return cantidad_gratuitos;
}

void GestorStreamers::set_cantidad_gratuitos(int cantidad_gratuitos)
{
    this->cantidad_gratuitos = cantidad_gratuitos;
}

int GestorStreamers::get_cantidad_pagados() const
{
    return cantidad_pagados;
}

void GestorStreamers::set_cantidad_pagados(int cantidad_pagados)
{
    this->cantidad_pagados = cantidad_pagados;
}

void GestorStreamers::cargar_datos_streamers(const char* nombArch)
{
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al cargar los streamers."<<endl;
        exit(1);
    }

    char tipo[100];
    int capPagados = 0, capGratuitos = 0;

    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof())break;
        if (strcmp(tipo,"Gratuito")==0) {
            llenarGratuitos(arch,capGratuitos);
        } else if (strcmp(tipo,"Pagado")==0) {
            llenarPagados(arch,capPagados);
        } else {
            while (arch.get()!='\n');
        }
    }
}

void GestorStreamers::llenarGratuitos(ifstream &arch, int &capGratuitos) {
    StreamerGratuito gratuito;
    gratuito.leer(arch);

    if (capGratuitos == cantidad_gratuitos) {
        incrementarEspaciosGratuitos(capGratuitos, cantidad_gratuitos, streamers_gratuitos);
    }
    streamers_gratuitos[cantidad_gratuitos-1] = gratuito;
    cantidad_gratuitos++;
}

void GestorStreamers::llenarPagados(ifstream &arch, int &capPagados) {
    StreamerPago pagado;
    pagado.leer(arch);
    if (capPagados == cantidad_pagados) {
        incrementarEspaciosPagados(capPagados,cantidad_pagados, streamers_pagados);
    }
    streamers_pagados[cantidad_pagados-1] = pagado;
    cantidad_pagados++;
}

void GestorStreamers::incrementarEspaciosPagados(int &cap, int &mind, StreamerPago *&arreglo) {
    cap+=5;
    StreamerPago *aux;
    if (arreglo == nullptr) {
        arreglo = new StreamerPago[cap]{};
        mind = 1;
    } else
    {
        aux = new StreamerPago[cap]{};
        for (int i = 0; i < mind;i++) {
            aux[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = aux;
    }
}

void GestorStreamers::incrementarEspaciosGratuitos(int &cap, int &mind, StreamerGratuito *&arreglo) {
    cap+=5;
    StreamerGratuito *aux;
    if (arreglo == nullptr) {
        arreglo = new StreamerGratuito[cap]{};
        mind = 1;
    } else
    {
        aux = new StreamerGratuito[cap]{};
        for (int i = 0; i < mind;i++) {
            aux[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = aux;
    }
}

void GestorStreamers::actualizar_datos_metricas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al actualizar las metricas de los streamers."<<endl;
        exit(1);
    }

    char tipo[100];
    int capStreamerFree[cantidad_gratuitos]{}, capStreamerBasic[cantidad_pagados]{}, capStreamerEngage[cantidad_pagados]{},
    capStreamerQuality[cantidad_pagados]{};

    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof())break;
        if (strcmp(tipo,"ENGAGEMENT")==0) {
            actualizarEngagements(arch,capStreamerEngage);
        } else if (strcmp(tipo,"BASIC")==0) {
            actualizarBasics(arch,capStreamerBasic,capStreamerFree);
        } else if (strcmp(tipo,"QUALITY")==0) {
            actualizarQualities(arch, capStreamerQuality);
        }
    }

}

void GestorStreamers::actualizarEngagements(ifstream &arch, int*capStreamerEngage) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();
    int posStreamer = buscarStreamerPago(idStreamer);
    if (posStreamer != -1) {
        streamers_pagados[posStreamer].actualizarDatosEngagement(arch,capStreamerEngage[posStreamer]);
    }
}

void GestorStreamers::actualizarQualities(ifstream &arch, int *capStreamerQuality) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();
    int posStreamer = buscarStreamerPago(idStreamer);
    if (posStreamer != -1) {
        streamers_pagados[posStreamer].actualizarDatosQualities(arch,capStreamerQuality[posStreamer]);
    }
}

void GestorStreamers::actualizarBasics(ifstream &arch, int *capStreamerBasic,int *capStreamerFree) {
    int idStreamer;
    arch>>idStreamer;
    arch.get();

    for (int i = 0; i < cantidad_gratuitos;i++) {// Basico Gratuito
        if (idStreamer == streamers_gratuitos[i].get_id()) {
            streamers_gratuitos[i].actualizarDatos(arch,capStreamerFree[i]);
            return;
        }
    }

    for (int i= 0; i < cantidad_pagados;i++) {// Basico Pagado
        if (idStreamer == streamers_pagados[i].get_id()) {
            streamers_pagados[i].actualizarDatosBasic(arch,capStreamerBasic[i]);
            return;
        }
    }
}


int GestorStreamers::buscarStreamerPago(int idStreamer) const {
    for (int i = 0; i < cantidad_pagados;i++) {
        if (streamers_pagados[i].get_id() == idStreamer) return i;
    }
    return -1;
}

void GestorStreamers::generarReportes() {
    for (int i = 0; i < cantidad_gratuitos;i++){
        if (streamers_gratuitos[i].get_fecha_fin_trial() > 0) {
            char cuenta[100]{}, categoria[100]{};
            streamers_gratuitos[i].get_categoria(categoria);
            streamers_gratuitos[i].get_cuenta(cuenta);
            char *nombreArchivo = crearNombreArchivo(cuenta,categoria,streamers_gratuitos[i].get_fecha_fin_trial());
            char *ruta = obtenerRuta(nombreArchivo, "Gratuito","Reportes");
            realizarElReporteGratuitos(ruta,i);
            delete []nombreArchivo; delete []ruta;
        }
    }

    for (int i = 0; i < cantidad_pagados;i++) {
        if (streamers_pagados[i].get_fecha_inicio_plan() > 0) {
            char cuenta[100]{}, categoria[100]{};
            streamers_pagados[i].get_categoria(categoria);
            streamers_pagados[i].get_cuenta(cuenta);
            char *nombreArchivo = crearNombreArchivo(cuenta,categoria,streamers_pagados[i].get_fecha_inicio_plan());
            char *ruta = obtenerRuta(nombreArchivo, "Pagado","Reportes");
            realizarElReportePagados(ruta,i);

            delete []nombreArchivo; delete []ruta;
        }
    }
}

void GestorStreamers::realizarElReportePagados(char *ruta, int pos)
{
    ofstream arch(ruta,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo generar el reporte."<<endl;
        exit(1);
    }
    elaborarLinea('=',120,arch);
    arch<<setw(70)<<"REPORTE DE STREAMERS"<<endl;
    elaborarLinea('=',120,arch);
    arch<<endl;

    streamers_pagados[pos].imprimir(arch);
    elaborarLinea('=',120,arch);
}

void GestorStreamers::realizarElReporteGratuitos(char *ruta, int pos)
{
    ofstream arch(ruta,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo generar el reporte."<<endl;
        exit(1);
    }
    elaborarLinea('=',120,arch);
    arch<<setw(70)<<"REPORTE DE STREAMERS"<<endl;
    elaborarLinea('=',120,arch);
    arch<<endl;

    streamers_gratuitos[pos].imprimir(arch);
    elaborarLinea('=',120,arch);
}

void GestorStreamers::elaborarLinea(char c, int max, ofstream &arch) {
    for (int i= 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}

char *GestorStreamers::obtenerRuta(char *nombreArchivo, const char*tipoStream, const char*carpeta_base) {
    int tamanho = strlen(carpeta_base)+strlen(tipoStream)+strlen(nombreArchivo)+3;
    char *ruta = new char[tamanho]{};
    strcat(ruta,carpeta_base);
    strcat(ruta,"/");
    strcat(ruta,tipoStream);
    strcat(ruta,"/");
    strcat(ruta,nombreArchivo);

    return ruta;
}

char*GestorStreamers::crearNombreArchivo(char*cuenta, char*categoria, int fecha){
    const char* fechaEnStr = to_string(fecha).c_str();
    int longCuen = strlen(cuenta);
    int longCat = strlen(categoria);
    int longDate = strlen(fechaEnStr);

    char *nombreArchivo = new char[longCuen+longCat+longDate+7]{};
    strcpy(nombreArchivo,cuenta);
    strcat(nombreArchivo,"_");
    strcat(nombreArchivo,categoria);
    strcat(nombreArchivo,"_");
    strcat(nombreArchivo,fechaEnStr);
    strcat(nombreArchivo,".txt");

    return nombreArchivo;
}