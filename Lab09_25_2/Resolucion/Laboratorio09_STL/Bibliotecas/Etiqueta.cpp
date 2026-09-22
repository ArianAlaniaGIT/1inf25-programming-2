//
// Created by arian on 8/01/2026.
//

#include "Etiqueta.h"

void Etiqueta::inicializa() {
    nombre = "";
    codigo = "";
}

Etiqueta::Etiqueta() {
    inicializa();
}

Etiqueta::Etiqueta(const Etiqueta& orig) {
    inicializa();
    *this = orig;
}

void Etiqueta::operator=(const Etiqueta& orig) {
    nombre = orig.nombre;
    codigo = orig.codigo;
}

Etiqueta::~Etiqueta() {
    // String gesta su propia memoria. No hace falta destructor.
}

string Etiqueta::get_codigo() const
{
    return codigo;
}

void Etiqueta::set_codigo(const string& codigo)
{
    this->codigo = codigo;
}

string Etiqueta::get_nombre() const
{
    return nombre;
}

void Etiqueta::set_nombre(const string& nombre)
{
    this->nombre = nombre;
}

void operator>>(ifstream &arch, Etiqueta &etiqueta) {
    char cadena[200];
    arch.getline(cadena,200,',');
    if (arch.eof())return;
    string guardado;
    guardado = cadena;
    etiqueta.set_codigo(guardado);
    arch.getline(cadena,200,'\n');
    guardado = cadena;
    etiqueta.set_nombre(guardado);
}

void operator<<(ofstream &arch, Etiqueta &etiqueta) {
    arch<<"CODIGO: "<<etiqueta.get_codigo()<<"  NOMBRE: "<<etiqueta.get_nombre()<<endl;
}