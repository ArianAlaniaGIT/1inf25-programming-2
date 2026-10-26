#include <iostream>

#include "Bibliotecas/Cursos.h"
#include "Bibliotecas/BibliotecaEstatica.h"
using namespace std;

int main() {


    Cursos curso;

    const char* codigo = "INF263";
    const char* nombre = "Algoritmia";
    const char* docente= "Melgar";

    curso.numpresencial = 1;
    curso.numvirtual = 2;
    curso.numsemipresencial = 4;

    curso.codigo = new char[strlen(codigo)+1];
    strcpy(curso.codigo, codigo);

    curso.nombre = new char[strlen(nombre)+1];
    strcpy(curso.nombre, nombre);

    curso.docente = new char[strlen(docente)+1];
    strcpy(curso.docente, docente);

    ++curso;

    cout<<curso;

    return 0;
}
