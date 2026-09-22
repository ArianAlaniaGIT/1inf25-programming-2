cmake_minimum_required(VERSION 4.1)
project(StreamersHerencia)

set(CMAKE_CXX_STANDARD 20)

add_executable(StreamersHerencia main.cpp
        Bibliotecas/GestorStreamers.cpp
        Bibliotecas/GestorStreamers.h
        Bibliotecas/Metrica.cpp
        Bibliotecas/MetricaBasica.cpp
        Bibliotecas/MetricaEngagement.cpp
        Bibliotecas/Streamer.cpp
        Bibliotecas/StreamerGratuito.cpp
        Bibliotecas/StreamerPago.cpp
        Bibliotecas/MetricaCalidad.cpp
        Bibliotecas/Metrica.h
        Bibliotecas/MetricaBasica.h
        Bibliotecas/MetricaEngagement.h
        Bibliotecas/Streamer.h
        Bibliotecas/StreamerGratuito.h
        Bibliotecas/StreamerPago.h
        Bibliotecas/MetricaCalidad.h)
