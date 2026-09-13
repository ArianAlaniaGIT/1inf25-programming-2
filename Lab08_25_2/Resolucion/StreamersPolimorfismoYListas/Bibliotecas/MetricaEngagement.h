//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_METRICAENGAGEMENT_H
#define STREAMERSPOLIMORFISMOYLISTAS_METRICAENGAGEMENT_H
#include "Metrica.h"


class MetricaEngagement: public Metrica {
public:
    MetricaEngagement();

    int get_mensajes_chat() const;

    void set_mensajes_chat(int mensajes_chat);

    int get_usuarios_unicos_chat() const;

    void set_usuarios_unicos_chat(int usuarios_unicos_chat);

    int get_clips_generados() const;

    void set_clips_generados(int clips_generados);

    void leer(ifstream &arch);
    void imprimir(ofstream &arch);
    char getTipo();

private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_METRICAENGAGEMENT_H