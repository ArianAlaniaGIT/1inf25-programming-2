cmake_minimum_required(VERSION 4.2)
project(SobrecargasYMascotas)

set(CMAKE_CXX_STANDARD 20)

add_executable(SobrecargasYMascotas main.cpp
        Bibliotecas/Mascota.cpp
        Bibliotecas/Mascota.h
        Bibliotecas/VacunaAplicada.cpp
        Bibliotecas/VacunaAplicada.h
        Bibliotecas/Veterinaria.cpp
        Bibliotecas/Veterinaria.h)
