//
// Created by arian on 8/11/2026.
//

#ifndef HERENCIAMAYORISTA_VENTATIENDA_H
#define HERENCIAMAYORISTA_VENTATIENDA_H
#include "Venta.h"


class VentaTienda: public Venta {
public:
    VentaTienda();
    VentaTienda(const VentaTienda &orig);

    void operator=(const VentaTienda &orig);

    void inicializa();

    bool is_empaque() const;

    bool is_tarjeta() const;

    void set_empaque(bool empaque);

    void set_tarjeta(bool tarjeta);

    void set_cuotas(int cuotas);

    int get_cuotas() const;

    virtual ~VentaTienda();

    void elimina();

    void leer(ifstream &arch);

    char get_tipo();

    void llenadoDetalles(Producto &prod, int &cap, int numUnit);

    void hallarSuTotal();

    void imprimir(ofstream &arch);

private:
    bool empaque;
    bool tarjeta;
    int cuotas;
};


#endif //HERENCIAMAYORISTA_VENTATIENDA_H
