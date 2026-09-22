//
// Created by arian on 17/01/2026.
//

#include "StreamerGratuito.h"

StreamerGratuito::StreamerGratuito()
{
    inicializa();

}

void StreamerGratuito::inicializa()
{
    Streamer::inicializa();
    fecha_fin_trial = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_basicas = 0;
}

StreamerGratuito::~StreamerGratuito()
{
    elimina();
}

void StreamerGratuito::elimina()
{

    if (metricas_basicas != nullptr) delete []metricas_basicas;
}

int StreamerGratuito::get_fecha_fin_trial() const
{
    return fecha_fin_trial;
}

void StreamerGratuito::set_fecha_fin_trial(int fecha_fin_trial)
{
    this->fecha_fin_trial = fecha_fin_trial;
}

int StreamerGratuito::get_cantidad_metricas_basicas() const
{
    return cantidad_metricas_basicas;
}

void StreamerGratuito::set_cantidad_metricas_basicas(int cantidad_metricas_basicas)
{
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

void StreamerGratuito::leer(ifstream& arch)
{
    Streamer::leer(arch);
    int dia,mes,anho;
    char c;
    arch>>anho>>c>>mes>>c>>dia;
    arch.get();
    fecha_fin_trial = anho*10000 + mes*100 + dia;
}

char StreamerGratuito::obtenerTipo(){
    return 'G';
}

void StreamerGratuito::actualizarDatos(ifstream &arch, int &capacidad) {
    MetricaBasica basica;
    basica.leer(arch);
    if (capacidad == cantidad_metricas_basicas) incrementarEspaciosMetricas(capacidad,cantidad_metricas_basicas, metricas_basicas);
    metricas_basicas[cantidad_metricas_basicas-1] = basica;
    cantidad_metricas_basicas++;
}

void StreamerGratuito::incrementarEspaciosMetricas(int &cap, int &mind, MetricaBasica *&arreglo) {
    cap+=5;
    MetricaBasica *aux;
    if (arreglo == nullptr) {
        arreglo = new MetricaBasica[cap]{};
        mind = 1;
    } else {
        aux = new MetricaBasica[cap]{};
        for (int i = 0; i < mind;i++) {
            aux[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = aux;
    }
}


void StreamerGratuito::imprimir(ofstream &arch) {
    arch.precision(2); arch<<fixed;
    Streamer::imprimir(arch);
    arch << " | TIPO: StreamerGratuito" << endl;
    elaborarLinea('-',120,arch);
    double horasTotales = 0; int totalEspectadores = 0, activas = 0, vencidas = 0;
    for (int i = 0; i < cantidad_metricas_basicas;i++) if (metricas_basicas[i].get_id() > 0) horasTotales += metricas_basicas[i].get_horas_transmitidas();
    for (int i= 0; i < cantidad_metricas_basicas;i++) if (metricas_basicas[i].get_id() > 0) totalEspectadores += metricas_basicas[i].get_espectadores_promedio();
    for (int i= 0; i < cantidad_metricas_basicas;i++) {
        if (metricas_basicas[i].get_id() > 0) {
            if (metricas_basicas[i].is_estado() == true)activas++;
            else vencidas++;
        }
    }
    arch<<"[BASIC] HORAS_TOT: "<<setw(5)<<horasTotales<<" | VIEWERS_PROM_GLOBAL: "<<setw(5)<<totalEspectadores<<" | ACTIVAS: "<<activas<<" | EXPIRADAS: "<<vencidas<<endl;
    arch<<"Codigo"<<setw(18)<<"Fecha Calc."<<setw(11)<<"Expira"<<setw(12)<<"Estado"<<setw(11)<<"Horas"<<setw(11)<<"Viewers"<<setw(16)<<"Descripcion"<<endl;
    for (int i = 0; i < cantidad_metricas_basicas;i++) if (metricas_basicas[i].get_id() > 0) metricas_basicas[i].imprimir(arch);
    elaborarLinea('-',120,arch);
    arch<<"[UPSELL] Funcionalidad Pro. Adquiere la licencia para ver estadísticas avanzadas."<<endl;
    elaborarLinea('-',120,arch);
    arch<<"[TOTAL] MÉTRICAS ACTIVAS: "<<activas<<" | MÉTRICAS EXPIRADAS: "<<vencidas<<" | FECHA DE REPORTE: 2025-11-07"<<endl;
}

void StreamerGratuito::elaborarLinea(char c, int max, ofstream &arch) {
    for (int i= 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}