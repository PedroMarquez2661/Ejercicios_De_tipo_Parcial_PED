#include <iostream>
using namespace std;

// Definición de la estructura
struct nodo
{
    int dato;
    nodo *sig;
};

// Punteros globales de control INICIALIZADOS correctamente
nodo *cab = nullptr;
nodo *finalNodo = nullptr;

// 1. Insertar al final
void insertarFinal(int n1, nodo *&cab, nodo *&finalNodo)
{
    nodo *nuevonodo = new nodo;
    nuevonodo->dato = n1;
    nuevonodo->sig = nullptr;

    if (cab == nullptr)
    {
        cab = nuevonodo;
        finalNodo = nuevonodo;
    }
    else
    {
        finalNodo->sig = nuevonodo;
        finalNodo = nuevonodo;
    }
}

// 2. Insertar al inicio
void insertarInicio(int n1, nodo *&cab, nodo *&finalNodo)
{
    nodo *nuevonodo = new nodo;
    nuevonodo->dato = n1;

    if (cab == nullptr)
    {
        nuevonodo->sig = nullptr;
        cab = nuevonodo;
        finalNodo = nuevonodo;
    }
    else
    {
        nuevonodo->sig = cab;
        cab = nuevonodo; // Se actualiza el inicio
    }
}

// 3. Mostrar la lista
void mostrar(nodo *cab)
{
    if (cab == nullptr)
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    nodo *temp = cab; // Variable local para recorrer
    cout << "Lista: ";
    while (temp != nullptr)
    {
        cout << temp->dato << " -> ";
        temp = temp->sig;
    }
    cout << "NULL" << endl;
}

// 4. Buscar elemento
bool buscar(int n1, nodo *cab)
{
    if (cab == nullptr)
    {
        return false;
    }

    nodo *temp = cab; // Variable local
    while (temp != nullptr)
    {
        if (temp->dato == n1)
        {
            return true;
        }
        temp = temp->sig;
    }
    return false;
}

// 5. Borrar elemento
void Borrar(nodo *&cab, nodo *&finalNodo, int valor)
{
    if (cab == nullptr)
    {
        cout << "La lista esta vacia." << endl;
        return;
    }

    // Si el dato está en la cabeza
    if (cab->dato == valor)
    {
        nodo *tempBorrar = cab;
        cab = cab->sig;

        if (cab == nullptr)
        {
            finalNodo = nullptr; // Si la lista quedó vacía
        }

        delete tempBorrar;
        cout << "Nodo eliminado exitosamente." << endl;
        return;
    }

    // Si está en el centro o al final
    nodo *aux = cab;
    while (aux->sig != nullptr && aux->sig->dato != valor)
    {
        aux = aux->sig;
    }

    if (aux->sig == nullptr)
    {
        cout << "El valor " << valor << " no se encuentra en la lista." << endl;
        return;
    }

    nodo *tempBorrar = aux->sig;
    if (tempBorrar == finalNodo)
    {
        finalNodo = aux; // Si borramos el último, actualizamos el puntero final
    }

    aux->sig = aux->sig->sig;
    delete tempBorrar;
    cout << "Nodo eliminado exitosamente." << endl;
}

// 6. Liberar memoria
void FreeList(nodo *&cab, nodo *&finalNodo)
{
    nodo *temp = nullptr;
    while (cab != nullptr)
    {
        temp = cab;
        cab = cab->sig;
        delete temp;
    }
    finalNodo = nullptr;
    cout << "Memoria liberada correctamente." << endl;
}

int main()
{
    int opcion = 0;
    int numero = 0;

    do
    {
        cout << "\n=== MENU LISTA ENLAZADA ===" << endl;
        cout << "1. Insertar al final" << endl;
        cout << "2. Insertar al inicio" << endl;
        cout << "3. Mostrar lista" << endl;
        cout << "4. Buscar elemento" << endl;
        cout << "5. Borrar elemento" << endl;
        cout << "6. Liberar lista" << endl;
        cout << "7. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Ingrese el numero a insertar al final: ";
            cin >> numero;
            insertarFinal(numero, cab, finalNodo);
            cout << "Elemento insertado al final." << endl;
            break;

        case 2:
            cout << "Ingrese el numero a insertar al inicio: ";
            cin >> numero;
            insertarInicio(numero, cab, finalNodo);
            cout << "Elemento insertado al inicio." << endl;
            break;

        case 3:
            mostrar(cab);
            break;

        case 4:
            cout << "Ingrese el numero a buscar: ";
            cin >> numero;
            if (buscar(numero, cab))
            {
                cout << "El numero " << numero << " SI existe en la lista." << endl;
            }
            else
            {
                cout << "El numero " << numero << " NO se encuentra en la lista." << endl;
            }
            break;

        case 5:
            cout << "Ingrese el numero a borrar: ";
            cin >> numero;
            Borrar(cab, finalNodo, numero);
            break;

        case 6:
            FreeList(cab, finalNodo);
            break;

        case 7:
            cout << "Saliendo del programa..." << endl;
            FreeList(cab, finalNodo);
            break;

        default:
            cout << "Opcion invalida. Intente de nuevo." << endl;
            break;
        }

    } while (opcion != 7);

    return 0;
}