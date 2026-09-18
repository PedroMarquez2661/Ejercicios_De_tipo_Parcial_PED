#include <iostream>
using namespace std;

// ============================================================================
// 1. DEFINICIÓN DE ESTRUCTURAS (struct)
// Define la plantilla de datos para los objetos que venderá la tienda.
// Debe ir al inicio para que el resto del programa reconozca el tipo 'producto'.
// ============================================================================
struct producto
{
    string nombre; // Nombre del producto deportivo (ej. Gi, Rash Guard)
    float precio;  // Precio unitario del producto
    int stock;     // Cantidad disponible en el inventario
};

// ============================================================================
// 2. PROTOTIPOS DE FUNCIONES (Declaraciones)
// Le anuncian al compilador qué funciones existiran más adelante.
// Permiten llamar a las funciones dentro del main() antes de desarrollarlas.
// ============================================================================

// Muestra las opciones del sistema en pantalla
void mostrarMenu();

// Imprime el nombre y el stock actual de cada producto
void mostrarInvetario(producto inventario[], int cantidad);

// Registra la venta de un producto en un día específico de la semana
void registrarVentas(int matrizVentas[3][5], producto inventario[]);

// Muestra la matriz de ventas semanal (3 Productos x 5 Días)
void mostrarReporteSemanal(int matrizVentas[3][5], producto inventario[]);


// ============================================================================
// 3. FUNCIÓN PRINCIPAL (Punto de entrada del programa)
// ============================================================================
int main() {

    // ------------------------------------------------------------------------
    // CREACIÓN Y CARGA DE DATOS EN MEMORIA
    // ------------------------------------------------------------------------

    // Arreglo unidimensional de structs para almacenar 3 productos
    producto tienda[3];

    // Asignación de valores al producto 0
    tienda[0].nombre = "GI DE BJJ";       
    tienda[0].precio = 88.99; 
    tienda[0].stock = 15;

    // Asignación de valores al producto 1
    tienda[1].nombre = "Rash Guard MMA";  
    tienda[1].precio = 35.50; 
    tienda[1].stock = 25;

    // Asignación de valores al producto 2
    tienda[2].nombre = "Guantes de Boxeo";
    tienda[2].precio = 45.00; 
    tienda[2].stock = 20;

    // Arreglo bidimensional (Matriz de 3 filas x 5 columnas)
    // Filas (0 a 2) -> Representan los 3 Productos
    // Columnas (0 a 4) -> Representan los días (Lunes a Viernes)
    // Se inicializa en 0 porque al inicio no hay ventas registradas.
    int VentaSemanales[3][5] = {
        {0, 0, 0, 0, 0}, // Ventas iniciales para GI DE BJJ
        {0, 0, 0, 0, 0}, // Ventas iniciales para Rash Guard MMA
        {0, 0, 0, 0, 0}  // Ventas iniciales para Guantes de Boxeo
    };

    int opcion = 0; // Variable para almacenar la opción del menú elegida por el usuario

    // ------------------------------------------------------------------------
    // BUCLE PRINCIPAL (Mantiene activo el sistema hasta seleccionar la opción 4)
    // ------------------------------------------------------------------------
    while (opcion != 4) {
        
        // 1. Llama a la función que imprime el menú visual
        mostrarMenu();
        
        // 2. Solicita la opción al usuario
        cout << "Seleccionar una opcion: ";
        cin >> opcion;
        cout << endl;

        // 3. Evalúa la opción seleccionada y ejecuta la función correspondiente
        switch (opcion)
        {
        case 1:
            // Muestra los productos y sus existencias
            mostrarInvetario(tienda, 3);
            break;

        case 2:
            // Registra una nueva venta restando del stock y sumando a la matriz
            registrarVentas(VentaSemanales, tienda);
            break;

        case 3:
            // Muestra la tabla (matriz) con el acumulado de ventas de la semana
            mostrarReporteSemanal(VentaSemanales, tienda);
            break;

        case 4:
            // Opción de salida: rompe el bucle al cumplirse la condición del while
            cout << "GRACIAS POR USAR EL PROGRAMA" << endl;
            break;

        default:
            // Mensaje de error para opciones fuera del rango (1-4)
            cout << "Opcion no valida." << endl;
            break;
        }
        cout << endl; // Salto de línea decorativo
    }

    return 0; // Finaliza la ejecución de la función main con éxito
}


