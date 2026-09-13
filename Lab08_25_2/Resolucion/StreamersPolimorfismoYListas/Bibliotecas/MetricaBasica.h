//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_METRICABASICA_H
#define STREAMERSPOLIMORFISMOYLISTAS_METRICABASICA_H
#include "Metrica.h"


class MetricaBasica: public Metrica {

public:
    MetricaBasica();

    double get_horas_transmitidas() const;

    void set_horas_transmitidas(double horas_transmitidas);

    int get_espectadores_promedio() const;

    void set_espectadores_promedio(int espectadores_promedio);

    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    char getTipo();

private:
    double horas_transmitidas;
    int espectadores_promedio;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_METRICABASICA_H