//
// Created by arian on 16/09/2026.
//

#ifndef SOBRECARGASYMASCOTAS_VETERINARIA_H
#define SOBRECARGASYMASCOTAS_VETERINARIA_H
#include "Mascota.h"


class Veterinaria {
public:
    Veterinaria();
    virtual ~Veterinaria();

    void operator <=(const char* nombArch);

    void operator<<=(const char *nombArch);

    int buscarMascota(char *nombre, int dni);



    void incrementarEspacios(int &cap, int &mind, Mascota *&arr);

    void operator<<(const char *nombArch);

    void elaborarLinea(ofstream &arch, int max, char c);

private:
    Mascota *listaDeMascotas;
    int numMascotas;
};


#endif //SOBRECARGASYMASCOTAS_VETERINARIA_H
