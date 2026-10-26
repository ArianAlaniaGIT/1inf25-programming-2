//
// Created by arian on 9/08/2026.
//

#ifndef CREARBIBLIOTECA_PARTE1_CURSOS_H
#define CREARBIBLIOTECA_PARTE1_CURSOS_H
#include "Alumnos.h"

struct Cursos {
    char *codigo;
    char *nombre;
    double creditos;
    char *docente;
    struct Alumnos *presencial;
    struct Alumnos *semipresencial;
    struct Alumnos *vvirtual;
    int numpresencial;
    int numsemipresencial;
    int numvirtual;
    char *tipofinal;
};

#endif //CREARBIBLIOTECA_PARTE1_CURSOS_H
