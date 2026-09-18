#include <iostream>
using namespace std;

struct Personaje {
    string nombre;
    int vida;
    int nivel;
};

// Función void que crea un personaje dinámicamente y lo devuelve por referencia de puntero
void crearPersonaje(Personaje*& ptr, string nombre, int vida, int nivel) {
    // Reservamos memoria para una estructura completa
    ptr = new Personaje;
    
    // Asignamos datos usando el operador flecha (->) para punteros a struct
    ptr->nombre = nombre;
    ptr->vida = vida;
    ptr->nivel = nivel;
}

// Función void para destruir el personaje y limpiar la memoria
void destruirPersonaje(Personaje*& ptr) {
    if (ptr != nullptr) {
        delete ptr;      // Liberar memoria
        ptr = nullptr;  // Asignar nullptr
        cout << "Personaje eliminado y memoria liberada." << endl;
    }
}

int main() {
    Personaje* jugador = nullptr; // Inicializado en nullptr

    // Crear personaje dinámicamente
    crearPersonaje(jugador, "Guerrero BJJ", 100, 5);

    if (jugador != nullptr) {
        cout << "--- PERSONAJE CREADO ---" << endl;
        cout << "Nombre: " << jugador->nombre << endl;
        cout << "Vida:   " << jugador->vida << endl;
        cout << "Nivel:  " << jugador->nivel << endl;
    }

    // Liberar memoria
    destruirPersonaje(jugador);

    return 0;
}