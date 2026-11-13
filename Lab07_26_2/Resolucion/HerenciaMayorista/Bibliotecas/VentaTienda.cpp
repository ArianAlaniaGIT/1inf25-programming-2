//
// Created by arian on 8/11/2026.
//

#include "VentaTienda.h"

VentaTienda::VentaTienda() {
    inicializa();
}

VentaTienda::VentaTienda(const VentaTienda &orig) {
    inicializa();
    *this = orig;
}

void VentaTienda::operator=(const VentaTienda &orig) {
    Venta::operator=(orig);
    empaque = orig.empaque;
    tarjeta = orig.tarjeta;
    cuotas = orig.cuotas;
}

void VentaTienda::inicializa() {
    Venta::inicializa();
    empaque = false;
    tarjeta = false;
    cuotas = 0;
}

bool VentaTienda::is_empaque() const {
    return empaque;
}

bool VentaTienda::is_tarjeta() const {
    return tarjeta;
}

void VentaTienda::set_empaque(bool empaque) {
    this->empaque = empaque;
}

void VentaTienda::set_tarjeta(bool tarjeta) {
    this->tarjeta = tarjeta;
}

void VentaTienda::set_cuotas(int cuotas) {
    this->cuotas = cuotas;
}

int VentaTienda::get_cuotas() const {
    return cuotas;
}

VentaTienda::~VentaTienda() {
    elimina();
}

void VentaTienda::elimina() {

}

void VentaTienda::leer(ifstream &arch) {
    Venta::leer(arch);
    char c;
    arch>>c;
    arch.get();
    if (c == 'E') empaque = true;
    arch>>c;
    arch.get();
    if (c == 'T') {
        tarjeta = true;
        arch>>cuotas;
        arch.get();
    }
}

char VentaTienda::get_tipo() {
    return 'T';
}

void VentaTienda::llenadoDetalles(Producto &prod, int &cap, int numUnit) {
    Venta::llenadoDetalles(prod, cap, numUnit);
}

void VentaTienda::hallarSuTotal() {

    double totalEncontrado = get_total_vendido();

    if (tarjeta) {
        double incremento1 = totalEncontrado * 0.055;
        totalEncontrado += incremento1;
        if (cuotas > 1) {
            // 1.25% = 0.0125
            double porcenTotal = cuotas*0.0125;
            double recargo = totalEncontrado*porcenTotal;
            totalEncontrado += recargo;
        }
    }

    if (is_empaque()) totalEncontrado += 15.50;

    set_total_vendido(totalEncontrado);
}

void VentaTienda::imprimir(ofstream &arch) {
    Venta::imprimir(arch);

    arch<<"EMPAQUE: ";
    if (empaque) {
        arch<<"CON EMPAQUE";
    } else {
        arch<<"SIN EMPAQUE";
    }

    arch<<setw(20)<<"MODO DE PAGO: ";
    if (tarjeta) {
        arch<<"TARJETA"<<setw(15)<<"CUOTAS: "<<cuotas<<endl;
    } else {
        arch<<"EFECTIVO"<<endl;
    }



    Venta::imprimirDetalles(arch);
    for (int i = 0; i < 100; i++) arch<<'=';
    arch<<endl;
}