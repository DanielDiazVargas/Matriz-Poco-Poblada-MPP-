#pragma once
#include <iostream>

#include "MPP.h"

template<typename T>
MPP<T>::MPP() {
    this->alto = 0;
    this->largo = 0;
    this->ACOL = nullptr;
    this->AROW = nullptr;
}

template<typename T>
MPP<T>::MPP(int alto, int largo) {
    this->alto = alto;
    this->largo = largo;

    // Inicializa columnas (cabeceras).
    this->ACOL = new NodoMPP<T>*[largo + 1];
    for (int i = 1; i <= largo; i++) {
        this->ACOL[i] = new NodoMPP<T>();
        this->ACOL[i]->setFila(0);
        this->ACOL[i]->setColumna(i);
        this->ACOL[i]->setUp(this->ACOL[i]);
    }

    // Inicializa filas (cabeceras).
    this->AROW = new NodoMPP<T>*[alto + 1];
    for (int i = 1; i <= alto; i++) {
        this->AROW[i] = new NodoMPP<T>();
        this->AROW[i]->setFila(i);
        this->AROW[i]->setColumna(0);
        this->AROW[i]->setLeft(this->AROW[i]);
    }
}

template<typename T>
int MPP<T>::getAlto() {
    return this->alto;
}

template<typename T>
int MPP<T>::getLargo() {
    return this->largo;
}

template<typename T>
NodoMPP<T>* MPP<T>::buscar(T dato) {
    for (int i = 1; i <= this->alto; i++) { // Avanza fila a fila.
        NodoMPP<T>* aux = this->AROW[i]->getLeft();
        while (aux != this->AROW[i]) { // Finaliza cuando se regresa a la cabecera de la fila.
            if constexpr (std::is_pointer<T>::value) { // Comprueba si el dato es primitivo o puntero.
                // Si el puntero es igual al puntero buscado, retorna el nodo.
                if (*aux->getDato() == *dato) return aux;
            } else {
                // Si el dato es igual al dato buscado, retorna el nodo.
                if (aux->getDato() == dato) return aux;
            }
            aux = aux->getLeft();
        }
    }
    return nullptr; // Retorna nullptr si se recorrió toda la matriz y no se encontro el dato buscado.
}

template<typename T>
NodoMPP<T>* MPP<T>::buscar(int fila, int columna) {
    // Verifica que las coordenadas se encuentren en la matriz, retorna nullptr en caso contrario.
    if (fila < 1 || fila > this->alto || columna < 1 || columna > this->largo) return nullptr;

    NodoMPP<T>* aux = this->AROW[fila]->getLeft(); // Se posiciona en la fila indicada.
    while (aux->getColumna() >= columna) { // Finaliza si la columna actual es menor a la buscada.
        if (aux->getColumna() == columna) return aux; // retorna el nodo si se encontro la columna buscada.
        aux = aux->getLeft();
    }
    // Retorna nullptr si se recorrió todas las columnas de la fila y no se encontro el dato buscado.
    return nullptr;
}

template<typename T>
int MPP<T>::insertar(T dato, int fila, int columna) {
    // Verifica que las coordenadas se encuentren en la matriz, retorna "2" en caso contrario.
    if (fila < 1 || fila > this->alto || columna < 1 || columna > this->largo) return 2;

    // Verifica si ya existe un nodo en las coordenadas dadas, retorna "1" si ya existe.
    if (buscar(fila, columna)) return 1;

    NodoMPP<T>* nuevoNodo = new NodoMPP<T>(fila, columna, dato);

    NodoMPP<T>* aux = this->AROW[fila];
    // Avanza hasta llegar al nodo a la derecha de la columna a insertar.
    while (aux->getLeft()->getColumna() > columna) {
        aux = aux->getLeft();
    }
    // Actualiza los enlaces de la fila.
    nuevoNodo->setLeft(aux->getLeft());
    aux->setLeft(nuevoNodo);

    aux = this->ACOL[columna];
    // Avanza hasta llegar al nodo abajo de la fila a insertar.
    while (aux->getUp()->getFila() > fila) {
        aux = aux->getUp();
    }
    // Actualiza los enlaces de la columna.
    nuevoNodo->setUp(aux->getUp());
    aux->setUp(nuevoNodo);

    return 0;
}

template<typename T>
int MPP<T>::eliminar(T dato) {
    // Hace uso del metodo "buscar" para verificar si el nodo existe, retorna "1" si no existe.
    NodoMPP<T>* nodoEliminar = buscar(dato);
    if (!nodoEliminar) return 1;

    NodoMPP<T>* aux = nodoEliminar->getLeft();
    // Avanza hasta llegar al nodo a la derecha del nodo a eliminar.
    while (aux->getLeft()->getColumna() != nodoEliminar->getColumna()) {
        aux = aux->getLeft();
    }
    // Actualiza los enlaces de la fila.
    aux->setLeft(nodoEliminar->getLeft());
    nodoEliminar->setLeft(nullptr);

    aux = nodoEliminar->getUp();
    // Avanza hasta llegar al nodo abajo del nodo a eliminar.
    while (aux->getUp()->getFila() != nodoEliminar->getFila()) {
        aux = aux->getUp();
    }
    // Actualiza los enlaces de la columna.
    aux->setUp(nodoEliminar->getUp());
    nodoEliminar->setUp(nullptr);

    delete nodoEliminar;
    return 0;
}

