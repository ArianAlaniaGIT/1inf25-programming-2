//
// Created by arian on 7/10/2026.
//

#ifndef LAB06_MULTA_H
#define LAB06_MULTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Multa {
public:
    Multa();

    void inicializa();

    Multa(const Multa &orig);

    void operator=(const Multa &orig);

    void get_placa(char *shield) const;

    void set_placa(char *placa);

    int get_fecha_de_infraccion() const;

    void set_fecha_de_infraccion(int fecha_de_infraccion);

    int get_fecha_de_pago() const;

    void set_fecha_de_pago(int fecha_de_pago);

    int get_codigo_infraccion() const;

    void set_codigo_infraccion(int codigo_infraccion);

    double get_multa() const;

    void set_multa(double multa);

    void convertirADMA(int &dia, int &mes, int &anho, int fecha);

private:
    char *placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;
};

void operator>>(ifstream &arch, Multa &multa);
void operator<<(ofstream &arch, Multa &multa);

#endif //LAB06_MULTA_H
