//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_CITA_H
#define HERENCIASYMASCOTAS_CITA_H
#include "Mascota.h"


class Cita {
public:
    Cita();

    void inicializa();

    Cita(const Cita &orig);

    void operator=(const Cita &orig);

    int get_fecha() const;

    void set_fecha(int fecha);

    int get_hora() const;

    void set_hora(int hora);

    Mascota get_amascota() const;

    void set_amascota(const Mascota &amascota);

    void leer(ifstream &arch);
    void imprime(ofstream &arch);

    virtual ~Cita();

private:
    int fecha;
    int hora;
    Mascota Amascota;
};


#endif //HERENCIASYMASCOTAS_CITA_H
