//
// Created by arian on 7/10/2026.
//

#ifndef LAB09_STL_INFRACCION_H
#define LAB09_STL_INFRACCION_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Infraccion {
public:
    Infraccion();
    void inicializa();
    Infraccion(const Infraccion &orig);
    void operator=(const Infraccion &orig);

    string get_codigo() const;

    void set_codigo(const string &codigo);

    double get_multa() const;

    void set_multa(double multa);

    string get_gravedad() const;

    void set_gravedad(const string &gravedad);

    string get_descripcion() const;

    void set_descripcion(const string &descripcion);

    virtual ~Infraccion();
private:
    string codigo;
    double multa;
    string gravedad;
    string descripcion;
};

void operator>>(ifstream &arch, Infraccion &infraccion);

#endif //LAB09_STL_INFRACCION_H