// ============================================================================
// 4. DESARROLLO DE FUNCIONES VOID (Implementación de la lógica)
// ============================================================================

/*
 * Función: mostrarMenu
 * Propósito: Imprimir la interfaz del menú principal en la consola.
 * No recibe parámetros ni devuelve ningún valor.
 */
void mostrarMenu() {
    cout << "========================================" << endl;
    cout << "     FIGHT ZONE STORE - SISTEMA UI      " << endl;
    cout << "========================================" << endl;
    cout << "1. Ver inventario de productos" << endl;
    cout << "2. Registrar ventas del dia" << endl;
    cout << "3. Ver reporte semanal de ventas (Matriz)" << endl;
    cout << "4. Salir" << endl;
    cout << "========================================" << endl;
}

/*
 * Función: mostrarInvetario
 * Parámetros: 
 *   - inventario[]: Arreglo de estructuras producto.
 *   - cantidad: Cantidad total de elementos a recorrer en el arreglo.
 * Propósito: Recorrer el arreglo e imprimir el estado del stock de cada ítem.
 */
void mostrarInvetario(producto inventario[], int cantidad) {
    cout << "--------INVENTARIO ACTUAL------" << endl;
    for (int i = 0; i < cantidad; i++)
    {
        // Se accede a las variables miembro de la struct mediante el operador punto (.)
        cout << "ID [ " << i << " ] " << inventario[i].nombre << " | stock: " << inventario[i].stock << endl;
    }
}

/*
 * Función: registrarVentas
 * Parámetros:
 *   - matrizVentas[][5]: Matriz donde se guardan las unidades vendidas.
 *   - inventario[]: Arreglo de productos para verificar y descontar stock.
 * Propósito: Pedir datos de venta, validarlos y actualizar tanto la matriz como el struct.
 */
void registrarVentas(int matrizVentas[3][5], producto inventario[]) {
    int id, dia, cant;

    // Entrada de datos
    cout << "INGRESA EL ID DEL PRODUCTO (0-2): "; cin >> id;
    cout << "INGRESA EL DIA: (0:Lun, 1:Mar, 2:Mie, 3:Jue, 4:Vie): "; cin >> dia;
    cout << "CANTIDAD DE LA VENTA: "; cin >> cant;

    // Validación de límites: 
    // - ID debe ser entre 0 y 2
    // - Día debe ser entre 0 y 4
    // - Cantidad debe ser menor o igual al stock disponible
    if (id >= 0 && id < 3 && dia >= 0 && dia < 5 && cant <= inventario[id].stock)
    {
        // Suma las unidades vendidas a la posición exacta de la matriz
        matrizVentas[id][dia] += cant;

        // Descuenta las unidades del inventario (struct)
        inventario[id].stock -= cant;

        cout << "VENTA REGISTRADA CON EXITO." << endl;
    } else {
        // Se ejecuta si alguna coordenada no existe o si no hay suficiente stock
        cout << "ERROR EN LOS DATOS INGRESADOS O STOCK INSUFICIENTE" << endl;
    }
}

/*
 * Función: mostrarReporteSemanal
 * Parámetros:
 *   - matrizVentas[][5]: Matriz con el conteo de ventas.
 *   - inventario[]: Arreglo para obtener los nombres de los productos.
 * Propósito: Imprimir una tabla de 2 dimensiones relacionando productos y ventas diarias.
 */
void mostrarReporteSemanal(int matrizVentas[3][5], producto inventario[]) {
    cout << "--- MATRIZ DE VENTAS ---" << endl;

    // Bucle externo: Recorre las filas (Productos)
    for (int i = 0; i < 3; i++) {
        // Imprime el nombre del producto y aplica un tabulador '\t' para alinear
        cout << inventario[i].nombre << "\t";

        // Bucle interno: Recorre las columnas (Días de la semana)
        for (int j = 0; j < 5; j++) {
            // Imprime las ventas de ese producto en ese día específico
            cout << matrizVentas[i][j] << " ";
        }
        cout << endl; // Salto de línea para pasar al siguiente producto (siguiente fila)
    }
}