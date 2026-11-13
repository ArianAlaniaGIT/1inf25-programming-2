//
// Created by arian on 7/10/2026.
//

#include "MinisterioDeTransporte.h"

MinisterioDeTransporte::MinisterioDeTransporte() {
    infracciones = nullptr;
    empresas = nullptr;
    numInf = 0;
    numEmp = 0;
}

void MinisterioDeTransporte::operator<(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al obtener la tabla de infracciones."<<endl;
        exit(1);
    }
    int capInf = 0;
    Infraccion infraccion;
    while (true) {
        arch>>infraccion;
        if (arch.eof())break;
        if (capInf == numInf) incrementarEspaciosInf(capInf,numInf,infracciones);
        infracciones[numInf-1] = infraccion;
        numInf++;
    }
}

void MinisterioDeTransporte::incrementarEspaciosEmp(int &cap, int &numEmp, Empresa *&empresas) {
    cap+=5;
    Empresa *aux;
    if (empresas == nullptr) {
        empresas = new Empresa[cap]{};
        numEmp = 1;
    } else {
        aux = new Empresa[cap]{};
        for (int i = 0; i < numEmp; i++) {
            aux[i] = empresas[i];
        }
        delete [] empresas;
        empresas = aux;
    }
}

void MinisterioDeTransporte::operator<=(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar las empresas."<<endl;
        exit(1);
    }

    int capEmp = 0;
    Empresa empresa;
    while (true) {
        arch>>empresa;
        if (arch.eof()) break;
        if (capEmp == numEmp) incrementarEspaciosEmp(capEmp,numEmp,empresas);
        empresas[numEmp-1] = empresa;
        numEmp++;
    }
}

void MinisterioDeTransporte::incrementarEspaciosInf(int &cap, int &num, Infraccion *&infracciones) {
    cap+=5;
    Infraccion *aux;
    if (infracciones == nullptr) {
        infracciones = new Infraccion[cap]{};
        num = 1;
    } else {
        aux = new Infraccion[cap]{};
        for (int i = 0; i < num; i++) {
            aux[i] = infracciones[i];
        }
        delete [] infracciones;
        infracciones = aux;
    }
}

MinisterioDeTransporte::~MinisterioDeTransporte() {
    if (infracciones != nullptr) delete [] infracciones;
    if (empresas != nullptr) delete [] empresas;
}


void MinisterioDeTransporte::operator<<=(const char*nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al registrar las infracciones cometidas por las empresas."<<endl;
        exit(1);
    }
    Multa multa;
    while (true) {
        arch>>multa;
        if (arch.eof())break;
        int posInf = buscarInfraccion(multa);
        if (posInf != -1) {
            multa.set_multa(infracciones[posInf].get_multa());
            buscarEmpresa(multa);
        }
    }
}

void MinisterioDeTransporte::buscarEmpresa(Multa &multa) {
    int posEmp = buscarIndiceEmpresa(multa);
    if (posEmp != -1) {
        empresas[posEmp] += multa;
    }
}

int MinisterioDeTransporte::buscarIndiceEmpresa(Multa &multa) {
    for (int i = 0; i < numEmp; i++) {
        for (int j = 0; j < empresas[i].get_num_placas(); j++) {
            char placa[100], placa2[100];
            empresas[i].getPlacaI(placa,j);
            multa.get_placa(placa2);
            if (strcmp(placa,placa2)==0) return i;
        }
    }
    return -1;
}

int MinisterioDeTransporte::buscarInfraccion(Multa &multa) {
    for (int i = 0; i < numInf; i++) {
        if (infracciones[i].get_codigo() == multa.get_codigo_infraccion()) return i;
    }
    return -1;
}

void MinisterioDeTransporte::operator>>(const char*nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al generar el reporte solicitado."<<endl;
        exit(1);
    }

    arch.precision(2);
    arch<<fixed;
    arch<<setw(107)<<"MINISTERIO DE TRANSPORTE"<<endl;
    elaborarLinea(arch,190,'=');
    arch<<setw(106)<<"TABLA DE INFRACCIONES"<<endl;
    elaborarLinea(arch,190,'-');
    arch<<right<<setw(11)<<"CODIGO"<<setw(9)<<"MULTA"
    <<setw(13)<<"GRAVEDAD"<<setw(16)<<"DESCRIPCION"<<endl;
    elaborarLinea(arch,190,'-');
    for (int i = 0; i < numInf && infracciones[i].get_codigo() != 0; i++) {
        arch<<infracciones[i];
    }
    imprimirRelacion(arch);
    elaborarLinea(arch,190,'=');
}

void MinisterioDeTransporte::imprimirRelacion(ofstream &arch) {
    elaborarLinea(arch,190,'=');
    arch<<setw(119)<<"RELACION DE EMPRESAS CON INFRACCIONES DE TRANSITO"<<endl;
    elaborarLinea(arch,190,'-');
    arch<<setw(8)<<"DNI"<<setw(15)<<"NOMBRE"<<setw(60)<<"PLACAS DE SUS VEHICULOS"<<endl;
    elaborarLinea(arch,190,'-');
    for (int i = 0; i < numEmp && empresas[i].get_dni() != 0; i++) {
        arch<<empresas[i];
    }
}

void MinisterioDeTransporte::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}