//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_DRONESEMAFORO_H
#define DRONESYARBOLES_DRONESEMAFORO_H
#include "Drone.h"


class DroneSemaforo: public Drone {
public:
    DroneSemaforo();

    int get_luz_roja() const;

    void set_luz_roja(int luz_roja);

    void leer(ifstream &arch);
    void muestra(ofstream &arch);

    void actualizar(int &vel, int &est, int &sem);

    char get_tipo();

private:
    int luz_roja;

};


#endif //DRONESYARBOLES_DRONESEMAFORO_H
