//
// Created by arian on 30/09/2026.
//

#include "funciones.h"


void cargarPacientes(const char *nombArch, void *&pacientes) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al leer los pacientes."<<endl;
        exit(1);
    }

    int mind = 0, cap = 0;
    void **pac = nullptr;
    while(true) {
        void *miniRegistro = leerDatos(arch);
        if (arch.eof() or miniRegistro == nullptr) break;
        if (mind == cap) incrementarEspacios(mind,cap, pac);
        pac[mind-1] = miniRegistro;
        mind++;
    }
    pacientes = pac;
}

void incrementarEspacios(int &mind, int &cap, void **&arr) {
    cap += 5;
    void **aux;
    if (arr == nullptr) {
        arr = new void*[cap]{};
        mind = 1;
    } else {
        aux = new void*[cap]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete arr;
        arr = aux;
    }
}

void *leerDatos(ifstream &arch) {
    int *id = new int, *edad = new int;
    char *nombre = nullptr, *genero = new char;
    arch>>*id;
    if (arch.eof()) return nullptr;
    arch.get();
    nombre = leerCadenaExacta(arch,120,',');
    arch>>*edad;
    arch.get();
    arch>>*genero;
    arch.get();
    double *costoTotal = new double;
    *costoTotal = 0.0;
    void **miniRegistro = new void*[6]{};
    miniRegistro[0] = id;
    miniRegistro[1] = nombre;
    miniRegistro[2] = edad;
    miniRegistro[3] = genero;
    miniRegistro[4] = nullptr;
    miniRegistro[5] = costoTotal;

    return miniRegistro;
}

char *leerCadenaExacta(ifstream &arch, int max, char delim) {
    char cadena[max], *ptCadena;
    arch.getline(cadena,max,delim);
    if (arch.eof()) return nullptr;
    ptCadena = new char[strlen(cadena)+1]{};
    strcpy(ptCadena,cadena);
    return ptCadena;
}

void cargarVisitas(const char*nombArch, void *&pac) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al leer las visitas de los pacientes."<<endl;
        exit(1);
    }
    int *fecha = new int, *hora = new int, dia,mes,anho, hour, min, id, numPacientes = 0;
    double *costo = new double;
    char c;
    void **pacientes = (void**)pac;
    while (pacientes[numPacientes]) numPacientes++;
    int nd[numPacientes+1], cap[numPacientes+1];

    for (int i = 0; i < numPacientes; i++) {
        nd[i] = 0; cap[i] = 0;
    }

    while (true) {
        arch>>dia;
        if (arch.eof())break;
        arch>>c>>mes>>c>>anho>>c>>hour>>c>>min>>c>>id>>c>>*costo;
        arch.get();
        *fecha = anho*10000 + mes*100 + dia;
        *hora = hour*100 + min;
        void **miniRegistro = new void*[4]{};
        miniRegistro[0] = fecha;
        miniRegistro[1] = hora;
        miniRegistro[2] = costo;
        ubicarLosPacientes(nd,cap,miniRegistro,pacientes, id);
    }
}

void ubicarLosPacientes(int *nd, int *cap, void**miniRegistro, void **&pacientes, int id) {
    int posPaciente = buscarPaciente(id,pacientes);
    if (posPaciente != -1) {
        void **paciente = (void**)pacientes[posPaciente];
        void **arreglo = (void**)paciente[4];
        if (nd[posPaciente] == cap[posPaciente]) incrementarEspacios(nd[posPaciente],cap[posPaciente],arreglo);

        arreglo[nd[posPaciente]-1] = miniRegistro;
        nd[posPaciente] += 1;
        paciente[4] = arreglo;

        double *costoPaciente = (double*)paciente[5];
        *costoPaciente += *(double*)miniRegistro[2];
        paciente[5] = costoPaciente;
        pacientes[posPaciente] = paciente;
    }
}

int buscarPaciente(int id, void **pacientes) {
    for (int i = 0; pacientes[i] != nullptr; i++) {
        void **dato = (void**)pacientes[i];
        if (id == *(int*)dato[0]) return i;
    }
    return -1;
}

void generarReporte(const char*nombArch, void*pac) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Ocurrio un inconveniente al generar el reporte solicitado."<<endl;
        exit(1);
    }
    void **pacientes = (void**)pac;
    elaborarEncabezado(arch);
    for (int i = 0; pacientes[i] != nullptr; i++) {
        void **paciente = (void**)pacientes[i];
        arch<<left<<setw(20)<<*(int*)paciente[0]<<" "<<setw(20)<<(char*)paciente[1]<<right;
        arch<<setw(10)<<*(int*)paciente[2]<<setw(15)<<*(char*)paciente[3];
        void **visitas = (void**)paciente[4];
        int numVisitas = 0;
        while (visitas[numVisitas]) numVisitas++;
        arch<<setw(14)<<numVisitas<<setw(20)<<*(double*)paciente[5]<<endl;
    }
    elaborarLinea(arch,103,'=');
}

void elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}

void elaborarEncabezado(ofstream &arch) {
    arch.precision(2);
    arch<<fixed;
    elaborarLinea(arch,103,'=');
    arch<<right<<setw(67)<<"REPORTE DEL SISTEMA DE URGENCIAS"<<endl;
    elaborarLinea(arch,103,'=');
    elaborarLinea(arch,103,'-');
    arch<<"ID"<<setw(25)<<"Nombre"<<setw(25)<<"Edad"<<setw(17)<<"Genero"<<setw(14)<<"Visitas"<<setw(19)<<"Total (S/)"<<endl;
    elaborarLinea(arch,103,'-');
}