//
// Created by alulab14 on 21/11/2025.
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

Metrica::Metrica(const Metrica &orig) {
    inicializa();
    *this = orig;
}

void Metrica::operator=(const Metrica &orig) {
    char cadena[200]{};
    id = orig.id;
    orig.get_descripcion(cadena);
    set_descripcion(cadena);
    fecha_calculo = orig.fecha_calculo;
    fecha_expiracion = orig.fecha_expiracion;
    estado = orig.estado;
}


int Metrica::get_id() const {
    return id;
}

void Metrica::set_id(int id) {
    this->id = id;
}

void Metrica::get_descripcion(char *script) const {
    if (descripcion == nullptr) script[0] = 0;
    else strcpy(script,descripcion);
}

void Metrica::set_descripcion(char *script) {
    if (descripcion != nullptr) delete descripcion;
    descripcion = new char[strlen(script)+1]{};
    strcpy(descripcion,script);
}

int Metrica::get_fecha_calculo() const {
    return fecha_calculo;
}

void Metrica::set_fecha_calculo(int fecha_calculo) {
    this->fecha_calculo = fecha_calculo;
}

int Metrica::get_fecha_expiracion() const {
    return fecha_expiracion;
}

void Metrica::set_fecha_expiracion(int fecha_expiracion) {
    this->fecha_expiracion = fecha_expiracion;
}

bool Metrica::is_estado() const {
    return estado;
}

void Metrica::set_estado(bool estado) {
    this->estado = estado;
}

void Metrica::leer(ifstream &arch) {
    int num;
    arch>>num;
    char cadena[200];
    arch.get();
    arch.getline(cadena,200,',');
    int fechaCalculo = leerFecha(arch);
    int fechaExpiracion = leerFecha(arch);
    set_id(num);
    set_descripcion(cadena);
    set_fecha_calculo(fechaCalculo);
    set_fecha_expiracion(fechaExpiracion);
    if (fechaExpiracion < 20251114) {
        set_estado(false);
    } else {
        set_estado(true);
    }
}

char Metrica::getTipo() {
    return ' ';
}

int Metrica::leerFecha(ifstream &arch) {
    int dia, mes, anho;
    char c;
    arch>>anho>>c>>mes>>c>>dia;
    arch.get();
    int fechaFormada = anho*10000 + mes*100 + dia;
    return fechaFormada;
}

void Metrica::imprimir(ofstream &arch) {
    char cadena[200]{};
    get_descripcion(cadena);
    int extraBytes = 0;

    // Esto es adicional para emparejar los espaciados, pues los caracteres con tildes ocupan mas de 1 bit.
    // Solo importa lo que está más abajo
    for (int i = 0; cadena[i]; i++) { // Contar cuántos bytes extra ocupan las tildes
        // En UTF-8, los caracteres extendidos tienen el bit más alto en 1 (valor negativo en char firmado)
        if (cadena[i] < 0) { // Esto permite detectar tildes
            extraBytes++; // Si el primer bit de un byte es 1, el sistema lo interpreta como un número negativo
            i++; // Saltamos el siguiente byte del carácter multi-byte
        }
    }

    int relleno = 50 - (strlen(cadena) - extraBytes);

    // Aquí se imprimen los datos
    arch<<right<<setw(4)<<"M"<<getTipo()<<'-'<<setfill('0')<<setw(4)<<id<<setfill(' ')<<setw(4)<<" "<<left<<cadena<<left;
    arch<<setw(relleno)<<" "<<right<<setw(8)<<fecha_calculo<<setw(13)<<fecha_expiracion<<setw(5)<<" ";
    if (is_estado()) {
        arch<<left<<setw(10)<<"ACTIVA";
    } else {
        arch<<left<<setw(10)<<"EXPIRADA";
    }
    arch<<right;
}

Metrica::~Metrica() {
    if (descripcion != nullptr) delete descripcion;
}
