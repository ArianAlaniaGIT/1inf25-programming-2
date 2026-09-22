#include <iostream>

#include "Bibliotecas/SistemaDeGestion.h"

int main()
{
    SistemaDeGestion sistemon;


    sistemon.cargarCategorias("Archivos/Categorias.csv");
    sistemon.cargaComentarios("Archivos/Comentarios.csv");
    sistemon.cargarEtiquetas("Archivos/Etiquetas.csv");
    sistemon.cargaStreamers("Archivos/Streamers.csv");

    sistemon.completarStreamers();

    sistemon.reporteDeStreamers("Reportes/reporteDeStreamers.txt");
    sistemon.eliminaStreamers("French");
    sistemon.reporteDeStreamers("Reportes/reporteActualizado.txt");

    return 0;
}
