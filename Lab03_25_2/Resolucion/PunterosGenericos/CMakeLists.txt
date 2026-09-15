cmake_minimum_required(VERSION 4.0)
project(PunterosGenericos)

set(CMAKE_CXX_STANDARD 20)

add_executable(PunterosGenericos main.cpp
        Bibliotecas/PunterosGenericos.cpp
        Bibliotecas/PunterosGenericos.h)
