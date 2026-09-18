#include <iostream>
using namespace std;

void mostrarMenu() {
    cout << "\n=== MENU PRINCIPAL ===" << endl;
    cout << "1. Saludar" << endl;
    cout << "2. Ver estado" << endl;
    cout << "3. Salir" << endl;
    cout << "Seleccione una opcion: ";
}

int main() {
    int opcion = 0;

    while (opcion != 3) {
        mostrarMenu();
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "¡Hola! Bienvenido al sistema." << endl;
                break;
            case 2:
                cout << "El sistema esta funcionando correctamente." << endl;
                break;
            case 3:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }
    return 0;
}