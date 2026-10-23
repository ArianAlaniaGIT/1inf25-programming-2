//
// Created by arian on 7/10/2026.
//

#ifndef LAB09_STL_MULTA_H
#define LAB09_STL_MULTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Vehiculo.h"
using namespace std;

class Multa {
public:
    Multa();

    void inicializa();

    Multa(const Multa &orig);

    void operator=(const Multa &orig);

    virtual ~Multa();

    int get_fecha() const;

    void set_fecha(int fecha);

    string get_placa() const;

    void set_placa(const string &placa);

    string get_cod_multa() const;

    void set_cod_multa(const string &cod_multa);

    double get_multa() const;

    void set_multa(double multa);

    bool is_pagada() const;

    void set_pagada(bool pagada);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);

private:
    int fecha;
    string placa;
    string codMulta;
    double multa;
    bool pagada;
    int fechaDePago;
};

void operator>>(ifstream &arch, Multa &multa);
void operator<<(ofstream &arch, Multa &multa);


#endif //LAB09_STL_MULTA_H
