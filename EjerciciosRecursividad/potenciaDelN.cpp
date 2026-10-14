#include<iostream>

using namespace std;

int potencia(int n){

        // Casos base
    if (n = 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    
    // Caso recursivo: F(n) = F(n-1) + F(n-2)
    return potencia(n) * potencia(n);
}




int main()
{

        int n = 2; // Cantidad de términos que deseas mostrar
        int n2 = 2;
    
    cout << "LA PONTENCIA DE "<<n << endl;
      for (int i = 0; i < n; i++) {
        cout << potencia(i) << " ";
    }
    cout << endl;

    

    return 0;
}
