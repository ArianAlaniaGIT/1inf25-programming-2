//
// Created by arian on 8/11/2026.
//

#ifndef HERENCIAMAYORISTA_VENTAWEB_H
#define HERENCIAMAYORISTA_VENTAWEB_H
#include "Venta.h"


class VentaWeb: public Venta {
public:
    VentaWeb();
    VentaWeb(const VentaWeb &orig);

    void operator=(const VentaWeb &orig);

    void inicializa();
    virtual ~VentaWeb();
    void elimina();

    int get_telefono() const;

    void set_telefono(int telefono);

    void get_distrito(char *district) const;

    void set_distrito(char *distrito);

    double get_flete() const;

    void set_flete(double flete);

    bool is_entrega_rapida() const;

    void set_entrega_rapida(bool entrega_rapida);

    void leer(ifstream &arch);

    char get_tipo();

    void llenadoDetalles(Producto &prod, int &cap, int numUnit);

    void hallarSuTotal();

    void imprimir(ofstream &arch);

private:
    int telefono;
    char* distrito;
    double flete;
    bool entregaRapida;

};


#endif //HERENCIAMAYORISTA_VENTAWEB_H
