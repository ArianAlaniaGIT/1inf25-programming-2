//
// Created by arian on 10/01/2026.
//

#ifndef LABORATORIO09_STL_COMENTARIO_H
#define LABORATORIO09_STL_COMENTARIO_H
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;


class Comentario {
public:
    void inicializa();
    Comentario();
    Comentario(const Comentario &orig);
    void operator=(const Comentario& orig);
    virtual ~Comentario();
    string get_canal() const;
    void set_canal(const string& canal);
    string get_comentario() const;
    void set_comentario(const string& comentario);
    bool operator<(const Comentario& com) const;

private:
    string canal;
    string comentario;
};

void operator>>(ifstream &arch, Comentario &comentario);


#endif //LABORATORIO09_STL_COMENTARIO_H