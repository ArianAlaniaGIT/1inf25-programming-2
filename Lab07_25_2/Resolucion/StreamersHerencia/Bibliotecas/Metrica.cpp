//
// Created by arian on 13/01/2026.
//

#include "Metrica.h"

#include <cstring>

Metrica::Metrica() {
    inicializa();
}

void Metrica::inicializa() {
    id = 0;
    descripcion = nullptr;
    fecha_calculo = 0;
    fecha_expiracion = 0;
    estado = false;
}

Metrica::Metrica(const Metrica& orig)
{
    inicializa();
    *this = orig;
}

void Metrica::operator=(const Metrica& orig) {
    char cadena[200]{};
    id = orig.id;
    orig.get_descripcion(cadena);
    set_descripcion(cadena);
    fecha_calculo = orig.fecha_calculo;
    fecha_expiracion = orig.fecha_expiracion;
    estado = orig.estado;
}

Metrica::~Metrica() {
    elimina();
}

int Metrica::get_id() const
{
    return id;
}

void Metrica::get_descripcion(char *script) const
{
    if (descripcion == nullptr) script[0] = 0;
    else strcpy(script, descripcion);
}

int Metrica::get_fecha_calculo() const
{
    return fecha_calculo;
}

int Metrica::get_fecha_expiracion() const
{
    return fecha_expiracion;
}

bool Metrica::is_estado() const
{
    return estado;
}

void Metrica::set_id(int id)
{
    this->id = id;
}

void Metrica::set_descripcion(char* script)
{
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(script)+1];
    strcpy(descripcion, script);
}

void Metrica::set_fecha_calculo(int fecha_calculo)
{
    this->fecha_calculo = fecha_calculo;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion)
{
    this->fecha_expiracion = fecha_expiracion;
}

void Metrica::set_estado(bool estado)
{
    this->estado = estado;
}


void Metrica::elimina() {
    if (descripcion != nullptr) delete descripcion;
}

void Metrica::leer(ifstream &arch) {
    int num; char cadena[100], c;
    int dia,mes,anho;
    arch>>id;
    arch.get();
    arch.getline(cadena,100,',');
    set_descripcion(cadena);
    arch>>anho>>c>>mes>>c>>dia;
    fecha_calculo = anho*10000 + mes*100 + dia;
    arch.get();
    arch>>anho>>c>>mes>>c>>dia;
    fecha_expiracion = anho*10000 + mes*100 + dia;
    if (fecha_expiracion > 20251107) estado = true;
    arch.get();
}

void Metrica::imprimir(ofstream &arch) {
    arch<<setfill('0')<<setw(4)<<id<<setfill(' ')<<setw(15)<<fecha_calculo<<setw(15)<<fecha_expiracion<<setw(4)<<" ";
    if (is_estado())arch<<"ACTIVA";
    else arch<<"EXPIRADA";
}