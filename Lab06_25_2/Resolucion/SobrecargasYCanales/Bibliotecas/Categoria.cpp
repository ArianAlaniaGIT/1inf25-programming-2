#include <iostream>
#include <cstring>
#include "Categoria.h"
#include "Comunes.h"

using namespace std;

ostream & operator<<(ostream &out, Categoria &categoria) {
    out << categoria.codigo;
    out << ": ";
    out << categoria.nombre;
    out << " - ";
    out << categoria.descripcion;
    return out;
}

Categoria::Categoria() {
    inicializa();

}

Categoria::Categoria(const Categoria &orig) {
    *this = orig;
}

void Categoria::operator=(const Categoria &orig) {
    set_codigo(orig.codigo);
    set_nombre(orig.nombre);
    set_descripcion(orig.descripcion);
}

Categoria::~Categoria() {
    elimina();
}

void Categoria::elimina() {
    if (nombre != nullptr) delete[] nombre;
    if (descripcion != nullptr) delete[] descripcion;
}

void Categoria::set_codigo(const char *cod) {
    for (int i = 0; codigo[i]; i++) {
        codigo[i] = '\0';
    }
    strcpy(codigo, cod);
}

void Categoria::get_codigo(char *cod) const {
    if (codigo[0] == 0) cod[0] = 0;
    else strcpy(cod, codigo);
}

void Categoria::inicializa() {
    nombre = nullptr;
    descripcion = nullptr;
    for (int i = 0; i < 7; i++) {
        codigo[i] = '\0';
    }
}

char *Categoria::get_nombre() const {
    return mi_strdup(nombre);
}

void Categoria::set_nombre(char *nomb) {
    liberar_cadena(nombre);
    nombre = mi_strdup((char*) nomb);
}

char *Categoria::get_descripcion(char *script) const {
    return mi_strdup(script);
}

void Categoria::set_descripcion(char *script) {
    liberar_cadena(descripcion);
    descripcion = mi_strdup((char*) script);
}

bool operator >>(istream &in, Categoria & categoria) {
    char cadena[200];
    in.getline(cadena,200,',');
    if (in.eof())return false;
    categoria.set_codigo(cadena);
    in.getline(cadena,200,',');
    categoria.set_nombre(cadena);
    in.getline(cadena,200,'\n');
    categoria.set_descripcion(cadena);
    return true;
}
