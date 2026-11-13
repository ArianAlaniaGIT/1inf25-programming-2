//
// Created by arian on 16/09/2026.
//

#include "Veterinaria.h"

Veterinaria::Veterinaria() {
    listaDeMascotas = nullptr;
    numMascotas = 0;
}

Veterinaria::~Veterinaria() {
    if (listaDeMascotas != nullptr) delete [] listaDeMascotas;
}

void Veterinaria::operator<=(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al leer las mascotas."<<endl;
        exit(1);
    }
    Mascota mascota;
    int cap = 0;

    while (true) {
        arch>>mascota;
        if (arch.eof())break;
        if (cap == numMascotas) incrementarEspacios(cap,numMascotas,listaDeMascotas);
        listaDeMascotas[numMascotas-1] = mascota;
        numMascotas++;
    }

}

void Veterinaria::operator<<=(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al leer las vacunas."<<endl;
        exit(1);
    }
    VacunaAplicada vacuna;
    char nombre[100]; int dni;
    while (true) {
        arch.getline(nombre,100,',');
        if (arch.eof()) break;
        arch>>dni;
        arch.get();
        int posMascota = buscarMascota(nombre, dni);
        if (posMascota != -1) {
            arch>>vacuna;
            listaDeMascotas[posMascota] += vacuna;
        } else {
            while (arch.get() != '\n');
        }
    }
}

int Veterinaria::buscarMascota(char *nombre, int dni) {

    if (numMascotas == 0) return -1;
    for (int i = 0; i < numMascotas; i++) {
        char nomb[100];
        listaDeMascotas[i].get_nombre(nomb);
        if (listaDeMascotas[i].get_dni() == dni or strcmp(nomb,nombre) == 0) {
            return i;
        }
    }
    return -1;
}


void Veterinaria::incrementarEspacios(int &cap, int &mind, Mascota *&arr) {
    cap += 5;
    Mascota *aux;
    if (arr == nullptr) {
        arr = new Mascota[cap+1]{};
        mind = 1;
    } else {
        aux = new Mascota[cap+1]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Veterinaria::operator<<(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al generar el reporte."<<endl;
        exit(1);
    }
    elaborarLinea(arch,66,'=');
    arch<<"REPORTE DE CARTILLAS - VETERINARIA HUELLITAS Y PLUMITAS"<<endl;
    elaborarLinea(arch,66,'=');

    int dni = listaDeMascotas[0].get_dni();
    arch<<"DNI: "<<dni<<endl<<endl;
    for (int i = 0; i < numMascotas; i++) {
        if (listaDeMascotas[i].get_dni() == 0) break;
        if (listaDeMascotas[i].get_dni() != dni) {
            elaborarLinea(arch,66,'-');
            arch<<"DNI: "<<listaDeMascotas[i].get_dni()<<endl;
            arch<<endl;
            dni = listaDeMascotas[i].get_dni();
        }
        arch<<listaDeMascotas[i];
        arch<<endl;
    }
    elaborarLinea(arch,66,'=');
}

void Veterinaria::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < 66; i++) {
        arch<<c;
    }
    arch<<endl;
}