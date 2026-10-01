#include <iostream>

#include "Bibliotecas/funciones.h"
using namespace std;

int main() {
    void *pacientes;

    cargarPacientes("Archivos/pacientes.csv", pacientes);
    cargarVisitas("Archivos/visitas.csv", pacientes);
    generarReporte("Reportes/reporte.txt", pacientes);


    return 0;
}
