//
// Created by arian on 7/10/2026.
//

#include "MinisterioDeTransporte.h"

void MinisterioDeTransporte::cargaDeInfracciones(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al cargar las infracciones."<<endl;
        exit(1);
    }


    while (true) {
        Infraccion infraccion;
        arch>>infraccion;
        if (arch.eof())break;
        tablaInfracciones.push_back(infraccion);
    }
}

void MinisterioDeTransporte::cargaEmpresas(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al cargar las empresas."<<endl;
        exit(1);
    }

    Empresa empresa;
    while (true) {
        arch>>empresa;
        if (arch.eof())break;
        listaEmpresas.push_back(empresa);
    }
}

void MinisterioDeTransporte::cargaVehiculos(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar los vehiculos."<<endl;
        exit(1);
    }

    int dni;
    while (true) {
        arch>>dni;
        if (arch.eof()) break;
        list<Empresa>::iterator posEmpresa = buscarEmpresa(dni);
        if (posEmpresa != listaEmpresas.end()) {
            posEmpresa->llenarVehiculos(arch);
        } else {
            while (arch.get() != '\n');
        }
    }
}

list<Empresa>::iterator MinisterioDeTransporte::buscarEmpresa(int dni) {
    list<Empresa>::iterator it;
    for (it = listaEmpresas.begin(); it != listaEmpresas.end(); ++it) {
        if (dni == it->get_dni()) return it;
    }
    return listaEmpresas.end();
}

void MinisterioDeTransporte::cargaInfraccionesCometidas(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al leer las infracciones."<<endl;
        exit(1);
    }

    Multa multa;
    while (true) {
        arch>>multa;
        if (arch.eof())break;
        list<Infraccion>::iterator posInfracc = buscarInfraccion(multa);
        if (posInfracc != tablaInfracciones.end()) {
            double mul = posInfracc->get_multa();
            multa.set_multa(mul);
        }
        completarMultas(multa);
    }
}

void MinisterioDeTransporte::completarMultas(Multa &multa) {
    list<Empresa>::iterator it1;
    bool placaEncontrada = false;
    for (it1 = listaEmpresas.begin(); it1 != listaEmpresas.end(); ++it1) {
        map<string,Vehiculo>::iterator it2;
        map<string,Vehiculo> vehiculos = it1->get_vehiculos();

        for (it2 = vehiculos.begin(); it2 != vehiculos.end(); ++it2) {
            if (it2->first == multa.get_placa()) {
                vector<Multa>multas = it1->get_multas();
                multas.push_back(multa);
                placaEncontrada = true;
                it1->set_multas(multas);
                break;
            }
        }
        it1->set_vehiculos(vehiculos);
        if (placaEncontrada) break;
    }
}

list<Infraccion>::iterator MinisterioDeTransporte::buscarInfraccion(Multa &multa) {
    list<Infraccion>::iterator it;
    for (it = tablaInfracciones.begin(); it != tablaInfracciones.end(); ++it) {
        if (multa.get_cod_multa() == it->get_codigo()) return it;
    }

    return tablaInfracciones.end();
}


void MinisterioDeTransporte::reporteDeEmpresasConInfracciones(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al generar el reporte solicitado."<<endl;
        exit(1);
    }


    imprimirLinea(arch,'=',120);
    arch<<setw(85)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    imprimirLinea(arch,'=',120);

    for (auto &empresa : listaEmpresas) {
        arch<<empresa;
        imprimirLinea(arch,'=',120);
    }
}

void MinisterioDeTransporte::imprimirLinea(ofstream &arch, char c, int max) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}

void MinisterioDeTransporte::eliminaInfraccionesPagadas(void) {

    for (auto &empresa : listaEmpresas) {
        empresa.eliminarInfraccionesPagadas();
    }


}