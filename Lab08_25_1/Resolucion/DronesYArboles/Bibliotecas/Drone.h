//
// Created by arian on 2/09/2026.
//

#ifndef DRONESYARBOLES_DRONE_H
#define DRONESYARBOLES_DRONE_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Drone {
public:
    Drone();

    void inicializa();

    Drone(const Drone &orig);

    void operator=(const Drone &orig);

    virtual ~Drone();

    void get_id(char *iden) const;

    void set_id(char *id);

    void get_ubicacion(char *loc) const;

    void set_ubicacion(char *ubicacion);

    int get_capacidad() const;

    void set_capacidad(int capacidad);

    virtual void leer(ifstream &arch);
    virtual void muestra(ofstream &arch);
    virtual void actualizar(int &vel, int &est, int &sem);
    virtual char get_tipo();

private:
    char *id;
    char *ubicacion;
    int capacidad;
};


#endif //DRONESYARBOLES_DRONE_H
