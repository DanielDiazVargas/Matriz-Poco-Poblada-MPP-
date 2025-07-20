#pragma once
#include "NodoMPP.h"

/**
 * @brief Clase que representa una Matriz Poco Poblada (MPP) usando listas de encabezado por filas y columnas.
 *
 * Esta clase almacena elementos dispersos en una matriz de tamaño fijo, con el objetivo de ahorrar memoria
 * cuando la mayoría de las posiciones están vacías.
 *
 * @tparam T Tipo de dato almacenado. Puede ser un tipo primitivo o puntero.
 */
template<typename T>
class MPP {
private:
    int alto;               // Número de filas de la matriz.
    int largo;              // Número de columnas de la matriz.
    NodoMPP<T>** AROW;      // Arreglo de punteros a los encabezados de fila.
    NodoMPP<T>** ACOL;      // Arreglo de punteros a los encabezados de columna.

public:
    /**
     * @brief Constructor por defecto. Crea una matriz vacía de 0x0.
     */
    MPP();

    /**
     * @brief Constructor que inicializa la matriz con dimensiones dadas.
     *
     * @param alto Número de filas.
     * @param largo Número de columnas.
     */
    MPP(int alto, int largo);

    /**
     * @brief Obtiene el número de filas de la matriz.
     *
     * @return Número de filas.
     */
    int getAlto();

    /**
     * @brief Obtiene el número de columnas de la matriz.
     *
     * @return Número de columnas.
     */
    int getLargo();

    /**
     * @brief Busca un nodo por su dato almacenado.
     *
     * @param dato Dato a buscar.
     * @return Puntero al nodo que contiene el dato o nullptr si no se encuentra.
     */
    NodoMPP<T>* buscar(T dato);

    /**
     * @brief Busca un nodo por su posición (fila y columna).
     *
     * @param fila Fila en la que buscar.
     * @param columna Columna en la que buscar.
     * @return Puntero al nodo en la posición dada o nullptr si no existe.
     */
    NodoMPP<T>* buscar(int fila, int columna);

    /**
     * @brief Inserta un dato en la posición dada de la matriz.
     *
     * @param dato Dato a insertar.
     * @param fila Fila en la que insertar.
     * @param columna Columna en la que insertar.
     * @return 0 si la inserción fue exitosa,
     *         1 si ya había un nodo en esa posición,
     *         2 si las coordenadas dadas no están en la matriz.
     */
    int insertar(T dato, int fila, int columna);

    /**
     * @brief Elimina el nodo que contiene el dato dado.
     *
     * @param dato Dato del nodo a eliminar.
     * @return 0 si la eliminacion fue exitosa,
     *         1 si no existe un nodo con el dato.
     */
    int eliminar(T dato);

    /**
     * @brief Elimina el nodo en la posición dada.
     *
     * @param fila Fila del nodo.
     * @param columna Columna del nodo.
     * @return 0 si la eliminacion fue exitosa,
     *         1 si no existe un nodo en las coordenadas dadas,
     *         2 si las coordenadas dadas no están en la matriz.
     */
    int eliminar(int fila, int columna);

    /**
     * @brief Mueve un nodo de una posición a otra dentro de la matriz.
     *
     * @param fila Fila original del nodo.
     * @param columna Columna original del nodo.
     * @param nuevaFila Nueva fila destinó.
     * @param nuevaColumna Nueva columna destinó.
     * @return 0 si se movió correctamente,
     *         1 si no existe un nodo en las coordenadas originales,
     *         2 si las coordenadas dadas no están en la matriz.
     *         3 si ya existe un nodo en las coordenadas nuevas.
     */
    int mover(int fila, int columna, int nuevaFila, int nuevaColumna);

    /**
     * @brief Elimina todos los nodos no cabecera de la matriz, dejándola vacía.
     */
    void vaciar();

    /**
     * @brief Verifica si la matriz está vacía.
     *
     * @return true si no hay ningún nodo, false en caso contrario.
     */
    bool esVacia();

    /**
     * @brief Imprime la matriz en consola.
     *
     * Imprime la matriz mostrando que posiciones están ocupadas y cuáles están vaciás.
     */
    void imprimir();

    /**
     * @brief Destructor de la clase MPP.
     *
     * Libera toda la memoria utilizada por los nodos y los arreglos de encabezado.
     */
    ~MPP();
};

#include "MPP.tpp"