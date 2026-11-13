//
// Created by arian on 16/09/2026.
//

#include "VacunaAplicada.h"

#include "Mascota.h"

VacunaAplicada::VacunaAplicada() {
    inicializa();
}

void VacunaAplicada::inicializa() {
    nombre = nullptr;
    fecha = 0;
    dosis = 0.0;
    colegiatura = nullptr;
}

VacunaAplicada::VacunaAplicada(const VacunaAplicada &orig) {
    inicializa();
    *this = orig;
}

void VacunaAplicada::operator=(const VacunaAplicada &orig) {
    char cadena[100];
    fecha = orig.fecha;
    dosis = orig.dosis;
    orig.get_nombre(cadena);
    set_nombre(cadena);
    orig.get_colegiatura(cadena);
    set_colegiatura(cadena);
}

VacunaAplicada::~VacunaAplicada() {
    if (nombre != nullptr) delete nombre;
    if (colegiatura != nullptr) delete colegiatura;
}

void VacunaAplicada::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = '\0';
    else strcpy(nomb,nombre);
}

void VacunaAplicada::set_nombre(char *nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb)+1]{};
    strcpy(nombre,nomb);
}

int VacunaAplicada::get_fecha() const {
    return fecha;
}

void VacunaAplicada::set_fecha(int fecha) {
    this->fecha = fecha;
}

double VacunaAplicada::get_dosis() const {
    return dosis;
}

void VacunaAplicada::set_dosis(double dosis) {
    this->dosis = dosis;
}

void VacunaAplicada::get_colegiatura(char *college) const {
    if (colegiatura == nullptr) college[0] = '\0';
    else strcpy(college,colegiatura);
}

void VacunaAplicada::set_colegiatura(char *college) {
    if (colegiatura != nullptr) delete colegiatura;
    colegiatura = new char[strlen(college)+1]{};
    strcpy(colegiatura, college);
}


// Lectura
void operator>>(ifstream &arch, VacunaAplicada &vacunaAplicada) {
    char cadena[100];
    int fecha;
    double dosis;
    arch.getline(cadena,100,',');
    vacunaAplicada.set_nombre(cadena);
    arch>>fecha;
    arch.get();
    vacunaAplicada.set_fecha(fecha);
    arch>>dosis;
    arch.get();
    vacunaAplicada.set_dosis(dosis);
    arch.getline(cadena,100,'\n');
    vacunaAplicada.set_colegiatura(cadena);
}


void operator<<(ofstream &arch, VacunaAplicada &vacunaAplicada) {
    char cadena1[100];
    vacunaAplicada.get_nombre(cadena1);
    char cadena2[100];
    vacunaAplicada.get_colegiatura(cadena2);
    int dia,mes,anho;
    anho = (vacunaAplicada.get_fecha())/10000;
    mes = ((vacunaAplicada.get_fecha())%10000) / 100;
    dia = ((vacunaAplicada.get_fecha())%10000) % 100;

    arch<<cadena1<<": "<<setfill('0')<<setw(2)<<dia<<'/'<<setw(2)
    <<mes<<'/'<<setw(4)<<anho<<setfill(' ')<<" ("<<vacunaAplicada.get_dosis()
    <<" ml, "<<cadena2<<")"<<endl;
}