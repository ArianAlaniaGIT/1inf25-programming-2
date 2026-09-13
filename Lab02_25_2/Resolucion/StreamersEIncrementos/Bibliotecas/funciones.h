//
// Created by arian on 24/12/2025.
//

#ifndef STREAMERSEINCREMENTOS_FUNCIONES_H
#define STREAMERSEINCREMENTOS_FUNCIONES_H

void incrementarEspaciosCategoria(char*** &categoria, int &mind, int &cap) ;
void cargarCategorias(const char*nombArch, char*** &categorias);
char *leerCadenaExacta(ifstream &arch, int max, char delim);
char **leerDatosCategoria(ifstream &arch);
void llenarDatosStreamers(char** &regStreamer, int* &regFecha, long long* &regTiempo, ifstream &arch);
char **llenarStreamer(char *cuenta, char*categoria);
int *llenarFecha(int fecha1, int fecha2, int num);
long long *llenarTiempo(long long numlong1, long long numlong2);
void incrementarDatosPorTres(int &mind, int &cap, char ***&streamers, int **&fechasPromedios, long long **&tiempoRepSeguidores);
void cargarStreamers(const char*nombArch, char*** &streamers, int** &fechasPromedios, long long** &tiempoRepSeguidores);
void leerRestoDelTexto(char **dupla, char**&regEtiq,ifstream &arch, char*texto1, char*texto2);
char **leerEtiquetas(ifstream &arch);
void incrementarEspaciosComentarios(int &mind, int &cap, char*** &comentarios);
void cargarComentarios(const char*nombArch, char*** &comentarios, char*** &etiquetas);
void imprimirReporte(const char*nombArch, char ***categorias, char ***streamers, int **fechasPromedios, long long **tiempoRepSeguidores, char ***comentarios, char***etiquetas);
void imprimirInfoStreamers(char *categoria, char ***streamers, int **fechasPromedios, long long **tiempoRepSeguidores, char ***comentarios, char***etiquetas,ofstream &arch);
void pasarADMA(int fecha, int &dia, int &mes, int &anho);
void imprimirFechas(int *fechasPromedios, ofstream &arch);
void imprimirEtiquetas(char ***etiquetas,char ***comentarios,char *streamer,ofstream &arch);
void imprimirLinea(ofstream &arch, char c, int max);

#endif //STREAMERSEINCREMENTOS_FUNCIONES_H