//
// Created by arian on 7/10/2026.
//

#ifndef LAB09_STL_MINISTERIODETRANSPORTE_H
#define LAB09_STL_MINISTERIODETRANSPORTE_H
#include <list>

#include "Empresa.h"
#include "Infraccion.h"


class MinisterioDeTransporte {
public:
    void cargaDeInfracciones(const char*nombArch);

    void cargaEmpresas(const char *nombArch);

    void cargaVehiculos(const char *nombArch);

    list<Empresa>::iterator buscarEmpresa(int dni);

    void cargaInfraccionesCometidas(const char *nombArch);

    void completarMultas(Multa &multa);

    list<Infraccion>::iterator buscarInfraccion(Multa &multa);

    void reporteDeEmpresasConInfracciones(const char *nombArch);

    void imprimirLinea(ofstream &arch, char c, int max);

    void eliminaInfraccionesPagadas();

private:
    list<Empresa> listaEmpresas;
    list<Infraccion> tablaInfracciones;
};



#endif //LAB09_STL_MINISTERIODETRANSPORTE_H
