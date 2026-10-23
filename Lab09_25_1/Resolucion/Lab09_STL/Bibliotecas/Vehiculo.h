//
// Created by arian on 7/10/2026.
//

#ifndef LAB09_STL_VEHICULO_H
#define LAB09_STL_VEHICULO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Vehiculo {
public:
    Vehiculo();

    void inicializa();
    Vehiculo(const Vehiculo &orig);
    void operator=(const Vehiculo &orig);
    virtual ~Vehiculo();

    string get_placa() const;

    void set_placa(const string &placa);

    string get_marca() const;

    void set_marca(const string &marca);

    string get_modelo() const;

    void set_modelo(const string &modelo);

private:
    string placa;
    string marca;
    string modelo;
};

void operator>>(ifstream &arch, Vehiculo &vehiculo);


#endif //LAB09_STL_VEHICULO_H
