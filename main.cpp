#include "Model/Contenedores/MPP.h"

int main() {
    // Matriz con enteros
    MPP<int> matrizInt(5, 5);
    matrizInt.insertar(10, 1, 1);
    matrizInt.insertar(20, 2, 3);
    matrizInt.insertar(30, 5, 5);
    matrizInt.imprimir();

    std::cout << "\nMoviendo valor de (2,3) a (4,4)...\n";
    matrizInt.mover(2, 3, 4, 4);
    matrizInt.imprimir();

    std::cout << "\nEliminando valor en (1,1)...\n";
    matrizInt.eliminar(1, 1);
    matrizInt.imprimir();

    std::cout << "\nVaciando matriz de enteros...\n";
    matrizInt.vaciar();
    matrizInt.imprimir();

    std::cout << '\n' << std::string(50,'*') << std::endl;

    // Matriz con strings
    MPP<std::string> matrizStr(4, 4);
    matrizStr.insertar("Hola", 1, 1);
    matrizStr.insertar("Mundo", 2, 2);
    matrizStr.insertar("CPP", 3, 3);
    matrizStr.imprimir();

    std::cout << "\nEliminando \"Mundo\" por contenido...\n";
    matrizStr.eliminar("Mundo");
    matrizStr.imprimir();

    std::cout << "\nMoviendo \"CPP\" de (3,3) a (4,1)...\n";
    matrizStr.mover(3, 3, 4, 1);
    matrizStr.imprimir();

    std::cout << "\nVaciando matriz de strings...\n";
    matrizStr.vaciar();
    matrizStr.imprimir();

    std::cout << '\n' << std::string(50,'*') << std::endl;

    // Matriz con punteros a enteros
    int* a = new int(100);
    int* b = new int(150);
    int* c = new int(200);

    MPP<int*> matrizPtr(7, 3);
    matrizPtr.insertar(a, 5, 2);
    matrizPtr.insertar(b, 7, 3);
    matrizPtr.insertar(c, 3, 1);
    matrizPtr.imprimir();

    std::cout << "\nMoviendo puntero de (3,1) a (7,1)...\n";
    matrizPtr.mover(3, 1, 7, 1);
    matrizPtr.imprimir();

    std::cout << "\nEliminando el puntero b...\n";
    matrizPtr.eliminar(b);
    matrizPtr.imprimir();

    std::cout << "\nVaciando matriz de punteros...\n";
    matrizPtr.vaciar();
    matrizPtr.imprimir();

    return 0;
}