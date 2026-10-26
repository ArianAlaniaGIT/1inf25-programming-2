cmake_minimum_required(VERSION 4.3)
project(CrearBiblioteca_Parte1)

set(CMAKE_CXX_STANDARD 20)

add_library(BibliotecaEstatica STATIC Bibliotecas/BibliotecaEstatica.cpp)

add_executable(CrearBiblioteca_Parte1 main.cpp)

target_link_libraries(CrearBiblioteca_Parte1 BibliotecaEstatica)
