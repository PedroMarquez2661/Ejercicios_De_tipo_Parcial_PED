//Reemplaza a funciones estándar como strcpy o métodos de <string>. Muy común cuando en un parcial piden procesar cadenas sin usar librerías externas.


#include <iostream>
using namespace std;

// Función para copiar una cadena origen a un destino
void copiarCadena(const char origen[], char destino[]) {
    int i = 0;
    // Recorremos hasta encontrar el carácter nulo '\0' que marca el final de la cadena
    while (origen[i] != '\0') {
        destino[i] = origen[i];
        i++;
    }
    destino[i] = '\0'; // Es fundamental cerrar la cadena en el destino
}

// Función para obtener la longitud de una cadena char[] (reemplaza a strlen)
int obtenerLongitud(const char cadena[]) {
    int longitud = 0;
    while (cadena[longitud] != '\0') {
        longitud++;
    }
    return longitud;
}

int main() {
    char mensajeOriginal[] = "ExamenParcial";
    char copia[50]; // Buffer con suficiente espacio

    copiarCadena(mensajeOriginal, copia);

    cout << "Copia: " << copia << endl;
    cout << "Longitud: " << obtenerLongitud(copia) << endl;

    return 0;
}