//
// Created by arian on 2/09/2026.
//

#include "DroneSemaforo.h"

#include <cstring>

DroneSemaforo::DroneSemaforo() {
    luz_roja = 0;
}

int DroneSemaforo::get_luz_roja() const {
    return luz_roja;
}

void DroneSemaforo::set_luz_roja(int luz_roja) {
    this->luz_roja = luz_roja;
}

void DroneSemaforo::leer(ifstream &arch) {
    Drone::leer(arch);
    char cadena[100];
    arch.getline(cadena,100);
    if (strcmp(cadena,"true") ==0) {
        luz_roja = 1;
    }
}

void DroneSemaforo::muestra(ofstream &arch) {
    Drone::muestra(arch);
    arch<<setw(20)<<luz_roja<<endl;
}

void DroneSemaforo::actualizar(int &vel, int &est, int &sem) {
    if (sem > 0) {
        luz_roja = 0;
        sem--;
    }
}

char DroneSemaforo::get_tipo() {

    return 'S';
}
