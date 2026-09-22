#ifndef CODIGO_VECTOR_H
#define CODIGO_VECTOR_H

/* Nombre: Arian Alfonso Alania Novoa */
/* Curso: Programación 2 */
/* Codigo: 20221762 */

/* Laboratorio 4: Arreglos, Punteros y Listas Genéricas */

#include <fstream>
using namespace std;

typedef struct {
    int size;
    void *front;
    void *back;
} list;

void push_front(list &lista, void *dato, void *(*clone)(void*));
void new_list(list &lista);
void push_back(list &lista, void *dato, void *(*clone)(void*));
void *begin(list &lista);
void *end();
void *next(void *it);
void *getValue(void *it);
void foreach(list &lista, void(*print_int)(void*));
bool findIf(list &lista, bool(*compare)(void*, void*), void*dato);

void *leerDatos(ifstream &arch); // Adicional por archivo csv

#endif //CODIGO_VECTOR_H
