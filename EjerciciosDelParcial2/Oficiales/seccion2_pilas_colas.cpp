// ============================================================================
// CASO PRÁCTICO #2 - SECCIÓN II: PILAS Y COLAS CON STL
// Ejercicios: 2.1 RemoveFromStack, 2.2 RotateQueue
// Compilar: g++ -std=c++17 -Wall -Wextra seccion2_pilas_colas.cpp -o seccion2
// ============================================================================

#include <iostream>  // Para std::cout (imprimir en pantalla).
#include <queue>     // Para std::queue (cola: primero en entrar, primero en salir).
#include <stack>     // Para std::stack (pila: último en entrar, primero en salir).

// ----------------------------------------------------------------------------
// EJERCICIO 2.1: Eliminar un valor de una pila
// ----------------------------------------------------------------------------
// Deja en 'tasks' todos los elementos menos los iguales a 'target', y conserva
// el orden relativo de los que quedan. 'tasks' va por referencia (&) porque la
// función debe modificar la pila ORIGINAL, no una copia.
void RemoveFromStack(std::stack<int>& tasks, int target) {
  std::stack<int> auxiliary;  // Pila auxiliar: guarda temporalmente los elementos que SÍ se conservan.

  // FASE 1: vaciar la pila original. Cada pop saca el elemento de arriba, así
  // que los elementos salen del más reciente al más antiguo.
  while (!tasks.empty()) {  // Mientras la pila original tenga elementos...
    int value = tasks.top();  // 'value' guarda el elemento de arriba (top solo lo mira, no lo saca).
    tasks.pop();              // Ahora sí lo sacamos de la pila original.

    if (value != target) {      // Si el elemento NO es el que queremos eliminar...
      auxiliary.push(value);    // ...lo guardamos en la auxiliar. Si es igual a 'target', simplemente se descarta.
    }                           // Fin de la decisión de conservar o descartar.
  }                             // Al salir, 'tasks' está vacía y 'auxiliary' tiene los elementos en orden INVERTIDO.

  // FASE 2 (la parte que completa el enunciado): devolver los elementos a la
  // pila original. Pasar de una pila a otra invierte el orden; como ya se
  // invirtió una vez en la fase 1, esta segunda inversión restaura el orden
  // original. Además, sin esta fase 'tasks' quedaría vacía y se perderían datos.
  while (!auxiliary.empty()) {  // Mientras la auxiliar tenga elementos...
    tasks.push(auxiliary.top());  // ...copiamos el de arriba de la auxiliar a la original...
    auxiliary.pop();              // ...y lo sacamos de la auxiliar.
  }                               // Al salir, 'tasks' tiene los elementos restantes en su orden original.
}  // Fin de RemoveFromStack.

// ----------------------------------------------------------------------------
// EJERCICIO 2.2: Rotar una cola
// ----------------------------------------------------------------------------
// Mueve los primeros 'k' elementos de la cola al final, conservando su orden.
// 'requests' va por referencia (&) porque se modifica la cola original.
void RotateQueue(std::queue<int>& requests, int k) {
  if (requests.empty() || k <= 0) {  // Cola vacía (no hay qué rotar) o k = 0 / negativo (no hay rotación)...
    return;                          // ...salimos sin hacer nada. Evita además dividir entre cero abajo.
  }                                  // Fin de los casos especiales.

  // Si k es mayor que el tamaño, dar vueltas completas no cambia nada: una
  // rotación de 7 en una cola de 5 equivale a 7 % 5 = 2 rotaciones.
  // static_cast<int> convierte size() (tipo sin signo) a int para evitar
  // mezclar tipos con y sin signo en la operación.
  int rotations = k % static_cast<int>(requests.size());  // 'rotations': cuántos elementos realmente hay que mover.

  for (int i = 0; i < rotations; ++i) {  // Repetimos 'rotations' veces; 'i' solo cuenta las vueltas.
    requests.push(requests.front());     // Copia el elemento del frente al final de la cola.
    requests.pop();                      // Quita el elemento del frente (ya está copiado al final).
  }                                      // Al salir, los primeros 'rotations' elementos pasaron al final en su orden.
}  // Fin de RotateQueue.

// ----------------------------------------------------------------------------
// FUNCIONES AUXILIARES PARA IMPRIMIR (no pedidas por el enunciado)
// ----------------------------------------------------------------------------

