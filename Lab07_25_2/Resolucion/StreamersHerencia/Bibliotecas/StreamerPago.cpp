//
// Created by arian on 17/01/2026.
//

#include "StreamerPago.h"

StreamerPago::StreamerPago()
{
    inicializa();
}

void StreamerPago::inicializa()
{
    Streamer::inicializa();
    fecha_inicio_plan = 0;
    metricas_basicas = nullptr;
    cantidad_metricas_basicas = 0;
    metricas_engagements = nullptr;
    cantidad_metricas_engagement = 0;
    metricas_calidades = nullptr;
    cantidad_metricas_calidades = 0;
}

int StreamerPago::get_fecha_inicio_plan() const
{
    return fecha_inicio_plan;
}

void StreamerPago::set_fecha_inicio_plan(int fecha_inicio_plan)
{
    this->fecha_inicio_plan = fecha_inicio_plan;
}

int StreamerPago::get_cantidad_metricas_basicas() const
{
    return cantidad_metricas_basicas;
}

void StreamerPago::set_cantidad_metricas_basicas(int cantidad_metricas_basicas)
{
    this->cantidad_metricas_basicas = cantidad_metricas_basicas;
}

int StreamerPago::get_cantidad_metricas_engagement() const
{
    return cantidad_metricas_engagement;
}

void StreamerPago::set_cantidad_metricas_engagement(int cantidad_metricas_engagement)
{
    this->cantidad_metricas_engagement = cantidad_metricas_engagement;
}

int StreamerPago::get_cantidad_metricas_calidades() const
{
    return cantidad_metricas_calidades;
}

void StreamerPago::set_cantidad_metricas_calidades(int cantidad_metricas_calidades)
{
    this->cantidad_metricas_calidades = cantidad_metricas_calidades;
}

StreamerPago::~StreamerPago()
{
    elimina();
}

void StreamerPago::elimina()
{
    if (metricas_basicas != nullptr) delete []metricas_basicas;
    if (metricas_calidades != nullptr) delete []metricas_calidades;
    if (metricas_engagements != nullptr) delete []metricas_engagements;
}

void StreamerPago::leer(ifstream& arch)
{
    Streamer::leer(arch);
    int dia,mes,anho;
    char c;
    arch>>anho>>c>>mes>>c>>dia;
    arch.get();
    fecha_inicio_plan = anho*10000 + mes*100 + dia;
}

char StreamerPago::obtenerTipo() {
    return 'P';
}

void StreamerPago::actualizarDatosEngagement(ifstream &arch, int &capacidad) {
    MetricaEngagement engagement;
    engagement.leer(arch);
    if (capacidad == cantidad_metricas_engagement) incrementarEspaciosEngagement(capacidad,cantidad_metricas_engagement, metricas_engagements);
    if (engagement.get_id() > 0) {
        metricas_engagements[cantidad_metricas_engagement-1] = engagement;
        cantidad_metricas_engagement++;
    }
}

void StreamerPago::incrementarEspaciosEngagement(int &cap, int &mind, MetricaEngagement *&arreglo) {
    cap+=5;
    MetricaEngagement *aux;
    if (arreglo == nullptr) {
        arreglo = new MetricaEngagement[cap]{};
        mind = 1;
    } else {
        aux = new MetricaEngagement[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arreglo[i];
        }
        delete [] arreglo;
        arreglo = aux;
    }
}

void StreamerPago::actualizarDatosBasic(ifstream &arch, int &capacidad) {
    MetricaBasica basica;
    basica.leer(arch);
    if (capacidad == cantidad_metricas_basicas) incrementarEspaciosMetricas(capacidad,cantidad_metricas_basicas, metricas_basicas);
    if (basica.get_id() > 0) {
        metricas_basicas[cantidad_metricas_basicas-1] = basica;
        cantidad_metricas_basicas++;
    }
}

