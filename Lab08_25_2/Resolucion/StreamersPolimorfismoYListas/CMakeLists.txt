cmake_minimum_required(VERSION 4.1)
project(StreamersPolimorfismoYListas)

set(CMAKE_CXX_STANDARD 20)

add_executable(StreamersPolimorfismoYListas main.cpp
        Bibliotecas/Metrica.cpp
        Bibliotecas/Metrica.h
        Bibliotecas/MetricaBasica.cpp
        Bibliotecas/MetricaBasica.h
        Bibliotecas/MetricaEngagement.cpp
        Bibliotecas/MetricaEngagement.h
        Bibliotecas/MetricaCalidad.cpp
        Bibliotecas/MetricaCalidad.h
        Bibliotecas/Nodo.cpp
        Bibliotecas/Nodo.h
        Bibliotecas/Lista.cpp
        Bibliotecas/Lista.h
        Bibliotecas/AdministrarMetricas.cpp
        Bibliotecas/AdministrarMetricas.h)
