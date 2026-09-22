//
// Created by arian on 16/01/2026.
//

#ifndef STREAMERSHERENCIA_STREAMER_H
#define STREAMERSHERENCIA_STREAMER_H
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

class Streamer {
public:
    Streamer();
    void inicializa();
    Streamer(const Streamer& orig);
    void operator=(const Streamer& orig);
    int get_id() const;
    void set_id(int id);
    void get_cuenta(char* account) const;
    void set_cuenta(char* cuenta);
    int get_n_seguidores() const;
    void set_n_seguidores(int n_seguidores);
    void get_categoria(char* category) const;
    void set_categoria(char* categoria);
    virtual ~Streamer();
    void elimina();

    void leer(ifstream &arch);
    void imprimir(ofstream& arch);

private:
    int id;
    char*cuenta;
    int n_seguidores;
    char*categoria;

};


#endif //STREAMERSHERENCIA_STREAMER_H