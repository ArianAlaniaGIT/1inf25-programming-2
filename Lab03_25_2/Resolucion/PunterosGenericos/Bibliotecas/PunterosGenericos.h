//
// Created by arian on 19/09/2025.
//

#ifndef PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
#define PUNTEROSGENERICOS_PUNTEROSGENERICOS_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


void cargastreamers(void *&str);
void *darConLosStreamers(ifstream &arch);
char *leerCadenaExacta(ifstream &arch, int max, char delim);
void incrementarEspacios(void**&arr, int &mind, int &cap);
void pruebaStreamers(void *str);
void cargacomentarios(void *&comen);
void *darConLosComentarios(ifstream &arch);
void pruebaComentarios(void *comen);
void actualizacomentarios(void *&str,void *&comen);
int buscarStreamer(void **streamers, char *emisor);
void imprimestreamers(const void*str);
void elaborarLinea(ofstream &arch,int max,char c);
void llenarLosRestantes(void **&comentarios, void **&streamers,int *nd,int *cap);
void imprimirComentariosStr(ofstream &arch, void *dato);


#endif //PUNTEROSGENERICOS_PUNTEROSGENERICOS_H
