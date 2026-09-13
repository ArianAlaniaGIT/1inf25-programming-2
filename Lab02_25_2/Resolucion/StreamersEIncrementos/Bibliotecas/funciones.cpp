//
// Created by arian on 24/12/2025.
//
#include <cstring>
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "funciones.h"

void cargarCategorias(const char*nombArch, char*** &categorias) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al cargar las categorias."<<endl;
        exit(1);
    }
    int mind = 0, cap = 0;
    char **miniRegistro; categorias = nullptr;
    while (true) {
        miniRegistro = leerDatosCategoria(arch);
        if (miniRegistro == nullptr or arch.eof())break;
        if (mind == cap) incrementarEspaciosCategoria(categorias,mind,cap);
        categorias[mind-1] = miniRegistro;
        mind++;
    }

}

char **leerDatosCategoria(ifstream &arch) {
    char **registro, *codigo, *nombre, *descripcion;
    registro = new char*[3]{};
    codigo = leerCadenaExacta(arch,200,',');
    if (arch.eof())return nullptr;
    nombre = leerCadenaExacta(arch,200,',');
    descripcion = leerCadenaExacta(arch,200,'\n');

    registro[0] = codigo;
    registro[1] = nombre;
    registro[2] = descripcion;

    return registro;
}

char *leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof())return nullptr;
    ptCadena = new char[strlen(cadena)+1];
    strcpy(ptCadena,cadena);
    return ptCadena;
}

void incrementarEspaciosCategoria(char*** &categoria, int &mind, int &cap) {
    char ***aux;
    cap+=5;
    if (categoria == nullptr) {
        categoria = new char**[cap]{};
        mind = 1;
    } else {
        aux = new char**[cap]{};
        for (int i = 0; i < mind;i++) {
            aux[i] = categoria[i];
        }
        delete categoria;
        categoria = aux;
    }
}

void cargarStreamers(const char*nombArch, char*** &streamers, int** &fechasPromedios, long long** &tiempoRepSeguidores) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al cargar los streamers."<<endl;
        exit(1);
    }
    int mind = 0, cap = 0; streamers = nullptr; fechasPromedios = nullptr; tiempoRepSeguidores = nullptr;
    char **regStreamer; int *regFecha; long long *regTiempo;
    while (true) {
        llenarDatosStreamers(regStreamer,regFecha,regTiempo,arch);
        if (arch.eof())break;
        if (mind == cap) incrementarDatosPorTres(mind, cap, streamers,fechasPromedios,tiempoRepSeguidores);
        streamers[mind-1] = regStreamer;
        fechasPromedios[mind-1] = regFecha;
        tiempoRepSeguidores[mind-1] = regTiempo;
        mind++;
    }
}

void incrementarDatosPorTres(int &mind, int &cap, char ***&streamers, int **&fechasPromedios, long long **&tiempoRepSeguidores) {
    char ***aux1; int **aux2; long long **aux3;
    cap+=5;
    if (streamers == nullptr) {
        streamers = new char**[cap]{};
        fechasPromedios = new int *[cap]{};
        tiempoRepSeguidores = new long long *[cap]{};
        mind = 1;
    } else {
        aux1 = new char**[cap]{}; aux2 = new int*[cap]{}; aux3 = new long long *[cap]{};
        for (int i = 0; i < mind;i++) {
            aux1[i] = streamers[i]; aux2[i] = fechasPromedios[i]; aux3[i] = tiempoRepSeguidores[i];
        }
        delete streamers; delete fechasPromedios; delete tiempoRepSeguidores;
        streamers = aux1; fechasPromedios = aux2; tiempoRepSeguidores = aux3;
    }
}

