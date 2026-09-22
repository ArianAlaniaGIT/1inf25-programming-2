//
// Created by arian on 10/01/2026.
//

#ifndef LABORATORIO09_STL_STREAMER_H
#define LABORATORIO09_STL_STREAMER_H
#include <vector>

#include "Categoria.h"
#include "Etiqueta.h"


class Streamer {
public:
    Streamer();
    string get_canal() const;
    void set_canal(const string& canal);
    int get_fecha() const;
    void set_fecha(int fecha);
    string get_etiquetas_str() const;
    void set_etiquetas_str(const string& etiquetas_str);
    string get_idioma() const;
    void set_idioma(const string& idioma);
    virtual ~Streamer();
    void guardarCategoria(string& cat);
    string obtenerCategoria() const;
    bool operator<(const Streamer& str2);
    void llenarDatosCategoria(string nomb, string desc);
    void sumarComentario(string comen);
    void llenarEtiqueta(Etiqueta etiq);
    void imprimirCategoria(ofstream& arch);
    void imprimirEtiquetas(ofstream& arch);
    void imprimirComentarios(ofstream& arch);

private:
    string canal;
    int fecha;
    Categoria categoria;
    string etiquetasStr;
    vector<Etiqueta> etiquetasVector;
    string idioma;
    vector<string> comentarios;
};

void operator>>(ifstream &arch, Streamer &streamer);
void operator<<(ofstream &arch, Streamer &streamer);


#endif //LABORATORIO09_STL_STREAMER_H