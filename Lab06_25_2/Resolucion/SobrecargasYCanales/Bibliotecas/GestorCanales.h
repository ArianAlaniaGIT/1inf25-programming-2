#ifndef CODIGO_DEV_GESTORCANALES_H
#define CODIGO_DEV_GESTORCANALES_H
#include "Canal.h"
#include "Categoria.h"
#include "Etiqueta.h"
#define NOMBRE_CSV_CATEGORIA "Archivos/categorias.csv"
#define NOMBRE_CSV_ETIQUETA "Archivos/etiquetas.csv"
#define NOMBRE_CSV_CANAL "Archivos/canales.csv"
#define MAX_CATEGORIAS 100
#define MAX_ETIQUETAS 100
#define MAX_CANALES 1000

class GestorCanales {

private:
    int cantidad_etiquetas;
    int cantidad_canales;
    int cantidad_categorias;
    Categoria vector_categorias[MAX_CATEGORIAS];
    Etiqueta vector_etiquetas[MAX_ETIQUETAS];
    Canal vector_canales[MAX_CANALES];
public:
    GestorCanales();

    void operator!();

    char *buscar_nombre_categoria(char *codigo) const;

    char *buscar_nombre_etiqueta(char *codigo) const;

    void operator*();

    int get_cantidad_categorias() const;

    void set_cantidad_categorias(int cantidad_categorias);

    int get_cantidad_etiquetas() const;

    void set_cantidad_etiquetas(int cantidad_etiquetas);

    int get_cantidad_canales() const;

    void set_cantidad_canales(int cantidad_canales);

    ostream &lista_categorias(ostream &out);

    ostream &lista_etiquetas(ostream &out);

    ostream &lista_canales(ostream & out);

    const Canal *get_vector_canales() const;

private:
    void cargar_categorias();

    void cargar_etiquetas();

    void cargar_canales();

    Canal lee_canal(istream &archivo_de_canales);
};


ostream &operator<<(ostream &out, GestorCanales &gestor);
#endif //CODIGO_DEV_GESTORCANALES_H