cmake_minimum_required(VERSION 4.3)
project(Lab06)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab06 main.cpp
        Bibliotecas/Infraccion.cpp
        Bibliotecas/Infraccion.h
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.h
        Bibliotecas/Multa.cpp
        Bibliotecas/Multa.h
        Bibliotecas/MinisterioDeTransporte.cpp
        Bibliotecas/MinisterioDeTransporte.h)
