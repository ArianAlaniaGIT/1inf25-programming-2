//
// Created by arian on 17/01/2026.
//

#ifndef STREAMERSHERENCIA_STREAMERPAGO_H
#define STREAMERSHERENCIA_STREAMERPAGO_H
#include "MetricaBasica.h"
#include "MetricaCalidad.h"
#include "MetricaEngagement.h"
#include "Streamer.h"


class StreamerPago: public Streamer {
public:
    StreamerPago();
    void inicializa();
    int get_fecha_inicio_plan() const;
    void set_fecha_inicio_plan(int fecha_inicio_plan);
    int get_cantidad_metricas_basicas() const;
    void set_cantidad_metricas_basicas(int cantidad_metricas_basicas);
    int get_cantidad_metricas_engagement() const;
    void set_cantidad_metricas_engagement(int cantidad_metricas_engagement);
    int get_cantidad_metricas_calidades() const;
    void set_cantidad_metricas_calidades(int cantidad_metricas_calidades);
    virtual ~StreamerPago();
    void elimina();
    void leer(ifstream &arch);
    char obtenerTipo();
    void actualizarDatosEngagement(ifstream& arch, int& capacidad);
    void incrementarEspaciosEngagement(int& cap, int& mind, MetricaEngagement*& arreglo);
    void actualizarDatosBasic(ifstream& arch, int& capacidad);
    void incrementarEspaciosMetricas(int& cap, int& mind, MetricaBasica*& arreglo);
    void actualizarDatosQualities(ifstream& arch, int& capacidad);
    void incrementarEspaciosCalidades(int& cap, int& mind, MetricaCalidad*& arreglo);
    void imprimir(ofstream& arch);

    void imprimirCalidades(ofstream &arch, int &activas, int &vencidas);

    void imprimirEngagements(ofstream &arch, int &activas, int &vencidas);

    void imprimirBasicas(ofstream &arch, int &activas, int &vencidas);

    void elaborarLinea(char c, int max, ofstream& arch);

private:
    int fecha_inicio_plan;
    MetricaBasica *metricas_basicas;
    int cantidad_metricas_basicas;
    MetricaEngagement *metricas_engagements;
    int cantidad_metricas_engagement;
    MetricaCalidad *metricas_calidades;
    int cantidad_metricas_calidades;
};


#endif //STREAMERSHERENCIA_STREAMERPAGO_H