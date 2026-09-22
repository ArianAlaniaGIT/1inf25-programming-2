#ifndef CODIGO_DEV_CANAL_H
#define CODIGO_DEV_CANAL_H
#include <iostream>
#define CANAL_NO_LEIDO -1
#define MAX_VECTOR_ETIQUETAS 5

using namespace std;

class Canal {
private:
    char *nombre;
    char *categoria;
    char *etiquetas;
    int cantidad_etiquetas;
    char *vector_etiquetas[MAX_VECTOR_ETIQUETAS];
    int seguidores;
public:
    Canal();

    Canal(const Canal &other);

    void agregar_etiqueta(char *etiqueta);

    void operator=(const Canal &other);

    char * get_nombre() const;

    void set_nombre(char *nombre);

    char * get_categoria() const;

    void set_categoria(char *categoria);

    char * get_etiquetas() const;

    void set_etiquetas(char *etiquetas);

    int get_cantidad_etiquetas() const;

    void set_cantidad_etiquetas(int cantidad_etiquetas);

    int get_seguidores() const;

    void set_seguidores(int seguidores);

    void inicializa();

    virtual ~Canal();

    void elimina();

    friend ostream & operator<<(ostream &out, Canal &canal);
};


#endif //CODIGO_DEV_CANAL_H
