//
// Created by arian on 13/09/2026.
//

#include "Cita.h"

Cita::Cita() {
    inicializa();
}

void Cita::inicializa() {
    fecha = 0;
    hora = 0;
}

Cita::Cita(const Cita &orig) {
    inicializa();
    *this = orig;
}

void Cita::operator=(const Cita &orig) {
    fecha = orig.fecha;
    hora = orig.hora;
    Amascota = orig.Amascota;
}

int Cita::get_fecha() const {
    return fecha;
}

void Cita::set_fecha(int fecha) {
    this->fecha = fecha;
}

int Cita::get_hora() const {
    return hora;
}

void Cita::set_hora(int hora) {
    this->hora = hora;
}

Mascota Cita::get_amascota() const {
    return Amascota;
}

void Cita::set_amascota(const Mascota &amascota) {
    Amascota = amascota;
}

void Cita::leer(ifstream &arch) {
    int dia, mes, anho;
    char c;
    arch>>dia>>c>>mes>>c>>anho>>c>>hora;
    fecha = anho*10000 + mes*100 + dia;
    arch.get();
    Amascota.leer(arch);
}

void Cita::imprime(ofstream &arch) {
    int dia, mes, anho;
    anho = fecha/10000;
    mes = (fecha%10000) / 100;
    dia = (fecha%10000) % 100;

    arch<<"  "<<setfill('0')<<setw(4)<<anho<<"."<<setw(2)<<mes<<"."<<setw(2)<<dia<<setfill(' ')<<"  "<<setfill('0')<<setw(2)<<hora<<setfill(' ')<<":00   ";

    Amascota.imprime(arch);


}

Cita::~Cita() {
}
