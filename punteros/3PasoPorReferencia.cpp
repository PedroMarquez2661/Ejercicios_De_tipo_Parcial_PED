#include <iostream>
using namespace std;

// 1. PASO POR PUNTERO
// Recibe la dirección de memoria. Necesita el asterisco (*) para modificar el valor.
void modificarConPuntero(int* p) {
    if (p != nullptr) { // Seguridad: Se debe verificar que no sea nulo
        *p = 100;       // Modifica el valor usando desreferencia (*)
    }
}

// 2. PASO POR REFERENCIA
// Recibe la variable directamente como alias. La sintaxis es idéntica a una variable normal.
void modificarConReferencia(int& r) {
    r = 200;            // Modifica el valor directamente, sin asteriscos
}

int main() {
    int x = 10;
    int y = 20;

    // Llamada con Puntero: Es OBLIGATORIO enviar la dirección usando &
    modificarConPuntero(&x);

    // Llamada con Referencia: Se pasa la variable directamente (más limpio)
    modificarConReferencia(y);

    cout << "Valor de x (puntero): " << x << endl; // Imprime 100
    cout << "Valor de y (referencia): " << y << endl; // Imprime 200

    return 0;
}