void llenarDatosStreamers(char** &regStreamer, int* &regFecha, long long* &regTiempo, ifstream &arch) {
    char *cuenta, *categoria, c;
    int num, dia, mes, anho, fecha1, fecha2;
    long long numlong1, numlong2;
    cuenta = leerCadenaExacta(arch,200,',');
    if (arch.eof() or cuenta == nullptr) return;
    arch>>dia>>c>>mes>>c>>anho;
    fecha1 = anho*10000 + mes*100 + dia;
    arch.get();
    arch>>dia>>c>>mes>>c>>anho;
    fecha2 = anho*10000 + mes*100 + dia;
    arch.get();
    arch>>numlong1>>c>>num>>c>>numlong2;
    arch.get();
    categoria = leerCadenaExacta(arch,200,'\n');

    regStreamer = llenarStreamer(cuenta,categoria);
    regFecha = llenarFecha(fecha1,fecha2,num);
    regTiempo = llenarTiempo(numlong1,numlong2);
}

char **llenarStreamer(char *cuenta, char*categoria) {
    char **reg = new char*[2]{};
    reg[0] = cuenta;
    reg[1] = categoria;
    return reg;
}

int *llenarFecha(int fecha1, int fecha2, int num) {
    int *reg = new int[3]{};
    reg[0] = fecha1;
    reg[1] = fecha2;
    reg[2] = num;
    return reg;
}

long long *llenarTiempo(long long numlong1, long long numlong2) {
    long long *reg = new long long[2]{};
    reg[0] = numlong1;
    reg[1] = numlong2;
    return reg;
}

void cargarComentarios(const char*nombArch, char*** &comentarios, char*** &etiquetas) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al cargar los comentarios."<<endl;
        exit(1);
    }
    comentarios = nullptr, etiquetas = nullptr;
    int mind = 0, cap = 0, mind2 = 0;
    char *cuenta = nullptr;
    char *texto1 = nullptr, *texto2 = nullptr, **buffEtiquetas[200]{};
    while (true) {
        char **dupla = new char*[2]{}, **regEtiq = nullptr;
        cuenta = leerCadenaExacta(arch,200,',');
        if (arch.eof() or cuenta == nullptr) break;
        dupla[0] = cuenta;
        leerRestoDelTexto(dupla,regEtiq, arch, texto1, texto2);
        buffEtiquetas[mind2] = regEtiq;
        mind2++;
        if (mind == cap) incrementarEspaciosComentarios(mind,cap,comentarios);
        comentarios[mind-1] = dupla;
        mind++;
    }
    etiquetas = new char**[mind2+1]{};
    for (int i = 0; i < mind2; i++) {
        etiquetas[i] = buffEtiquetas[i];
    }
    etiquetas[mind2] = nullptr;
}

void incrementarEspaciosComentarios(int &mind, int &cap, char*** &comentarios) {
    char ***aux;
    cap+= 5;
    if (comentarios == nullptr) {
        comentarios = new char**[cap]{};
        mind = 1;
    } else {
        aux = new char**[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = comentarios[i];
        }
        delete comentarios;
        comentarios = aux;
    }
}

void leerRestoDelTexto(char **dupla, char**&regEtiq,ifstream &arch, char*texto1, char*texto2) {
    char *parte1, *parte2;
    char cadena1[200], cadena2[200];
    arch.getline(cadena1,200,'[');
    regEtiq = leerEtiquetas(arch);
    arch.getline(cadena2,200,'\n');

    int len = strlen(cadena1)+1 + strlen(cadena2)+1;
    parte1 = new char[len]{};
    strcpy(parte1,cadena1);
    strcat(parte1,cadena2);
    dupla[1] = parte1;
}

char **leerEtiquetas(ifstream &arch) {
    char caracter;
    int i = 0, j = 0, k = 0;
    char *cadena = nullptr;
    cadena = new char[200]{};
    char *buffEtiq[100]{};
    while (true) {
        arch.get(caracter);
        if (caracter == ' ' or caracter == ']') {
            buffEtiq[k] = new char[strlen(cadena+1)];
            strcpy(buffEtiq[k], cadena);
            k++; i = 0;
            delete cadena;
            cadena = new char[200]{};
            if (caracter == ']')break;
        } else {
            cadena[i] = caracter;
            i++;
        }
    }
    char **regEtiq = new char*[k+1]{};
    for (int a = 0; a < k; a++) {
        regEtiq[a] = buffEtiq[a];
    }
    regEtiq[k] = nullptr;
    return regEtiq;
}

