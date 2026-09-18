#include <iostream>
using namespace std;

// 1. PASO POR VALOR:
// Recibe una copia exacta de la variable original.
// Cualquier modificación dentro de esta función NO afecta a la variable de main().
void passByValue(int val) {
    val += 10;
}

// 2. PASO POR REFERENCIA:
// Crea un alias directo (&) de la variable original.
// Cualquier cambio afecta DIRECTAMENTE a la variable pasada como argumento.
void passByReference(int &ref) {
    ref += 10;
}

// 3. PASO POR PUNTERO:
// Recibe la dirección de memoria de la variable.
// Se usa el operador de desreferencia (*) para alterar el valor almacenado en esa dirección.
void passByPointer(int* ptr) {
    if (ptr != nullptr) { // Verificación preventiva contra punteros nulos
        *ptr += 10;
    }
}

int main() {
    int number = 5;

    // Caso 1: Por Valor
    passByValue(number);
    cout << "Después de passByValue: " << number << endl; // Imprime 5 (sin cambios)

    // Caso 2: Por Referencia
    passByReference(number);
    cout << "Después de passByReference: " << number << endl; // Imprime 15 (se sumaron 10)

    // Caso 3: Por Puntero
    // Se requiere pasar la dirección de memoria explícitamente con '&'
    passByPointer(&number);
    cout << "Después de passByPointer: " << number << endl; // Imprime 25 (se sumaron 10 más)

    return 0;
}