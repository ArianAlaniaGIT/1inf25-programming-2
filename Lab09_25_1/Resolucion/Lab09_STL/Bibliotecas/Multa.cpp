//
// Created by arian on 7/10/2026.
//

#include "Multa.h"

Multa::Multa() {
    inicializa();
}

void Multa::inicializa() {
    fecha = 0;
    placa = "";
    codMulta = "";
    multa = 0.0;
    pagada = false;
    fechaDePago = 0;
}


Multa::Multa(const Multa &orig) {
    inicializa();
    *this = orig;
}

void Multa::operator=(const Multa &orig) {
    fecha = orig.fecha;
    placa = orig.placa;
    codMulta = orig.codMulta;
    multa = orig.multa;
    pagada = orig.pagada;
    fechaDePago = orig.fechaDePago;
}

Multa::~Multa() {
}

int Multa::get_fecha() const {
    return fecha;
}

void Multa::set_fecha(int fecha) {
    this->fecha = fecha;
}

string Multa::get_placa() const {
    return placa;
}

void Multa::set_placa(const string &placa) {
    this->placa = placa;
}

string Multa::get_cod_multa() const {
    return codMulta;
}

void Multa::set_cod_multa(const string &cod_multa) {
    codMulta = cod_multa;
}

double Multa::get_multa() const {
    return multa;
}

void Multa::set_multa(double multa) {
    this->multa = multa;
}

bool Multa::is_pagada() const {
    return pagada;
}

void Multa::set_pagada(bool pagada) {
    this->pagada = pagada;
}

int Multa::get_fecha_de_pago() const {
    return fechaDePago;
}

void Multa::set_fecha_de_pago(int fecha_de_pago) {
    fechaDePago = fecha_de_pago;
}

void operator>>(ifstream &arch, Multa &multa) {
    int dia, mes, anho, fecha, fechaPago = 0;
    string placa, cod_multa;
    char cadena[100], c, letra;
    arch>>dia;
    if (arch.eof())return;
    arch>>c>>mes>>c>>anho;
    fecha = anho*10000 + mes*100 + dia;
    arch.get();
    arch.getline(cadena,100,',');
    placa = cadena;
    arch.getline(cadena,100,',');
    cod_multa = cadena;
    arch>>letra;
    arch.get();
    if (letra == 'P') {
        arch>>dia>>c>>mes>>c>>anho;
        fechaPago = anho*10000 + mes*100 + dia;
        arch.get();
        multa.set_pagada(true);
        multa.set_fecha_de_pago(fechaPago);
    } else {
        multa.set_pagada(false);
    }
    multa.set_fecha(fecha);
    multa.set_placa(placa);
    multa.set_cod_multa(cod_multa);
}

void operator<<(ofstream &arch, Multa &multa) {
    arch<<multa.get_placa()<<setw(10)<<" ";
    int dia,mes,anho, fecha;
    fecha = multa.get_fecha();
    anho = fecha/10000;
    mes = (fecha%10000)/100;
    dia = (fecha%10000)%100;
    arch<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes
    <<"/"<<setw(4)<<anho<<setfill(' ');
    arch<<right<<setw(25)<<multa.get_cod_multa();
    arch.precision(2); arch<<fixed;
    arch<<setw(19)<<multa.get_multa();
    if (multa.is_pagada()) {
        arch<<setw(12)<<"SI"<<setw(11)<<" ";
        fecha = multa.get_fecha_de_pago();
        anho = fecha/10000;
        mes = (fecha%10000)/100;
        dia = (fecha%10000)%100;
        arch<<setfill('0')<<setw(2)<<dia<<"/"<<setw(2)<<mes
        <<"/"<<setw(4)<<anho<<setfill(' ')<<" ";
    }
    else arch<<setw(12)<<"NO";
    arch<<endl;


}