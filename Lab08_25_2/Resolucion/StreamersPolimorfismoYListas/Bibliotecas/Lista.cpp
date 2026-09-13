//
// Created by alulab14 on 21/11/2025.
//

#include "Lista.h"

#include <list>

Lista::Lista() {
    crearLista();
}

void Lista::crearLista() {
    listaDoblementeLigada = nullptr;
}

void Lista::insertarEnOrden(Metrica *metrica, char *tipo) {
    Nodo *nuevoNodo = new Nodo;
    nuevoNodo->anterior = nullptr;
    nuevoNodo->siguiente = nullptr;
    nuevoNodo->metrica = metrica;

    if (listaDoblementeLigada == nullptr) {
        listaDoblementeLigada = nuevoNodo;
        return;
    } else {
        Nodo *recorrido = listaDoblementeLigada;
        // Basic -> < 100
        // Engagement -> 100 <= id < 999
        // Calidad -> >= 1000
        char descripcion1[100];
        char descripcion2[100];
        metrica->get_descripcion(descripcion1);
        while (recorrido) {

            recorrido->metrica->get_descripcion(descripcion2);
            if (recorrido->metrica->getTipo() > metrica->getTipo() or (strcmp(descripcion2,descripcion1)>0 and recorrido->metrica->getTipo() == metrica->getTipo())) {
                break;
            }

            if (recorrido->siguiente == nullptr) {
                recorrido->siguiente = nuevoNodo;
                nuevoNodo->anterior = recorrido;
                return;
            }
            recorrido = recorrido->siguiente;
        }
        if (recorrido == listaDoblementeLigada) {
            nuevoNodo->siguiente = listaDoblementeLigada;
            listaDoblementeLigada->anterior = nuevoNodo;
            listaDoblementeLigada = nuevoNodo;

        } else {

            nuevoNodo->siguiente = recorrido;
            nuevoNodo->anterior = recorrido->anterior;
            recorrido->anterior->siguiente = nuevoNodo;
            recorrido->anterior = nuevoNodo;

        }
    }

}

void Lista::detonarLista() {
    Nodo *rec = listaDoblementeLigada;
    Nodo *nodo;

    while (rec) {
        nodo = rec;
        rec = rec->siguiente;
        delete nodo;
    }
}

Lista::~Lista() {
    detonarLista();
}

void Lista::generarReporte(ofstream &arch) {
    Nodo *rec = listaDoblementeLigada;
    bool encabezado = true;
    char tipoAnterior = ' ';
    int activos = 0, vencidos = 0;

    elaborarLinea('=',135,arch);
    arch<<setw(78)<<"REPORTE DE MÉTRICAS"<<endl;
    elaborarLinea('=',135,arch);

    while (rec) {
        char tipo = rec->metrica->getTipo();
        if (tipoAnterior == ' ') {
            tipoAnterior = tipo;
            imprimirEncabezado(tipo,arch);
            encabezado = false;
        }
        if (tipo != tipoAnterior) encabezado = true;
        if (encabezado) {
            elaborarLinea('-',135,arch);
            imprimirEncabezado(tipo,arch);
            tipoAnterior= tipo;
            encabezado = false;
        }

        rec->metrica->imprimir(arch);
        if (rec->metrica->is_estado()) {
            activos++;
        } else {
            vencidos++;
        }
        rec = rec->siguiente;
    }
    elaborarLinea('-',135,arch);
    arch<<"[TOTAL] MÉTRICAS ACTIVAS: "<<activos<<" | MÉTRICAS EXPIRADAS: "<<vencidos<<" | FECHA DE REPORTE: 2026-01-08"<<endl;
    elaborarLinea('=',135,arch);
}


void Lista::elaborarLinea(char tipo, int max, ofstream &arch){

    for (int i = 0; i < max; i++) {
        arch<<tipo;
    }
    arch<<endl;
}

void Lista::imprimirEncabezado(char tipo,ofstream &arch) {
    arch<<right<<setw(11)<<"[MÉTRICAS ";
    if (tipo == 'B') {
        arch<<"BASIC]"<<endl;
        arch<<setw(10);
        arch<<right<<"Código"<<setw(17)<<"Descripción"<<setw(49)<<"Fecha Calc."<<setw(10)<<"Expira"<<setw(12)<<"Estado"<<
            setw(14)<<"Horas"<<setw(12)<<"Viewers"<<endl;
    } else if (tipo == 'Q') {
        arch<<"QUALITY]"<<endl;
        arch<<setw(10);
        arch<<right<<"Código"<<setw(17)<<"Descripción"<<setw(49)<<"Fecha Calc."<<setw(10)<<"Expira"<<setw(12)<<"Estado"<<
            setw(15)<<"Bitrate"<<setw(9)<<"Drop%"<<setw(10)<<"FPS"<<endl;
    } else if (tipo == 'E') {
        arch<<"ENGAGEMENT]"<<endl;
        arch<<setw(10);
        arch<<right<<"Código"<<setw(17)<<"Descripción"<<setw(49)<<"Fecha Calc."<<setw(10)<<"Expira"<<setw(12)<<"Estado"<<
            setw(14)<<"Msgs"<<setw(12)<<"Chatters"<<setw(9)<<"Clips"<<endl;
    }
}

void Lista::eliminaNodos() {
    Nodo*recorrido = listaDoblementeLigada;
    Nodo *seleccionado;
    while (recorrido) {

        if (not recorrido->metrica->is_estado()) {
            seleccionado = recorrido;
            if (recorrido->anterior != nullptr) {
                recorrido->anterior->siguiente = recorrido->siguiente;
            } else {
                listaDoblementeLigada = recorrido->siguiente;
            }

            if (recorrido->siguiente != nullptr) {
                recorrido->siguiente->anterior = recorrido->anterior;
            }
            recorrido = recorrido->siguiente;
            delete seleccionado;
        } else {
            recorrido = recorrido->siguiente;
        }
    }

}