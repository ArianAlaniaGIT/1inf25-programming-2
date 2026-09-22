//
// Created by arian on 13/01/2026.
//

#ifndef STREAMERSHERENCIA_METRICABASICA_H
#define STREAMERSHERENCIA_METRICABASICA_H
#include "Metrica.h"


class MetricaBasica: public Metrica {
public:
    MetricaBasica();
    void inicializa();
    MetricaBasica(const MetricaBasica& orig);
    void operator=(const MetricaBasica& orig);
    void elimina();
    virtual ~MetricaBasica();

    double get_horas_transmitidas() const;
    void set_horas_transmitidas(double horas_transmitidas);
    int get_espectadores_promedio() const;
    void set_espectadores_promedio(int espectadores_promedio);
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);

private:
    double horas_transmitidas;
    int espectadores_promedio;

};


#endif //STREAMERSHERENCIA_METRICABASICA_H