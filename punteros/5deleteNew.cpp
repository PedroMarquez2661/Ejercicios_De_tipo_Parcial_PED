#include <iostream>
using namespace std;

void cargarYMostrarNotas(int* notas, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "Ingresa la nota " << i + 1 << ": ";
        cin >> notas[i];
    }

    cout << "\n--- NOTAS REGISTRADAS ---" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Nota [" << i + 1 << "]: " << notas[i] << endl;
    }
}

int main() {
    int totalNotas;

    cout << "=== SISTEMA DE NOTAS DINAMICO ===" << endl;
    cout << "¿Cuantas notas deseas ingresar?: ";
    cin >> totalNotas;

    if (totalNotas <= 0) {
        cout << "Cantidad invalida." << endl;
        return 0;
    }

    // Reservamos un arreglo de tamaño exacto según lo que pidió el usuario
    int* listaNotas = new int[totalNotas];

    // Procesamos el arreglo
    cargarYMostrarNotas(listaNotas, totalNotas);

    // IMPORTANTE: Liberar arreglos dinámicos usando delete[] (con corchetes)
    delete[] listaNotas;
    listaNotas = nullptr; // Limpiamos la referencia

    cout << "\nMemoria del arreglo liberada correctamente." << endl;

    return 0;
}