//
// Created by arian on 2/09/2026.
//

#include "Drone.h"

#include <cstring>

Drone::Drone() {
    inicializa();
}

void Drone::inicializa() {
    id = nullptr;
    ubicacion = nullptr;
    capacidad = 0;
}

Drone::Drone(const Drone &orig) {
    inicializa();
    *this = orig;
}


void Drone::operator=(const Drone &orig) {
    char cadena[200];
    capacidad = orig.capacidad;
    orig.get_ubicacion(cadena);
    set_ubicacion(cadena);
    orig.get_id(cadena);
    set_id(cadena);
}

Drone::~Drone() {
    if (ubicacion != nullptr) delete ubicacion;
    if (id != nullptr) delete id;
}

void Drone::get_id(char *iden) const {
    if (id == nullptr) iden[0] = 0;
    else strcpy(iden,id);
}

void Drone::set_id(char *iden) {
    if (id != nullptr) delete id;
    id = new char[strlen(iden)+1];
    strcpy(id,iden);
}

void Drone::get_ubicacion(char *loc) const {
    if (ubicacion == nullptr) loc[0] = 0;
    else strcpy(loc,ubicacion);
}

void Drone::set_ubicacion(char *loc) {
    if (ubicacion != nullptr) delete ubicacion;
    ubicacion = new char[strlen(loc)+1];
    strcpy(ubicacion,loc);
}

int Drone::get_capacidad() const {
    return capacidad;
}

void Drone::set_capacidad(int capacidad) {
    this->capacidad = capacidad;
}

void Drone::leer(ifstream &arch) {
    char cadena[100];
    arch.getline(cadena,100,',');
    set_id(cadena);
    arch.getline(cadena,100,',');
    set_ubicacion(cadena);
    arch>>capacidad;
    arch.get();
}

void Drone::muestra(ofstream &arch) {
    arch<<left<<setw(12)<<id<<setw(10)<<ubicacion<<right<<
        setw(10)<<capacidad;
}

void Drone::actualizar(int &vel, int &est, int &sem) {
}

char Drone::get_tipo() {
    return ' ';
}
