//
// Created by arian on 2/09/2026.
//

#include "Central.h"

#include <cstring>

#include "DroneEstacionamiento.h"
#include "DroneSemaforo.h"
#include "DroneVelocidad.h"

void Central::carga(const char *nombArch) {
    ifstream arch(nombArch,ios::in);
    if (not arch.is_open()) {
        cout<<"Hubo un problema al leer los drones."<<endl;
        exit(1);
    }

    char tipo[100];
    class Drone *drone;
    while (true) {
        arch.getline(tipo,100,',');
        if (arch.eof())break;
        if (asignarMemoria(drone,tipo)) {
            drone->leer(arch);
            crearArbol(drone);
        } else {
            while (arch.get() != '\n');
        }
    }
}

void Central::crearArbol(Drone *drone) {
    ABBDrones.sumarDrone(drone);
}

bool Central::asignarMemoria(Drone *&drone, char *tipo) {
    if (strcmp(tipo,"Velocidad")==0) {
        drone = new DroneVelocidad;
        return true;
    } else if (strcmp(tipo,"Estacionamiento")==0) {
        drone = new DroneEstacionamiento;
        return true;
    } else if (strcmp(tipo,"Semaforo")==0) {
        drone = new DroneSemaforo;
        return true;
    }
    return false;
}

void Central::muestra(const char *nombArch) {
    ofstream arch(nombArch,ios::out);
    if (not arch.is_open()) {
        cout<<"ERROR: Hubo un problema al generar el reporte."<<endl;
        exit(1);
    }
    elaborarLinea(arch,60,'=');
    arch<<setw(38)<<"REPORTE DE DRONES"<<endl;
    elaborarLinea(arch,60,'=');
    arch<<"Codigo"<<setw(15)<<"Ubicacion"<<setw(15)<<"Capacidad"<<setw(24)<<"Velocidad/Zona/Luz"<<endl;
    elaborarLinea(arch,60,'=');
    ABBDrones.mostrar(arch);
}

void Central::elaborarLinea(ofstream &arch, int max, char c) {
    for (int i = 0; i < max; i++) {
        arch<<c;
    }
    arch<<endl;
}

void Central::actualiza() {
    int contVelocidad = 0, contSemaforo = 0, contEstacionamiento = 0;

    ABBDrones.contar(contVelocidad,contEstacionamiento,contSemaforo);

    int mitadVel = contVelocidad / 2;
    int mitadSem = contSemaforo / 2;
    int mitadEst = contEstacionamiento / 2;

    ABBDrones.actualizar(mitadVel,mitadEst,mitadSem);

}


