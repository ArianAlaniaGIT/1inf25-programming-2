//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_ADMINISTRARMETRICAS_H
#define STREAMERSPOLIMORFISMOYLISTAS_ADMINISTRARMETRICAS_H
#include "Lista.h"


class AdministrarMetricas {
public:
    void insertarEnLista(Metrica *metrica, char *tipo);

    void cargarArchivo(const char*nombArch);

    bool asignarMemoria(class Metrica *&metrica, char *tipo);

    void generarReporte(const char *nombArch);
    void eliminarNodos();

private:

    Lista listaDeMetricas;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_ADMINISTRARMETRICAS_H