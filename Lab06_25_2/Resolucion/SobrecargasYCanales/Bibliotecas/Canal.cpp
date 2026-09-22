#include <iostream>
#include "Canal.h"
#include <cstring>

#include "Comunes.h"

using namespace std;



ostream &operator<<(ostream &out, Canal &canal) {
    out << canal.nombre;
    out << ": ";
    out << canal.seguidores;
    out << " - ";
    out << canal.categoria;
    out << "[";
    for (int i = 0; i < canal.cantidad_etiquetas; i++) {
        out << canal.vector_etiquetas[i];
        if (i > 0 and i != canal.cantidad_etiquetas - 1)
            out << ", ";
    }
    out << "]";
    return out;
}

Canal::Canal() {
    inicializa();
}

Canal::Canal(const Canal &other) {
    inicializa();
    *this = other;
}

void Canal::agregar_etiqueta(char *etiqueta) {
    vector_etiquetas[cantidad_etiquetas] = mi_strdup(etiqueta);
    cantidad_etiquetas++;
}

void Canal::operator=(const Canal &other) {

    nombre = other.get_nombre();
    categoria = other.get_categoria();
    etiquetas = other.get_etiquetas();
    cantidad_etiquetas = other.cantidad_etiquetas;
    for (int i = 0; i < cantidad_etiquetas; i++) {
        vector_etiquetas[i] = mi_strdup(other.vector_etiquetas[i]);
    }
    seguidores = other.seguidores;
}

char * Canal::get_nombre() const {
    return mi_strdup(nombre);
}

void Canal::set_nombre(char *nomb) {
    nombre = mi_strdup((char*)nomb);
}

char * Canal::get_categoria() const {
    return mi_strdup(categoria);
}

void Canal::set_categoria(char *cat) {
    categoria = mi_strdup((char*)cat);
}

char * Canal::get_etiquetas() const {
    return mi_strdup(etiquetas);
}

void Canal::set_etiquetas(char *etiq) {
    etiquetas = mi_strdup((char *)etiq);
}

int Canal::get_cantidad_etiquetas() const {
    return cantidad_etiquetas;
}

void Canal::set_cantidad_etiquetas(int cantidad_etiquetas) {
    this->cantidad_etiquetas = cantidad_etiquetas;
}

int Canal::get_seguidores() const {
    return seguidores;
}

void Canal::set_seguidores(int seguidores) {
    this->seguidores = seguidores;
}


void Canal::inicializa() {
    nombre = nullptr;
    categoria = nullptr;
    etiquetas = nullptr;
    cantidad_etiquetas = 0;
    for (int i = 0; i < MAX_VECTOR_ETIQUETAS;i++) {
        vector_etiquetas[i] = nullptr;
    }
    seguidores = -1;
}

Canal::~Canal() {
    elimina();
}

void Canal::elimina() {
    if (nombre != nullptr) delete []nombre;
    if (categoria != nullptr) delete []categoria;
    if (etiquetas != nullptr) delete []etiquetas;

    for (int i = 0; i < cantidad_etiquetas; i++) {
        liberar_cadena(vector_etiquetas[i]);
    }
    cantidad_etiquetas = 0;
}


