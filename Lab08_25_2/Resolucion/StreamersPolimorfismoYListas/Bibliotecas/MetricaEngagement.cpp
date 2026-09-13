//
// Created by alulab14 on 21/11/2025.
//

#include "MetricaEngagement.h"

MetricaEngagement::MetricaEngagement() {
    mensajes_chat = 0;
    usuarios_unicos_chat = 0;
    clips_generados = 0;
}

int MetricaEngagement::get_mensajes_chat() const {
    return mensajes_chat;
}

void MetricaEngagement::set_mensajes_chat(int mensajes_chat) {
    this->mensajes_chat = mensajes_chat;
}

int MetricaEngagement::get_usuarios_unicos_chat() const {
    return usuarios_unicos_chat;
}

void MetricaEngagement::set_usuarios_unicos_chat(int usuarios_unicos_chat) {
    this->usuarios_unicos_chat = usuarios_unicos_chat;
}

int MetricaEngagement::get_clips_generados() const {
    return clips_generados;
}

void MetricaEngagement::set_clips_generados(int clips_generados) {
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
    Metrica::imprimir(arch);
    arch<<setw(10)<<mensajes_chat<<setw(10)<<usuarios_unicos_chat<<setw(10)<<clips_generados<<endl;
}

char MetricaEngagement::getTipo() {
    char c = Metrica::getTipo();
    return 'E';
}


