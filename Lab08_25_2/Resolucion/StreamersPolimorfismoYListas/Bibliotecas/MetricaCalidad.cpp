//
// Created by alulab14 on 21/11/2025.
//

#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad() {
    bitrate_promedio_kbps = 0;
    porcentaje_frames_perdidos = 0;
    fps_promedio = 0;
}

int MetricaCalidad::get_bitrate_promedio_kbps() const {
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps) {
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const {
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos) {
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const {
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int fps_promedio) {
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream &arch) {
    Metrica::leer(arch);
    arch>>bitrate_promedio_kbps;
    arch.get();
    arch>>porcentaje_frames_perdidos;
    arch.get();
    arch>>fps_promedio;
    arch.get();
}

void MetricaCalidad::imprimir(ofstream &arch) {
    Metrica::imprimir(arch);
    arch<<setw(10)<<bitrate_promedio_kbps<<setw(10)<<
        porcentaje_frames_perdidos<<setw(10)<<fps_promedio<<endl;
}

char MetricaCalidad::getTipo() {
    char c= Metrica::getTipo();
    return 'Q';
}
