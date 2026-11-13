//
// Created by arian on 8/11/2026.
//

#include "DetalleVenta.h"

#include <cstring>

DetalleVenta::DetalleVenta() {
    inicializa();
}

void DetalleVenta::inicializa() {
    codigo = nullptr;
    unidades = 0;
    descripcion = nullptr;
    precioUnit = 0.0;
    total = 0.0;
}

DetalleVenta::DetalleVenta(const DetalleVenta &orig) {
    inicializa();
    *this=orig;
}

void DetalleVenta::operator=(const DetalleVenta &orig) {
    char cadena[200]{};
    orig.get_codigo(cadena);
    set_codigo(cadena);
    orig.get_descripcion(cadena);
    set_descripcion(cadena);
    unidades = orig.unidades;
    precioUnit = orig.precioUnit;
    total = orig.total;
}


DetalleVenta::~DetalleVenta() {
    if (codigo != nullptr) delete codigo;
    if (descripcion != nullptr) delete descripcion;
}

void DetalleVenta::get_codigo(char *cod) const {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod,codigo);
}

void DetalleVenta::set_codigo(char *cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1]{};
    strcpy(codigo,cod);
}

int DetalleVenta::get_unidades() const {
    return unidades;
}

void DetalleVenta::set_unidades(int unidades) {
    this->unidades = unidades;
}

void DetalleVenta::get_descripcion(char *script) const {
    if (descripcion == nullptr) script[0] = 0;
    else strcpy(script,descripcion);
}

void DetalleVenta::set_descripcion(char *script) {
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(script) + 1]{};
    strcpy(descripcion,script);
}

double DetalleVenta::get_precio_unit() const {
    return precioUnit;
}

void DetalleVenta::set_precio_unit(double precio_unit) {
    precioUnit = precio_unit;
}

double DetalleVenta::get_total() const {
    return total;
}

void DetalleVenta::set_total(double total) {
    this->total = total;
}

void DetalleVenta::imprimir(ofstream &arch) {
    arch<<left<<setw(10)<<codigo<<setw(40)<<descripcion<<right<<setw(10)<<unidades
    <<setw(15)<<precioUnit<<setw(15)<<total<<endl;
}