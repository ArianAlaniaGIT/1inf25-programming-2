//
// Created by arian on 2/09/2026.
//

#include "DroneVelocidad.h"

DroneVelocidad::DroneVelocidad() {
    velocidad_maxima_permitida = 0.0;
}

double DroneVelocidad::get_velocidad_maxima_permitida() const {
    return velocidad_maxima_permitida;
}

void DroneVelocidad::set_velocidad_maxima_permitida(double velocidad_maxima_permitida) {
    this->velocidad_maxima_permitida = velocidad_maxima_permitida;
}

void DroneVelocidad::leer(ifstream &arch) {
    Drone::leer(arch);
    arch>>velocidad_maxima_permitida;
    arch.get();
}

void DroneVelocidad::muestra(ofstream &arch) {
    Drone::muestra(arch);
    arch<<setw(20)<<velocidad_maxima_permitida<<endl;
}

char DroneVelocidad::get_tipo() {
    return 'V';
}

void DroneVelocidad::actualizar(int &vel, int &est, int &sem) {

}