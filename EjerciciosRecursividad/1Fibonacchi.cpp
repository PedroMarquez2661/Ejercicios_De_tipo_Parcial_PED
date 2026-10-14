#include <iostream>

using namespace std;

// Función recursiva para calcular el n-ésimo término de Fibonacci
int fibonacci(int n) {
    // Casos base
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Caso recursivo: F(n) = F(n-1) + F(n-2)
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n = 10; // Cantidad de términos que deseas mostrar
    
    cout << "Secuencia de Fibonacci (" << n << " términos):" << endl;
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
    
    return 0;
}