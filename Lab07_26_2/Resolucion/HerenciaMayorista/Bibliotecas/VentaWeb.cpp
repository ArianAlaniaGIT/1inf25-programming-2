//
// Created by arian on 8/11/2026.
//

#include "VentaWeb.h"

#include "Producto.h"

VentaWeb::VentaWeb() {
    inicializa();
}

VentaWeb::VentaWeb(const VentaWeb &orig) {
    inicializa();
    *this = orig;
}

void VentaWeb::operator=(const VentaWeb &orig) {
    Venta::operator=(orig);
    telefono = orig.telefono;
    char cadena[100];
    orig.get_distrito(cadena);
    set_distrito(cadena);
    flete = orig.flete;
    entregaRapida = orig.entregaRapida;
}

void VentaWeb::inicializa() {
    Venta::inicializa();
    telefono = 0;
    distrito = nullptr;
    flete = 0;
    entregaRapida = false;
}

VentaWeb::~VentaWeb() {
    elimina();
}

void VentaWeb::elimina() {
    if (distrito != nullptr) delete distrito;
}

int VentaWeb::get_telefono() const {
    return telefono;
}

void VentaWeb::set_telefono(int telefono) {
    this->telefono = telefono;
}

void VentaWeb::get_distrito(char *district) const {
    if (distrito == nullptr) district[0] = 0;
    else strcpy(district, distrito);
}

void VentaWeb::set_distrito(char *district) {
    if (distrito != nullptr) delete distrito;
    distrito = new char[strlen(district)+1]{};
    strcpy(distrito, district);
}

double VentaWeb::get_flete() const {
    return flete;
}

void VentaWeb::set_flete(double flete) {
    this->flete = flete;
}

bool VentaWeb::is_entrega_rapida() const {
    return entregaRapida;
}

void VentaWeb::set_entrega_rapida(bool entrega_rapida) {
    entregaRapida = entrega_rapida;
}

void VentaWeb::leer(ifstream &arch) {
    Venta::leer(arch);
    arch>>telefono;
    arch.get();
    char cadena[100];
    arch.getline(cadena,100,',');
    set_distrito(cadena);
    arch>>flete;
    arch.get();
    arch.getline(cadena,100,'\n');
    if (strcmp(cadena,"Rapido")==0) {
        entregaRapida = true;
    } else {
        entregaRapida = false;
    }
}


char VentaWeb::get_tipo() {
    return 'W';
}

void VentaWeb::llenadoDetalles(Producto &prod, int &cap, int numUnit) {
    Venta::llenadoDetalles(prod, cap, numUnit);
}

void VentaWeb::hallarSuTotal() {
    double totalEncontrado = get_total_vendido();
    double enDecimal = flete/100;

    double aumento = totalEncontrado * enDecimal;
    totalEncontrado += aumento;

    if (entregaRapida) {
        aumento = totalEncontrado * 0.025;
        totalEncontrado += aumento;
    }

    set_total_vendido(totalEncontrado);
}

void VentaWeb::imprimir(ofstream &arch) {
    Venta::imprimir(arch);

    arch<<"TELEFONO: "<<telefono<<setw(10)<<" "<<setw(11)<<"DISTRITO: "<<distrito;
    arch<<setw(10)<<"ENVIO: ";
    if (entregaRapida) {
        arch<<"RAPIDO"<<endl;
    } else {
        arch<<"REGULAR"<<endl;
    }



    Venta::imprimirDetalles(arch);
    for (int i = 0; i < 100; i++) arch<<'=';
    arch<<endl;
}