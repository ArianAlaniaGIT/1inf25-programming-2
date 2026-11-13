cmake_minimum_required(VERSION 4.4)
project(HerenciaMayorista)

set(CMAKE_CXX_STANDARD 20)

add_executable(HerenciaMayorista main.cpp
        Bibliotecas/Producto.cpp
        Bibliotecas/Producto.h
        Bibliotecas/DetalleVenta.cpp
        Bibliotecas/DetalleVenta.h
        Bibliotecas/Venta.cpp
        Bibliotecas/Venta.h
        Bibliotecas/VentaWeb.cpp
        Bibliotecas/VentaWeb.h
        Bibliotecas/VentaTienda.cpp
        Bibliotecas/VentaTienda.h
        Bibliotecas/Empresa.cpp
        Bibliotecas/Empresa.h
)
