#include <iostream>
#include <string>
#include "operaciones.h"
using namespace std;

void depositar (cuenta &cuenta) {
    float monto;
    cout<<"\nIngrese el monto a depositar (Max. 1000): "; cin >> monto;
    cin.ignore();
    if (monto > 0 && monto <= 1000) {
        cuenta.saldo += monto;
        cout<<"Deposito exitoso. Nuevo saldo: "<<cuenta.saldo<<endl<<endl;        
    }
    else {
        cout<<"Error: Monto invalido."<<endl<<endl;
    }
    system("pause");
}

void retirar (cuenta &cuenta) {
    float monto;
    cout<<"\nIngrese el monto a retirar: "; cin>>monto;
    if (monto <= 0) {
        cout<<"Error: Monto invalido."<<endl;
    } 
    else if (monto > cuenta.saldo) {
        cout<<"Fondos insuficientes. Saldo actual: "<<cuenta.saldo<<endl<<endl;
    } 
    else {
        cuenta.saldo -= monto;
        cout<<"Retiro exitoso. Saldo actual: "<<cuenta.saldo<<endl<<endl;
    }
    system("pause");
}

void saldoActual (cuenta &cuenta) {
    cout << "Saldo actual: " << cuenta.saldo << "\n";
    system("pause");
}