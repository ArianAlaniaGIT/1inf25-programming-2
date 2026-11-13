//
// Created by arian on 8/11/2026.
//

#ifndef HERENCIAMAYORISTA_DETALLEVENTA_H
#define HERENCIAMAYORISTA_DETALLEVENTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class DetalleVenta {
public:
    DetalleVenta();

    void inicializa();

    DetalleVenta(const DetalleVenta &orig);

    void operator=(const DetalleVenta &orig);

    virtual ~DetalleVenta();

    void get_codigo(char *cod) const;

    void set_codigo(char *codigo);

    int get_unidades() const;

    void set_unidades(int unidades);

    void get_descripcion(char *script) const;

    void set_descripcion(char *descripcion);

    double get_precio_unit() const;

    void set_precio_unit(double precio_unit);

    double get_total() const;

    void set_total(double total);

    void imprimir(ofstream &arch);

private:
    char* codigo;
    int unidades;
    char *descripcion;
    double precioUnit;
    double total;
};


#endif //HERENCIAMAYORISTA_DETALLEVENTA_H
