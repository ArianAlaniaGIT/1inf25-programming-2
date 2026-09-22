#include <iostream>

#include "Bibliotecas/GestorStreamers.h"
using namespace std;

int main() {
    GestorStreamers comoGestionar;
    comoGestionar.cargar_datos_streamers("Archivos/streamers.csv");
    comoGestionar.actualizar_datos_metricas("Archivos/metricas.csv");

    comoGestionar.generarReportes();

    return 0;
}
