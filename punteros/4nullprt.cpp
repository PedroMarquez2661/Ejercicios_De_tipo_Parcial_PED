#include <iostream>
using namespace std;

int main() {
    // 1. Reservamos memoria dinámica para un entero usando 'new'
    int* ptrNumero = new int; 

    // 2. Le asignamos un valor a la memoria reservada
    *ptrNumero = 42;

    cout << "Valor en memoria dinamica: " << *ptrNumero << endl;
    cout << "Direccion de memoria: " << ptrNumero << endl;

    // 3. Liberamos la memoria reservada
    delete ptrNumero; 

    // 4. BUENA PRÁCTICA: Asignamos nullptr para evitar un "puntero colgante" (dangling pointer)
    ptrNumero = nullptr; 

    // Validamos antes de usar el puntero para evitar errores en el sistema
    if (ptrNumero == nullptr) {
        cout << "El puntero esta limpio y no apunta a nada seguro." << endl;
    }

    return 0;
}