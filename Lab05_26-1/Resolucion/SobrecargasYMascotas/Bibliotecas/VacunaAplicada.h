//
// Created by arian on 16/09/2026.
//

#ifndef SOBRECARGASYMASCOTAS_VACUNAAPLICADA_H
#define SOBRECARGASYMASCOTAS_VACUNAAPLICADA_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;

class VacunaAplicada {
public:
    VacunaAplicada();

    void inicializa();

    VacunaAplicada(const VacunaAplicada &orig);

    void operator=(const VacunaAplicada &orig);

    virtual ~VacunaAplicada();

    void get_nombre(char *nomb) const;

    void set_nombre(char *nombre);

    int get_fecha() const;

    void set_fecha(int fecha);

    double get_dosis() const;

    void set_dosis(double dosis);

    void get_colegiatura(char *college) const;

    void set_colegiatura(char *colegiatura);

private:
    char *nombre;
    int fecha;
    double dosis;
    char *colegiatura;
};

void operator>>(ifstream &arch, VacunaAplicada &vacunaAplicada);
void operator<<(ofstream &arch, VacunaAplicada &vacunaAplicada);

#endif //SOBRECARGASYMASCOTAS_VACUNAAPLICADA_H
