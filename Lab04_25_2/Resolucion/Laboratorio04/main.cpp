#include <iostream>
#include <cstring>
#include <cassert>
#include "Bibliotecas/list.h"
#include "Bibliotecas/comunes.h"
#include <fstream>

using namespace std;


void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();
void test08();
void test09();
void test10();
void test11();
void test12();
// void test13(); // Adicional por archivo csv proporcionado


int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
    test06();
    test07();
    test08();
    test09();
    test10();
    test11();
    test12();
    // test13(); // Adicional por archivo csv proporcionado
    return 0;
}
/*
void test13() {// Adicional por archivo csv
    list lista;
    new_list(lista);

    ifstream arch("personal.csv",ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: No se pudo abrir el archivo del personal.csv"<<endl;
        exit(1);
    }
    bool alternaciones = false;
    while (true) {
        void *dato = leerDatos(arch);
        if (arch.eof() or dato == nullptr) break;
        if (alternaciones) { // Si alternaciones es true, al inicio
            void **reg = (void**)dato;
            push_front(lista,&reg[0], clone_int);
            alternaciones = false;
        } else { // Si alternaciones es false, al final
            void **reg = (void**)dato;
            push_front(lista,&reg[0], clone_int);
            alternaciones = true;
        }
    }
}

*/

void test12() {
    list lista;
    new_list(lista);
    char dato[100];

    strcpy(dato, "Andrés Melgar");
    push_back(lista, &dato, clone_string);
    assert(lista.size==1);
    strcpy(dato, "Miguel Guanira");
    push_back(lista, &dato, clone_string);
    assert(lista.size==2);
    strcpy(dato, "Erasmo Gómez");
     push_front(lista, &dato, clone_string);
    assert(lista.size==3);

    strcpy(dato, "Andrés Melgar");
    bool flag = findIf(lista, compare_string, dato);
    assert(flag==true);

    strcpy(dato, "Roberto Melgar");
    flag = findIf(lista, compare_string, dato);
    assert(flag==false);
}

void test11() {
    list lista;
    new_list(lista);
    double dato;

    dato=18.65;
    push_back(lista, &dato, clone_real);
    assert(lista.size==1);
    dato=15.67;
    push_back(lista, &dato, clone_real);
    assert(lista.size==2);
    dato=19.87;
    push_front(lista, &dato, clone_real);
    assert(lista.size==3);

    dato = 15.67;
    bool flag = findIf(lista, compare_real, &dato);
    assert(flag==true);

    dato = 456.67;
    flag = findIf(lista, compare_real, &dato);
    assert(flag==false);
}

void test10() {
    list lista;
    new_list(lista);
    int dato;

    dato=10;
    push_back(lista, &dato, clone_int);
    assert(lista.size==1);
    dato=20;
    push_back(lista, &dato, clone_int);
    assert(lista.size==2);
    dato=5;
    push_front(lista, &dato, clone_int);
    assert(lista.size==3);

    dato = 5;
    bool flag = findIf(lista, compare_int, &dato);
    assert(flag==true);

    dato = 67;
    flag = findIf(lista, compare_int, &dato);
    assert(flag==false);
}

void test09() {
    list lista;
    new_list(lista);
    char dato[100];

    strcpy(dato, "Andrés Melgar");
    push_back(lista, &dato, clone_string);
    assert(lista.size==1);
    strcpy(dato, "Miguel Guanira");
    push_back(lista, &dato, clone_string);
    assert(lista.size==2);
    strcpy(dato, "Erasmo Gómez");
    push_front(lista, &dato, clone_string);
    assert(lista.size==3);

    cout << "[";
    foreach(lista, print_string);
    cout << "]" <<endl;
}

void test08() {
    list lista;
    new_list(lista);
    double dato;

    dato=18.65;
    push_back(lista, &dato, clone_real);
    assert(lista.size==1);
    dato=15.67;
    push_back(lista, &dato, clone_real);
    assert(lista.size==2);
    dato=19.87;
    push_front(lista, &dato, clone_real);
    assert(lista.size==3);

    cout << "[";
    foreach(lista, print_real);
    cout << "]" <<endl;
}

void test07() {
     list lista;
     new_list(lista);
     int dato;

     dato=10;
     push_back(lista, &dato, clone_int);
     assert(lista.size==1);
     dato=20;
     push_back(lista, &dato, clone_int);
     assert(lista.size==2);
     dato=5;
     push_front(lista, &dato, clone_int);
     assert(lista.size==3);

     cout << "[";
     foreach(lista, print_int);
     cout << "]" <<endl;
}

void test06() {
     list lista;
     new_list(lista);
     char dato[100];

     strcpy(dato, "Andrés Melgar");
     push_back(lista, &dato, clone_string);
     assert(lista.size==1);
     strcpy(dato, "Miguel Guanira");
     push_back(lista, &dato, clone_string);
     assert(lista.size==2);
     strcpy(dato, "Erasmo Gómez");
     push_front(lista, &dato, clone_string);
     assert(lista.size==3);

     cout << "[";
     for (void* it = begin(lista); it != end(); it = next(it)) {
         void* valor = getValue(it);
         print_string(valor);
         if (next(it) != nullptr)
             cout << ", ";
     }
     cout << "]" <<endl;
}

void test05() {
     list lista;
     new_list(lista);
     double dato;

     dato=18.65;
     push_back(lista, &dato, clone_real);
     assert(lista.size==1);
     dato=15.67;
     push_back(lista, &dato, clone_real);
     assert(lista.size==2);
     dato=19.87;
     push_front(lista, &dato, clone_real);
     assert(lista.size==3);

     cout << "[";
     for (void* it = begin(lista); it != end(); it = next(it)) {
         void* valor = getValue(it);
         print_real(valor);
         if (next(it) != nullptr)
             cout << ", ";
     }
     cout << "]" <<endl;
}

void test04() {
    list lista;
    new_list(lista);
    int dato;

    dato=10;
    push_back(lista, &dato, clone_int);
    assert(lista.size==1);
    dato=20;
    push_back(lista, &dato, clone_int);
    assert(lista.size==2);
    dato=5;
    push_front(lista, &dato, clone_int);
    assert(lista.size==3);

    cout << "[";
    for (void* it = begin(lista); it != end(); it = next(it)) {
        void* valor = getValue(it);
        print_int(valor);
        if (next(it) != nullptr)
            cout << ", ";
    }
    cout << "]" <<endl;
}

void test03() {
    list lista;
    new_list(lista);
    char dato[100];

    strcpy(dato, "Andrés Melgar");
    push_back(lista, &dato, clone_string);
    assert(lista.size==1);
    strcpy(dato, "Miguel Guanira");
    push_back(lista, &dato, clone_string);
    assert(lista.size==2);
    strcpy(dato, "Erasmo Gómez");
    push_front(lista, &dato, clone_string);
    assert(lista.size==3);
}

void test02() {
    list lista;
     new_list(lista);
     double dato;

     dato=18.65;
     push_back(lista, &dato, clone_real);
     assert(lista.size==1);
     dato=15.67;
     push_back(lista, &dato, clone_real);
     assert(lista.size==2);
     dato=19.87;
     push_front(lista, &dato, clone_real);
     assert(lista.size==3);
}

void test01() {
    list lista;

    new_list(lista);
    int dato;

    dato=10;
    push_back(lista, &dato, clone_int);
    assert(lista.size==1);
    dato=20;
    push_back(lista, &dato, clone_int);
    assert(lista.size==2);
    dato=5;
    push_front(lista, &dato, clone_int);
    assert(lista.size==3);
}
