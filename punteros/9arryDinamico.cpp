#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Ingrese el tamaño del arreglo dinámico: ";

    // Validación de entrada: asegura que el usuario ingrese un número entero mayor a 0
    if (!(cin >> size) || size <= 0) return 1;

    // RESERVA DINÁMICA: Se solicita memoria en el Heap durante tiempo de ejecución.
    // 'dynamicArr' guarda la dirección del bloque reservado.
    int* dynamicArr = new int[size];

    // Llenado del arreglo con múltiplos de 10
    for (int i = 0; i < size; i++) {
        dynamicArr[i] = (i + 1) * 10;
    }

    // Lectura de los elementos
    cout << "Elementos del arreglo dinámico:" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Indice [" << i << "]: " << dynamicArr[i] << endl;
    }

    // LIBERACIÓN DE MEMORIA: Es esencial para prevenir fugas de memoria (Memory Leaks).
    delete[] dynamicArr;

    // Buena práctica: Asignar nullptr para evitar que el puntero apunte a memoria liberada (Dangling Pointer)
    dynamicArr = nullptr;

    return 0;
}