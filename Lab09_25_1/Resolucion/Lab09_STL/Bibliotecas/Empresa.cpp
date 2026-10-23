//
// Created by arian on 7/10/2026.
//

#include "Empresa.h"

Empresa::Empresa() {
    dni = 0;
    nombre ="";
    distrito = "";
}

Empresa::~Empresa() {
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

string Empresa::get_nombre() const {
    return nombre;
}

void Empresa::set_nombre(const string &nombre) {
    this->nombre = nombre;
}

string Empresa::get_distrito() const {
    return distrito;
}

void Empresa::set_distrito(const string &distrito) {
    this->distrito = distrito;
}

map<string, Vehiculo> Empresa::get_vehiculos() const {
    return vehiculos;
}

void Empresa::set_vehiculos(const map<string, Vehiculo> &vehiculos) {
    this->vehiculos = vehiculos;
}

vector<Multa> Empresa::get_multas() const {
    return multas;
}

void Empresa::set_multas(const vector<Multa> &multas) {
    this->multas = multas;
}

void operator >>(ifstream &arch, Empresa &empresa) {
    int dni;
    string nombre, distrito;
    char cadena[200];
    arch>>dni;
    if (arch.eof())return;
    arch.get();
    empresa.set_dni(dni);
    arch.getline(cadena,200,',');
    nombre = cadena;
    empresa.set_nombre(nombre);
    arch.getline(cadena,200,'\n');
    distrito = cadena;
    empresa.set_distrito(distrito);
}


void Empresa::llenarVehiculos(ifstream &arch) {
    Vehiculo vehiculo;
    arch>>vehiculo;
    string placa = vehiculo.get_placa();
    vehiculos[placa] = vehiculo;
}

void operator<<(ofstream &arch, Empresa &empresa) {
    arch<<right<<"DNI: "<<empresa.get_dni()<<setw(15)<<"NOMBRE: "
    <<left<<setw(40)<<empresa.get_nombre()<<setw(10)<<"DISTRITO: "<<empresa.get_distrito()<<endl;
    arch<<"VEHICULOS DE LA EMPRESA: "<<endl;
    map<string,Vehiculo> vehiculos = empresa.get_vehiculos();
    arch<<right<<"PLACA"<<setw(15)<<"MARCA"<<setw(16)<<"MODELO"<<endl;

    for (auto it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        Vehiculo datos = it->second;
        arch<<left<<setw(15)<<it->first<<setw(15)<<datos.get_marca()<<datos.get_modelo()<<endl;
    }

    for (int i = 0; i < 120;i++) arch<<'-';
    arch<<right<<endl<<"MULTAS IMPUESTAS"<<endl;

    vector<Multa> multas = empresa.get_multas();
    arch<<"PLACA"<<setw(28)<<"FECHA DE INFRACCION"<<setw(30)
    <<"CÓDIGO DE INFRACCIÓN"<<setw(10)<<"MULTA"<<setw(15)<<"PAGADA"
    <<setw(20)<<"FECHA DE PAGO"<<endl;
    for (auto it = multas.begin(); it != multas.end(); ++it) {
        arch<<*it;
    }

}

void Empresa::eliminarInfraccionesPagadas(void) {
    for (auto it = multas.begin(); it != multas.end(); ) {
        if (it->is_pagada()) {
            it = multas.erase(it);
        } else {
            it++;
        }
    }
}