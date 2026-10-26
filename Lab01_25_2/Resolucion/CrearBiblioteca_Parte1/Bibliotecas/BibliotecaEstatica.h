//
// Created by arian on 9/08/2026.
//

#ifndef CREARBIBLIOTECA_PARTE1_BIBLIOTECAESTATICA_H
#define CREARBIBLIOTECA_PARTE1_BIBLIOTECAESTATICA_H

#include <iostream>
#include <cstring>
#include <fstream>
#include "Cursos.h"
using namespace std;

char *leerCadenaExacta(ifstream &arch, int max, char delim) ;
void operator >> (ifstream &arch, Cursos &curso);
void operator ++(Cursos &curso);
void operator>>(ifstream &arch, Alumnos &alumno);
bool operator >(Alumnos &alumno, int codigoalumno);
bool operator >(Cursos &curso, char* codigocurso);
void operator += (Cursos &curso, Alumnos &alumno);
int operator <=(Alumnos *arrAlumnos, Alumnos &alumno);
int operator >=(Cursos *arrCursos, Cursos &curso);
void operator<<(ostream &arch, Cursos &curso);


#endif //CREARBIBLIOTECA_PARTE1_BIBLIOTECAESTATICA_H
