//
// Created by arian on 9/08/2026.
//

#include "BibliotecaEstatica.h"

#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

#include "Cursos.h"
using namespace std;


void operator >> (ifstream &arch, Cursos &curso) {
    char *codigo, *nombre, *nombreDocente;
    int cod;
    curso.codigo = leerCadenaExacta(arch,200,',');
    if (arch.eof()) return;
    curso.nombre = leerCadenaExacta(arch,200,',');
    arch>>curso.creditos;
    arch.get();
    arch>>cod;
    arch.get();
    curso.docente = leerCadenaExacta(arch,200,'\n');
    curso.numpresencial = 0;
    curso.numsemipresencial = 0;
    curso.numvirtual = 0;
    curso.presencial = new struct Alumnos[50]{};
    curso.semipresencial = new struct Alumnos[50]{};
    curso.vvirtual = new struct Alumnos[50]{};
}

char *leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof()) return nullptr;
    ptCadena = new char[strlen(cadena)+1]{};
    strcpy(ptCadena,cadena);
    return ptCadena;
}

void operator>>(ifstream &arch, Alumnos &alumno) {
    arch>>alumno.codigo;
    if (arch.eof())return;
    arch.get();
    alumno.nombre = leerCadenaExacta(arch,200,',');
    arch>>alumno.tipo;
    arch.get();
}

bool operator >(Alumnos &alumno, int codigoalumno) {
    return alumno.codigo == codigoalumno;
}

bool operator >(Cursos &curso, char* codigocurso) {
    return strcmp(curso.codigo,codigocurso)==0;
}

void operator += (Cursos &curso, Alumnos &alumno) {
    if (alumno.tipo == 'P') {
        curso.presencial[curso.numpresencial] = alumno;
        curso.numpresencial++;
    } else if (alumno.tipo == 'S') {
        curso.semipresencial[curso.numsemipresencial] = alumno;
        curso.numsemipresencial++;
    } else if (alumno.tipo == 'V') {
        curso.vvirtual[curso.numvirtual] = alumno;
        curso.numvirtual++;
    }
}

int operator <=(Alumnos *arrAlumnos, Alumnos &alumno) {
    for (int i = 0; arrAlumnos[i].codigo != 0; i++) {
        if (arrAlumnos[i] > alumno.codigo) {
            return i;
        }
    }
    return -1;
}

int operator >=(Cursos *arrCursos, Cursos &curso) {
    for (int i = 0; arrCursos[i].codigo != nullptr; i++) {
        if (arrCursos[i] > curso.codigo) {
            return i;
        }
    }
    return -1;
}

void operator ++(Cursos &curso) {
    int total = curso.numpresencial + curso.numsemipresencial + curso.numvirtual;
    const char *resultadoPresencial = "La clase se dictará en aula";
    const char *resultadoNoPresencial = "La clase se dictará 100% virtual";

    double porcentajePresenciales = (double)curso.numpresencial / (double) total;

    if (porcentajePresenciales >= 0.50) {
        curso.tipofinal = new char[strlen(resultadoPresencial)+1]{};
        strcpy (curso.tipofinal,resultadoPresencial);
    } else {
        curso.tipofinal = new char[strlen(resultadoNoPresencial)+1]{};
        strcpy (curso.tipofinal,resultadoNoPresencial);
    }
}

void operator<<(ostream &arch, Cursos &curso) {
    arch<<left<<setw(10)<<curso.codigo<<setw(20)<<curso.nombre<<endl;
    arch<<left<<curso.docente<<endl;
    arch<<setw(30)<<"Alumnos presenciales: "<<curso.numpresencial<<endl;
    arch<<setw(30)<<"Alumnos semipresenciales: "<<curso.numsemipresencial<<endl;
    arch<<setw(30)<<"Alumnos virtuales: "<<curso.numvirtual<<endl;
    if (curso.tipofinal != nullptr) {
        arch<<curso.tipofinal<<endl;
    }
}