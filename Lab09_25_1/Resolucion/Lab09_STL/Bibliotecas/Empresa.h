//
// Created by arian on 7/10/2026.
//

#ifndef LAB09_STL_EMPRESA_H
#define LAB09_STL_EMPRESA_H
#include <map>
#include <vector>
#include "Multa.h"
#include "Vehiculo.h"


class Empresa {
public:
    Empresa();
    ~Empresa();

    int get_dni() const;

    void set_dni(int dni);

    string get_nombre() const;

    void set_nombre(const string &nombre);

    string get_distrito() const;

    void set_distrito(const string &distrito);

    map<string, Vehiculo> get_vehiculos() const;

    void set_vehiculos(const map<string, Vehiculo> &vehiculos);

    vector<Multa> get_multas() const;

    void set_multas(const vector<Multa> &multas);

    void llenarVehiculos(ifstream &arch);

    void eliminarInfraccionesPagadas();

private:
    int dni;
    string nombre;
    string distrito;
    map<string,Vehiculo> vehiculos;
    vector<Multa>multas;
};

void operator >>(ifstream &arch, Empresa &empresa);
void operator <<(ofstream &arch, Empresa &empresa);


#endif //LAB09_STL_EMPRESA_H
