//
// Created by alulab14 on 21/11/2025.
//

#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    horas_transmitidas = 0.0;
    espectadores_promedio = 0;
}

double MetricaBasica::get_horas_transmitidas() const {
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double horas_transmitidas) {
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const {
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int espectadores_promedio) {
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch>>horas_transmitidas;
    arch.get();
    arch>>espectadores_promedio;
    arch.get();
}

void MetricaBasica::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch.precision(2);
    arch<<fixed;
    arch<<setw(10)<<horas_transmitidas<<setw(10)<<espectadores_promedio<<'m'<<endl;
}

char MetricaBasica::getTipo() {
    char c = Metrica::getTipo();
    return 'B';
}


