//
// Created by alulab14 on 21/11/2025.
//

#ifndef STREAMERSPOLIMORFISMOYLISTAS_METRICA_H
#define STREAMERSPOLIMORFISMOYLISTAS_METRICA_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
#include <cstring>

class Metrica {
public:
    Metrica();

    void inicializa();

    Metrica(const Metrica &orig);

    void operator=(const Metrica &orig);

    int get_id() const;

    void set_id(int id);

    void get_descripcion(char *script) const;

    void set_descripcion(char *descripcion);

    int get_fecha_calculo() const;

    void set_fecha_calculo(int fecha_calculo);

    int get_fecha_expiracion() const;

    void set_fecha_expiracion(int fecha_expiracion);

    bool is_estado() const;

    void set_estado(bool estado);

    virtual void leer(ifstream &arch);

    int leerFecha(ifstream &arch);

    virtual void imprimir(ofstream &arch);
    virtual char getTipo();
    virtual ~Metrica();

private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
};


#endif //STREAMERSPOLIMORFISMOYLISTAS_METRICA_H