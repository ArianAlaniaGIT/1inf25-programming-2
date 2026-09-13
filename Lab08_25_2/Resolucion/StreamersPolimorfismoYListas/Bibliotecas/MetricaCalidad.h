//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_METRICACALIDAD_H
#define STREAMERSPOLIMORFISMOYLISTAS_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad: public Metrica {
public:
    MetricaCalidad();

    int get_bitrate_promedio_kbps() const;

    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);

    double get_porcentaje_frames_perdidos() const;

    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);

    int get_fps_promedio() const;

    void set_fps_promedio(int fps_promedio);
    void leer(ifstream &arch);
    void imprimir(ofstream &arch);

    char getTipo();

private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_METRICACALIDAD_H