void imprimirReporte(const char*nombArch, char ***categorias, char ***streamers, int **fechasPromedios, long long **tiempoRepSeguidores, char ***comentarios, char***etiquetas) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Ocurrio un problema al generar el reporte."<<endl;
        exit(1);
    }
    for (int i = 0; categorias[i];i++) {
        char **regCat = categorias[i];
        int len1 = (strlen(regCat[1])+1)/2; int max =230;

        arch<<'/';
        imprimirLinea(arch,'*',114-len1);
        arch<<regCat[1];
        imprimirLinea(arch,'*',114-len1);
        arch<<'/'<<endl;
        arch<<left<<setw(27)<<"CUENTA"<<setw(24)<<"FECHA CREACION"<<setw(25)<<"FECHA ULT. STREAM."<<setw(20)<<"TIEMPO REP."<<setw(29)<<"CANT SEGUIDORES"<<"ETIQUETAS"<<right<<endl;
        if (strlen(regCat[1]) %2 != 0) max = 229;
        imprimirLinea(arch,'=',max);
        arch<<endl;
        imprimirInfoStreamers(regCat[0],streamers,fechasPromedios,tiempoRepSeguidores,comentarios,etiquetas,arch);
        arch<<endl<<endl;
    }
}

void imprimirLinea(ofstream &arch, char c, int max) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }

}

void imprimirInfoStreamers(char *categoria, char ***streamers, int **fechasPromedios, long long **tiempoRepSeguidores, char ***comentarios, char***etiquetas,ofstream &arch) {
    arch.precision(2);
    arch<<fixed;
    for (int i = 0; streamers[i];i++) {
        char **regStream = streamers[i];
        if (strcmp(regStream[1],categoria)==0) {
            arch.precision(2);
            arch<<fixed;
            arch<<left<<setw(25)<<regStream[0];
            imprimirFechas(fechasPromedios[i],arch);
            long long *tiempo = tiempoRepSeguidores[i];
            long double tiempoEnDias = (long double)tiempo[0] / (long double)86400000;
            arch<<setw(10)<<tiempoEnDias<<" (dias)";
            arch<<setw(20)<<tiempo[1];
            imprimirEtiquetas(etiquetas,comentarios,regStream[0],arch);
            arch<<endl;
        }
    }
}

void imprimirEtiquetas(char ***etiquetas,char ***comentarios,char *streamer,ofstream &arch) {
    for (int i = 0; etiquetas[i];i++) {
        char **regEtiq = etiquetas[i];
        for (int j = 0; regEtiq[j];j++) {
            if (strcmp(regEtiq[j],streamer)==0) {
                char **regCom = comentarios[i];
                arch<<setw(15)<<'['<<regCom[0]<<']'<<setw(5)<<" "<<"'"<<regCom[1]<<"'";
                return;
            }
        }
    }
}

void imprimirFechas(int *fechasPromedios, ofstream &arch) {
    int dia,mes,anho;
    pasarADMA(fechasPromedios[0],dia,mes,anho);
    arch<<right<<"  "<<setfill('0')<<setw(2)<<dia<<'-'<<setw(2)<<mes<<'-'<<setw(4)<<anho<<setfill(' ')<<setw(12)<<" ";
    pasarADMA(fechasPromedios[1],dia,mes,anho);
    arch<<"  "<<setfill('0')<<setw(2)<<dia<<'-'<<setw(2)<<mes<<'-'<<setw(4)<<anho<<setfill(' ')<<setw(10)<<" ";

}

void pasarADMA(int fecha, int &dia, int &mes, int &anho) {
    anho = fecha/10000;
    mes = (fecha%10000)/100;
    dia = (fecha%10000)%100;
}

