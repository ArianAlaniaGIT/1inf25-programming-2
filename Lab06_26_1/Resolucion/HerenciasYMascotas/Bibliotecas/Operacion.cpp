//
// Created by arian on 13/09/2026.
//

#include "Operacion.h"

Operacion::Operacion() {
    inicializa();
}

void Operacion::inicializa() {
    Cita::inicializa();
    anestesiageneral = false;
    nummedicos = 0;
    total = 0;
}

Operacion::Operacion(const Operacion &orig) {
    inicializa();
    *this = orig;
}

void Operacion::operator=(const Operacion &orig) {
    Cita::operator=(orig);
    anestesiageneral = orig.anestesiageneral;
    nummedicos = orig.nummedicos;
    total = orig.total;
}

Operacion::~Operacion() {
}

bool Operacion::is_anestesiageneral() const {
    return anestesiageneral;
}

void Operacion::set_anestesiageneral(bool anestesiageneral) {
    this->anestesiageneral = anestesiageneral;
}

int Operacion::get_nummedicos() const {
    return nummedicos;
}

void Operacion::set_nummedicos(int nummedicos) {
    this->nummedicos = nummedicos;
}

double Operacion::get_total() const {
    return total;
}

void Operacion::set_total(double total) {
    this->total = total;
}

void Operacion::leer(ifstream &arch) {
    Cita::leer(arch);
    arch>>total;
    arch.get();
    int valor;
    arch>>valor;
    arch.get();
    arch>>nummedicos;
    arch.get();
    if (valor) anestesiageneral = true;
    else anestesiageneral = false;
}

void Operacion::imprime(ofstream &arch) {
    Cita::imprime(arch);
    arch<<right<<setw(10);
    if (anestesiageneral) arch<<"General";
    else arch<<"Parcial";
    arch<<setw(21)<<nummedicos<<endl;

}
