//
// Created by arian on 2/09/2026.
//

#include "DroneEstacionamiento.h"

#include <cstring>


DroneEstacionamiento::DroneEstacionamiento() {
    zona_carga = 0;
}

int DroneEstacionamiento::get_zona_carga() const {
    return zona_carga;
}

void DroneEstacionamiento::set_zona_carga(int zona_carga) {
    this->zona_carga = zona_carga;
}

void DroneEstacionamiento::leer(ifstream &arch) {
    Drone::leer(arch);
    char cadena[100];
    arch.getline(cadena,100);
    if (strcmp(cadena,"true") ==0) {
        zona_carga = 1;
    }
}

void DroneEstacionamiento::muestra(ofstream &arch) {
    Drone::muestra(arch);
    arch<<setw(20)<<zona_carga<<endl;
}

void DroneEstacionamiento::actualizar(int &vel, int &est, int &sem) {
    if (est > 0) {
        zona_carga = 1;
        est--;
    }
}

char DroneEstacionamiento::get_tipo() {

    return 'E';
}
