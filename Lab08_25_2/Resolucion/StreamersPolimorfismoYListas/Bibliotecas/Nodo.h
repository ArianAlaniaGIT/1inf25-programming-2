//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_NODO_H
#define STREAMERSPOLIMORFISMOYLISTAS_NODO_H
#include "Metrica.h"


class Nodo {
public:
    Nodo();
    friend class Lista;


private:
    Metrica *metrica;
    Nodo *anterior;
    Nodo *siguiente;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_NODO_H