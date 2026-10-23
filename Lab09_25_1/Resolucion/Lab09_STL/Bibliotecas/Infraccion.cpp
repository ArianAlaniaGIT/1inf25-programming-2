//
// Created by arian on 7/10/2026.
//

#include "Infraccion.h"

Infraccion::Infraccion() {
    inicializa();
}

void Infraccion::inicializa() {
    codigo = "";
    multa = 0.0;
    gravedad = "";
    descripcion = "";
}


Infraccion::Infraccion(const Infraccion &orig) {
    inicializa();
    *this = orig;
}

void Infraccion::operator=(const Infraccion &orig) {
    codigo = orig.codigo;
    multa = orig.multa;
    gravedad = orig.gravedad;
    descripcion = orig.descripcion;
}

string Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(const string &codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

string Infraccion::get_gravedad() const {
    return gravedad;
}

void Infraccion::set_gravedad(const string &gravedad) {
    this->gravedad = gravedad;
}

string Infraccion::get_descripcion() const {
    return descripcion;
}

void Infraccion::set_descripcion(const string &descripcion) {
    this->descripcion = descripcion;
}

Infraccion::~Infraccion() {

}

void operator>>(ifstream &arch, Infraccion &infraccion) {
    char cadena[200];
    string cod, grav, desc;
    double mul;
    arch.getline(cadena,200,',');
    if (arch.eof())return;
    cod = cadena;
    infraccion.set_codigo(cod);
    arch>>mul;
    arch.get();
    arch.getline(cadena,200,',');
    grav = cadena;
    arch.getline(cadena,200);
    desc = cadena;
    infraccion.set_multa(mul);
    infraccion.set_gravedad(grav);
    infraccion.set_descripcion(desc);

}