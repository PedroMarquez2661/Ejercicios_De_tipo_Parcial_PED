// ============================================================================
// CASO PRÁCTICO #2 - SECCIÓN III: ORDENAMIENTO Y BÚSQUEDA
// Ejercicios: 3.1 InsertionSort por segmento, 3.2 BinarySearch (primera aparición)
// Compilar: g++ -std=c++17 -Wall -Wextra seccion3_ordenamiento_busqueda.cpp -o seccion3
// ============================================================================

#include <iostream>  // Para std::cout (imprimir en pantalla).

// ----------------------------------------------------------------------------
// EJERCICIO 3.1: Ordenar únicamente un segmento
// ----------------------------------------------------------------------------
// Ordena de forma ascendente SOLO values[start..end] (ambos incluidos).
// Los elementos fuera del segmento no se tocan.
// Cambios respecto al insertion sort original:
//   1) Se agregan los parámetros 'start' y 'end'.
//   2) El ciclo externo empieza en start + 1 (antes: 1) y termina en end (antes: size - 1).
//   3) El ciclo interno se detiene en start (antes: 0).
//   4) Se validan los índices al inicio.
void InsertionSort(int values[], int size, int start, int end) {
  if (values == nullptr || start < 0 || end >= size || start > end) {  // Índices inválidos: arreglo nulo, start negativo, end fuera del arreglo o segmento al revés...
    return;                                                            // ...no hacemos nada para no leer/escribir fuera de los límites.
  }                                                                    // Fin de la validación.

  // 'i' es el índice del elemento que vamos a insertar en la parte ya ordenada.
  // Empieza en start + 1 porque values[start] por sí solo ya es un segmento
  // ordenado de un elemento. Si empezáramos en 1, tocaríamos elementos fuera
  // del segmento (índices menores que start).
  for (int i = start + 1; i <= end; ++i) {
    int key = values[i];  // 'key' guarda el valor a insertar; se guarda porque el desplazamiento lo sobrescribe.
    int j = i - 1;        // 'j' recorre hacia la izquierda la parte ya ordenada del segmento.

    // Desplazamos a la derecha los elementos mayores que 'key'. La condición
    // j >= start (y no j >= 0) impide salirnos del segmento por la izquierda.
    while (j >= start && values[j] > key) {  // Mientras 'j' esté dentro del segmento y el elemento sea mayor que 'key'...
      values[j + 1] = values[j];             // ...lo corremos una posición a la derecha (abre un hueco para 'key').
      --j;                                   // ...y seguimos comparando con el elemento anterior.
    }                                        // Al salir, values[j + 1] es el hueco donde va 'key'.

    values[j + 1] = key;  // Colocamos 'key' en su posición correcta dentro de la parte ordenada.
  }                       // Fin del ciclo externo: el segmento queda ordenado.
}  // Fin de InsertionSort.

// ----------------------------------------------------------------------------
// EJERCICIO 3.2: Búsqueda binaria de la primera aparición (arreglo DESCENDENTE)
// ----------------------------------------------------------------------------
// Retorna el índice de la primera aparición de 'target' o -1 si no existe.
// 'values' es const porque la búsqueda no debe modificar el arreglo.
int BinarySearch(const int values[], int size, int target) {
  int left = 0;          // Límite izquierdo de la zona donde aún buscamos.
  int right = size - 1;  // Límite derecho de la zona donde aún buscamos.
  int result = -1;       // Mejor respuesta encontrada hasta ahora; -1 significa "todavía no aparece".

  while (left <= right) {  // Mientras quede al menos un elemento por revisar...
    int mid = left + (right - left) / 2;  // Índice central; esta forma evita desbordamiento de enteros en arreglos enormes.

    if (values[mid] == target) {  // Si el elemento central es el buscado...
      result = mid;               // ...lo guardamos como candidato (puede que no sea la primera aparición).
      right = mid - 1;            // ...y seguimos buscando A LA IZQUIERDA por si hay una aparición anterior.
    } else if (values[mid] < target) {  // Si el central es MENOR que 'target'...
      right = mid - 1;                  // ...en orden descendente, lo buscado está a la IZQUIERDA (valores mayores).
    } else {                            // Si el central es MAYOR que 'target'...
      left = mid + 1;                   // ...lo buscado está a la DERECHA (valores menores).
    }                                   // Fin de las tres decisiones.
  }                                     // Fin del ciclo: la zona de búsqueda se agotó.

  return result;  // Índice de la primera aparición, o -1 si nunca se encontró.
}  // Fin de BinarySearch.

// ----------------------------------------------------------------------------
// FUNCIÓN AUXILIAR (no pedida): imprimir un arreglo
// ----------------------------------------------------------------------------
void PrintArray(const int values[], int size) {
  for (int i = 0; i < size; ++i) {      // 'i' recorre cada posición del arreglo.
    std::cout << values[i] << " ";      // Imprimimos el valor seguido de un espacio.
  }                                     // Fin del recorrido.
  std::cout << '\n';                    // Salto de línea.
}  // Fin de PrintArray.

// ----------------------------------------------------------------------------
// PROGRAMA PRINCIPAL: pruebas
// ----------------------------------------------------------------------------
int main() {
  // ---------------- Prueba 3.1 ----------------
  std::cout << "=== Ejercicio 3.1: InsertionSort por segmento ===\n";  // Título.
  int values[] = {9, 7, 5, 4, 3, 8, 1, 6};  // Arreglo de prueba (8 elementos).

  std::cout << "Antes:   ";       // Etiqueta.
  PrintArray(values, 8);          // Esperado: 9 7 5 4 3 8 1 6

  InsertionSort(values, 8, 2, 5);  // Ordenamos solo los índices 2 a 5 (valores 5 4 3 8).

  std::cout << "Despues: ";       // Etiqueta.
  PrintArray(values, 8);          // Esperado: 9 7 3 4 5 8 1 6

  int invalid[] = {3, 2, 1};       // Arreglo para probar índices inválidos.
  InsertionSort(invalid, 3, -1, 2);  // start negativo: debe ignorarse.
  InsertionSort(invalid, 3, 0, 5);   // end fuera del arreglo: debe ignorarse.
  InsertionSort(invalid, 3, 2, 0);   // start > end: debe ignorarse.
  std::cout << "Indices invalidos (sin cambios): ";  // Etiqueta.
  PrintArray(invalid, 3);                            // Esperado: 3 2 1

  // ---------------- Prueba 3.2 ----------------
  std::cout << "\n=== Ejercicio 3.2: BinarySearch primera aparicion ===\n";  // Título.
  int sorted_desc[] = {9, 7, 7, 7, 5, 3, 1};  // Arreglo ordenado DESCENDENTE con repetidos.
  int size = 7;                               // Cantidad de elementos de 'sorted_desc'.

  std::cout << "Buscar 7 -> " << BinarySearch(sorted_desc, size, 7) << '\n';  // Esperado: 1 (no 2 ni 3).
  std::cout << "Buscar 4 -> " << BinarySearch(sorted_desc, size, 4) << '\n';  // Esperado: -1 (no existe).
  std::cout << "Buscar 9 -> " << BinarySearch(sorted_desc, size, 9) << '\n';  // Esperado: 0 (primer elemento).
  std::cout << "Buscar 1 -> " << BinarySearch(sorted_desc, size, 1) << '\n';  // Esperado: 6 (último elemento).

  return 0;  // Fin del programa sin errores.
}  // Fin de main.
