//
// Created by arian on 13/01/2026.
//

#ifndef STREAMERSHERENCIA_METRICAENGAGEMENT_H
#define STREAMERSHERENCIA_METRICAENGAGEMENT_H
#include "Metrica.h"


class MetricaEngagement: public Metrica {
public:
    MetricaEngagement();
    void inicializa();
    MetricaEngagement(const MetricaEngagement& orig);
    void operator=(const MetricaEngagement& orig);

    virtual ~MetricaEngagement();

    int get_mensajes_chat() const;
    void set_mensajes_chat(int mensajes_chat);
    int get_usuarios_unicos_chat() const;
    void set_usuarios_unicos_chat(int usuarios_unicos_chat);
    int get_clips_generados() const;
    void set_clips_generados(int clips_generados);
    void leer(ifstream& arch);

    void imprimir(ofstream &arch);

private:
    int mensajes_chat;
    int usuarios_unicos_chat;
    int clips_generados;

};


#endif //STREAMERSHERENCIA_METRICAENGAGEMENT_H