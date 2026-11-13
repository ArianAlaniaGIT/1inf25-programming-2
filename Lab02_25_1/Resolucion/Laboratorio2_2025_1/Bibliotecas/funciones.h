//
// Created by arian on 16/08/2026.
//

#ifndef LABORATORIO2_2025_1_FUNCIONES_H
#define LABORATORIO2_2025_1_FUNCIONES_H
#include "Conductores.h"
#include "Faltas.h"
#include "Infracciones.h"

void operator+=(Conductores &conductores, const char*nombArch);
void operator +=(Infracciones &infracciones, const char *nombArch);
void cargar_faltas_de_los_conductores(Faltas &faltas);
char *leerCadenaExacta(ifstream &arch, int max, char delim);
int buscarDNI(int dni, Conductores &conductores);
void incrementarEspacios(int &cap, int &mind, char **&arreglo);
int buscarInf(Infracciones &infracciones, int cod) ;
int buscarPlaca(char **placas, char *placa);
void llenarYCompletar(char **&placas, int &cant, int &cap, char*cadPlaca);
void imprimir_faltas_de_los_conductores(struct Faltas &faltas);


#endif //LABORATORIO2_2025_1_FUNCIONES_H
