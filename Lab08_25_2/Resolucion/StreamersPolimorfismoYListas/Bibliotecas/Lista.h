//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_LISTA_H
#define STREAMERSPOLIMORFISMOYLISTAS_LISTA_H
#include "Nodo.h"


class Lista {
public:
    Lista();
    void crearLista();

    void insertarEnOrden(Metrica *metrica, char *tipo);

    void detonarLista();
    virtual ~Lista();

    void generarReporte(ofstream &arch);
    void elaborarLinea(char tipo, int max, ofstream& arch);
    void imprimirEncabezado(char tipo, ofstream& arch);
    void eliminaNodos();

private:
    Nodo *listaDoblementeLigada;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_LISTA_H