//
// Created by arian on 13/09/2026.
//

#include "Mascota.h"


Mascota::Mascota() {
    inicializa();
}

void Mascota::inicializa() {
    codigo = 0;
    nombre = nullptr;
    tipo = ' ';
    raza = nullptr;
}

void Mascota::imprime(ofstream &arch) {
    arch<<left<<setw(20)<<raza<<setw(20)<<nombre;
}

Mascota::Mascota(const Mascota &orig) {
    inicializa();
    *this = orig;
}

void Mascota::operator=(const Mascota &orig) {
    char cadena[100];
    codigo = orig.codigo;
    tipo = orig.tipo;
    orig.get_nombre(cadena);
    set_nombre(cadena);
    orig.get_raza(cadena);
    set_raza(cadena);
}

Mascota::~Mascota() {
    if (nombre != nullptr) delete nombre;
    if (raza != nullptr) delete raza;
}

int Mascota::get_codigo() const {
    return codigo;
}

void Mascota::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Mascota::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = '\0';
    else strcpy(nomb, nombre);
}

void Mascota::set_nombre(char *nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1]{};
    strcpy(nombre, nomb);
}

char Mascota::get_tipo() const {
    return tipo;
}

void Mascota::set_tipo(char tipo) {
    this->tipo = tipo;
}

void Mascota::get_raza(char *breed) const {
    if (raza == nullptr) breed[0] = '\0';
    else strcpy(breed, raza);
}

void Mascota::set_raza(char *breed) {
    if (raza != nullptr) delete raza;
    raza = new char[strlen(breed) + 1]{};
    strcpy(raza, breed);
}

void Mascota::leer(ifstream &arch) {
    char cadena[100];
    arch>>codigo;
    arch.get();
    arch.getline(cadena,100,',');
    set_nombre(cadena);
    arch>>tipo;
    arch.get();
    arch.getline(cadena,100,',');
    set_raza(cadena);

}
