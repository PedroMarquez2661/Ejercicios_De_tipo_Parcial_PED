#include <iostream>
#include <stack>
/*
push() Los pone arriba
pop() quita la mas reciente
top() cual esta hasta arriba
size()Cuantos tiene adentro
empty() esta vacia = 1 / llena = 0

*/

using namespace std;

int main()
{
    stack<int> numbers;
    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
    cout << numbers.top();

    return 0;
}
