cmake_minimum_required(VERSION 3.30)
project(MPP)

set(CMAKE_CXX_STANDARD 20)

add_executable(
        MPP main.cpp
        Model/Contenedores/MPP.tpp
        Model/Contenedores/MPP.h
        Model/Contenedores/NodoMPP.tpp
        Model/Contenedores/NodoMPP.h)
