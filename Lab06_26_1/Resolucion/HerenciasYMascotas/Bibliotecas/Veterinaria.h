//
// Created by arian on 13/09/2026.
//

#ifndef HERENCIASYMASCOTAS_VETERINARIA_H
#define HERENCIASYMASCOTAS_VETERINARIA_H
#include "Control.h"
#include "Operacion.h"
#include "Vacuna.h"


class Veterinaria {

public:
    Veterinaria();

    void inicializa();

    virtual ~Veterinaria();

    void cargacitas();

    void llenarControl(ifstream &arch);

    void incrementarEspaciosControl(int &mind, int &cap, Control *&arr);

    void incrementarEspaciosVacuna(int &mind, int &cap, Vacuna *&arr);

    void incrementarEspaciosOperacion(int &mind, int &cap, Operacion *&arr);

    void llenarVacuna(ifstream &arch);

    void llenarOperacion(ifstream &arch);

    void muestracitas();

    void imprimeOperacion(ofstream &arch, double &totalPorOperaciones);

    void imprimeVacuna(ofstream &arch, int &totalVacunas);

    void imprimeControl(ofstream &arch, double &montoTotalControl);

    void elaborarLinea(ofstream &arch, int max, char c);

private:
    // Nota: En el laboratorio pedía dos arreglos estáticos para vacuna y operacion,
    // pero para esta ocasion, se decidió manejar los tres arreglos como dinamicos

    Control *arrControl;
    Vacuna *arrVacuna;
    Operacion *arrOperacion;
    int numdatControl;
    int capaControl;
    int numdatVacuna;
    int capaVacuna;
    int numdatOperacion;
    int capaOperacion;
};


#endif //HERENCIASYMASCOTAS_VETERINARIA_H
