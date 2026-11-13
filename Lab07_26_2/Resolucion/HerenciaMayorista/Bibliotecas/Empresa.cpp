//
// Created by arian on 9/11/2026.
//

#include "Empresa.h"
#include <fstream>
using namespace std;

Empresa::Empresa() {
    productos = nullptr;
    numProd = 0;
    ventasPorWeb = nullptr;
    numVentWeb = 0;
    ventasPorTienda = nullptr;
    numVentTienda = 0;
}

Empresa::~Empresa() {
    if (productos != nullptr) delete []productos;
    if (ventasPorWeb != nullptr) delete []ventasPorWeb;
    if (ventasPorTienda != nullptr) delete []ventasPorTienda;
}

void Empresa::cargarProductos(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar los productos."<<endl;
        exit(1);
    }
    Producto buffProd[300]{}, prod{};
    int cant = 0;

    while (true) {
        arch>>prod;
        if (arch.eof())break;
        buffProd[cant] = prod;
        cant++;
    }

    productos = new Producto[cant + 1]{};
    for (int i = 0; i < cant; i++) {
        productos[i] = buffProd[i];
    }
    numProd = cant;
}

char *Empresa::leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max+1], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof()) return nullptr;
    ptCadena = new char[strlen(cadena)+1]{};
    strcpy(ptCadena,cadena);
    return ptCadena;
}

void Empresa::cargarVentas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar las ventas."<<endl;
        exit(1);
    }

    int capWeb = 0, capTienda = 0;
    char tipo[100];
    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof()) break;

        if (strcmp(tipo,"WEB")==0) {
            cargarWeb(arch,capWeb);
        } else if (strcmp(tipo,"TIENDA")==0) {
            cargarTienda(arch,capTienda);
        } else {
            while (arch.get()!= '\n');
        }
    }
}

void Empresa::cargarWeb(ifstream &arch, int &capWeb) {
    VentaWeb web{};
    web.leer(arch);

    if (capWeb == numVentWeb) incrementarEspaciosWeb(numVentWeb, capWeb, ventasPorWeb);
    ventasPorWeb[numVentWeb-1] = web;
    numVentWeb++;
}

void Empresa::cargarTienda(ifstream &arch, int &capTienda) {
    VentaTienda tienda;
    tienda.leer(arch);

    if (capTienda == numVentTienda) incrementarEspaciosTienda(numVentTienda,capTienda,ventasPorTienda);
    ventasPorTienda[numVentTienda-1] = tienda;
    numVentTienda++;
}


void Empresa::incrementarEspaciosTienda(int &mind, int &cap, VentaTienda *&arr) {
    cap += 5;
    VentaTienda *aux;
    if (arr == nullptr) {
        arr = new VentaTienda[cap]{};
        mind = 1;
    } else {
        aux = new VentaTienda[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Empresa::incrementarEspaciosWeb(int &mind, int &cap, VentaWeb *&arr) {
    cap += 5;
    VentaWeb *aux;
    if (arr == nullptr) {
        arr = new VentaWeb[cap]{};
        mind = 1;
    } else {
        aux = new VentaWeb[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Empresa::cargaDetalles(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar los detalles de ventas."<<endl;
        exit(1);
    }

    int capDetalles1[numVentTienda];
    int capDetalles2[numVentWeb];

    for (int i= 0; i < numVentTienda; i++) capDetalles1[i] = 0;
    for (int i= 0; i < numVentWeb; i++) capDetalles2[i] = 0;

    while (true) {
        char codVenta[100], codProd[100];
        arch.getline(codVenta,100,',');
        if (arch.eof())break;
        arch.getline(codProd,100,',');
        int numUnit = 0;
        arch>>numUnit;
        arch.get();

        char tipo;
        int indVent = -1;
        buscarVenta(codVenta,tipo,indVent);
        if (indVent != -1) {
            int indProd = buscarProd(codProd);
            if (indProd != -1) {
                if (tipo == 'W') {
                    complementarWeb(productos[indProd], capDetalles2[indVent], numUnit, indVent);
                } else if (tipo == 'T') {
                    complementarTienda(productos[indProd], capDetalles1[indVent], numUnit,indVent);
                }
            }
        }
    }
}

void Empresa::complementarWeb(Producto &producto, int &cap, int numUnit, int indVent) {
    ventasPorWeb[indVent].llenadoDetalles(producto,cap,numUnit);
}

void Empresa::complementarTienda(Producto &producto, int &cap, int numUnit, int indVent) {
    ventasPorTienda[indVent].llenadoDetalles(producto,cap,numUnit);
}

int Empresa::buscarProd(char *cadena) {
    for (int i = 0; i < numProd; i++) {
        char cod[100];
        productos[i].get_codigo(cod);
        if (strcmp(cadena,cod)==0) return i;
    }
    return -1;
}

void Empresa::buscarVenta(char *codVenta, char &tipo, int &indVent) {

    for (int i = 0; i < numVentWeb; i++) {
        char cod[100];
        ventasPorWeb[i].get_codigo(cod);
        if (strcmp(codVenta,cod)==0) {
            indVent = i;
            tipo = ventasPorWeb[i].get_tipo();
            return;
        };
    }

    for (int i = 0; i < numVentTienda; i++) {
        char cod[100];
        ventasPorTienda[i].get_codigo(cod);
        if (strcmp(codVenta,cod)==0) {
            indVent = i;
            tipo = ventasPorTienda[i].get_tipo();
            return;
        }
    }

    indVent = -1;
}

void Empresa::calculaTotales() {
    for (int i = 0; i < numVentTienda;i++) {
        ventasPorTienda[i].hallarSuTotal();
    }

    for (int i = 0; i < numVentWeb;i++) {
        ventasPorWeb[i].hallarSuTotal();
    }
}

void Empresa::reporteDeVentas(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"Hubo un problema al generar el reporte solicitado."<<endl;
        exit(1);
    }


    // Encabezado
    arch<<setw(57)<<"PackMart S.A."<<endl;
    arch<<setw(59)<<"REGISTRO DE VENTAS"<<endl;
    elaborarLinea(arch,100,'=');

    arch.precision(2);
    arch<<fixed;


    // Imprimir Productos
    arch<<"PRODUCTOS DE LA EMPRESA"<<endl;
    arch<<"CODIGO"<<setw(14)<<"DESCRIPCION"<<setw(44)<<"PRECIO UNIT."<<endl;
    elaborarLinea(arch,100,'-');
    for (int i = 0; i < numProd; i++) {
        arch<<productos[i];
    }
    elaborarLinea(arch,100,'=');
    arch<<"VENTAS REALIZADAS POR LA WEB"<<endl;
    elaborarLinea(arch,100,'=');

    // Imprimir Ventas Realizadas Por La Web

    for (int i = 0; i < numVentWeb; i++) {
        char cod[100];
        ventasPorWeb[i].get_codigo(cod);
        if (cod[0] != 0) {
            ventasPorWeb[i].imprimir(arch);
        }
    }


    arch<<"VENTAS REALIZADAS EN LA TIENDA"<<endl;
    elaborarLinea(arch,100,'=');
    for (int i = 0; i < numVentTienda; i++) {
        char cod[100];
        ventasPorTienda[i].get_codigo(cod);
        if (cod[0] != 0) {
            ventasPorTienda[i].imprimir(arch);
        }
    }





}

void Empresa::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}