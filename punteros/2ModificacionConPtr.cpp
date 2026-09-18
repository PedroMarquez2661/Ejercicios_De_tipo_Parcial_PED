#include <iostream>
using namespace std;

// Función void que recibe un puntero a entero
void curarjugador (int* ptrVida, int pocion){
// Le sumamos la poción directamente al valor en memoria

    *ptrVida = *ptrVida + pocion;
}
int main (){
    int VidaJugador = 40;
    cout <<"VIDA ANTES DE LA POCION:  "<<VidaJugador<<endl;

    // Le pasamos la DIRECCIÓN de 'vidaJugador' usando &

    curarjugador(&VidaJugador,30);

    cout<<"VIDA DESPUES DE LA OPCION: "<<VidaJugador<<endl;




return 0;
}