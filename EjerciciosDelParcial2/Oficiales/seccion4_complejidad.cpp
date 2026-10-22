// ============================================================================
// CASO PRÁCTICO #2 - SECCIÓN IV: ANÁLISIS DE COMPLEJIDAD
// Ejercicios: 4.1 CountGreater (O(n)), 4.2 CountPairs (O(n^2))
// Compilar: g++ -std=c++17 -Wall -Wextra seccion4_complejidad.cpp -o seccion4
// En esta sección el enunciado NO pide ejecutar nada; aquí se ejecuta solo para
// COMPROBAR el análisis. Cada línea indica su costo: O(1) = constante.
// ============================================================================

#include <iostream>  // Para std::cout (imprimir en pantalla).
#include <vector>    // Para std::vector (arreglo dinámico).

// ----------------------------------------------------------------------------
// EJERCICIO 4.1: Conteo de elementos  -> complejidad O(n)
// ----------------------------------------------------------------------------
int CountGreater(const std::vector<int>& values, int target) {
  int count = 0;  // O(1): crea el contador; no depende del tamaño del vector.
  int size = static_cast<int>(values.size());  // O(1): size() del vector es constante; lo guardamos en 'size' para reutilizarlo.

  for (int i = 0; i < size; ++i) {  // Ciclo principal: se ejecuta 'size' (= n) veces. ESTE ciclo determina el crecimiento del tiempo.
    if (values[i] > target) {       // O(1) por vuelta: acceso por índice + una comparación.
      ++count;                      // O(1) por vuelta: incrementa el contador.
    }                               // Fin del if.
  }                                 // Total del ciclo: n vueltas x O(1) = O(n).

  int last_value = size > 0 ? values[size - 1] : 0;  // O(1): toma el último elemento (o 0 si el vector está vacío, para no acceder fuera de rango).

  if (last_value > target) {  // O(1): una comparación.
    ++count;                  // O(1): OJO, este incremento cuenta el último elemento POR SEGUNDA VEZ (el ciclo ya lo había contado).
  }                           // Fin del if.

  return count;  // O(1): devolver el resultado.
}  // Total = O(n) + O(1) + O(1) = O(n). Si n se duplica, el ciclo hace el doble de trabajo.

// Función EXTRA (no pedida): versión corregida que no cuenta dos veces el último elemento.
int CountGreaterCorrected(const std::vector<int>& values, int target) {
  int count = 0;  // Contador de elementos mayores que 'target'.
  for (int value : values) {  // Recorre cada elemento; 'value' es una copia del elemento actual.
    if (value > target) {     // Si es mayor que 'target'...
      ++count;                // ...lo contamos una sola vez.
    }                         // Fin del if.
  }                           // Fin del recorrido: O(n).
  return count;  // Devolvemos el total correcto.
}  // Fin de CountGreaterCorrected.

// ----------------------------------------------------------------------------
// EJERCICIO 4.2: Comparación de pares  -> complejidad O(n^2)
// ----------------------------------------------------------------------------
int CountPairs(const std::vector<int>& values) {
  int count = 0;  // O(1): cuenta los pares (i, j) con valores iguales.
  int size = static_cast<int>(values.size());  // O(1): tamaño n del vector.

  for (int i = 0; i < size; ++i) {          // Ciclo EXTERNO: fija el primer elemento del par; da n vueltas.
    for (int j = i + 1; j < size; ++j) {    // Ciclo INTERNO: recorre solo los elementos POSTERIORES a 'i' (j > i), así cada par se revisa una sola vez.
      if (values[i] == values[j]) {         // O(1): una comparación entre elementos.
        ++count;                            // O(1): encontramos un par igual.
      }                                     // Fin del if.
    }                                       // El interno hace (n - 1 - i) vueltas: depende de 'i', por eso NO basta mirar solo el externo.
  }                                         // Fin del ciclo externo.

  return count;  // O(1): devolver el resultado.
}  // Comparaciones totales: (n-1) + (n-2) + ... + 1 + 0 = n(n-1)/2  ->  O(n^2).

// Función EXTRA (no pedida): igual que CountPairs pero cuenta cuántas comparaciones
// se hacen, para verificar la fórmula n(n-1)/2.
int CountPairsWithComparisons(const std::vector<int>& values, long long& comparisons) {
  int count = 0;         // Cantidad de pares iguales.
  comparisons = 0;       // Reiniciamos el contador de comparaciones (se devuelve por referencia).
  int size = static_cast<int>(values.size());  // Tamaño n.

  for (int i = 0; i < size; ++i) {        // Ciclo externo.
    for (int j = i + 1; j < size; ++j) {  // Ciclo interno.
      ++comparisons;                      // Cada vuelta del interno es exactamente una comparación entre elementos.
      if (values[i] == values[j]) {       // Comparación real.
        ++count;                          // Par igual encontrado.
      }                                   // Fin del if.
    }                                     // Fin del interno.
  }                                       // Fin del externo.

  return count;  // Pares iguales encontrados.
}  // Fin de CountPairsWithComparisons.

// ----------------------------------------------------------------------------
// PROGRAMA PRINCIPAL: comprobaciones del análisis
// ----------------------------------------------------------------------------
int main() {
  // ---------------- 4.1 ----------------
  std::cout << "=== Ejercicio 4.1: CountGreater ===\n";  // Título.
  std::vector<int> values = {1, 5, 9};  // Vector de prueba; hay 2 elementos mayores que 4 (5 y 9).
  std::cout << "CountGreater (original, target=4): " << CountGreater(values, 4) << '\n';  // Da 3: cuenta el 9 dos veces (error lógico).
  std::cout << "CountGreaterCorrected (target=4):  " << CountGreaterCorrected(values, 4) << '\n';  // Da 2: resultado correcto.

  // ---------------- 4.2 ----------------
  std::cout << "\n=== Ejercicio 4.2: CountPairs ===\n";  // Título.
  std::vector<int> repeated = {3, 1, 3, 3, 2};  // El 3 aparece 3 veces -> 3 pares iguales: (0,2), (0,3), (2,3).
  std::cout << "Pares iguales: " << CountPairs(repeated) << '\n';  // Esperado: 3.

  // Comprobamos que las comparaciones son n(n-1)/2 y que se cuadruplican al duplicar n.
  int sizes[] = {10, 20, 40, 80};  // Tamaños de prueba; cada uno es el doble del anterior.
  for (int n : sizes) {            // 'n' toma cada tamaño de la lista anterior.
    std::vector<int> data(n, 0);   // Vector de n ceros (todos iguales, no importa el contenido para contar comparaciones).
    long long comparisons = 0;     // Aquí se guardará el número de comparaciones realizadas.
    CountPairsWithComparisons(data, comparisons);  // Ejecutamos y contamos.
    std::cout << "n = " << n << " -> comparaciones = " << comparisons
              << " (formula n(n-1)/2 = " << static_cast<long long>(n) * (n - 1) / 2 << ")\n";  // Real y teórico deben coincidir.
  }                                // Fin del ciclo de tamaños: se observa que al duplicar n, las comparaciones se multiplican ~4.

  return 0;  // Fin del programa sin errores.
}  // Fin de main.
