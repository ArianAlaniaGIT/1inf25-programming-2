//
// Created by arian on 16/01/2026.
//

#include "Streamer.h"

#include <cstring>

Streamer::Streamer()
{
    inicializa();
}

void Streamer::inicializa() {
    id = 0;
    categoria = nullptr;
    cuenta = nullptr;
    n_seguidores = 0;
}

Streamer::Streamer(const Streamer& orig)
{
    inicializa();
    *this = orig;
}

void Streamer::operator=(const Streamer& orig)
{
    char cadena[200]{};
    id = orig.id;
    orig.get_cuenta(cadena);
    set_cuenta(cadena);
    orig.get_categoria(cadena);
    set_categoria(cadena);
    n_seguidores = orig.n_seguidores;
}

int Streamer::get_id() const
{
    return id;
}

void Streamer::set_id(int id)
{
    this->id = id;
}

void Streamer::get_cuenta(char *account) const
{
    if (cuenta == nullptr) account[0] = 0;
    else strcpy(account, cuenta);
}

void Streamer::set_cuenta(char* account)
{
    if (cuenta != nullptr) delete cuenta;
    cuenta = new char[strlen(account)+1];
    strcpy(cuenta, account);
}

int Streamer::get_n_seguidores() const
{
    return n_seguidores;
}

void Streamer::set_n_seguidores(int n_seguidores)
{
    this->n_seguidores = n_seguidores;
}

void Streamer::get_categoria(char *category) const
{
    if (categoria == nullptr) category[0] = 0;
    else strcpy(category, categoria);
}

void Streamer::set_categoria(char* category)
{
    if (categoria != nullptr) delete categoria;
    categoria = new char[strlen(category)+1];
    strcpy(categoria, category);
}

Streamer::~Streamer()
{
    elimina();
}

void Streamer::elimina()
{
    if (categoria != nullptr) delete categoria;
    if (cuenta != nullptr) delete cuenta;
}

void Streamer::leer(ifstream& arch)
{
    char cadena[100];
    arch>>id;
    arch.get();
    arch.getline(cadena,100,',');
    set_cuenta(cadena);
    arch.getline(cadena,100,',');
    set_categoria(cadena);
    arch>>n_seguidores;
    arch.get();
}

void Streamer::imprimir(ofstream &arch)  {
    char nombre[200],cat[200];

    arch<<"[ST] CUENTA: "<<cuenta<<setw(8)<<" | SEGUIDORES: "<<setw(8)<<n_seguidores<<" | CATEGORIA: "<<categoria;
}