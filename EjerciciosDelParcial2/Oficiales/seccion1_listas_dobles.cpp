// ============================================================================
// CASO PRÁCTICO #2 - SECCIÓN I: LISTAS DOBLEMENTE ENLAZADAS
// Ejercicios: 1.1 InsertAfter, 1.2 SplitByPosition, 1.3 MoveLastToFront
// Compilar: g++ -std=c++17 -Wall -Wextra seccion1_listas_dobles.cpp -o seccion1
// ============================================================================

#include <iostream>  // Necesaria para std::cout (imprimir en pantalla).

// ----------------------------------------------------------------------------
// ESTRUCTURA BASE (proporcionada por el enunciado, no se modifica)
// ----------------------------------------------------------------------------
struct Node {  // Un nodo de la lista doblemente enlazada.
  int data;    // Valor entero que guarda este nodo.
  Node* next;  // Puntero al nodo siguiente (nullptr si es el último).
  Node* prev;  // Puntero al nodo anterior (nullptr si es el primero).
};  // Fin de la estructura Node.

// ----------------------------------------------------------------------------
// FUNCIONES BASE (proporcionadas por el enunciado)
// ----------------------------------------------------------------------------

// Agrega un valor al final de la lista. 'head' va por referencia (Node*&)
// porque si la lista está vacía, 'head' mismo debe cambiar.
void Append(Node*& head, int value) {
  Node* new_node = new Node{value, nullptr, nullptr};  // Crea el nodo: data=value, next=nullptr, prev=nullptr.

  if (head == nullptr) {  // Si la lista está vacía...
    head = new_node;      // ...el nodo nuevo es el primer (y único) nodo.
    return;               // Terminamos: no hay nada más que enlazar.
  }                       // Fin del caso "lista vacía".

  Node* current = head;  // 'current' recorre la lista; empieza en el primer nodo.

  while (current->next != nullptr) {  // Mientras el nodo actual tenga siguiente...
    current = current->next;          // ...avanzamos un nodo. Al salir, 'current' es el último.
  }                                   // Fin del recorrido.

  current->next = new_node;  // El último nodo ahora apunta hacia adelante al nodo nuevo.
  new_node->prev = current;  // El nodo nuevo apunta hacia atrás al antiguo último (enlace doble).
}  // Fin de Append.

// Imprime la lista de principio a fin siguiendo los punteros 'next'.
void PrintForward(Node* head) {
  Node* current = head;  // 'current' recorre la lista; empieza en el primer nodo.

  while (current != nullptr) {          // Mientras no hayamos pasado del último nodo...
    std::cout << current->data << " ";  // ...imprimimos el valor del nodo actual.
    current = current->next;            // ...y avanzamos al siguiente.
  }                                     // Fin del recorrido.

  std::cout << '\n';  // Salto de línea al terminar de imprimir.
}  // Fin de PrintForward.

// Imprime la lista de fin a principio siguiendo los punteros 'prev'.
// Sirve para comprobar que los enlaces 'prev' quedaron correctos.
void PrintBackward(Node* head) {
  if (head == nullptr) {  // Si la lista está vacía...
    return;               // ...no hay nada que imprimir.
  }                       // Fin del caso "lista vacía".

  Node* current = head;  // 'current' empieza en el primer nodo.

  while (current->next != nullptr) {  // Primero viajamos hasta el último nodo (usando 'next').
    current = current->next;          // Avanzamos un nodo.
  }                                   // Al salir, 'current' es el último nodo.

  while (current != nullptr) {          // Ahora retrocedemos hasta pasar del primer nodo...
    std::cout << current->data << " ";  // ...imprimiendo el valor de cada nodo.
    current = current->prev;            // Retrocedemos con 'prev'. Si algún 'prev' está mal, aquí se nota.
  }                                     // Fin del retroceso.

  std::cout << '\n';  // Salto de línea al terminar.
}  // Fin de PrintBackward.

