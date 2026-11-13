#include <iostream>

#include "Bibliotecas/MinisterioDeTransporte.h"
using namespace std;

int main() {
    MinisterioDeTransporte ministerio;
    ministerio < "Archivos/TablaDeInfracciones.csv";
    ministerio <= "Archivos/EmpresasRegistradas.csv";
    ministerio <<= "Archivos/InfraccionesCometidas.csv";
    ministerio >> "Reportes/ReporteParaElMinisterio.txt";
    


    return 0;
}
