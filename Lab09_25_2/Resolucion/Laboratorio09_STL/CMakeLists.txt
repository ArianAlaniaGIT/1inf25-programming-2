cmake_minimum_required(VERSION 4.1)
project(Laboratorio09_STL)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio09_STL main.cpp
        Bibliotecas/Etiqueta.cpp
        Bibliotecas/Etiqueta.h
        Bibliotecas/Categoria.cpp
        Bibliotecas/Categoria.h
        Bibliotecas/Comentario.cpp
        Bibliotecas/Comentario.h
        Bibliotecas/Streamer.cpp
        Bibliotecas/Streamer.h
        Bibliotecas/SistemaDeGestion.cpp
        Bibliotecas/SistemaDeGestion.h)
