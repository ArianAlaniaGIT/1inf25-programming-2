//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_MASCOTA_H
#define HERENCIASYMASCOTAS_MASCOTA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;


class Mascota {
public:
    Mascota();
    void inicializa();

    void imprime(ofstream & arch);

    Mascota(const Mascota &orig);
    void operator=(const Mascota &orig);
    virtual ~Mascota();

    int get_codigo() const;

    void set_codigo(int codigo);

    void get_nombre(char *nomb) const;

    void set_nombre(char *nomb);

    char get_tipo() const;

    void set_tipo(char tipo);

    void get_raza(char *breed) const;

    void set_raza(char *breed);

    void leer(ifstream &arch);

private:
    int codigo;
    char *nombre;
    char tipo;
    char *raza;
};


#endif //HERENCIASYMASCOTAS_MASCOTA_H
