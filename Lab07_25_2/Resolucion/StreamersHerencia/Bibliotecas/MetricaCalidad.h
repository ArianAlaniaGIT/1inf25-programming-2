//
// Created by arian on 16/01/2026.
//

#ifndef STREAMERSHERENCIA_METRICACALIDAD_H
#define STREAMERSHERENCIA_METRICACALIDAD_H
#include "Metrica.h"


class MetricaCalidad: public Metrica {
public:
    MetricaCalidad();
    void inicializa();
    MetricaCalidad(const MetricaCalidad &orig);
    void operator=(const MetricaCalidad& orig);
    virtual ~MetricaCalidad();
    void elimina();
    int get_bitrate_promedio_kbps() const;
    void set_bitrate_promedio_kbps(int bitrate_promedio_kbps);
    double get_porcentaje_frames_perdidos() const;
    void set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos);
    int get_fps_promedio() const;
    void set_fps_promedio(int fps_promedio);
    void leer(ifstream &arch);

    void imprimir(ofstream &arch);

private:
    int bitrate_promedio_kbps;
    double porcentaje_frames_perdidos;
    int fps_promedio;
};


#endif //STREAMERSHERENCIA_METRICACALIDAD_H