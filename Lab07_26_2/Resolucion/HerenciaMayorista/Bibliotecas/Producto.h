//
// Created by arian on 8/11/2026.
//

#ifndef HERENCIAMAYORISTA_PRODUCTO_H
#define HERENCIAMAYORISTA_PRODUCTO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Producto {
public:
    Producto();

    void inicializa();

    Producto(const Producto &orig);

    void operator=(const Producto &orig);

    virtual ~Producto();

    void get_codigo(char *cod) const;

    void set_codigo(char *codigo);

    void get_descripcion(char *script) const;

    void set_descripcion(char *descripcion);

    double get_precio_unit() const;

    void set_precio_unit(double precio_unit);

    char *leerCadenaExacta(ifstream &arch, int max, char delim);

private:
    char *codigo;
    char *descripcion;
    double precioUnit;
};

void operator>>(ifstream &arch, Producto &prod);
void operator<<(ofstream &arch, Producto &prod);

#endif //HERENCIAMAYORISTA_PRODUCTO_H
