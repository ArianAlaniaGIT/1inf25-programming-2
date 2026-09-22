#ifndef CODIGO_DEV_CATEGORIA_H
#define CODIGO_DEV_CATEGORIA_H
#include <iostream>

using namespace std;

class Categoria {
private:
    char codigo[7];
    char *nombre;
    char *descripcion;
public:
    Categoria();

    Categoria(const Categoria &orig);

    void operator=(const Categoria &orig);

    virtual ~Categoria();

    void elimina();

    void set_codigo(const char *cod);

    void get_codigo(char *cod) const;

    void inicializa();

    char *get_nombre() const;

    void set_nombre(char *nomb);

    char *get_descripcion(char *script) const;

    void set_descripcion(char *script);

    friend ostream & operator<<(ostream &out, Categoria &categoria);
};

bool operator >>(istream &in, Categoria & categoria);

#endif //CODIGO_DEV_CATEGORIA_H
