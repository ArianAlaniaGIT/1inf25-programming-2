//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_OPERACION_H
#define HERENCIASYMASCOTAS_OPERACION_H
#include "Cita.h"


class Operacion: public Cita {
public:
    Operacion();

    void inicializa();

    Operacion(const Operacion &orig);

    void operator=(const Operacion &orig);

    virtual ~Operacion();

    bool is_anestesiageneral() const;

    void set_anestesiageneral(bool anestesiageneral);

    int get_nummedicos() const;

    void set_nummedicos(int nummedicos);

    double get_total() const;

    void set_total(double total);
    void leer(ifstream &arch);
    void imprime(ofstream &arch);

private:
    bool anestesiageneral;
    int nummedicos;
    double total;
};


#endif //HERENCIASYMASCOTAS_OPERACION_H
