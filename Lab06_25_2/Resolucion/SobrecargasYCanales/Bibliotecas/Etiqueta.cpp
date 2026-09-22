#include <iostream>
#include <cstring>
#include "Etiqueta.h"
#include "Comunes.h"

using namespace std;

char *Etiqueta::get_nombre() const {
    return mi_strdup(nombre);
}

void Etiqueta::set_nombre(char *nomb) {
    nombre = mi_strdup((char*) nomb);
}

void Etiqueta::set_codigo(const char *cod) {
    for (int i = 0; codigo[i]; i++) {
        codigo[i] = '\0';
    }
    strcpy(codigo, cod);
}

void Etiqueta::get_codigo(char *cod) const {
    if (codigo[0] == 0) cod[0] = '\0';
    else strcpy(cod, codigo);
}

Etiqueta::Etiqueta() {
    inicializa();
}

Etiqueta::Etiqueta(const char* cod, char *nomb) {
    set_nombre(nomb);
    set_codigo(cod);
}



Etiqueta::Etiqueta(const Etiqueta &orig) {
    *this = orig;
}

void Etiqueta::operator=(const Etiqueta &orig) {
    set_nombre(orig.nombre);
    set_codigo(orig.codigo);
}

void Etiqueta::inicializa() {
    nombre = nullptr;
    for (int i = 0; i < 7; i++) {
        codigo[i] = '\0';
    }
}

Etiqueta::~Etiqueta() {
    if (nombre != nullptr) delete []nombre;
}

bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta) {
    char codigo_buffer[7];
    char nombre_buffer[20];

    archivo_de_etiquetas.getline(codigo_buffer, 7, ',');
    if (archivo_de_etiquetas.eof())
        return false;
    archivo_de_etiquetas.getline(nombre_buffer, 20, '\n');

    Etiqueta etiqueta_local(codigo_buffer, nombre_buffer);
    etiqueta = etiqueta_local;
    return true;
}

ostream & operator<<(ostream &out, Etiqueta &etiqueta) {
    out << etiqueta.codigo;
    out << ": ";
    out << etiqueta.nombre;
    return out;
}