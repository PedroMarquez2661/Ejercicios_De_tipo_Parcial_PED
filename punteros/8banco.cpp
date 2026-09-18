#include <iostream>
#include <string> // Necesario para trabajar con el tipo de dato string
using namespace std;

// Definición de la estructura para agrupar los datos de una cuenta
struct BankAccount {
    string holderName; // Nombre del titular
    double balance;    // Saldo actual de la cuenta
};

// Función para depositar fondos
// Usamos BankAccount* para poder modificar el atributo 'balance' directamente en la estructura original
void deposit(BankAccount* account, double amount) {
    if (amount > 0) {
        // Usamos el operador flecha (->) para acceder a un miembro desde un puntero
        account->balance += amount; 
        cout << "Depósito exitoso. Nuevo saldo: $" << account->balance << endl;
    }
}

// Función para retirar fondos
void withdraw(BankAccount* account, double amount) {
    // Validación: El monto debe ser positivo y no exceder el saldo disponible
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        cout << "Retiro exitoso. Nuevo saldo: $" << account->balance << endl;
    } else {
        cout << "Fondos insuficientes o monto inválido." << endl;
    }
}

int main() {
    // Creación e inicialización de una instancia de BankAccount
    BankAccount myAcc = {"Carlos López", 500.0};
    
    cout << "Cuenta: " << myAcc.holderName << " | Saldo inicial: $" << myAcc.balance << endl;

    // Pasamos la dirección de memoria de 'myAcc' usando el operador '&'
    deposit(&myAcc, 150.50);  // Saldo pasa a 650.50
    withdraw(&myAcc, 200.00); // Saldo pasa a 450.50

    return 0;
}