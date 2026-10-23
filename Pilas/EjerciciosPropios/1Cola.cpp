#include <iostream>
#include <queue>

/*
push(x) Agrega x al final
front() Consulta el primer elemento
black()consulta el ultimo elemento
pop() elimina el primer elemento
empty()comprueba si esta vacia
size()Devuelve la cantidad de elemntos

*/

using namespace std;

int main(){
    queue <int> requests;

    requests.push(10);
    requests.push(20);
    requests.push(30);

    requests.pop();// borrar el 10

    return 0;
}