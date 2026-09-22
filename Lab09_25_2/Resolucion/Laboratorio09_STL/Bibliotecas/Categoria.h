//
// Created by arian on 8/01/2026.
//

#ifndef LABORATORIO09_STL_CATEGORIA_H
#define LABORATORIO09_STL_CATEGORIA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class Categoria {
public:
    Categoria();
    void inicializa();
    Categoria(const Categoria &orig);
    void operator=(const Categoria& orig);
    virtual ~Categoria();

    string get_codigo() const;
    void set_codigo(const string& codigo);
    string get_nombre() const;
    void set_nombre(const string& nombre);
    string get_descripcion() const;
    void set_descripcion(const string& descripcion);
    bool operator<(Categoria& cat2) const;

private:
    string codigo;
    string nombre;
    string descripcion;
};

void operator>>(ifstream &arch, Categoria &categoria);
void operator<<(ofstream &arch, Categoria &categoria);

#endif //LABORATORIO09_STL_CATEGORIA_H