//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_CENTRAL_H
#define DRONESYARBOLES_CENTRAL_H
#include "Arbol.h"


class Central {
public:
    void carga(const char*nombArch);

    void crearArbol(Drone *drone);

    bool asignarMemoria(Drone *&drone, char*tipo);
    void muestra(const char*nombArch);

    void elaborarLinea(ofstream &arch, int max, char c);

    void actualiza();

private:
    Arbol ABBDrones;
};


#endif //DRONESYARBOLES_CENTRAL_H
