#include <iostream>
#include <string>
#include "operaciones.h"

using namespace std;

void depositar (cuenta &cuenta) {
    float monto;
    cout<<"\n\033[36mIngrese el monto a depositar (Max. 1000): \033[0m"; cin >> monto;
    cin.ignore();
    if (monto > 0 && monto <= 1000) {
        cuenta.saldo += monto;
        cout<<"\033[32mDeposito exitoso.\033[0m Nuevo saldo: "<<cuenta.saldo<<endl<<endl;        
    }
    else {
        cout<<"\033[31mError: Monto invalido.\033[0m"<<endl<<endl;
    };
}

void retirar (cuenta &cuenta) {
    float monto;
    cout<<"\n\033[36mIngrese el monto a retirar: \033[0m"; cin>>monto;
    if (monto <= 0) {
        cout<<"\033[31mError: Monto invalido.\033[0m"<<endl;
    } 
    else if (monto > cuenta.saldo) {
        cout<<"\033[31mFondos insuficientes.\033[0m Saldo actual: "<<cuenta.saldo<<endl<<endl;
    } 
    else {
        cuenta.saldo -= monto;
        cout<<"\033[32mRetiro exitoso.\033[0m Saldo actual: "<<cuenta.saldo<<endl<<endl;
    };
}

void saldoActual (cuenta &cuenta) {
    cout << "Saldo actual: " << cuenta.saldo << "\n";
}