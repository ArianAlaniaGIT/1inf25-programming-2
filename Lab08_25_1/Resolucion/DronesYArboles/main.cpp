#include <iostream>

#include "Bibliotecas/Central.h"

int main() {
    Central central;
    central.carga("Archivos/Drones.csv");
    central.muestra("Reportes/reporte.txt");
    central.actualiza();
    central.muestra("Reportes/reporte2.txt");
    return 0;
}