template<typename T>
int MPP<T>::eliminar(int fila, int columna) {
    // Verifica que las coordenadas se encuentren en la matriz, retorna "2" en caso contrario.
    if (fila < 1 || fila > this->alto || columna < 1 || columna > this->largo) return 2;

    NodoMPP<T>* aux = AROW[fila];
    // Avanza hasta llegar al nodo a la derecha del nodo a eliminar.
    while (aux->getLeft()->getColumna() != columna) {
        // Si la columna del aux es menor a la columna dada el nodo no existe y retorna "1".
        if (aux->getLeft()->getColumna() < columna) return 1;
        aux = aux->getLeft();
    }

    // Actualiza los enlaces en la fila.
    NodoMPP<T>* nodoEliminar = aux->getLeft();
    aux->setLeft(nodoEliminar->getLeft());
    nodoEliminar->setLeft(nullptr);

    aux = nodoEliminar->getUp();
    // Avanza hasta llegar al nodo abajo del nodo a eliminar.
    while (aux->getUp()->getFila() != fila) {
        aux = aux->getUp();
    }

    // Actualiza los enlaces en la columna.
    aux->setUp(nodoEliminar->getUp());
    nodoEliminar->setUp(nullptr);

    delete nodoEliminar;
    return 0;
}

template<typename T>
int MPP<T>::mover(int fila, int columna, int nuevaFila, int nuevaColumna) {
    // Verifica que las coordenadas se encuentren en la matriz, retorna "2" en caso contrario.
    if (fila < 1 || fila > this->alto || columna < 1 || columna > this->largo) return 2;
    if (nuevaFila < 1 || nuevaFila > this->alto || nuevaColumna < 1 || nuevaColumna > this->largo) return 2;

    // Hace uso del metodo "buscar" para verificar si el nodo existe, retorna "1" si no existe.
    NodoMPP<T>* nodoMover = buscar(fila, columna);
    if (!nodoMover) return 1;

    // Hace uso del metodo "buscar" para verificar que no exista un nodo, retorna "3" si existe.
    if (buscar(nuevaFila, nuevaColumna)) return 3;

    // Hace uso del metodo "insertar" para crear un nuevo nodo en las coordenadas.
    insertar(nodoMover->getDato(), nuevaFila, nuevaColumna);
    // Si el dato es puntero, quita la referencia para evitar eliminarla.
    if constexpr (std::is_pointer<T>::value) {
        nodoMover->setDato(nullptr);
    }
    // Hace uso del metodo "eliminar" para limpiar el espacio del nodo antiguo.
    eliminar(fila, columna);

    return 0;
}

template<typename T>
void MPP<T>::vaciar() {
    for (int i = 1; i <= this->alto; i++) { // Avanza fila a fila.
        NodoMPP<T>* aux = AROW[i]->getLeft();
        while (aux != AROW[i]) { // Finaliza cuando se regresa a la cabecera de la fila.
            NodoMPP<T>* temp = aux; // Guarda el nodo a liminar en un nodo temporal.
            aux = aux->getLeft(); // Avanza al siguiente nodo.
            delete temp; // Elimina el nodo guardado temporalmente.
        }
        // Hace que la cabecera de la fila actual se apunte a sí misma una vez eliminados los nodos de la fila.
        AROW[i]->setLeft(AROW[i]);
    }
    // Hace que la cabecera de la columna actual se apunte a si misma.
    for (int i = 1; i <= this->largo; i++) {// Avanza columna a columna.
        ACOL[i]->setUp(ACOL[i]);
    }
}

template<typename T>
bool MPP<T>::esVacia() {
    for (int i = 1; i <= this->alto; i++) { // Avanza fila a fila.
        if (AROW[i]->getLeft() != AROW[i]) return false; // Si la cabecera no se apunta a si misma, retorna false.
    }
    return true; // Retorna true si todas las cabeceras se apuntan a si mismas.
}

template<typename T>
void MPP<T>::imprimir() {
    // Imprime por consola los numero que representan las columna de la matriz.
    for (int i = 1; i <= this->largo; i++) {
        std::cout << "   " << i;
    }

    for (int i = 1; i <= this->alto; i++) { // Avanza fila a fila.
        int columna = this->largo; // Entero utilizado para saber la posición actual de la comuna en el ciclo while.
        std::string s = ""; // String utilizado para imprimir los datos de la fila actual.

        NodoMPP<T>* aux = AROW[i];
        while (true) {
            aux = aux->getLeft();
            // Agrega " [ ]" a la izquierda del string "s" la cantidad de columnas libres a la derecha de la actual.
            for (int j = 0; j < columna - aux->getColumna(); j++) {
                s = " [ ]" + s;
            }
            if (aux->getColumna() == 0) { // Finaliza cuando el nodo actual es la cabecera de la fila.
                // Agrega a la izquierda del string "s" un salto de linea y
                // un numero que representa la fila en la matriz.
                s = '\n' + std::to_string(i) + s;
                break; // Finaliza el ciclo while.
            }
            columna = aux->getColumna() -1; // Actualiza la columna actual a la izquierda de la columna del nodo "aux".
            // Agrega " [X]" a la izquierda del string "s" en representation de que la posición esta ocupada.
            s = " [X]" + s;
        }
        std::cout << s; // Imprime por consola la information de la fila actual.
    }
    std::cout << std::endl;
}

template<typename T>
MPP<T>::~MPP() {
    // Elimina todos los nodos no cabeceras.
    vaciar();

    // Eliminar cabeceras de fila.
    for (int i = 1; i <= this->alto; ++i) {
        delete this->AROW[i];
    }

    // Eliminar cabeceras de columna.
    for (int i = 1; i <= this->largo; ++i) {
        delete this->ACOL[i];
    }

    delete[] this->AROW;
    delete[] this->ACOL;
}