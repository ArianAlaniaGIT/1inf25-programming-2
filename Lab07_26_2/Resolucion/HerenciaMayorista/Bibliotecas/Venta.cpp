//
// Created by arian on 8/11/2026.
//

#include "Venta.h"

#include "Producto.h"

Venta::Venta() {
    inicializa();
}

Venta::Venta(const Venta &orig) {
    inicializa();
    *this = orig;
}

void Venta::operator=(const Venta &orig) {
    char cadena[100];
    orig.get_codigo(cadena);
    set_codigo(cadena);
    orig.get_fecha(cadena);
    set_fecha(cadena);
}

void Venta::inicializa() {
    codigo = nullptr;
    fecha = nullptr;
    detalles = nullptr;
    numDetalles = 0;
    totalVendido = 0;
}


Venta::~Venta() {
    elimina();
}

void Venta::elimina() {
    if (codigo != nullptr) delete codigo;
    if (fecha != nullptr) delete fecha;
    if (detalles != nullptr) delete []detalles;
}

void Venta::get_codigo(char *cod) const {
    if (codigo == nullptr) cod[0] = 0;
    else strcpy(cod, codigo);
}

void Venta::set_codigo(char *cod) {
    if (codigo != nullptr) delete codigo;
    codigo = new char[strlen(cod) + 1]{};
    strcpy(codigo, cod);
}

void Venta::get_fecha(char *date) const {
    if (fecha == nullptr) date[0] = 0;
    else strcpy(date, fecha);
}

void Venta::set_fecha(char *date) {
    if (fecha != nullptr) delete fecha;
    fecha = new char[strlen(date) + 1]{};
    strcpy(fecha, date);
}


int Venta::get_num_detalles() const {
    return numDetalles;
}

void Venta::set_num_detalles(int num_detalles) {
    numDetalles = num_detalles;
}

double Venta::get_total_vendido() const {
    return totalVendido;
}

void Venta::set_total_vendido(double total_vendido) {
    totalVendido = total_vendido;
}

void Venta::leer(ifstream &arch) {
    char cadena[100];
    arch.getline(cadena,100,',');
    set_codigo(cadena);
    arch.getline(cadena,100,',');
    set_fecha(cadena);
}

void Venta::incrementarEspacios(int &mind, int &cap, DetalleVenta *&arr) {
    cap +=5;
    DetalleVenta *aux;
    if (arr == nullptr) {
        arr = new DetalleVenta[cap]{};
        mind = 1;
    } else {
        aux = new DetalleVenta[cap]{};
        for (int i = 0; i < mind;i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}


int Venta::buscarProdEnDet(Producto &prod) {
    if (detalles == nullptr) return -1;
    for (int i = 0; i < numDetalles;i++) {
        char cod[100];
        detalles[i].get_codigo(cod);
        char cod2[100];
        prod.get_codigo(cod2);
        if (strcmp(cod,cod2)==0) return i;
    }

    return -1;
}

void Venta::llenadoDetalles(Producto &prod, int &cap, int numUnit) {
    if (cap == numDetalles) incrementarEspacios(numDetalles, cap, detalles);

    int indProdDet = buscarProdEnDet(prod);

    if (indProdDet == -1) {
        DetalleVenta nuevo{};
        char cod[100];
        prod.get_codigo(cod);
        nuevo.set_codigo(cod);
        nuevo.set_unidades(numUnit);
        nuevo.set_precio_unit(prod.get_precio_unit());
        prod.get_descripcion(cod);
        nuevo.set_descripcion(cod);
        nuevo.set_total(numUnit*prod.get_precio_unit());

        detalles[numDetalles-1] = nuevo;
        numDetalles++;
    } else {
        int numU = detalles[indProdDet].get_unidades();
        numU += numUnit;
        double totalASumar = prod.get_precio_unit() * numUnit;
        double totalActual = detalles[indProdDet].get_total();
        totalActual += totalASumar;

        detalles[indProdDet].set_total(totalActual);
        detalles[indProdDet].set_unidades(numU);
    }

}

void Venta::imprimir(ofstream &arch) {
    char cod[100];
    get_codigo(cod);

    arch<<"CODIGO DE LA VENTA: "<<cod<<setw(4)<<" "<<"FECHA DE VENTA: "<<fecha<<endl;
}

void Venta::imprimirDetalles(ofstream &arch) {
    double montoTotal = 0;
    for (int i = 0; i < 100; i++) arch<<'-';
    arch<<endl;
    arch<<"PRODUCTOS COMPRADOS: "<<endl;
    arch<<"CODIGO"<<setw(15)<<"DESCRIPCION"<<setw(42)<<"CANTIDAD"<<setw(16)<<"PRECIO UNIT."<<setw(11)<<"SUBTOTAL"<<endl;
    for (int i = 0; i < 100; i++) arch<<'-';
    arch<<endl;
    for (int i = 0; i < numDetalles;i++) {
        char cod[100];
        detalles[i].get_codigo(cod);

        if (cod[0] != 0) {
            detalles[i].imprimir(arch);
            montoTotal += detalles[i].get_total();
        }

    }
    arch<<endl<<"MONTO TOTAL CON RECARGOS: "<<montoTotal<<endl;
}