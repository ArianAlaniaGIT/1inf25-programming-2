//
// Created by arian on 13/09/2026.
//

#include "Vacuna.h"

Vacuna::Vacuna() {
    inicializa();
}

void Vacuna::inicializa() {
    Cita::inicializa();
    dosis = 0;
    meses = 0;
}

Vacuna::Vacuna(const Vacuna &orig) {
    inicializa();
    *this = orig;
}

void Vacuna::operator=(const Vacuna &orig) {
    Cita::operator=(orig);
    dosis = orig.dosis;
    meses = orig.meses;
}

Vacuna::~Vacuna() {
}

int Vacuna::get_dosis() const {
    return dosis;
}

void Vacuna::set_dosis(int dosis) {
    this->dosis = dosis;
}

int Vacuna::get_meses() const {
    return meses;
}

void Vacuna::set_meses(int meses) {
    this->meses = meses;
}

void Vacuna::leer(ifstream &arch) {
    Cita::leer(arch);
    arch>>dosis;
    arch.get();
    arch>>meses;
    arch.get();
}

void Vacuna::imprime(ofstream &arch) {
    Cita::imprime(arch);
    arch<<right<<setw(10)<<dosis<<setw(25)<<meses<<endl;
}
