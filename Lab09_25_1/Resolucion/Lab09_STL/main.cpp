#include <iostream>

#include "Bibliotecas/MinisterioDeTransporte.h"
using namespace std;

int main() {

    MinisterioDeTransporte ministerio;

    ministerio.cargaDeInfracciones("Archivos/TablaDeInfracciones.csv");
    ministerio.cargaEmpresas("Archivos/EmpresasRegistradas.csv");
    ministerio.cargaVehiculos("Archivos/VehiculosRegistrados.csv");
    ministerio.cargaInfraccionesCometidas("Archivos/InfraccionesCometidas.csv");
    ministerio.reporteDeEmpresasConInfracciones("Reportes/reporteCompleto.txt");
    ministerio.eliminaInfraccionesPagadas();
    ministerio.reporteDeEmpresasConInfracciones("Reportes/reporteSinPagadas.txt");

    return 0;
}
