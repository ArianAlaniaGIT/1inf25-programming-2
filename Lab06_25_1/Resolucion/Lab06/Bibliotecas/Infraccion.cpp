//
// Created by arian on 7/10/2026.
//

#include "Infraccion.h"

#include <cstring>

Infraccion::Infraccion() {
    inicializa();
}

void Infraccion::inicializa() {
    codigo = 0;
    descripcion = nullptr;
    gravedad = nullptr;
    multa = 0.0;
}

Infraccion::Infraccion(const Infraccion &orig) {
    inicializa();
    *this = orig;
}

void Infraccion::operator=(const Infraccion &orig) {
    codigo = orig.codigo;
    multa = orig.multa;
    char cadena[200];
    orig.get_descripcion(cadena);
    set_descripcion(cadena);
    orig.get_gravedad(cadena);
    set_gravedad(cadena);
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

void Infraccion::get_descripcion(char *script) const {
    if (descripcion == nullptr) script[0] = '\0';
    else strcpy(script, descripcion);
}

void Infraccion::set_descripcion(char *script) {
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(script)+1]{};
    strcpy(descripcion, script);
}

void Infraccion::get_gravedad(char *grav) const {
    if (gravedad == nullptr) grav[0] = '\0';
    else strcpy(grav, gravedad);
}

void Infraccion::set_gravedad(char *grav) {
    if (gravedad != nullptr) delete gravedad;
    gravedad = new char[strlen(grav)+1]{};
    strcpy(gravedad, grav);
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

Infraccion::~Infraccion() {
    if (descripcion != nullptr) delete descripcion;
    if (gravedad != nullptr) delete gravedad;
}


void operator>>(ifstream &arch, Infraccion &infraccion) {
    int cod;
    double mul;
    char cadena[200];
    arch>>cod;
    if (arch.eof())return;
    arch.get();
    arch>>mul;
    arch.get();
    arch.getline(cadena,200,',');
    infraccion.set_codigo(cod);
    infraccion.set_gravedad(cadena);
    infraccion.set_multa(mul);
    arch.getline(cadena,200,'\n');
    infraccion.set_descripcion(cadena);
}

void operator<<(ofstream &arch, Infraccion &infraccion) {
    arch<<right<<setw(9)<<infraccion.get_codigo()<<setw(12)<<infraccion.get_multa();
    char gravedad[200], descripcion[200];
    infraccion.get_descripcion(descripcion);
    infraccion.get_gravedad(gravedad);
    arch<<setw(4)<<" "<<left<<setw(12)<<gravedad<<" "<<descripcion<<right<<endl;
}