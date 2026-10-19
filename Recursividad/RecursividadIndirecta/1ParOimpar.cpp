#include <iostream>

using namespace std;

// Declaración anticipada (forward declaration) necesaria 
// para que esPar conozca la existencia de esImpar antes de ser definida.
bool esImpar(int n);

/**
 * @brief Evalúa si un número entero es par mediante recursividad indirecta.
 * @param n Número entero a evaluar.
 * @return true si es par, false en caso contrario.
 */
bool esPar(int n) {
    // Manejo de números negativos convirtiéndolos a positivos
    if (n < 0) {
        return esPar(-n);
    }
    
    // Caso base: el 0 es par por definición
    if (n == 0) {
        return true;
    }
    
    // Llamada cruzada (indirecta): delega la evaluación al número anterior usando esImpar
    return esImpar(n - 1);
}

/**
 * @brief Evalúa si un número entero es impar mediante recursividad indirecta.
 * @param n Número entero a evaluar.
 * @return true si es impar, false en caso contrario.
 */
bool esImpar(int n) {
    // Manejo de números negativos convirtiéndolos a positivos
    if (n < 0) {
        return esPar(-n);
    }
    
    // Caso base: el 0 no es impar
    if (n == 0) {
        return false;
    }
    
    // Llamada cruzada (indirecta): delega la evaluación al número anterior usando esPar
    return esPar(n - 1);
}

int main() {
    // Prueba con diferentes valores
    int numeroPrueba = 7;

    cout << "Evaluando el numero: " << numeroPrueba << endl;

    if (esPar(numeroPrueba)) {
        cout << "El numero " << numeroPrueba << " es PAR." << endl;
    } else {
        cout << "El numero " << numeroPrueba << " es IMPAR." << endl;
    }

    return 0;
}