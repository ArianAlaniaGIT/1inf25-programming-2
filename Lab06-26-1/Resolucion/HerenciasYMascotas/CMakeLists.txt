cmake_minimum_required(VERSION 4.3)
project(HerenciasYMascotas)

set(CMAKE_CXX_STANDARD 20)

add_executable(HerenciasYMascotas main.cpp
        Bibliotecas/Mascota.cpp
        Bibliotecas/Mascota.h
        Bibliotecas/Cita.cpp
        Bibliotecas/Cita.h
        Bibliotecas/Control.cpp
        Bibliotecas/Control.h
        Bibliotecas/Operacion.cpp
        Bibliotecas/Operacion.h
        Bibliotecas/Vacuna.cpp
        Bibliotecas/Vacuna.h
        Bibliotecas/Veterinaria.cpp
        Bibliotecas/Veterinaria.h)