void StreamerPago::incrementarEspaciosMetricas(int &cap, int &mind, MetricaBasica *&arreglo) {
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

void StreamerPago::actualizarDatosQualities(ifstream &arch, int &capacidad) {
    MetricaCalidad calidad;
    calidad.leer(arch);
    if (capacidad == cantidad_metricas_calidades) incrementarEspaciosCalidades(capacidad,cantidad_metricas_calidades, metricas_calidades);
    if (calidad.get_id() > 0) {
        metricas_calidades[cantidad_metricas_calidades-1] = calidad;
        cantidad_metricas_calidades++;
    }
}

void StreamerPago::incrementarEspaciosCalidades(int &cap, int &mind, MetricaCalidad *&arreglo) {
    cap +=5;
    MetricaCalidad *aux;
    if (arreglo == nullptr) {
        arreglo = new MetricaCalidad[cap]{};
        mind = 1;
    } else {
        aux = new MetricaCalidad[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arreglo[i];
        }
        delete []arreglo;
        arreglo = aux;
    }
}

void StreamerPago::imprimir(ofstream &arch) {
    Streamer::imprimir(arch);
    arch<<" | TIPO: StreamerPago"<<endl;
    elaborarLinea('-',120,arch);
    int activasBasic = 0, vencidasBasic = 0, activasEngage = 0, vencidasEngage = 0, activasQuality = 0, vencidasQuality = 0;
    int activas = 0, vencidas = 0;
    imprimirBasicas(arch,activasBasic,vencidasBasic);
    imprimirEngagements(arch,activasEngage,vencidasEngage);
    imprimirCalidades(arch,activasQuality,vencidasQuality);
    activas = activasEngage + activasBasic + activasQuality;
    vencidas = vencidasBasic + vencidasQuality + vencidasEngage;

    arch<<"[TOTAL] MÉTRICAS ACTIVAS: "<<activas<<" | MÉTRICAS EXPIRADAS: "<<vencidas<<" | FECHA DE REPORTE: 2025-11-07"<<endl;
}

void StreamerPago::imprimirCalidades(ofstream &arch, int &activas, int &vencidas) {
    int bit = 0, fps = 0;
    double promedio = 0;
    for (int i = 0; i < cantidad_metricas_calidades; i++) {
        if (metricas_calidades[i].get_id() > 0) {
            if (metricas_calidades[i].is_estado()) activas++;
            else vencidas++;
            bit += metricas_calidades[i].get_bitrate_promedio_kbps();
            fps += metricas_calidades[i].get_fps_promedio();
            promedio += metricas_calidades[i].get_porcentaje_frames_perdidos();
        }
    }
    arch<<"[QUALITY] BITRATE_PROM: "<<bit<<" kbps | DROP%_PROM: "<<promedio<<" | FPS_PROM: "<<fps<<" | ACTIVAS: "<<activas<<" | EXPIRADAS: "<<vencidas<<endl;
    arch<<"Codigo"<<setw(18)<<"Fecha Calc."<<setw(11)<<"Expira"<<setw(12)<<"Estado"<<setw(11)<<"Bitrate"<<setw(11)<<"Drop%"<<setw(11)<<"FPS"<<setw(16)<<"Descripcion"<<endl;
    for (int i = 0; i < cantidad_metricas_calidades; i++) if (metricas_calidades[i].get_id() > 0) metricas_calidades[i].imprimir(arch);
    elaborarLinea('-',120,arch);
}

void StreamerPago::imprimirEngagements(ofstream &arch, int &activas, int &vencidas) {
    int mes = 0, us = 0, clips = 0;
    for (int i = 0; i < cantidad_metricas_engagement;i++) {
        if (metricas_engagements[i].get_id() > 0) {
            if (metricas_engagements[i].is_estado()) activas++;
            else vencidas++;
            mes += metricas_engagements[i].get_mensajes_chat();
            us += metricas_engagements[i].get_usuarios_unicos_chat();
            clips += metricas_engagements[i].get_clips_generados();
        }
    }
    arch<<"[ENGAGE] CHAT_MSGS: "<<setw(6)<<mes<<" | CHATTERS_UNICOS: "<<setw(5)<<us<<" | CLIPS: "<<setw(4)<<clips<<" | ACTIVAS: "<<activas<<" | EXPIRADAS: "<<vencidas<<endl;
    arch<<"Codigo"<<setw(18)<<"Fecha Calc."<<setw(11)<<"Expira"<<setw(12)<<"Estado"<<setw(11)<<"Msgs"<<setw(11)<<"Chatters"<<setw(11)<<"Clips"<<setw(16)<<"Descripcion"<<endl;
    for (int i = 0; i < cantidad_metricas_engagement;i++) if (metricas_engagements[i].get_id() > 0) metricas_engagements[i].imprimir(arch);
    elaborarLinea('-',120,arch);
}

void StreamerPago::imprimirBasicas(ofstream &arch, int&activas, int&vencidas) {
    double horasTotales = 0; int totalEspectadores = 0;
    for (int i= 0; i < cantidad_metricas_basicas;i++) {
        if (metricas_basicas[i].get_id() > 0) {
            if (metricas_basicas[i].is_estado() == true)activas++;
            else vencidas++;
            horasTotales += metricas_basicas[i].get_horas_transmitidas();
            totalEspectadores += metricas_basicas[i].get_espectadores_promedio();
        }
    }
    arch<<"[BASIC] HORAS_TOT: "<<setw(5)<<horasTotales<<" | VIEWERS_PROM_GLOBAL: "<<setw(5)<<totalEspectadores<<" | ACTIVAS: "<<activas<<" | EXPIRADAS: "<<vencidas<<endl;
    arch<<"Codigo"<<setw(18)<<"Fecha Calc."<<setw(11)<<"Expira"<<setw(12)<<"Estado"<<setw(11)<<"Horas"<<setw(11)<<"Viewers"<<setw(16)<<"Descripcion"<<endl;
    for (int i = 0; i < cantidad_metricas_basicas;i++) if (metricas_basicas[i].get_id() > 0) metricas_basicas[i].imprimir(arch);
    elaborarLinea('-',120,arch);
}

void StreamerPago::elaborarLinea(char c, int max, ofstream &arch)
{
    for (int i= 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}