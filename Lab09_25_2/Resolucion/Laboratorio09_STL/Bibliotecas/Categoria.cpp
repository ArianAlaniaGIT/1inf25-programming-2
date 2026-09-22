//
// Created by arian on 8/01/2026.
//

#include "Categoria.h"

Categoria::Categoria() {
    inicializa();
}

void Categoria::inicializa() {
    codigo = "";
    nombre = "";
    descripcion = "";
}

Categoria::Categoria(const Categoria& orig) {
    inicializa();
    *this = orig;
}

void Categoria::operator=(const Categoria& orig) {
    codigo = orig.codigo;
    nombre = orig.nombre;
    descripcion = orig.descripcion;
}

Categoria::~Categoria() {
    // No hace falta pues String gesta su propia memoria.
}

string Categoria::get_codigo() const
{
    return codigo;
}

void Categoria::set_codigo(const string& codigo)
{
    this->codigo = codigo;
}

string Categoria::get_nombre() const
{
    return nombre;
}

void Categoria::set_nombre(const string& nombre)
{
    this->nombre = nombre;
}

string Categoria::get_descripcion() const
{
    return descripcion;
}

void Categoria::set_descripcion(const string& descripcion)
{
    this->descripcion = descripcion;
}

void operator>>(ifstream &arch, Categoria &categoria) {
    char cadena[200];
    arch.getline(cadena,200,',');
    if (arch.eof())return;
    string guardado;
    guardado = cadena;
    categoria.set_codigo(guardado);
    arch.getline(cadena,200,',');
    guardado = cadena;
    categoria.set_nombre(guardado);
    arch.getline(cadena,200,'\n');
    guardado = cadena;
    categoria.set_descripcion(guardado);
}

bool Categoria::operator<(Categoria &cat2) const
{
    string cod1, cod2;
    cod1 = get_codigo();
    cod2 = cat2.get_codigo();

    return cod1 < cod2;
}

void operator<<(ofstream &arch, Categoria &categoria) {
    arch<<"CATEGORIA: "<<endl;
    arch<<"   CODIGO:      "<<categoria.get_codigo()<<endl;
    arch<<"   NOMBRE:      "<<categoria.get_nombre()<<endl;
    arch<<"   DESCRIPCION: "<<categoria.get_descripcion()<<endl;
}