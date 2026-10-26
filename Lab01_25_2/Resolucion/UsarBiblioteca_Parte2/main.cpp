#include <iostream>
#include <fstream>
#include "Bibliotecas/BibliotecaEstatica.h"
using namespace std;

int main() {
    // Manejo de archivos
    ifstream archAlumnos("Archivos/Alumnos.csv",ios::in);
    if (not archAlumnos.is_open()) {
        cout<<"ERROR: Hubo un problema al leer los alumnos."<<endl;
        exit(1);
    }

    ifstream archCursos("Archivos/Cursos.csv",ios::in);
    if (not archCursos.is_open()) {
        cout<<"ERROR: Ocurrio un inconveniente al leer los cursos"<<endl;
        exit(1);
    }

    ifstream archMatricula("Archivos/Matricula.csv",ios::in);
    if (not archMatricula.is_open()) {
        cout<<"ERROR: No se pudo analizar la matricula."<<endl;
        exit(1);
    }

    ofstream archReporte("Reportes/reporte.txt",ios::out);
    if (not archReporte.is_open()) {
        cout<<"Hubo un problema al generar el reporte solicitado."<<endl;
        exit(1);
    }


    // Definicion de arreglos
    Alumnos *alumnos = new Alumnos[100]{};
    int numAlumnos = 0;
    Alumnos alumno{};

    Cursos *cursos = new Cursos[100]{};
    int numCursos = 0;
    Cursos curso{};


    // Llenado de alumnos
    while (true) {
        archAlumnos>>alumno;
        if (archAlumnos.eof()) break;
        if ((alumnos <= alumno) == -1) {
            alumnos[numAlumnos] = alumno;
            numAlumnos++;
        };
    }


    // Llenado de Cursos
    while (true) {
        archCursos>>curso;
        if (archCursos.eof()) break;
        if ((cursos >= curso) == -1) {
            cursos[numCursos] = curso;
            numCursos++;
        }
    }


    // Analisis de Matricula
    while (true) {
        char *codCursoMatricula = leerCadenaExacta(archMatricula,10,',');
        if (archMatricula.eof()) break;
        int codAlumnoMatricula;
        archMatricula>>codAlumnoMatricula;
        archMatricula.get();
        Cursos cursoDado{};
        cursoDado.codigo = codCursoMatricula;
        int posCurso = cursos >= cursoDado;
        if (posCurso != -1) {
            Alumnos alumnoDado{};
            alumnoDado.codigo = codAlumnoMatricula;
            int posAlumno = alumnos <= alumnoDado;
            if (posAlumno != -1) {
                cursos[posCurso] += alumnos[posAlumno];
            }
        }
    }


    // Actualizacion de porcentaje de alumnos matriculados
    for (int i = 0; i < numCursos; i++) {
        ++cursos[i];
    }


    // Impresion de resultados
    for (int i = 0; i < numCursos; i++) {
        archReporte<<cursos[i];
        archReporte<<endl;
    }

    return 0;
}
