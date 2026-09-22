//
// Created by arian on 13/01/2026.
//

#include "MetricaBasica.h"

MetricaBasica::MetricaBasica() {
    inicializa();
}

void MetricaBasica::inicializa()
{
    Metrica::inicializa();
    horas_transmitidas = 0;
    espectadores_promedio = 0.0;
}

MetricaBasica::MetricaBasica(const MetricaBasica& orig) {
    inicializa();
    *this = orig;
}

void MetricaBasica::operator=(const MetricaBasica& orig) {
    Metrica::operator=(orig);
    horas_transmitidas = orig.horas_transmitidas;
    espectadores_promedio = orig.espectadores_promedio;
}

void MetricaBasica::elimina() {
    // no pasa nada
}

MetricaBasica::~MetricaBasica() {
    elimina();
}

double MetricaBasica::get_horas_transmitidas() const
{
    return horas_transmitidas;
}

void MetricaBasica::set_horas_transmitidas(double horas_transmitidas)
{
    this->horas_transmitidas = horas_transmitidas;
}

int MetricaBasica::get_espectadores_promedio() const
{
    return espectadores_promedio;
}

void MetricaBasica::set_espectadores_promedio(int espectadores_promedio)
{
    this->espectadores_promedio = espectadores_promedio;
}

void MetricaBasica::leer(ifstream& arch) {
    Metrica::leer(arch);
    arch>>horas_transmitidas;
    arch.get();
    arch>>espectadores_promedio;
    arch.get();
}

void MetricaBasica::imprimir(ofstream &arch) {
    arch<<"MB-";
    Metrica::imprimir(arch);
    char cadena[100];
    Metrica::get_descripcion(cadena);
    arch<<setw(10)<<horas_transmitidas<<setw(10)<<espectadores_promedio<<"M"<<setw(6)<<" "<<cadena<<endl;

}
