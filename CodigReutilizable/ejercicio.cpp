#include <iostream>
using namespace std;

struct Producto {
    int id;
    char nombre[30];
    float precio;
    int stock;
};

// Se cambia float &cajaTotal por float* cajaTotal (PUNTERO)
void procesarVentaConPunteros(Producto* tienda, int cantidadProductos, int matrizVentas[3][5], float* cajaTotal) {
    int idProducto, dia, unidades;

    cout << "ID Producto (0-2): ";
    cin >> idProducto;
    cout << "Dia (0-4): ";
    cin >> dia;
    cout << "Cantidad: ";
    cin >> unidades;

    // Acceso a struct usando puntero: operador flecha (->) en lugar del punto (.)
    // (tienda + idProducto) avanza en memoria hasta el elemento seleccionado
    Producto* prodActual = tienda + idProducto; 

    if (unidades <= 0 || unidades > prodActual->stock) {
        cout << "[ERROR]: Stock insuficiente." << endl;
        return;
    }

    // Descuenta stock usando el puntero
    prodActual->stock -= unidades;

    // Registra en la matriz
    matrizVentas[idProducto][dia] += unidades;

    // Usamos el asterisco (*) para Modificar el VALOR donde apunta el puntero
    float totalVenta = unidades * prodActual->precio;
    *cajaTotal = *cajaTotal + totalVenta; 

    cout << "Venta registrada. Total: $" << totalVenta << endl;
}

int main() {
    Producto tienda[3] = {
        {0, "Gi BJJ Koral", 90.00f, 10},
        {1, "Rashguard Venum", 35.00f, 15},
        {2, "Guantes Hayabusa", 50.00f, 8}
    };

    int matrizVentas[3][5] = {0};
    float cajaTotal = 0.0f;

    // Para pasar la variable al puntero se le envía su DIRECCIÓN usando &
    procesarVentaConPunteros(tienda, 3, matrizVentas, &cajaTotal);

    cout << "Caja final: $" << cajaTotal << endl;

    return 0;
}