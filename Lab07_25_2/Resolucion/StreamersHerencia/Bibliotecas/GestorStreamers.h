//
// Created by arian on 22/01/2026.
//

#ifndef STREAMERSHERENCIA_GESTORSTREAMERS_H
#define STREAMERSHERENCIA_GESTORSTREAMERS_H
#include "StreamerGratuito.h"
#include "StreamerPago.h"


class GestorStreamers
{
public:
    GestorStreamers();
    void inicializa();
    int get_cantidad_gratuitos() const;
    void set_cantidad_gratuitos(int cantidad_gratuitos);
    int get_cantidad_pagados() const;
    void set_cantidad_pagados(int cantidad_pagados);

    void cargar_datos_streamers(const char*nombArch);
    void llenarGratuitos(ifstream& arch, int& capGratuitos);
    void llenarPagados(ifstream& arch, int& capPagados);
    void incrementarEspaciosPagados(int& cap, int& mind, StreamerPago*& arreglo);
    void incrementarEspaciosGratuitos(int& cap, int& mind, StreamerGratuito*& arreglo);
    void actualizar_datos_metricas(const char* nombArch);
    void actualizarEngagements(ifstream& arch, int* capStreamerEngage);
    void actualizarQualities(ifstream& arch, int* capStreamerQuality);
    void actualizarBasics(ifstream& arch, int* capStreamerBasic, int* capStreamerFree);

    int buscarStreamerPago(int idStreamer) const;
    void generarReportes();
    void realizarElReportePagados(char* ruta, int pos);
    void realizarElReporteGratuitos(char* ruta, int pos);
    void elaborarLinea(char c, int max, ofstream& arch);
    char* obtenerRuta(char* nombreArchivo, const char* tipoStream, const char* carpeta_base);
    char* crearNombreArchivo(char* cuenta, char* categoria, int fecha);

private:
    StreamerGratuito *streamers_gratuitos;
    StreamerPago *streamers_pagados;
    int cantidad_gratuitos;
    int cantidad_pagados;
};


#endif //STREAMERSHERENCIA_GESTORSTREAMERS_H