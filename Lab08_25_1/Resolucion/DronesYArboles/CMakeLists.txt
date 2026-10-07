cmake_minimum_required(VERSION 4.2)
project(DronesYArboles)

set(CMAKE_CXX_STANDARD 20)

add_executable(DronesYArboles main.cpp
        Bibliotecas/Drone.cpp
        Bibliotecas/Drone.h
        Bibliotecas/DroneSemaforo.cpp
        Bibliotecas/DroneSemaforo.h
        Bibliotecas/DroneEstacionamiento.cpp
        Bibliotecas/DroneEstacionamiento.h
        Bibliotecas/DroneVelocidad.cpp
        Bibliotecas/DroneVelocidad.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Arbol.cpp
        Bibliotecas/Arbol.h
        Bibliotecas/Central.cpp
        Bibliotecas/Central.h)
