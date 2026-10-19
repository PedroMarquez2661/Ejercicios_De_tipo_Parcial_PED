#include <iostream>

using namespace std;

// Estructura que representa cada nodo del árbol
struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    // Constructor para inicializar el nodo fácilmente
    Nodo(int val) {
        valor = val;
        izquierdo = nullptr;
        derecho = nullptr;
    }
};

/**
 * @brief Inserta un nuevo valor en el Árbol de Búsqueda Binaria.
 * @param raiz Puntero a la raíz actual del subárbol.
 * @param valor Valor entero que se desea insertar.
 * @return Nodo* Puntero actualizado de la raíz.
 */
Nodo* insertar(Nodo* raiz, int valor) {
    // Caso base: si el subárbol está vacío, creamos y retornamos el nuevo nodo
    if (raiz == nullptr) {
        return new Nodo(valor);
    }

    // Si el valor es menor, insertamos en el subárbol izquierdo
    if (valor < raiz->valor) {
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    }
    // Si el valor es mayor, insertamos en el subárbol derecho
    else if (valor > raiz->valor) {
        raiz->derecho = insertar(raiz->derecho, valor);
    }
    // Si el valor es igual, no hacemos nada (evitamos duplicados)

    return raiz;
}

/**
 * @brief Recorrido In-Order (Izquierda -> Raíz -> Derecha).
 * Imprime los elementos del árbol ordenados de menor a mayor.
 */
void recorrerInOrder(Nodo* raiz) {
    if (raiz == nullptr) {
        return;
    }
    recorrerInOrder(raiz->izquierdo);
    cout << raiz->valor << " ";
    recorrerInOrder(raiz->derecho);
}

int main() {
    Nodo* raiz = nullptr;

    // Inserción de elementos de prueba
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    // Mostramos los elementos ordenados gracias a las propiedades del BST
    cout << "Elementos del arbol (In-Order): ";
    recorrerInOrder(raiz);
    cout << endl;

    return 0;
}