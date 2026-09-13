//
// Created by arian on 16/08/2026.
//

#ifndef LABORATORIO2_2025_1_FALTAS_H
#define LABORATORIO2_2025_1_FALTAS_H
#include "Conductores.h"
#include "Infracciones.h"

struct Faltas {
    Conductores conductores;
    Infracciones infracciones;
    
    char ***placas;
    int *capacidades;
};

#endif //LABORATORIO2_2025_1_FALTAS_H
