//
// Created by arian on 10/01/2026.
//

#include "Comentario.h"

Comentario::Comentario() {
    inicializa();
}

void Comentario::inicializa() {
    canal = "";
    comentario = "";
}

Comentario::Comentario(const Comentario& orig) {
    inicializa();
    *this = orig;
}

void Comentario::operator=(const Comentario& orig)
{
    canal = orig.canal;
    comentario = orig.comentario;
}

Comentario::~Comentario() {
    // No hace falta
}

string Comentario::get_canal() const
{
    return canal;
}

void Comentario::set_canal(const string& canal)
{
    this->canal = canal;
}

string Comentario::get_comentario() const
{
    return comentario;
}

void Comentario::set_comentario(const string& comentario)
{
    this->comentario = comentario;
}

void operator>>(ifstream &arch, Comentario &comentario) {
    char cadena[200];
    arch.getline(cadena,200,',');
    if (arch.eof())return;
    string guardado;
    guardado = cadena;
    comentario.set_canal(guardado);
    arch.getline(cadena,200,'\n');
    guardado =cadena;
    comentario.set_comentario(guardado);
}

bool Comentario::operator<(const Comentario &com) const {
    string cod1 = get_canal();
    string cod2 = com.get_canal();
    return cod1 < cod2;
}

void operator<<(ofstream &arch, Comentario &comentario) {
    arch<<comentario.get_comentario()<<endl;
}