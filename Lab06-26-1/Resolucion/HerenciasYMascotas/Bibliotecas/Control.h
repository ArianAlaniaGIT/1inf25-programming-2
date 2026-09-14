//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_CONTROL_H
#define HERENCIASYMASCOTAS_CONTROL_H
#include "Cita.h"


class Control: public Cita {
public:
    Control();

    void inicializa();

    Control(const Control &orig);

    void operator=(const Control &orig);

    double get_costo() const;

    void set_costo(double costo);

    int get_codmed() const;

    void set_codmed(int codmed);

    virtual ~Control();

    void leer(ifstream &arch);
    void imprime(ofstream &arch);

private:
    double costo;
    int codmed;



};


#endif //HERENCIASYMASCOTAS_CONTROL_H
