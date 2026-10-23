#include <iostream>
#include <stack> // Biblioteca estándar para el manejo de pilas (stack)

using namespace std; // Permite usar los elementos de la biblioteca estándar sin el prefijo std::

int main() {
    // 1. Declaración
    // Creamos una pila vacía que almacenará números enteros.
    stack<int> miPila;

    // 2. empty()
    // Comprueba si la pila está vacía. Devuelve true si no tiene elementos, false en caso contrario.
    if (miPila.empty()) {
        cout << "La pila esta vacia actualmente." << endl;
    }

    // 3. push()
    // Inserta elementos en la parte superior (cima) de la pila.
    // Estructura resultante (de abajo hacia arriba): [10, 20, 30]
    miPila.push(10);
    miPila.push(20);
    miPila.push(30); // El 30 es el último en entrar y el primero en salir

    // 4. size()
    // Devuelve el número total de elementos que contiene la pila.
    cout << "Numero de elementos en la pila (size): " << miPila.size() << endl;

    // 5. top()
    // Permite consultar (leer) el elemento que se encuentra en la cima sin eliminarlo.
    cout << "Elemento en la cima de la pila (top): " << miPila.top() << endl;

    // 6. pop()
    // Elimina el elemento que está en la cima de la pila (en este caso, el 30).
    miPila.pop();

    // Verificamos el nuevo estado superior y el nuevo tamaño tras el pop()
    cout << "\nDespues de hacer un pop()..." << endl;
    cout << "Nuevo elemento en la cima (top): " << miPila.top() << endl; // Ahora es 20
    cout << "Nuevo tamano de la pila: " << miPila.size() << endl;        // Ahora es 2

    return 0;
}