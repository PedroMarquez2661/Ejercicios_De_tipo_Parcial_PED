#include <iostream>
#include <map> //lista de listas
#include <string>
#include <vector>
using namespace std;
//GRAFO NO DIRIGIDO 
void registrarusurio(map<string, vector<string>>& red, vector<string>& usarios){
    /*

    
    
    */
    int n;
    cout<<"cuantos usuarios quieres ";
    cin>> n;
    for (int i = 0; i < n; i++)
    {
        string nombre;
        cin>>nombre;
        usarios.push_back(nombre);  // pone a bajo de la lista->vector basio 
        red[nombre]={}; 
    }
    

}

void crearConexiones(map<string, vector<string>>& red, vector<string>& usarios){
    int n; 
    cout<<"Cuentas conexiones quieres crear: ";
    cin>> n;
    for (int i = 0; i < n; i++)
    {
       string using1, usario2;
       cout<<"Ingresa el usurio 1 ; ";
       cin>>n;
       cout<<"ingresa el usurio 2";

       red[using1].push_back(usario2);
       red[using1].push_back(using1);

    }
}

int main(){
    map<string,vector<string>>red;
    vector<string> usurio;
    registrarusurio(red, usurio);
    crearConexiones(red);




    return 0 ; 

}