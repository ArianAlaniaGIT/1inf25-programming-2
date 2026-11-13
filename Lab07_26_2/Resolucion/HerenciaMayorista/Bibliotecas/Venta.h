//
// Created by arian on 8/11/2026.
//

#ifndef HERENCIAMAYORISTA_VENTA_H
#define HERENCIAMAYORISTA_VENTA_H
#include "DetalleVenta.h"
#include "Producto.h"


class Venta {
public:
    Venta();

    Venta(const Venta &orig);

    void operator=(const Venta &orig);

    void inicializa();

    virtual ~Venta();

    void elimina();

    void get_codigo(char *cod) const;

    void set_codigo(char *codigo);

    void get_fecha(char *date) const;

    void set_fecha(char *fecha);


    int get_num_detalles() const;

    void set_num_detalles(int num_detalles);

    double get_total_vendido() const;

    void set_total_vendido(double total_vendido);

    void leer(ifstream &arch);

    void incrementarEspacios(int &mind, int &cap, DetalleVenta *&arr);

    int buscarProdEnDet(Producto &prod);

    void llenadoDetalles(Producto &prod, int &cap, int numUnit);

    void imprimir(ofstream &arch);

    void imprimirDetalles(ofstream &arch);

private:
    char *codigo;
    char *fecha;
    DetalleVenta *detalles;
    int numDetalles;
    double totalVendido;
};


#endif //HERENCIAMAYORISTA_VENTA_H