// Función AUXILIAR (no pedida): libera la memoria de todos los nodos para
// no dejar fugas de memoria al final de cada prueba.
void FreeList(Node*& head) {
  while (head != nullptr) {      // Mientras queden nodos...
    Node* to_delete = head;      // Guardamos el nodo actual, porque 'head' va a avanzar.
    head = head->next;           // 'head' pasa al siguiente nodo (si no, perderíamos la lista).
    delete to_delete;            // Liberamos la memoria del nodo guardado.
  }                              // Al terminar, 'head' vale nullptr (lista vacía).
}  // Fin de FreeList.

// ----------------------------------------------------------------------------
// EJERCICIO 1.1: Insertar después de un valor
// ----------------------------------------------------------------------------
// Inserta un nodo con 'value' justo después de la PRIMERA aparición de 'target'.
// Retorna true si lo insertó; false si 'target' no existe (lista sin cambios).
// 'head' va por valor porque la inserción nunca cambia cuál es el primer nodo.
bool InsertAfter(Node* head, int target, int value) {
  Node* current = head;  // 'current' recorre la lista buscando 'target'; empieza en el primer nodo.

  while (current != nullptr && current->data != target) {  // Mientras no lleguemos al final y no encontremos 'target'...
    current = current->next;                               // ...avanzamos al siguiente nodo.
  }                                                        // Al salir: 'current' es el nodo con 'target', o nullptr si no existe.

  if (current == nullptr) {  // Si llegamos al final sin encontrar 'target'...
    return false;            // ...no modificamos nada y avisamos con false.
  }                          // Fin del caso "no existe".

  // Creamos el nodo nuevo ya enlazado: su 'next' será el que seguía a 'current'
  // y su 'prev' será 'current'. Así el nodo nace con sus dos punteros correctos.
  Node* new_node = new Node{value, current->next, current};

  if (current->next != nullptr) {      // Si 'current' NO era el último nodo...
    current->next->prev = new_node;    // ...el nodo que seguía debe apuntar atrás al nuevo (arregla su 'prev').
  }                                    // Si era el último, no hay nodo siguiente que actualizar.

  current->next = new_node;  // Finalmente 'current' apunta adelante al nodo nuevo (arregla su 'next').
  return true;               // Inserción exitosa.
}  // Fin de InsertAfter.

// ----------------------------------------------------------------------------
// EJERCICIO 1.2: Separar una lista por posición (pares / impares)
// ----------------------------------------------------------------------------
// Reparte los nodos de 'head' en dos listas según su posición original
// (0, 1, 2, ...): posiciones pares -> even_head, impares -> odd_head.
// Reutiliza los mismos nodos (no crea nodos ni copia valores). Al final
// 'head' queda en nullptr. Se asume que even_head y odd_head llegan en nullptr.
void SplitByPosition(Node*& head, Node*& even_head, Node*& odd_head) {
  Node* even_tail = nullptr;  // Último nodo de la lista par; permite agregar al final en O(1) sin recorrer.
  Node* odd_tail = nullptr;   // Último nodo de la lista impar; misma razón.
  Node* current = head;       // Nodo que estamos procesando; empieza en el primero de la lista original.
  int position = 0;           // Posición original del nodo actual (0, 1, 2...) para decidir par o impar.

  head = nullptr;  // La lista original queda vacía al terminar (requisito); ya guardamos el inicio en 'current'.

  while (current != nullptr) {  // Procesamos cada nodo exactamente una vez: complejidad O(n).
    Node* next_node = current->next;  // GUARDAR el siguiente ANTES de cambiar current->next; si no, perdemos el resto de la lista.
    current->next = nullptr;          // Desconectamos el nodo de su vecino de adelante.
    current->prev = nullptr;          // Desconectamos el nodo de su vecino de atrás.

    // Elegimos a qué lista pertenece este nodo. Son REFERENCIAS (Node*&), así
    // que modificar 'target_head' / 'target_tail' modifica la lista real elegida.
    Node*& target_head = (position % 2 == 0) ? even_head : odd_head;  // Cabeza de la lista destino (par o impar).
    Node*& target_tail = (position % 2 == 0) ? even_tail : odd_tail;  // Cola de la lista destino (par o impar).

    if (target_head == nullptr) {    // Si la lista destino aún está vacía...
      target_head = current;         // ...este nodo es su primer nodo.
    } else {                         // Si ya tiene nodos...
      target_tail->next = current;   // ...el último nodo apunta adelante a este nodo.
      current->prev = target_tail;   // ...y este nodo apunta atrás al último (si olvidamos esto, falla PrintBackward).
    }                                // Fin de agregar el nodo a la lista destino.

    target_tail = current;   // Este nodo es ahora el último de la lista destino.
    current = next_node;     // Pasamos al nodo siguiente de la lista ORIGINAL (el que guardamos).
    ++position;              // La siguiente posición alterna entre par e impar.
  }                          // Fin del recorrido de la lista original.
}  // Fin de SplitByPosition.

