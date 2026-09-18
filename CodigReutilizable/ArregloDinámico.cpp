#include <iostream>
#include <string>
using namespace std;

// Busca un nombre y regresa su posición (-1 si no existe)
int buscarNombre(const string nombres[], int tamano, const string& objetivo) {
    for (int i = 0; i < tamano; i++) {
        if (nombres[i] == objetivo) {
            return i; // Retorna el índice encontrado
        }
    }
    return -1; // No encontrado
}

int main() {
    string lista[] = {"Ana", "Carlos", "Maria", "Pedro"};
    int tamano = 4;

    string aBuscar = "Maria";
    int pos = buscarNombre(lista, tamano, aBuscar);

    if (pos != -1) {
        cout << aBuscar << " encontrado en el indice: " << pos << endl;
    } else {
        cout << aBuscar << " no esta en la lista." << endl;
    }

    return 0;
}