cmake_minimum_required(VERSION 4.3)
project(PunterosGenericos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosGenericos main.cpp
        Bibliotecas/funciones.cpp
        Bibliotecas/funciones.h)
