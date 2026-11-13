//
// Created by arian on 7/10/2026.
//

#include "Empresa.h"

#include <cstring>

Empresa::Empresa() {
    inicializa();
}

Empresa::Empresa(const Empresa &orig) {
    inicializa();
    *this = orig;
}

void Empresa::operator=(const Empresa &orig) {
    char cadena[200], cadena2[200];
    orig.get_nombre(cadena2);
    set_nombre(cadena2);
    dni = orig.dni;
    numPlacas = orig.numPlacas;
    numMultas = orig.numMultas;
    if (placas != nullptr) delete [] placas;
    completarPlacas(orig.placas,numPlacas);
    if (not orig.verificacionDeNulidad2()) {
        for (int i = 0; i < orig.numMultas;i++) {
            multas[i] = orig.multas[i];
        }
    }
}

void Empresa::setPlacaI(const char*shield, int i) {
    if (placas[i] != nullptr) delete placas[i];
    placas[i] = new char[strlen(shield) + 1]{};
    strcpy(placas[i], shield);
}

void Empresa::getPlacaI(char*shield, int i) const {
    if (placas == nullptr) shield[0] = '\0';
    else if (placas[i] == nullptr) shield[0] = '\0';
    else strcpy(shield, placas[i]);
}

void Empresa::inicializa() {
    dni = 0;
    nombre = nullptr;
    placas = nullptr;
    numPlacas = 0;
    multas = nullptr;
    numMultas = 0;
}


bool Empresa::verificacionDeNulidad() const {
    return placas == nullptr;
}

bool Empresa::verificacionDeNulidad2() const {
    return multas == nullptr;
}

Empresa::~Empresa() {
    if (placas != nullptr) delete [] placas;
    if (nombre != nullptr) delete [] nombre;
    if (multas != nullptr) delete [] multas;
}

int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

void Empresa::get_nombre(char *nomb) const {
    if (nombre == nullptr) nomb[0] = '\0';
    else strcpy(nomb, nombre);
}

void Empresa::set_nombre(char *nomb) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(nomb) + 1]{};
    strcpy(nombre, nomb);
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void Empresa::completarPlacas(char **arrPlacas, int num) {
    placas = new char*[num+1]{};
    for (int i = 0; i < num; i++) {
        setPlacaI(arrPlacas[i], i);
    }
    placas[num] = nullptr;
    numPlacas = num;
}

void operator>>(ifstream &arch, Empresa &empresa) {
    int num = 0, dni;
    char *placas[10]{}, cadena[100]{}, cadena2[9]{};
    arch>>dni;
    if (arch.eof())return;
    arch.get();
    arch.getline(cadena,100,',');
    empresa.set_dni(dni);
    for (int i = 0; cadena[i];i++) {
        if (cadena[i] == '/' or cadena[i] == '-') cadena[i] = ' ';
    }
    empresa.set_nombre(cadena);
    while (true) {
        arch.get(cadena2,9);
        placas[num] = new char[strlen(cadena2) + 1]{};
        strcpy(placas[num], cadena2);
        num++;
        if (arch.get() == '\n') break;
    }
    empresa.completarPlacas(placas, num);
}

void Empresa::operator+=(Multa &infraccionCometida) {
    Multa buffMultas[100]{};
    int num = 0;
    if (not verificacionDeNulidad2()) {
        for (int i = 0; i < numMultas; i++) {
            buffMultas[i] = multas[i];
        }
        num = numMultas;
    }
    buffMultas[num] = infraccionCometida;
    num++;

    if (multas != nullptr) delete [] multas;
    multas = new Multa[num+1]{};
    for (int i = 0; i < num; i++) {
        multas[i] = buffMultas[i];
    }
    numMultas = num;
}

void Empresa::imprimirMultas(ofstream &arch) {
    arch<<setw(13)<<"Placa"<<setw(24)<<"Fecha de infraccion"<<
        setw(25)<<"Codigo de infraccion"<<setw(8)<<"Multa"<<setw(18)<<"Fecha de pago"<<endl;

    for (int i = 0; i < numMultas; i++) {
        arch<<setw(8)<<" ";
        arch<<multas[i];
    }
}

void operator<<(ofstream &arch, Empresa &empresa) {
    arch<<setw(13)<<empresa.get_dni()<<setw(4)<<" ";
    char cadena[200];
    empresa.get_nombre(cadena);
    arch<<left<<setw(43)<<cadena;

    for (int i = 0; i < empresa.get_num_placas(); i++) {
        arch<<setw(10);
        char cadena2[200]{};
        empresa.getPlacaI(cadena2,i);
        arch<<cadena2;
    }
    arch<<right<<endl;
    empresa.imprimirMultas(arch);
    arch<<endl;
}