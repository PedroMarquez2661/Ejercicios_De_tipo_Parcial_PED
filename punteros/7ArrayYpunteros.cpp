// Incluimos la librería estándar de entrada y salida
#include <iostream>
using namespace std;

// Función que recibe un puntero al primer elemento del arreglo y su tamaño
void swapEndpoints(int* arr, int size) {
    // Validación: Si el arreglo tiene menos de 2 elementos, no hay nada que intercambiar
    if (size < 2) return;

    // Guardamos el primer elemento (arr[0]) en una variable temporal
    int temp = arr[0];

    // Asignamos el último elemento (arr[size - 1]) a la primera posición
    arr[0] = arr[size - 1];

    // Colocamos el valor guardado en 'temp' dentro de la última posición
    arr[size - 1] = temp;
}

int main() {
    // Declaración e inicialización del arreglo
    int data[] = {10, 20, 30, 40, 50};

    // Cálculo automático del tamaño del arreglo:
    // sizeof(data) es el tamaño total en bytes de la estructura.
    // sizeof(data[0]) es el tamaño en bytes de un solo tipo int.
    int size = sizeof(data) / sizeof(data[0]);

    // Imprimir el arreglo original
    cout << "Original: ";
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    cout << endl;

    // Llamada a la función pasándole el arreglo (los arreglos decaen implícitamente en punteros)
    swapEndpoints(data, size);

    // Imprimir el arreglo modificado para comprobar el cambio
    cout << "Intercambiado: ";
    for (int i = 0; i < size; i++) cout << data[i] << " ";
    cout << endl;

    return 0;
}