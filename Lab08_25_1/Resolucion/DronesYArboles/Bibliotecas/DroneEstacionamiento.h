//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_DRONEESTACIONAMIENTO_H
#define DRONESYARBOLES_DRONEESTACIONAMIENTO_H
#include "Drone.h"


class DroneEstacionamiento: public Drone {
public:
    DroneEstacionamiento();

    int get_zona_carga() const;
    void set_zona_carga(int zona_carga);
    void leer(ifstream &arch);
    void muestra(ofstream &arch);
    void actualizar(int &vel, int &est, int &sem);

    char get_tipo();

private:
    int zona_carga;

};


#endif //DRONESYARBOLES_DRONEESTACIONAMIENTO_H
