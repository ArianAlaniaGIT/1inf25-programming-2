//
// Created by arian on 13/09/2026.
//

#include "Control.h"

Control::Control() {
    inicializa();
}

void Control::inicializa() {
    Cita::inicializa();
    costo = 0;
    codmed = 0;
}

Control::Control(const Control &orig) {
    inicializa();
    *this = orig;
}

void Control::operator=(const Control &orig) {
    Cita::operator=(orig);
    costo = orig.costo;
    codmed = orig.codmed;
}


double Control::get_costo() const {
    return costo;
}

void Control::set_costo(double costo) {
    this->costo = costo;
}

int Control::get_codmed() const {
    return codmed;
}

void Control::set_codmed(int codmed) {
    this->codmed = codmed;
}

Control::~Control() {

}

void Control::leer(ifstream &arch) {
    Cita::leer(arch);
    arch>>codmed;
    arch.get();
    arch>>costo;
    arch.get();
}

void Control::imprime(ofstream &arch) {
    Cita::imprime(arch);
    arch<<right<<setw(10)<<codmed<<setw(10)<<costo<<endl;
}
