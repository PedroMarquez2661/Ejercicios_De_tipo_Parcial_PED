#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int>num;
    num.push(1);
    num.push(2);
    num.push(3);
    num.push(4);

    cout<<"TOP : "<<num.top()<<endl;
    num.pop(); // borrar 4 
    cout<<"TOP : "<<num.top()<<endl;
    num.pop(); ///borrar 3
    cout<<"TOP : "<<num.top()<<endl;
    num.pop();//borrar 2
    return 0;
    //Crear un matriz de 3 dimesiones que funcione como un pila 
}