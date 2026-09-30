#include <iostream>

// Estructura de un nodo en una lista doblemente enlazada
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// PUSH: Inserta al inicio de la lista.
// Al insertar aquí, este elemento se convierte automáticamente en el "último en haber entrado",
// por lo que será el "primero en ser eliminado" (comportamiento de Pila/LIFO).
void Push(Node*& head, int data) {
    Node* new_node = new Node{data, head, nullptr};

    if (head != nullptr) {
        head->prev = new_node;
    }

    head = new_node;
    std::cout << "Elemento " << data << " agregado exitosamente.\n";
}

// POP: Elimina el último elemento que fue insertado (el que está en la cabeza/inicio).
void Pop(Node*& head) {
    // Validación: Si la lista está vacía, no hay nada que eliminar.
    if (head == nullptr) {
        std::cout << "La lista esta vacia. No hay elementos para eliminar.\n";
        return;
    }

    Node* temp = head;          // Guardamos referencia al nodo a eliminar
    int removed_value = temp->data;

    head = head->next;          // Avanzamos la cabeza al siguiente nodo

    if (head != nullptr) {
        head->prev = nullptr;   // El nuevo primer nodo ya no tiene elemento anterior
    }

    delete temp;                // Liberamos la memoria correctamente
    std::cout << "Elemento eliminado: " << removed_value << std::endl;
}

// PEEK / TOP: Consulta el próximo elemento a ser eliminado sin modificar la lista.
void Peek(Node* head) {
    // Validación: Si la lista está vacía, se notifica al usuario.
    if (head == nullptr) {
        std::cout << "La lista esta vacia. No hay un proximo elemento para eliminar.\n";
        return;
    }

    // El próximo elemento a eliminar es siempre el primero (head)
    std::cout << "El proximo elemento a eliminar es: " << head->data << std::endl;
}

// Muestra los elementos de la lista desde el más reciente al más antiguo
void PrintList(Node* head) {
    if (head == nullptr) {
        std::cout << "La lista esta vacia." << std::endl;
        return;
    }

    Node* current = head;
    std::cout << "Estado actual de la lista: ";
    while (current != nullptr) {
        std::cout << current->data << " -> ";
        current = current->next;
    }
    std::cout << "NULL" << std::endl;
}

// Liberación adecuada de toda la memoria reservada en la lista
void FreeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    std::cout << "Memoria liberada correctamente.\n";
}

int main() {
    Node* lista = nullptr;
    int option = 0;

    do {
        std::cout << "\n--- MENU DE OPCIONES ---\n";
        std::cout << "1. Insertar elemento (Push)\n";
        std::cout << "2. Eliminar ultimo elemento insertado (Pop)\n";
        std::cout << "3. Consultar proximo elemento a eliminar (Peek)\n";
        std::cout << "4. Imprimir lista\n";
        std::cout << "5. Liberar memoria y salir\n";
        std::cout << "Ingrese una opcion: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                int n;
                std::cout << "Ingrese un numero int: ";
                std::cin >> n;
                Push(lista, n);
                break;
            }
            case 2: {
                Pop(lista);
                break;
            }
            case 3: {
                Peek(lista);
                break;
            }
            case 4: {
                PrintList(lista);
                break;
            }
            case 5: {
                FreeList(lista);
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            }
            default: {
                std::cout << "Opcion invalida. Intente de nuevo.\n";
                break;
            }
        }
    } while (option != 5);

    return 0;
}