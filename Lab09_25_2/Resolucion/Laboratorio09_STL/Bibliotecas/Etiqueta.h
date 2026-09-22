//
// Created by arian on 8/01/2026.
//

#ifndef LABORATORIO09_STL_ETIQUETA_H
#define LABORATORIO09_STL_ETIQUETA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Etiqueta {
public:
    void inicializa();
    Etiqueta();
    Etiqueta(const Etiqueta &orig);
    void operator=(const Etiqueta& orig);
    virtual ~Etiqueta();
    string get_codigo() const;
    void set_codigo(const string& codigo);
    string get_nombre() const;
    void set_nombre(const string& nombre);

private:
    string codigo;
    string nombre;
};

void operator>>(ifstream &arch, Etiqueta &etiqueta);
void operator<<(ofstream &arch, Etiqueta &etiqueta);


#endif //LABORATORIO09_STL_ETIQUETA_H