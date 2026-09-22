//
// Created by arian on 10/01/2026.
//

#ifndef LABORATORIO09_STL_SISTEMADEGESTION_H
#define LABORATORIO09_STL_SISTEMADEGESTION_H
#include <list>
#include <map>

#include "Categoria.h"
#include "Comentario.h"
#include "Etiqueta.h"
#include "Streamer.h"


class SistemaDeGestion
{
public:
    void cargarCategorias(const char*nombArch);
    void cargarEtiquetas(const char* nombArch);
    void cargaStreamers(const char* nombArch);
    void cargaComentarios(const char* nombArch);
    void completarCategoriaPorStreamer();
    void completarStreamers();
    void completarEtiquetasPorStreamer();
    void buscarEtiqueta(string cadStr, list<Streamer>::iterator& it);
    void completarComentariosPorStreamer();
    void reporteDeStreamers(const char* nombArch);
    void elaborarLinea(ofstream& arch, int max, char c);
    void eliminaStreamers(string idioma);

private:
    list<Categoria> categorias;
    list<Comentario> comentarios;
    map<string,Etiqueta> etiquetas;
    list<Streamer>streamers;
};


#endif //LABORATORIO09_STL_SISTEMADEGESTION_H