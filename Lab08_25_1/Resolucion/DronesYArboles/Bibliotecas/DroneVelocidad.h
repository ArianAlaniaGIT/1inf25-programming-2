//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_DRONEVELOCIDAD_H
#define DRONESYARBOLES_DRONEVELOCIDAD_H
#include "Drone.h"


class DroneVelocidad: public Drone {
public:
    DroneVelocidad();

    double get_velocidad_maxima_permitida() const;

    void set_velocidad_maxima_permitida(double velocidad_maxima_permitida);

    void leer(ifstream &arch);
    void muestra(ofstream &arch);

    void actualizar(int &vel, int &est, int &sem);

    char get_tipo();

private:
    double velocidad_maxima_permitida;
};


#endif //DRONESYARBOLES_DRONEVELOCIDAD_H
