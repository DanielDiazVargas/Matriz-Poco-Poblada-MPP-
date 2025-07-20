#pragma once

/**
 * @brief Clase NodoMPP para representar un nodo de una Matriz Poco Poblada (MPP).
 *
 * Esta versión maneja datos almacenados por valor.
 *
 * @tparam T Tipo del dato almacenado en el nodo.
 */
template<typename T>
class NodoMPP {
private:
    NodoMPP* left;     // Puntero al nodo a la izquierda.
    NodoMPP* up;       // Puntero al nodo superior.
    int fila;          // Índice de la fila del nodo.
    int columna;       // Índice de la columna del nodo.
    T dato;            // Dato almacenado.

public:
    /**
     * @brief Constructor por defecto.
     */
    NodoMPP();

    /**
     * @brief Constructor que inicializa fila, columna y dato.
     *
     * @param fila Fila del nodo.
     * @param columna Columna del nodo.
     * @param dato Dato a almacenar.
     */
    NodoMPP(int fila, int columna, T dato);

    /**
     * @brief Obtiene el puntero al nodo izquierdo.
     *
     * @return Puntero al nodo izquierdo.
     */
    NodoMPP* getLeft();

    /**
     * @brief Obtiene el puntero al nodo superior.
     *
     * @return Puntero al nodo superior.
     */
    NodoMPP* getUp();

    /**
     * @brief Obtiene la fila del nodo.
     *
     * @return Índice de fila.
     */
    int getFila();

    /**
     * @brief Obtiene la columna del nodo.
     *
     * @return Índice de columna.
     */
    int getColumna();

    /**
     * @brief Obtiene el dato almacenado en el nodo.
     *
     * @return Valor del dato.
     */
    T getDato();

    /**
     * @brief Asigna el puntero al nodo izquierdo.
     *
     * @param left Puntero al nuevo nodo izquierdo.
     */
    void setLeft(NodoMPP* left);

    /**
     * @brief Asigna el puntero al nodo superior.
     *
     * @param up Puntero al nuevo nodo superior.
     */
    void setUp(NodoMPP* up);

    /**
     * @brief Asigna la fila del nodo.
     *
     * @param fila Nueva fila.
     */
    void setFila(int fila);

    /**
     * @brief Asigna la columna del nodo.
     *
     * @param columna Nueva columna.
     */
    void setColumna(int columna);

    /**
     * @brief Asigna el dato del nodo.
     *
     * @param dato Nuevo dato.
     */
    void setDato(T dato);

    /**
     * @brief Destructor del nodo.
     *
     * Este destructor está marcado como "= default" para indicar
     * explícitamente que el comportamiento por defecto del compilador es suficiente.
     */
    ~NodoMPP();
};

/**
 * @brief Especialización de NodoMPP para manejar punteros como datos.
 *
 * Esta clase permite almacenar punteros a objetos y es útil cuando se
 * requiere manipular instancias dinámicas dentro de la matriz.
 *
 * @tparam T Tipo del dato apuntado.
 */
template<typename T>
class NodoMPP<T*> {
private:
    NodoMPP* left;     // Puntero al nodo a la izquierda.
    NodoMPP* up;       // Puntero al nodo superior.
    int fila;          // Índice de la fila del nodo.
    int columna;       // Índice de la columna del nodo.
    T* dato;           // Puntero al dato almacenado.

public:
    /**
     * @brief Constructor por defecto.
     */
    NodoMPP();

    /**
     * @brief Constructor que inicializa fila, columna y puntero al dato.
     *
     * @param fila Fila del nodo.
     * @param columna Columna del nodo.
     * @param dato Puntero al dato a almacenar.
     */
    NodoMPP(int fila, int columna, T* dato);

    /**
     * @brief Obtiene el puntero al nodo izquierdo.
     *
     * @return Puntero al nodo izquierdo.
     */
    NodoMPP* getLeft();

    /**
     * @brief Obtiene el puntero al nodo superior.
     *
     * @return Puntero al nodo superior.
     */
    NodoMPP* getUp();

    /**
     * @brief Obtiene la fila del nodo.
     *
     * @return Índice de fila.
     */
    int getFila();

    /**
     * @brief Obtiene la columna del nodo.
     *
     * @return Índice de columna.
     */
    int getColumna();

    /**
     * @brief Obtiene el puntero al dato almacenado.
     *
     * @return Puntero al dato.
     */
    T* getDato();

    /**
     * @brief Asigna el puntero al nodo izquierdo.
     *
     * @param left Puntero al nuevo nodo izquierdo.
     */
    void setLeft(NodoMPP* left);

    /**
     * @brief Asigna el puntero al nodo superior.
     *
     * @param up Puntero al nuevo nodo superior.
     */
    void setUp(NodoMPP* up);

    /**
     * @brief Asigna la fila del nodo.
     *
     * @param fila Nueva fila.
     */
    void setFila(int fila);

    /**
     * @brief Asigna la columna del nodo.
     *
     * @param columna Nueva columna.
     */
    void setColumna(int columna);

    /**
     * @brief Asigna el puntero al dato.
     *
     * @param dato Nuevo puntero al dato.
     */
    void setDato(T* dato);

    /**
     * @brief Destructor del nodo.
     *
     * No se puede saber si el puntero fue asignado con `new` o no,
     * por lo que se recomienda usar `std::shared_ptr` o `std::unique_ptr`
     * si se desea un manejo automático de memoria.
     */
    ~NodoMPP();
};

#include "NodoMPP.tpp"