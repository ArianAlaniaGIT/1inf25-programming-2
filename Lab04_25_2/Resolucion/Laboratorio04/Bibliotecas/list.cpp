#include <iostream>
#include "list.h"

#include <cstring>
#include <fstream>


using namespace std;

void new_list(list &lista) {
    // Creacion de la lista
    lista.size = 0;
    lista.back = nullptr;
    lista.front = nullptr;
}

void push_front(list &lista, void *dato, void *(*clone)(void*)) {
    // El nodo se inserta al inicio de la lista
    void *dato_clone = clone(dato);

    void **nodo = new void*[2]{};
    nodo[0] = dato_clone;
    nodo[1] = nullptr;

    if (lista.front == nullptr) { // Si la lista está vacia, el front y el back deben apuntar al primer nodo
        lista.front = nodo;
        lista.back = nodo;
    } else { // Si la lista no está vacía, se añade el nodo al inicio
        void **nodoInicial = (void**)lista.front;
        nodo[1] = nodoInicial;
        lista.front = nodo;
    }

    lista.size++; // Se incrementa la cantidad de elementos
}

void push_back(list &lista, void *dato, void *(*clone)(void*)) {
    // El nodo se inserta al final de la lista
    void *dato_clone = clone(dato);

    void **nodo = new void*[2]{};
    nodo[0] = dato_clone;
    nodo[1] = nullptr;

    if (lista.front == nullptr) { // Si la lista está vacia, el front y el back deben apuntar al primer nodo
        lista.front = nodo;
        lista.back = nodo;
    } else { // Si la lista no está vacía, se añade el nodo al final
        void **ultimoNodo = (void**)lista.back;
        lista.back = nodo;
        ultimoNodo[1] = nodo;
    }

    lista.size++; // Se incrementa la cantidad de elementos
}

void *begin(list &lista) {
    // Devuelve el nodo inicial de la lista
    return lista.front;
}

void *end() {
    // Devuelve el final de la lista
    return nullptr;
}

void *next(void *it) {
    // Devuelve el siguiente nodo de la lista
    void **siguiente = (void**)it;
    siguiente = (void**)siguiente[1];
    return siguiente;
}

void *getValue(void *it) {
    // Devuelve el elemento contenido en el nodo
    void **valor = (void**)it;
    return valor[0];
}

void foreach(list &lista, void(*print)(void*)) {
    // Se recorre todos los elementos de la lista, del principio hasta el final
    for (void *i = begin(lista); i != end(); i = next(i)) {
        print(getValue(i));
        if (next(i) != nullptr) cout << ", ";
    }
}

bool findIf(list &lista, bool(*compare)(void*, void*), void*dato) {
    // Busqueda de elementos
    for (void *i = begin(lista); i != end(); i = next(i)) {
        void *datoNodos = getValue(i);
        if (compare(datoNodos, dato)) return true; // Si encontró el elemento se devuelve true

    }
    return false; // Si no encontro nada, se devuelve false
}


/* 
void *leerDatos(ifstream &arch) { // Adicional por archivo csv
    int *cod = new int;
    char *nombre, cadena[150];
    double *sueldo = new double;

    arch>>*cod;
    if (arch.eof())return nullptr;
    arch.get();
    arch.getline(cadena,150,',');
    nombre = new char[strlen(cadena)+1];
    strcpy(nombre,cadena);
    arch>>*sueldo;
    arch.get();

    void **reg = new void*[3]{};

    reg[0] = cod;
    reg[1] = nombre;
    reg[2] = sueldo;

    return reg;
}

*/