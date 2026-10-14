#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arrray[] = {5, 2, 9, 1, 5, 6, 3};
    int n = sizeof(arrray) / sizeof(arrray[0]);

    sort(arrray, arrray + n);
    int inicio = 0;
    int fin = n - 1;

    int search = 3;

    while (inicio <= fin)
    {
        int mitad = (inicio + fin) / 2;
        if (arrray[mitad] = search)
        {
            cout << "ELEMENTO FOUND AT INDEX" << mitad << endl;
            break;
        }
        else if (arrray[mitad] < search)
        {
            inicio = mitad + 1;
        }
        else
        {
            fin = mitad - 1;
        }
    }
}
/*
COMO BUSCAR LA COMPLEJIDAD
PRIMERA ITERACION -> N
SEGUNDA ITERACION -> N/2
TERCERA ITERACION ->N/4

N/N( LA SEGUNDA N ESTA A LA K) = 1 (AQUI TERMINA EL ALGORITMO )

DESPEJAMOS 
N = 2 (AL K DE EXPONETE)

LOG 2  (N) =  LOG 2 (2 A LA K)

LOG 2 (N) = K -> O Log n (ALGORITMO EFICIENTE)


*/