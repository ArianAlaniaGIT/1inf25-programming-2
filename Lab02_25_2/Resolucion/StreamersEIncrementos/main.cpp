#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include "Bibliotecas/funciones.h"

int main() {
    char*** categorias;
    cargarCategorias("Archivos/categorias.csv",
                    categorias);

    char*** streamers;
    int** fechasPromedios;
    long long** tiempoRepSeguidores;
    cargarStreamers("Archivos/streamers.csv",
                    streamers,
                    fechasPromedios,
                    tiempoRepSeguidores);

    char*** comentarios;
    char*** etiquetas;
    cargarComentarios("Archivos/comentarios.csv",
                      comentarios,
                      etiquetas);

    imprimirReporte("Reportes/reporte.txt",
                    categorias,
                    streamers,
                    fechasPromedios,
                    tiempoRepSeguidores,
                    comentarios,
                    etiquetas);
    return 0;
}