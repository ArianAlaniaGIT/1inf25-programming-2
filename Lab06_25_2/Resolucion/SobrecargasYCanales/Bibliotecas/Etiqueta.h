#ifndef CODIGO_DEV_ETIQUETA_H
#define CODIGO_DEV_ETIQUETA_H
#include <iostream>

using namespace std;

class Etiqueta {
private:
    char codigo[7];
    char *nombre;

public:
    char * get_nombre() const;

    void set_nombre(char *nomb);

    void set_codigo(const char *cod);

    void get_codigo(char *cod) const;

    Etiqueta();

    Etiqueta(const char *cod, char *nomb);

    Etiqueta(const Etiqueta &orig);

    void operator=(const Etiqueta &orig);

    void inicializa();

    virtual ~Etiqueta();


    friend bool operator>>(istream &archivo_de_etiquetas, Etiqueta &etiqueta);
    friend ostream & operator<<(ostream &out, Etiqueta &etiqueta);
};


#endif //CODIGO_DEV_ETIQUETA_H