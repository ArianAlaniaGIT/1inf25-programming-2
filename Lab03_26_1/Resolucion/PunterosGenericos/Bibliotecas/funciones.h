//
// Created by arian on 30/09/2026.
//

#ifndef PUNTEROSGENERICOS_FUNCIONES_H
#define PUNTEROSGENERICOS_FUNCIONES_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

void cargarPacientes(const char *nombArch, void *&pacientes);
char *leerCadenaExacta(ifstream &arch, int max, char delim);
void *leerDatos(ifstream &arch);
void incrementarEspacios(int &mind, int &cap, void **&arr);
void ubicarLosPacientes(int *nd, int *cap, void**miniRegistro, void **&pacientes, int id);
int buscarPaciente(int id, void **pacientes);
void cargarVisitas(const char*nombArch, void *&pac);
void generarReporte(const char*nombArch, void*pac);
void elaborarLinea(ofstream &arch, int max, char c);
void elaborarEncabezado(ofstream &arch);

#endif //PUNTEROSGENERICOS_FUNCIONES_H