// Imprime la pila desde el tope hacia abajo (el orden en que saldrían con pop).
// 'tasks' va POR VALOR (sin &) a propósito: se trabaja con una COPIA, así la
// pila original no se destruye al vaciarla para imprimir.
void PrintStack(std::stack<int> tasks) {
  while (!tasks.empty()) {                // Mientras la copia tenga elementos...
    std::cout << tasks.top() << " ";      // ...imprimimos el de arriba...
    tasks.pop();                          // ...y lo sacamos para ver el siguiente.
  }                                       // Fin del vaciado de la copia.
  std::cout << '\n';                      // Salto de línea.
}  // Fin de PrintStack.

// Imprime la cola de frente a final. También recibe una COPIA (por valor) para
// no destruir la cola original.
void PrintQueue(std::queue<int> requests) {
  while (!requests.empty()) {             // Mientras la copia tenga elementos...
    std::cout << requests.front() << " "; // ...imprimimos el del frente...
    requests.pop();                       // ...y lo sacamos para ver el siguiente.
  }                                       // Fin del vaciado de la copia.
  std::cout << '\n';                      // Salto de línea.
}  // Fin de PrintQueue.

// ----------------------------------------------------------------------------
// PROGRAMA PRINCIPAL: pruebas
// ----------------------------------------------------------------------------
int main() {
  // ---------------- Prueba 2.1 ----------------
  std::cout << "=== Ejercicio 2.1: RemoveFromStack ===\n";  // Título.
  std::stack<int> tasks;  // Pila de tareas (enteros) para probar.
  tasks.push(10);         // Fondo de la pila.
  tasks.push(20);         // Se eliminará.
  tasks.push(30);         // Se conserva.
  tasks.push(20);         // Se eliminará (segunda aparición).
  tasks.push(40);         // Tope de la pila.

  std::cout << "Antes (tope -> fondo): ";  // Etiqueta.
  PrintStack(tasks);                       // Esperado: 40 20 30 20 10

  RemoveFromStack(tasks, 20);  // Eliminamos todas las apariciones de 20.

  std::cout << "Despues (tope -> fondo): ";  // Etiqueta.
  PrintStack(tasks);                         // Esperado: 40 30 10

  // ---------------- Prueba 2.2 ----------------
  std::cout << "\n=== Ejercicio 2.2: RotateQueue ===\n";  // Título.
  std::queue<int> requests;  // Cola de solicitudes (enteros) para probar.
  requests.push(10);         // Frente de la cola.
  requests.push(20);
  requests.push(30);
  requests.push(40);
  requests.push(50);         // Final de la cola.

  std::cout << "Antes (frente -> final): ";  // Etiqueta.
  PrintQueue(requests);                      // Esperado: 10 20 30 40 50

  RotateQueue(requests, 2);  // Rotamos 2 posiciones.

  std::cout << "Despues de k=2: ";  // Etiqueta.
  PrintQueue(requests);             // Esperado: 30 40 50 10 20
  std::cout << "Elemento al frente: " << requests.front() << '\n';  // Esperado: 30 (antes estaba en la posición 3).

  RotateQueue(requests, 0);  // Caso borde: k = 0, no debe cambiar nada.
  std::cout << "Despues de k=0: ";  // Etiqueta.
  PrintQueue(requests);             // Esperado: 30 40 50 10 20

  std::queue<int> big_k;  // Cola para probar k mayor que el tamaño.
  for (int value = 1; value <= 5; ++value) {  // 'value' toma 1, 2, 3, 4, 5.
    big_k.push(value);                        // Llenamos la cola: 1 2 3 4 5.
  }                                           // Fin del llenado.
  RotateQueue(big_k, 7);  // 7 % 5 = 2 rotaciones.
  std::cout << "k=7 en cola de 5: ";  // Etiqueta.
  PrintQueue(big_k);                  // Esperado: 3 4 5 1 2

  std::queue<int> empty_queue;  // Caso borde: cola vacía.
  RotateQueue(empty_queue, 3);  // No debe fallar.
  std::cout << "Cola vacia sigue vacia? " << (empty_queue.empty() ? "si" : "no") << '\n';  // Esperado: si.

  return 0;  // Fin del programa sin errores.
}  // Fin de main.
