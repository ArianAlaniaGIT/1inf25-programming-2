//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_ARBOL_H
#define DRONESYARBOLES_ARBOL_H
#include "Nodo.h"


class Arbol {
public:
    Arbol();

    void sumarDrone(Drone *drone);
    void mostrar(ofstream &arch);

    void contar(int &vel, int &est, int &sem);



    void actualizar(int vel, int est, int sem);


private:
    void sumarDroneR(Nodo *&nodo, Drone *drone);
    void mostrarR(const Nodo *raiz, ofstream &arch);

    void contarR(const Nodo *raiz, int &vel, int &est, int &sem);
    void actualizarR(Nodo *nodo, int &vel, int &est, int &sem);;

    Nodo *raiz;
};


#endif //DRONESYARBOLES_ARBOL_H
