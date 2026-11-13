#include <iostream>
#include "Bibliotecas/Empresa.h"

// Nota: Para esta ocasion se decidió llevar el laboratorio al siguiente nivel, trabajando todos
// los arreglos como 100% dinámicos.

int main() {
    Empresa empresa;

    empresa.cargarProductos("Archivos/Productos.csv");
    empresa.cargarVentas("Archivos/Ventas.csv");
    empresa.cargaDetalles("Archivos/DetalleVentas.csv");
    empresa.calculaTotales();
    empresa.reporteDeVentas("Reportes/RegistroDeVentas.txt");

    return 0;
}
