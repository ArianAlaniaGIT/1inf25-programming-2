//
// Created by arian on 13/09/2026.
//

#include "Veterinaria.h"

Veterinaria::Veterinaria() {
    inicializa();
}

void Veterinaria::inicializa() {
    arrControl = nullptr;
    arrOperacion = nullptr;
    arrVacuna = nullptr;
    numdatControl = 0;
    numdatOperacion = 0;
    numdatVacuna = 0;
    capaControl = 0;
    capaOperacion = 0;
    capaVacuna = 0;
}

Veterinaria::~Veterinaria() {
    if (arrControl != nullptr) delete []arrControl;
    if (arrOperacion != nullptr) delete []arrOperacion;
    if (arrVacuna != nullptr) delete []arrVacuna;
}


void Veterinaria::cargacitas() {
    ifstream arch("Archivos/atenciones.csv",ios::in);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema para leer las atenciones."<<endl;
        exit(1);
    }
    char tipo;
    while (true) {
        arch>>tipo;
        if (arch.eof()) break;
        arch.get();
        if (tipo == 'C') {
            llenarControl(arch);
        } else if (tipo == 'O') {
            llenarOperacion(arch);
        } else if (tipo == 'V') {
            llenarVacuna(arch);
        } else {
            while (arch.get() != '\n');
        }
    }
}

void Veterinaria::llenarControl(ifstream &arch) {
    Control control;
    control.leer(arch);
    if (numdatControl == capaControl) incrementarEspaciosControl(numdatControl,capaControl,arrControl);
    arrControl[numdatControl-1] = control;
    numdatControl++;
}

void Veterinaria::incrementarEspaciosControl(int &mind, int &cap, Control *&arr) {
    cap +=5;
    Control *aux;
    if (arr == nullptr) {
        arr = new Control[cap+1]{};
        mind = 1;
    } else {
        aux = new Control[cap+1]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Veterinaria::incrementarEspaciosVacuna(int &mind, int &cap, Vacuna *&arr) {
    cap +=5;
    Vacuna *aux;
    if (arr == nullptr) {
        arr = new Vacuna[cap+1]{};
        mind = 1;
    } else {
        aux = new Vacuna[cap+1]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Veterinaria::incrementarEspaciosOperacion(int &mind, int &cap, Operacion *&arr) {
    cap +=5;
    Operacion *aux;
    if (arr == nullptr) {
        arr = new Operacion[cap+1]{};
        mind = 1;
    } else {
        aux = new Operacion[cap+1]{};
        for (int i = 0; i < mind; i++) {
            aux[i] = arr[i];
        }
        delete [] arr;
        arr = aux;
    }
}

void Veterinaria::llenarVacuna(ifstream &arch) {
    Vacuna vacuna;
    vacuna.leer(arch);
    if (numdatVacuna == capaVacuna) incrementarEspaciosVacuna(numdatVacuna,capaVacuna,arrVacuna);
    arrVacuna[numdatVacuna-1] = vacuna;
    numdatVacuna++;

}

void Veterinaria::llenarOperacion(ifstream &arch) {
    Operacion operacion;
    operacion.leer(arch);
    if (numdatOperacion == capaOperacion) incrementarEspaciosOperacion(numdatOperacion,capaOperacion,arrOperacion);
    arrOperacion[numdatOperacion-1] = operacion;
    numdatOperacion++;
}

void Veterinaria::muestracitas() {
    ofstream arch("Reportes/Reporte.txt",ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un inconveniente al generar el reporte solicitado."<<endl;
        exit(1);
    }

    double montoTotalControl = 0;
    int totalVacunas = 0;
    double totalPorOperaciones = 0;;

    // Parte Control
    imprimeControl(arch,montoTotalControl);
    arch<<endl;
    imprimeVacuna(arch,totalVacunas);
    arch<<endl;
    imprimeOperacion(arch,totalPorOperaciones);

}

void Veterinaria::imprimeOperacion(ofstream &arch, double &totalPorOperaciones) {
    arch<<"Citas de Vacunas: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(25)<<"Anestesia"<<setw(20)<<"Numero de medicos"<<endl;
    elaborarLinea(arch,100,'-');

    for (int i = 0; i < numdatOperacion && arrOperacion[i].get_fecha() != 0; i++) {
        arrOperacion[i].imprime(arch);
        totalPorOperaciones += arrOperacion[i].get_total();
    }
    arch<<endl<<"Total por operaciones: "<<totalPorOperaciones<<endl;
}

void Veterinaria::imprimeVacuna(ofstream &arch, int &totalVacunas) {
    arch<<"Citas de Vacunas: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(21)<<"Dosis"<<setw(30)<<"Meses próxima Dosis"<<endl;
    elaborarLinea(arch,100,'-');

    for (int i = 0; i < numdatVacuna && arrVacuna[i].get_fecha() != 0; i++) {
        arrVacuna[i].imprime(arch);
        totalVacunas += arrVacuna[i].get_dosis();
    }
    arch<<endl<<"Numero de vacunas: "<<totalVacunas<<endl;

}

void Veterinaria::imprimeControl(ofstream &arch, double &montoTotalControl) {

    arch<<"Citas de Control: "<<endl;
    arch<<setw(7)<<"Fecha"<<setw(11)<<"Hora"<<setw(9)<<"Raza"<<setw(22)<<"Nombre"<<setw(24)<<"Cod. Medico"<<setw(9)<<"Monto"<<endl;
    elaborarLinea(arch,100,'-');

    arch.precision(2);
    arch<<fixed;

    for (int i = 0; i < numdatControl && arrControl[i].get_fecha() != 0; i++) {
        arrControl[i].imprime(arch);
        montoTotalControl += arrControl[i].get_costo();
    }
    arch<<endl<<"Monto por Control: "<<montoTotalControl<<endl;
}

void Veterinaria::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}