#include <iostream>
using namespace std;

// Busca un valor en el arreglo y cuenta cuántas veces aparece.
// Devuelve true si existe, false si no.
bool buscarYContar(const int arreglo[], int tamano, int numeroBuscado, int &repeticiones) {
    repeticiones = 0;
    
    for (int i = 0; i < tamano; i++) {
        if (arreglo[i] == numeroBuscado) {
            repeticiones++;
        }
    }
    
    return (repeticiones > 0);
}

int main() {
    int datos[] = {5, 12, 8, 5, 20, 5, 10};
    int tamano = 7;
    int numero = 5;
    int contador = 0;

    if (buscarYContar(datos, tamano, numero, contador)) {
        cout << "El numero " << numero << " existe y se repite " << contador << " veces." << endl;
    } else {
        cout << "El numero no fue encontrado." << endl;
    }

    return 0;
}