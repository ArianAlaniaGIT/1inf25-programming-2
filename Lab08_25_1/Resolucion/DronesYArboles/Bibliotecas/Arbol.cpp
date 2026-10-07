//
// Created by arian on 2/09/2026.
//

#include "Arbol.h"

#include <cstring>

Arbol::Arbol() {
    raiz = nullptr;
}


void Arbol::sumarDroneR(Nodo *&nodo, Drone *drone) {
    if (nodo == nullptr) {
        nodo = new Nodo;
        nodo->drone = drone;
        nodo->izq = nullptr;
        nodo->der = nullptr;
        return;
    }

    char cadena1[100], cadena2[100];
    nodo->drone->get_id(cadena1);
    drone->get_id(cadena2);

    if (strcmp(cadena1, cadena2) > 0) {
        sumarDroneR(nodo->izq, drone);
    } else {
        sumarDroneR(nodo->der, drone);
    }

}

void Arbol::sumarDrone(Drone *drone) {
    sumarDroneR(raiz,drone);
}

void Arbol::mostrar(ofstream &arch) {
    mostrarR(raiz, arch);
}

void Arbol::mostrarR(const Nodo *raiz, ofstream &arch) {
    if (raiz == nullptr) return;
    mostrarR(raiz->izq, arch);
    raiz->drone->muestra(arch);
    mostrarR(raiz->der, arch);
}

void Arbol::contarR(const Nodo *raiz, int &vel, int &est, int &sem) {
    if (raiz == nullptr) return;
    contarR(raiz->izq, vel, est, sem);
    if (raiz->drone->get_tipo() == 'V') {
        vel++;
    } else if (raiz->drone->get_tipo() == 'E') {
        est++;
    } else if (raiz->drone->get_tipo() == 'S') {
        sem++;
    }

    contarR(raiz->der, vel, est, sem);
}

void Arbol::contar(int &vel, int &est, int &sem) {
    contarR(raiz, vel, est, sem);
}

void Arbol::actualizarR(Nodo *nodo, int &vel, int &est, int &sem) {
    if (nodo == nullptr) return;
    actualizarR(nodo->izq, vel, est, sem);
    nodo->drone->actualizar(vel,est,sem);
    actualizarR(nodo->der, vel, est, sem);
}

void Arbol::actualizar(int vel, int est, int sem) {
    actualizarR(raiz,vel,est,sem);
}
