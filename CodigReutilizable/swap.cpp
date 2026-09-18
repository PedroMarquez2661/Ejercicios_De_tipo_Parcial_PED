#include <iostream>
using namespace std;

// Función reutilizable para intercambiar 2 enteros
void intercambiar(int &a, int &b) {
    int temporal = a;
    a = b;
    b = temporal;
}

int main() {
    int x = 10;
    int y = 50;

    cout << "Antes: x = " << x << ", y = " << y << endl;
    
    intercambiar(x, y);

    cout << "Despues: x = " << x << ", y = " << y << endl;

    return 0;
}