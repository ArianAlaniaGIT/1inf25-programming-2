//
// Created by arian on 9/11/2026.
//

#ifndef HERENCIAMAYORISTA_EMPRESA_H
#define HERENCIAMAYORISTA_EMPRESA_H
#include "Producto.h"
#include "VentaTienda.h"
#include "VentaWeb.h"


class Empresa {
public:
    Empresa();
    ~Empresa();

    void cargarProductos(const char*nombArch);

    char *leerCadenaExacta(ifstream &arch, int max, char delim);

    void cargarVentas(const char *nombArch);

    void cargarWeb(ifstream &arch, int &capWeb);

    void cargarTienda(ifstream &arch, int &capTienda);

    void incrementarEspaciosTienda(int &mind, int &cap, VentaTienda *&arr);

    void incrementarEspaciosWeb(int &mind, int &cap, VentaWeb *&arr);

    void cargaDetalles(const char *nombArch);

    void complementarWeb(Producto &producto, int &cap, int numUnit, int indVent);

    void complementarTienda(Producto &producto, int &cap, int numUnit, int indVent);

    int buscarProd(char *cadena);

    void buscarVenta(char *codVenta, char &tipo, int &indVent);

    void calculaTotales();

    void reporteDeVentas(const char *nombArch);

    void elaborarLinea(ofstream &arch, int max, char c);

private:
    Producto *productos;
    int numProd;
    VentaWeb *ventasPorWeb;
    int numVentWeb;
    VentaTienda *ventasPorTienda;
    int numVentTienda;
};


#endif //HERENCIAMAYORISTA_EMPRESA_H
