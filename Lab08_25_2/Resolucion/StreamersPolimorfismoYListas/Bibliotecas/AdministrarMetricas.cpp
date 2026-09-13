//
// Created by alulab14 on 21/11/2025.
//

#include "AdministrarMetricas.h"

#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"

void AdministrarMetricas::insertarEnLista(Metrica *metrica,char*tipo) {
    listaDeMetricas.insertarEnOrden(metrica, tipo);
}

void AdministrarMetricas::cargarArchivo(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al intentar abrir el archivo de metricas."<<endl;
        exit(1);
    }

    char tipo[100];
    int idStreamer;
    Metrica *metrica;
    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof())break;
        arch>>idStreamer;
        arch.get();
        if (asignarMemoria(metrica,tipo)) {
            metrica->leer(arch);
            insertarEnLista(metrica,tipo);
        } else {
            while (arch.get()!= '\n');
        }
    }

}

bool AdministrarMetricas::asignarMemoria(class Metrica *&metrica, char *tipo) {
    if (strcmp(tipo,"ENGAGEMENT")==0) {
        metrica = new MetricaEngagement;
        return true;
    } else if (strcmp(tipo,"BASIC")==0) {
        metrica = new MetricaBasica;
        return true;
    } else if (strcmp(tipo, "QUALITY") == 0) {
        metrica = new MetricaCalidad;
        return true;
    } else return false;
}

void AdministrarMetricas::generarReporte(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al generar el reporte."<<endl;
        exit(1);
    }

    listaDeMetricas.generarReporte(arch);
}

void AdministrarMetricas::eliminarNodos() {
    listaDeMetricas.eliminaNodos();
}