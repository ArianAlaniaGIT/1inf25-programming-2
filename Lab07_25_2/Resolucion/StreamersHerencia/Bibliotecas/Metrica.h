//
// Created by arian on 13/01/2026.
//

#ifndef STREAMERSHERENCIA_METRICA_H
#define STREAMERSHERENCIA_METRICA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class Metrica {
public:
    Metrica();
    void inicializa();
    Metrica(const Metrica &orig);
    void operator=(const Metrica& orig);
    virtual ~Metrica();

    int get_id() const;
    void get_descripcion(char* script) const;
    int get_fecha_calculo() const;
    int get_fecha_expiracion() const;
    bool is_estado() const;

    void set_id(int id);
    void set_descripcion(char* script);
    void set_fecha_calculo(int fecha_calculo);
    void set_fecha_expiracion(int fecha_expiracion);
    void set_estado(bool estado);
    void elimina();
    void leer(ifstream& arch);
    void imprimir(ofstream& arch);

private:
    int id;
    char *descripcion;
    int fecha_calculo;
    int fecha_expiracion;
    bool estado;
};


#endif //STREAMERSHERENCIA_METRICA_H