// ----------------------------------------------------------------------------
// EJERCICIO 1.3: Mover el último nodo al inicio
// ----------------------------------------------------------------------------
// Mueve el último nodo al frente sin crear ni borrar nodos ni copiar valores.
// 'head' va por referencia porque el primer nodo de la lista CAMBIA.
void MoveLastToFront(Node*& head) {
  if (head == nullptr || head->next == nullptr) {  // Lista vacía (nada que mover) o de un solo nodo (ya está al inicio)...
    return;                                        // ...no hay que hacer nada.
  }                                                // Fin de los casos especiales.

  Node* last = head;  // 'last' buscará el último nodo; empieza en el primero.

  while (last->next != nullptr) {  // Mientras 'last' tenga siguiente...
    last = last->next;             // ...avanzamos. Al salir, 'last' es el último nodo.
  }                                // Fin de la búsqueda del último.

  last->prev->next = nullptr;  // El penúltimo pasa a ser el último (su 'next' = nullptr). Esto evita crear un ciclo.
  last->prev = nullptr;        // El nodo que irá al frente no tiene anterior.
  last->next = head;           // El nodo que irá al frente apunta adelante al antiguo primero.
  head->prev = last;           // El antiguo primero apunta atrás al nodo movido (enlace doble completo).
  head = last;                 // Actualizamos 'head': el nodo movido es ahora el primero de la lista.
}  // Fin de MoveLastToFront.

