//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_VACUNA_H
#define HERENCIASYMASCOTAS_VACUNA_H
#include "Cita.h"


class Vacuna: public Cita {
public:
    Vacuna();

    void inicializa();

    Vacuna(const Vacuna &orig);

    void operator=(const Vacuna &orig);

    virtual ~Vacuna();

    int get_dosis() const;

    void set_dosis(int dosis);

    int get_meses() const;

    void set_meses(int meses);


    void leer(ifstream &arch);
    void imprime(ofstream &arch);

private:
    int dosis;
    int meses;
};


#endif //HERENCIASYMASCOTAS_VACUNA_H
