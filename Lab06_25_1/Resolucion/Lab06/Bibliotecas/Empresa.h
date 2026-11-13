//
// Created by arian on 7/10/2026.
//

#ifndef LAB06_EMPRESA_H
#define LAB06_EMPRESA_H
#include "Multa.h"


class Empresa {
public:
    Empresa();
    Empresa(const Empresa &orig);
    void operator=(const Empresa &orig);

    void setPlacaI(const char *shield, int i);

    void getPlacaI(char *shield, int i) const;



    void inicializa();

    bool verificacionDeNulidad() const;

    bool verificacionDeNulidad2() const;

    virtual ~Empresa();

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nomb) const;

    void set_nombre(char *nombre);

    int get_num_placas() const;

    void set_num_placas(int num_placas);

    int get_num_multas() const;

    void set_num_multas(int num_multas);

    void completarPlacas(char **arrPlacas, int num);

    void operator+=(Multa &infraccionCometida);

    void imprimirMultas(ofstream &arch);

private:
    int dni;
    char *nombre;
    char **placas;
    int numPlacas;
    Multa *multas;
    int numMultas;
};

void operator>>(ifstream &arch, Empresa &empresa);
void operator<<(ofstream &arch, Empresa &empresa);

#endif //LAB06_EMPRESA_H
