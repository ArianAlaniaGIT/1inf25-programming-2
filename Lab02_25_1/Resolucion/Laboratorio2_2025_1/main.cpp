#include <iostream>

#include "Bibliotecas/funciones.h"

int main() {
    Faltas faltas{};
    cargar_faltas_de_los_conductores(faltas);
    imprimir_faltas_de_los_conductores(faltas);

    return 0;
}
