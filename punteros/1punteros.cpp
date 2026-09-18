#include <iostream>
using namespace std;

int main (){
    int numero = 50;

    int* ptr = &numero;
    cout<<"1.valor de la variable numero: "<<numero<<endl;
    cout<<"2.Direccion de memoria del numero (&numero): "<<&numero<<endl;
    cout<<"3.Lo que guarda el puntero ptr: "<<ptr<<endl;
    cout<<"4.El valor que apunta ptr (*ptr): "<<*ptr<<endl;
    
return 0;

}