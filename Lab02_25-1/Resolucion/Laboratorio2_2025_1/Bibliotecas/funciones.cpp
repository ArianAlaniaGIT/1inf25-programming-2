//
// Created by arian on 16/08/2026.
//

#include "funciones.h"

#include <cstring>




void operator+=(Conductores &conductores, const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al leer los conductores."<<endl;
        exit(1);
    }
    int cantBuf = 0, buffDNIS[200]{};
    char *buffNomb[200]{};
    while (true) {
        arch>>buffDNIS[cantBuf];
        if (arch.eof()) break;
        arch.get();
        buffNomb[cantBuf] = leerCadenaExacta(arch,100,'\n');
        cantBuf++;
    }
    cantBuf++;
    conductores.dnis = new int[cantBuf]{};
    conductores.nombres = new char*[cantBuf]{};
    int i;
    for (i = 0; i < cantBuf; i++) {
        conductores.dnis[i] = buffDNIS[i];
        conductores.nombres[i] = buffNomb[i];
    }
    conductores.dnis[cantBuf] = 0;
    conductores.cantidad = cantBuf;

}

void operator +=(Infracciones &infracciones, const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al leer las infracciones."<<endl;
        exit(1);
    }
    int buffCod[200]{}, cant = 0;
    char *buffDescripciones[200]{}, *buffTipos[200]{};
    double buffValores[200]{};
    while (true) {
        arch>>buffCod[cant];
        if (arch.eof()) break;
        arch.get();
        buffDescripciones[cant] = leerCadenaExacta(arch,200,',');
        buffTipos[cant] = leerCadenaExacta(arch,100,',');
        arch>>buffValores[cant];
        arch.get();
        cant++;
    }
    infracciones.codigos = new int[cant+1]{};
    infracciones.descripciones = new char*[cant+1]{};
    infracciones.tipos = new char*[cant+1]{};
    infracciones.valores = new double[cant+1]{};
    for (int i = 0; i < cant; i++) {
        infracciones.codigos[i] = buffCod[i];
        infracciones.descripciones[i] = buffDescripciones[i];
        infracciones.tipos[i] = buffTipos[i];
        infracciones.valores[i] = buffValores[i];
    }
    infracciones.codigos[cant] = 0;
    infracciones.cantidad = cant;
}

char *leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max], *ptCadena;
    arch.getline(cadena,max,delim);
    ptCadena = new char[strlen(cadena)+1]{};
    strcpy(ptCadena,cadena);
    return ptCadena;
}


int buscarDNI(int dni, Conductores &conductores) {
    for (int i = 0; i < conductores.cantidad;i++) {
        if (conductores.dnis[i] == dni) return i;
    }

    return -1;
}

void cargar_faltas_de_los_conductores(Faltas &faltas) {
    faltas.conductores += "Archivos/Conductores.csv";
    faltas.infracciones += "Archivos/Infracciones.csv";
    faltas.capacidades = nullptr;
    faltas.placas = nullptr;
    int dni, numDat = 0, posPlaca, dia, mes, anho, cod, cant= 0;
    char cadPlaca[8], *registrarPlaca, c;
    ifstream archFaltas("Archivos/Faltas.csv",ios::in);
    if (not archFaltas.is_open()) {
        cout<<"ERROR: No se pudo abrir faltas.csv"<<endl;
        exit(1);
    }
    faltas.placas = new char **[faltas.conductores.cantidad]{};
    faltas.capacidades = new int[faltas.conductores.cantidad]{};
    int *cantidades = new int[faltas.conductores.cantidad]{};
    while (true) {
        archFaltas>>dni;
        if (archFaltas.eof()) break;
        archFaltas.get();
        archFaltas.getline(cadPlaca,8,',');
        archFaltas>>dia>>c>>mes>>c>>anho>>c>>cod;
        archFaltas.get();
        int posDNI = buscarDNI(dni, faltas.conductores);
        if (posDNI != -1) {
            int posInf = buscarInf(faltas.infracciones,cod);
            if (posInf != -1) {
                llenarYCompletar(faltas.placas[posDNI],
                    cantidades[posDNI], faltas.capacidades[posDNI],
                    cadPlaca);
            }
        }
    }
}

void llenarYCompletar(char **&placas, int &cant, int &cap, char*cadPlaca) {
    if (cant == cap) incrementarEspacios(cap,cant,placas);
    int posPlaca = buscarPlaca(placas, cadPlaca);
    char *ptPlaca = new char[strlen(cadPlaca)+1]{};
    strcpy(ptPlaca,cadPlaca);
    if (posPlaca == -1) {
        placas[cant-1] = ptPlaca;
        cant++;
    }
}


int buscarPlaca(char **placas, char *placa) {
    if (placas == nullptr) return -1;
    for (int i = 0; placas[i];i++) {
        if (strcmp(placas[i], placa)==0) {
            return i;
        }
    }
    return -1;
}


int buscarInf(Infracciones &infracciones, int cod) {
    for (int i = 0; i < infracciones.cantidad; i++) {
        if (infracciones.codigos[i] == cod) return i;
    }
    return -1;
}

void incrementarEspacios(int &cap, int &mind, char **&arreglo) {
    char **aux;
    cap += 2;
    if (arreglo == nullptr) {
        arreglo = new char *[cap]{};
        mind = 1;
    } else {
        aux = new char *[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = aux;
    }
}

void imprimir_faltas_de_los_conductores(struct Faltas &faltas) {
    ofstream archReporte("Reportes/Reporte.txt",ios::out);
    if (not archReporte.is_open()) {
        cout<<"ERROR: No se pudo abrir Reporte.txt"<<endl;
        exit(1);
    }

    for (int i = 0; i < faltas.conductores.cantidad, faltas.conductores.dnis[i] != 0; i++) {
        int cantPlacas = 0;

            char **arrPlacas = faltas.placas[i];
            if (arrPlacas != nullptr) {
                for (int j = 0; arrPlacas[j];j++) {
                    cantPlacas++;
                }
            }

            archReporte<<faltas.conductores.dnis[i]<<"  "<<left<<setw(40)<<faltas.conductores.nombres[i]<<right<<setw(4)<<cantPlacas<<endl;


    }


}