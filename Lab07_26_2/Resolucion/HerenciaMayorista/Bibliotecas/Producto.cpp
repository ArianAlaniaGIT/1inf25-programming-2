//
// Created by arian on 8/11/2026.
//

#include "Producto.h"

Producto::Producto() {
    inicializa();
}

void Producto::inicializa() {
    codigo = nullptr;
    descripcion = nullptr;
    precioUnit = 0.0;
}

Producto::Producto(const Producto &orig) {
    inicializa();
    *this = orig;
}

void Producto::operator=(const Producto &orig) {
    char cadena[200]{};
    orig.get_codigo(cadena);
    set_codigo(cadena);
    orig.get_descripcion(cadena);
    set_descripcion(cadena);
    precioUnit = orig.precioUnit;
}

Producto::~Producto() {
    if (codigo != nullptr) delete codigo;
    if (descripcion != nullptr) delete descripcion;
}

void Producto::get_codigo(char *cod) const {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod,codigo);
}

void Producto::set_codigo(char *cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1]{};
    strcpy(codigo,cod);
}

void Producto::get_descripcion(char *script) const {
    if (descripcion == nullptr) script[0] = 0;
    else strcpy(script,descripcion);
}

void Producto::set_descripcion(char *script) {
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(script) + 1]{};
    strcpy(descripcion,script);
}

double Producto::get_precio_unit() const {
    return precioUnit;
}

void Producto::set_precio_unit(double precio_unit) {
    precioUnit = precio_unit;
}

char *Producto::leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max+1], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof()) return nullptr;
    ptCadena = new char[strlen(cadena)+1]{};
    strcpy(ptCadena,cadena);
    return ptCadena;
}

void operator>>(ifstream &arch, Producto &prod) {
    char *cod, *desc;
    double prec;
    cod = prod.leerCadenaExacta(arch,100,',');
    if (arch.eof() or cod == nullptr) return;
    desc = prod.leerCadenaExacta(arch,100,',');
    arch>>prec;
    arch.get();

    prod.set_precio_unit(prec);
    prod.set_codigo(cod);
    prod.set_descripcion(desc);
}

void operator<<(ofstream &arch, Producto &prod) {
    char cod[100], descripcion[100];
    double precio;

    prod.get_codigo(cod);
    prod.get_descripcion(descripcion);
    precio = prod.get_precio_unit();

    arch<<left<<setw(9)<<cod<<setw(40)<<descripcion<<
        right<<setw(10)<<precio<<endl;
}