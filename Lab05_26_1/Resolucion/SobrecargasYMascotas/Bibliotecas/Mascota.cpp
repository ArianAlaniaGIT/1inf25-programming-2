//
// Created by arian on 16/09/2026.
//

#include "Mascota.h"

Mascota::Mascota() {
    inicializa();
}

void Mascota::inicializa() {
    dni = 0;
    nombre = nullptr;
    especie = nullptr;
    edad = 0;
    peso = 0.0;
    colegiatura = nullptr;
    numVacunas = 0;
}

Mascota::Mascota(const Mascota &orig) {
    inicializa();
    *this = orig;
}

void Mascota::operator=(const Mascota &orig) {
    char cadena[100];
    dni = orig.dni;
    edad = orig.edad;
    peso = orig.peso;
    numVacunas = orig.numVacunas;
    orig.get_nombre(cadena);
    set_nombre(cadena);
    orig.get_especie(cadena);
    set_especie(cadena);
    orig.get_colegiatura(cadena);
    set_colegiatura(cadena);
}

Mascota::~Mascota() {
    if (nombre != nullptr) delete nombre;
    if (especie != nullptr) delete especie;
    if (colegiatura != nullptr) delete colegiatura;
}

int Mascota::get_dni() const {
    return dni;
}

void Mascota::set_dni(int dni) {
    this->dni = dni;
}

void Mascota::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = '\0';
    else strcpy(nomb,nombre);
}

void Mascota::set_nombre(char *nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1]{};
    strcpy(nombre,nomb);
}

void Mascota::get_especie(char *esp) const {
    if (especie == nullptr) esp[0] = '\0';
    else strcpy(esp,especie);
}

void Mascota::set_especie(char *esp) {
    if (especie != nullptr) delete especie;
    especie = new char[strlen(esp)+1]{};
    strcpy(especie,esp);
}

int Mascota::get_edad() const {
    return edad;
}

void Mascota::set_edad(int edad) {
    this->edad = edad;
}

double Mascota::get_peso() const {
    return peso;
}

void Mascota::set_peso(double peso) {
    this->peso = peso;
}

void Mascota::get_colegiatura(char *college) const {
    if (colegiatura == nullptr) college[0] = '\0';
    else strcpy(college,colegiatura);
}

void Mascota::set_colegiatura(char *college) {
    if (colegiatura != nullptr) delete colegiatura;
    colegiatura = new char[strlen(college)+1]{};
    strcpy(colegiatura,college);
}

int Mascota::get_num_vacunas() const {
    return numVacunas;
}

void Mascota::set_num_vacunas(int num_vacunas) {
    numVacunas = num_vacunas;
}


void Mascota::obtenerVacunas(VacunaAplicada *&arreglo) {
    if (arreglo != nullptr) delete []arreglo;

    arreglo = new VacunaAplicada[numVacunas+1]{};
    for (int i = 0; i < numVacunas; i++) {
        arreglo[i] = listaVacunas[i];
    }
}


void Mascota::operator +=(VacunaAplicada &vacuna) {
    listaVacunas[numVacunas] = vacuna;
    numVacunas++;
}

bool Mascota::operator~() {
    for (int i = 0; i < numVacunas; i++) {
        for (int j = i+1; j < numVacunas; j++) {
            char cad1[100], cad2[100];
            listaVacunas[i].get_nombre(cad1);
            listaVacunas[j].get_nombre(cad2);
            if (strcmp(cad1,cad2) == 0) return true;
        }
    }

    return false;
}

// Lectura
void operator>>(ifstream &arch, Mascota &mascota) {
    int dni, edad;
    double peso;
    char cadena[100];
    arch>>dni;
    if (arch.eof())return;
    arch.get();
    arch.getline(cadena,100,',');
    mascota.set_dni(dni);
    mascota.set_nombre(cadena);
    arch.getline(cadena,100,',');
    mascota.set_especie(cadena);
    arch>>edad;
    arch.get();
    mascota.set_edad(edad);
    arch>>peso;
    mascota.set_peso(peso);
    arch.get();
    arch.getline(cadena,100,'\n');
    mascota.set_colegiatura(cadena);
}

void operator <<(ofstream &arch, Mascota &mascota) {
    char cadena[100], c2[100];
    mascota.get_nombre(cadena);
    mascota.get_especie(c2);
    arch<<"Mascota : "<<cadena<<" ("<<c2<<", "<<
        mascota.get_edad()<<" años, "<<mascota.get_peso()<<" kg)"<<endl;

    if (~mascota) {
        arch<<"** ALERTA: cartilla con registros duplicados **"<<endl;
        arch<<endl;
    }

    VacunaAplicada *vacunas = nullptr;
    for (int i = 0; i < mascota.get_num_vacunas(); i++) {
        mascota.obtenerVacunas(vacunas);
    }

    arch<<"Vacunas: "<<endl;
    if (mascota.get_num_vacunas() == 0) {
        arch<<"La mascota no presenta vacunas registradas."<<endl;
    } else {

        for (int i = 0; i < mascota.get_num_vacunas(); i++) {
            arch<<"- ";
            arch<<vacunas[i];
        }
    }
}