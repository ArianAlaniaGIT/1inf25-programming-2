#include <iostream>

#include "Bibliotecas/Veterinaria.h"

int main() {
    Veterinaria veterinaria;

    veterinaria <= "Archivos/mascotas.csv";
    veterinaria <<= "Archivos/vacunasAplicadas.csv";
    veterinaria << "Reportes/Reporte.txt";



    return 0;
}
