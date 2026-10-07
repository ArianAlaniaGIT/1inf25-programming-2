//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_NODO_H
#define DRONESYARBOLES_NODO_H
#include "Drone.h"


class Nodo {
public:
    Nodo();
    friend class Arbol;
private:
    Drone *drone;
    Nodo *izq;
    Nodo *der;
};


#endif //DRONESYARBOLES_NODO_H
