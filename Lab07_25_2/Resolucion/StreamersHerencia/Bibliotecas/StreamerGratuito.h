//
// Created by arian on 17/01/2026.
//

#ifndef STREAMERSHERENCIA_STREAMERGRATUITO_H
#define STREAMERSHERENCIA_STREAMERGRATUITO_H
#include "MetricaBasica.h"
#include "Streamer.h"


class StreamerGratuito: public Streamer {
public:
    StreamerGratuito();
    void inicializa();
    virtual ~StreamerGratuito();
    void elimina();
    int get_fecha_fin_trial() const;
    void set_fecha_fin_trial(int fecha_fin_trial);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
    void leer(ifstream& arch);
    char obtenerTipo();
    void actualizarDatos(ifstream& arch, int& capacidad);
    void incrementarEspaciosMetricas(int& cap, int& mind, MetricaBasica*& arreglo);
    void imprimir(ofstream& arch);
    void elaborarLinea(char c, int max, ofstream& arch);

private:
    int fecha_fin_trial;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;

};


#endif //STREAMERSHERENCIA_STREAMERGRATUITO_H