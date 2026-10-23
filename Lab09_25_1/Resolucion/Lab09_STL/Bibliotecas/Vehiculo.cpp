//
// Created by arian on 7/10/2026.
//

#include "Vehiculo.h"


Vehiculo::Vehiculo() {
    inicializa();
}

void Vehiculo::inicializa() {
    placa ="";
    marca = "";
    modelo = "";
}

Vehiculo::Vehiculo(const Vehiculo &orig) {
    inicializa();
    *this = orig;
}

void Vehiculo::operator=(const Vehiculo &orig) {
    placa = orig.placa;
    marca = orig.marca;
    modelo = orig.modelo;
}

Vehiculo::~Vehiculo() {
}

string Vehiculo::get_placa() const {
    return placa;
}

void Vehiculo::set_placa(const string &placa) {
    this->placa = placa;
}

string Vehiculo::get_marca() const {
    return marca;
}

void Vehiculo::set_marca(const string &marca) {
    this->marca = marca;
}

string Vehiculo::get_modelo() const {
    return modelo;
}

void Vehiculo::set_modelo(const string &modelo) {
    this->modelo = modelo;
}

void operator>>(ifstream &arch, Vehiculo &vehiculo) {
    string placa, marca, modelo;
    arch.get();
    char cadena[100];
    arch.getline(cadena,100,',');
    placa = cadena;
    arch.getline(cadena,100,',');
    marca = cadena;
    arch.getline(cadena,100);
    modelo = cadena;
    vehiculo.set_placa(placa);
    vehiculo.set_marca(marca);
    vehiculo.set_modelo(modelo);
}