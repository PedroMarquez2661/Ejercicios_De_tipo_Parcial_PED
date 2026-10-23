#include <iostream>

using namespace std;

struct nodo
{
    int dato;
    nodo *siguiente;
    nodo *anterior;
};
struct listaDoble
{
    nodo *cabeza;
    nodo *cola;
};
// Crea un nodo nuevo en memoria dinámica y lo devuelve
nodo *crearNodo(int d)
{
    nodo *n = new nodo;     // reserva memoria para el nodo
    n->dato = d;            // guarda el dato
    n->siguiente = nullptr; // todavía no apunta a nadie
    n->anterior = nullptr;
    return n;
}
// Inserta un valor al INICIO de la lista
// El & en "ListaDoble& l" hace que modifiquemos la lista original
// y no una copia

void insertaInicio(listaDoble& l, int d){
    nodo* n = crearNodo (d);
    n->siguiente = l.cabeza;// el nuevo apunta a la cabeza actual

    if (l.cabeza !=nullptr)
    {
        l.cabeza->anterior = n;
    }else{
    l.cola = n;
    }

    
}

int main()
{

    return 0;
}
