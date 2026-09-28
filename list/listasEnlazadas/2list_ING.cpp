#include<iostream>

struct Node{
    int data;
    Node* next;
    
};

void Insert(Node*& head, int data){
    Node* new_node = new Node{data, head};
    head = new_node;
}

void InsertAtEnd(Node*& head, int data){
    Node* new_node = new Node{data, nullptr};

    //Si esto ocurre es porque la lista esta vacia
    if(head == nullptr){
        head = new_node;
        return;
    }

    //Pero esto pasa si acaso no esta vacia
    Node* current = head;

    while(current->next != nullptr){
        current = current->next;
    }

    current->next = new_node;
}

void PrintList(Node* head){
    Node* current = head;

    while(current != nullptr){
        std::cout<<current->data<<" -> ";
        current = current->next;
    }

    std::cout<<std::endl;
}

void FreeList(Node*& head){
    while(head != nullptr){
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

void DeleteValue(Node*& head, int value){

    if(head == nullptr){
        return;
    }

    //Si el elemento esta en el primer nodo
    if(head->data == value){
        Node* temp = head;
        head=head->next;
        delete temp;
        return;
    }
    
    Node* current = head;

    while(
        current->next != nullptr &&
        current->next->data != value
    ){
        current=current->next;
    }

    if(current->next != nullptr){
        Node* temp=current->next;
        current->next=current->next->next;
        delete temp;
    
    }

}

int main(){
    Node* lista1 = nullptr;
    Node* lista2 = nullptr;

    int option = 0;

    do{
        std::cout<<"1. Insertar al inicio"<<std::endl;
        std::cout<<"2. Insertar al final"<<std::endl;
        std::cout<<"3. Imprimir lista"<<std::endl;
        std::cout<<"4. Liberar memoria"<<std::endl;
        std::cin>>option;

        switch(option){
            case 1:{
                int n;
                std::cout<<"Ingrese un numero: ";
                std::cin>>n;

                Insert(lista1, n);

                break;
            }
            case 2:{
                int n;
                std::cout<<"Ingrese un numero: ";
                std::cin>>n;

                InsertAtEnd(lista1, n);

                break;
            }
            case 3:{
                PrintList(lista1);
                break;
            }
            case 4:{
                std::cout<<"Liberando memoria..."<<std::endl;
                FreeList(lista1);
                break;
            }
            default:{
                std::cout<<"Opcion invalida"<<std::endl;
                break;
            }
        }
    }while(option != 100);


    return 0;
}