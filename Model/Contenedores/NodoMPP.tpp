#pragma once

#include "NodoMPP.h"

template<typename T>
NodoMPP<T>::NodoMPP() {
    this->left = nullptr;
    this->up = nullptr;
    this->fila = 0;
    this->columna = 0;
}

template<typename T>
NodoMPP<T>::NodoMPP(int fila, int columna, T dato) {
    this->left = nullptr;
    this->up = nullptr;
    this->fila = fila;
    this->columna = columna;
    this->dato = dato;
}

template<typename T>
NodoMPP<T>* NodoMPP<T>::getLeft() {
    return this->left;
}

template<typename T>
NodoMPP<T>* NodoMPP<T>::getUp() {
    return this->up;
}

template<typename T>
int NodoMPP<T>::getFila() {
    return this->fila;
}

template<typename T>
int NodoMPP<T>::getColumna() {
    return this->columna;
}

template<typename T>
T NodoMPP<T>::getDato() {
    return this->dato;
}

template<typename T>
void NodoMPP<T>::setLeft(NodoMPP* left) {
    this->left = left;
}

template<typename T>
void NodoMPP<T>::setUp(NodoMPP* up) {
    this->up = up;
}

template<typename T>
void NodoMPP<T>::setFila(int fila) {
    this->fila = fila;
}

template<typename T>
void NodoMPP<T>::setColumna(int columna) {
    this->columna = columna;
}

template<typename T>
void NodoMPP<T>::setDato(T dato) {
    this->dato = dato;
}

template<typename T>
NodoMPP<T>::~NodoMPP() = default;

template<typename T>
NodoMPP<T*>::NodoMPP() {
    this->left = nullptr;
    this->up = nullptr;
    this->fila = 0;
    this->columna = 0;
    this->dato = nullptr;
}

template<typename T>
NodoMPP<T*>::NodoMPP(int fila, int columna, T* dato) {
    this->left = nullptr;
    this->up = nullptr;
    this->fila = fila;
    this->columna = columna;
    this->dato = dato;
}

template<typename T>
NodoMPP<T*>* NodoMPP<T*>::getLeft() {
    return this->left;
}

template<typename T>
NodoMPP<T*>* NodoMPP<T*>::getUp() {
    return this->up;
}

template<typename T>
int NodoMPP<T*>::getFila() {
    return this->fila;
}

template<typename T>
int NodoMPP<T*>::getColumna() {
    return this->columna;
}

template<typename T>
T* NodoMPP<T*>::getDato() {
    return this->dato;
}

template<typename T>
void NodoMPP<T*>::setLeft(NodoMPP<T*>* left) {
    this->left = left;
}

template<typename T>
void NodoMPP<T*>::setUp(NodoMPP<T*>* up) {
    this->up = up;
}

template<typename T>
void NodoMPP<T*>::setFila(int fila) {
    this->fila = fila;
}

template<typename T>
void NodoMPP<T*>::setColumna(int columna) {
    this->columna = columna;
}

template<typename T>
void NodoMPP<T*>::setDato(T* dato) {
    this->dato = dato;
}

template<typename T>
NodoMPP<T*>::~NodoMPP() {
    if (this->dato) delete this->dato;
}