// ----------------------------------------------------------------------------
// PROGRAMA PRINCIPAL: pruebas de los tres ejercicios
// ----------------------------------------------------------------------------
int main() {
  // ---------------- Prueba 1.1 ----------------
  std::cout << "=== Ejercicio 1.1: InsertAfter ===\n";  // Título de la prueba.
  Node* head = nullptr;  // Lista inicial vacía.
  Append(head, 10);      // Lista: 10
  Append(head, 20);      // Lista: 10 20
  Append(head, 30);      // Lista: 10 20 30
  Append(head, 40);      // Lista: 10 20 30 40
  Append(head, 50);      // Lista: 10 20 30 40 50

  bool inserted = InsertAfter(head, 20, 25);  // 'inserted' guarda si se pudo insertar 25 después de 20.
  std::cout << "Insertar 25 despues de 20 -> " << (inserted ? "true" : "false") << '\n';  // Esperado: true.
  PrintForward(head);   // Esperado: 10 20 25 30 40 50
  PrintBackward(head);  // Esperado: 50 40 30 25 20 10 (verifica los 'prev').

  bool not_inserted = InsertAfter(head, 99, 1);  // 99 no existe, debe retornar false.
  std::cout << "Insertar 1 despues de 99 -> " << (not_inserted ? "true" : "false") << '\n';  // Esperado: false.
  PrintForward(head);  // Esperado: la lista no cambió.

  InsertAfter(head, 50, 60);  // Caso borde: insertar después del ÚLTIMO nodo.
  PrintForward(head);         // Esperado: 10 20 25 30 40 50 60
  PrintBackward(head);        // Esperado: 60 50 40 30 25 20 10
  FreeList(head);             // Liberamos la memoria de la lista.

  // ---------------- Prueba 1.2 ----------------
  std::cout << "\n=== Ejercicio 1.2: SplitByPosition ===\n";  // Título de la prueba.
  Node* list = nullptr;       // Lista original (la llamamos 'list' para no mezclarla con 'head' anterior).
  Node* even_head = nullptr;  // Aquí quedarán los nodos de posiciones 0, 2, 4, 6...
  Node* odd_head = nullptr;   // Aquí quedarán los nodos de posiciones 1, 3, 5...

  Append(list, 10);  // Posición 0
  Append(list, 20);  // Posición 1
  Append(list, 30);  // Posición 2
  Append(list, 40);  // Posición 3
  Append(list, 50);  // Posición 4
  Append(list, 60);  // Posición 5
  Append(list, 70);  // Posición 6

  SplitByPosition(list, even_head, odd_head);  // Separamos la lista.

  PrintForward(even_head);   // Esperado: 10 30 50 70
  PrintBackward(even_head);  // Esperado: 70 50 30 10
  PrintForward(odd_head);    // Esperado: 20 40 60
  PrintBackward(odd_head);   // Esperado: 60 40 20
  std::cout << "head original es nullptr? " << (list == nullptr ? "si" : "no") << '\n';  // Esperado: si.

  FreeList(even_head);  // Liberamos la lista par.
  FreeList(odd_head);   // Liberamos la lista impar.

  // Casos borde de 1.2: lista vacía y lista de un solo nodo.
  Node* empty_list = nullptr;       // Lista vacía.
  Node* empty_even = nullptr;       // Destino par para la lista vacía.
  Node* empty_odd = nullptr;        // Destino impar para la lista vacía.
  SplitByPosition(empty_list, empty_even, empty_odd);  // No debe fallar.
  std::cout << "Lista vacia -> par vacia? " << (empty_even == nullptr ? "si" : "no")
            << ", impar vacia? " << (empty_odd == nullptr ? "si" : "no") << '\n';  // Esperado: si, si.

  Node* single_list = nullptr;      // Lista de un solo nodo.
  Node* single_even = nullptr;      // Destino par.
  Node* single_odd = nullptr;       // Destino impar.
  Append(single_list, 99);          // Único nodo en posición 0 (par).
  SplitByPosition(single_list, single_even, single_odd);  // Separamos.
  PrintForward(single_even);        // Esperado: 99
  std::cout << "Impar vacia? " << (single_odd == nullptr ? "si" : "no") << '\n';  // Esperado: si.
  FreeList(single_even);            // Liberamos memoria.

  // ---------------- Prueba 1.3 ----------------
  std::cout << "\n=== Ejercicio 1.3: MoveLastToFront ===\n";  // Título de la prueba.
  Node* move_list = nullptr;  // Lista para probar el movimiento.
  Append(move_list, 10);      // 10
  Append(move_list, 20);      // 10 20
  Append(move_list, 30);      // 10 20 30
  Append(move_list, 40);      // 10 20 30 40
  Append(move_list, 50);      // 10 20 30 40 50

  MoveLastToFront(move_list);  // Movemos el 50 al inicio.
  PrintForward(move_list);     // Esperado: 50 10 20 30 40
  PrintBackward(move_list);    // Esperado: 40 30 20 10 50
  FreeList(move_list);         // Liberamos memoria.

  Node* empty_move = nullptr;  // Caso borde: lista vacía.
  MoveLastToFront(empty_move);  // No debe fallar.
  std::cout << "Lista vacia sigue vacia? " << (empty_move == nullptr ? "si" : "no") << '\n';  // Esperado: si.

  Node* one_move = nullptr;  // Caso borde: un solo nodo.
  Append(one_move, 7);       // Lista: 7
  MoveLastToFront(one_move); // No debe cambiar nada.
  PrintForward(one_move);    // Esperado: 7
  FreeList(one_move);        // Liberamos memoria.

  return 0;  // Fin del programa sin errores.
}  // Fin de main.
