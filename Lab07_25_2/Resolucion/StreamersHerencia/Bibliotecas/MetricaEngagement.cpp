//
// Created by arian on 13/01/2026.
//

#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    inicializa();
}

void MetricaEngagement::inicializa() {
    Metrica::inicializa();
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

MetricaEngagement::MetricaEngagement(const MetricaEngagement& orig) {
    inicializa();
    *this = orig;
}

void MetricaEngagement::operator=(const MetricaEngagement& orig) {
    Metrica::operator=(orig);
    mensajes_chat = orig.mensajes_chat;
    usuarios_unicos_chat = orig.usuarios_unicos_chat;
    clips_generados = orig.clips_generados;
}

MetricaEngagement::~MetricaEngagement() {
    // no pasa nada
}

int MetricaEngagement::get_mensajes_chat() const
{
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int mensajes_chat)
{
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const
{
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat)
{
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const
{
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int clips_generados)
{
    this->clips_generados = clips_generados;
}

void MetricaEngagement::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch>>mensajes_chat;
    arch.get();
    arch>>usuarios_unicos_chat;
    arch.get();
    arch>>clips_generados;
    arch.get();
}

void MetricaEngagement::imprimir(ofstream &arch) {
    arch<<"ME-";
    Metrica::imprimir(arch);
    char cadena[100];
    Metrica::get_descripcion(cadena);
    arch<<setw(11)<<mensajes_chat<<setw(9)<<usuarios_unicos_chat<<setw(11)<<clips_generados<<setw(7)<<" "<<cadena<<endl;
}


