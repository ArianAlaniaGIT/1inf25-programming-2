//
// Created by arian on 16/09/2026.
//

#ifndef SOBRECARGASYMASCOTAS_MASCOTA_H
#define SOBRECARGASYMASCOTAS_MASCOTA_H
#include "VacunaAplicada.h"


class Mascota {
public:
    Mascota();
    void inicializa();
    Mascota(const Mascota &orig);
    void operator=(const Mascota &orig);
    virtual ~Mascota();

    int get_dni() const;

    void set_dni(int dni);

    void get_nombre(char *nomb) const;

    void set_nombre(char *nomb);

    void get_especie(char *esp) const;

    void set_especie(char *especie);

    int get_edad() const;

    void set_edad(int edad);

    double get_peso() const;

    void set_peso(double peso);

    void get_colegiatura(char *college) const;

    void set_colegiatura(char *colegiatura);

    int get_num_vacunas() const;

    void set_num_vacunas(int num_vacunas);

    void obtenerVacunas(VacunaAplicada *&arreglo);

    void operator+=(VacunaAplicada &vacuna);

    bool operator~();

private:
    int dni;
    char *nombre;
    char *especie;
    int edad;
    double peso;
    char *colegiatura;
    VacunaAplicada listaVacunas[20];
    int numVacunas;
};

void operator>>(ifstream &arch, Mascota &mascota);
void operator<<(ofstream &arch, Mascota &mascota);


#endif //SOBRECARGASYMASCOTAS_MASCOTA_H
