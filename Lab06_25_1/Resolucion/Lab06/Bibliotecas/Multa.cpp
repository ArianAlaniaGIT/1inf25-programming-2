//
// Created by arian on 7/10/2026.
//

#include "Multa.h"

#include <cstring>

Multa::Multa() {
    inicializa();
}

void Multa::inicializa() {
    placa = nullptr;
    fechaDeInfraccion = 0;
    fechaDePago = 0;
    codigoInfraccion = 0;
    multa = 0.0;
}


Multa::Multa(const Multa &orig) {
    inicializa();
    *this = orig;
}

void Multa::operator=(const Multa &orig) {
    char cadena[200];
    orig.get_placa(cadena);
    set_placa(cadena);
    fechaDeInfraccion = orig.fechaDeInfraccion;
    fechaDePago = orig.fechaDePago;
    codigoInfraccion = orig.codigoInfraccion;
    multa = orig.multa;
}

void Multa::get_placa(char *shield) const {
    if (placa == nullptr) shield[0] = '\0';
    else strcpy(shield, placa);
}

void Multa::set_placa(char *shield) {
    if (placa != nullptr) delete placa;
    placa = new char[strlen(shield)+1]{};
    strcpy(placa,shield);
}

int Multa::get_fecha_de_infraccion() const {
    return fechaDeInfraccion;
}

void Multa::set_fecha_de_infraccion(int fecha_de_infraccion) {
    fechaDeInfraccion = fecha_de_infraccion;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

int Multa::get_codigo_infraccion() const {
    return codigoInfraccion;
}

void Multa::set_codigo_infraccion(int codigo_infraccion) {
    codigoInfraccion = codigo_infraccion;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

void operator>>(ifstream &arch, Multa &multa) {
    int dia, mes, anho, cod, fechaReg = 0;
    char c, cadena[100], letra;
    arch>>dia;
    if (arch.eof())return;
    arch>>c>>mes>>c>>anho;
    multa.set_fecha_de_infraccion(anho*10000 + mes*100 + dia);
    arch.get();
    arch.getline(cadena,100,',');
    multa.set_placa(cadena);
    arch>>cod;
    multa.set_codigo_infraccion(cod);
    if (arch.get() == ',') {
        arch.get();
        arch.get();
        arch>>dia>>c>>mes>>c>>anho;
        fechaReg = anho*10000 + mes*100 + dia;
        arch.get();
    }
    multa.set_fecha_de_pago(fechaReg);
}

void operator<<(ofstream &arch, Multa &multa) {
    int dia, mes, anho, fecha;
    fecha = multa.get_fecha_de_infraccion();
    char placa[100];
    multa.get_placa(placa);
    multa.convertirADMA(dia,mes,anho,fecha);
    arch<<left<<setw(13)<<placa<<right<<" "<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<setw(4)<<anho
    <<setfill(' ')<<" "<<setw(20)<<multa.get_codigo_infraccion()<<setw(18)<<multa.get_multa();
    if (multa.get_fecha_de_pago() != 0) {
        fecha = multa.get_fecha_de_pago();
        multa.convertirADMA(dia,mes,anho,fecha);
        arch<<right<<setw(6)<<" "<<setfill('0')
        <<setw(2)<<dia<<'/'<<setw(2)<<mes<<'/'<<setw(4)<<anho
        <<setfill(' ')<<" ";
    }

    arch<<endl;
}

void Multa::convertirADMA(int &dia, int &mes, int &anho, int fecha) {
    anho = fecha/10000;
    mes = (fecha%10000)/100;
    dia = (fecha%10000)%100;
}