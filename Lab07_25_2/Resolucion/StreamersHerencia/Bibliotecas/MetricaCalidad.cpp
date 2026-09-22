//
// Created by arian on 16/01/2026.
//

#include "MetricaCalidad.h"

MetricaCalidad::MetricaCalidad()
{
    inicializa();
}

void MetricaCalidad::inicializa()
{
    Metrica::inicializa();
    bitrate_promedio_kbps = 0;
    porcentaje_frames_perdidos = 0;
    fps_promedio = 0;
}

MetricaCalidad::MetricaCalidad(const MetricaCalidad& orig) {
    inicializa();
    *this = orig;
}

void MetricaCalidad::operator=(const MetricaCalidad& orig) {
    Metrica::operator=(orig);
    bitrate_promedio_kbps = orig.bitrate_promedio_kbps;
    porcentaje_frames_perdidos = orig.porcentaje_frames_perdidos;
    fps_promedio = orig.fps_promedio;
}

MetricaCalidad::~MetricaCalidad()
{
    elimina();
}

void MetricaCalidad::elimina()
{
    // no pasa nada
}

int MetricaCalidad::get_bitrate_promedio_kbps() const
{
    return bitrate_promedio_kbps;
}

void MetricaCalidad::set_bitrate_promedio_kbps(int bitrate_promedio_kbps)
{
    this->bitrate_promedio_kbps = bitrate_promedio_kbps;
}

double MetricaCalidad::get_porcentaje_frames_perdidos() const
{
    return porcentaje_frames_perdidos;
}

void MetricaCalidad::set_porcentaje_frames_perdidos(double porcentaje_frames_perdidos)
{
    this->porcentaje_frames_perdidos = porcentaje_frames_perdidos;
}

int MetricaCalidad::get_fps_promedio() const
{
    return fps_promedio;
}

void MetricaCalidad::set_fps_promedio(int fps_promedio)
{
    this->fps_promedio = fps_promedio;
}

void MetricaCalidad::leer(ifstream& arch) {
    Metrica::leer(arch);
    arch>>bitrate_promedio_kbps;
    arch.get();
    arch>>porcentaje_frames_perdidos;
    arch.get();
    arch>>fps_promedio;
    arch.get();
}

void MetricaCalidad::imprimir(ofstream &arch) {
    arch<<"MQ-";
    Metrica::imprimir(arch);
    char cadena[100];
    Metrica::get_descripcion(cadena);
    arch<<setw(10)<<bitrate_promedio_kbps<<setw(12)<<porcentaje_frames_perdidos<<setw(10)<<fps_promedio<<setw(6)<<" "<<cadena<<endl;
}
