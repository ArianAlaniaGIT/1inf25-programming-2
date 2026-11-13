//
// Created by arian on 7/10/2026.
//

#ifndef LAB06_MINISTERIODETRANSPORTE_H
#define LAB06_MINISTERIODETRANSPORTE_H
#include "Empresa.h"
#include "Infraccion.h"


class MinisterioDeTransporte {
public:
    MinisterioDeTransporte();

    void operator<(const char *nombArch);

    void incrementarEspaciosEmp(int &cap, int &numEmp, Empresa *&empresas);

    void operator<=(const char *nombArch);

    void incrementarEspaciosInf(int &cap, int &num, Infraccion *&infracciones);

    virtual ~MinisterioDeTransporte();

    void operator<<=(const char *nombArch);

    void buscarEmpresa(Multa &multa);

    int buscarIndiceEmpresa(Multa &multa);

    int buscarInfraccion(Multa &multa);

    void operator>>(const char *nombArch);

    void imprimirRelacion(ofstream &arch);

    void elaborarLinea(ofstream &arch, int max, char c);

private:
    Infraccion *infracciones;
    Empresa *empresas;
    int numInf;
    int numEmp;
};


#endif //LAB06_MINISTERIODETRANSPORTE_H
