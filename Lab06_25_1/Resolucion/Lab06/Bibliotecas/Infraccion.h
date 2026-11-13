//
// Created by arian on 7/10/2026.
//

#ifndef LAB06_INFRACCION_H
#define LAB06_INFRACCION_H
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

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_descripcion(char *script) const;

    void set_descripcion(char *descripcion);

    void get_gravedad(char *grav) const;

    void set_gravedad(char *gravedad);

    double get_multa() const;

    void set_multa(double multa);

    virtual ~Infraccion();

private:
    int codigo;
    char *descripcion;
    char *gravedad;
    double multa;
};

void operator>>(ifstream &arch, Infraccion &infraccion);
void operator<<(ofstream &arch, Infraccion &infraccion);

#endif //LAB06_INFRACCION_H
