#include <iostream>
using namespace std;
#include "Bibliotecas/AdministrarMetricas.h"

int main()
{
    AdministrarMetricas metricasEnLista;

    metricasEnLista.cargarArchivo("Archivos/metricas.csv");
    metricasEnLista.generarReporte("Reportes/reporteGeneral.txt");
    metricasEnLista.eliminarNodos();
    metricasEnLista.generarReporte("Reportes/reporteSinVencidas.txt");
    return 0;
}