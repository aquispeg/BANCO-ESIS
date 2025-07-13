#include <iostream>
#include <string>
#include "operaciones.h"
using namespace std;

void depositar(cuenta &cuenta) {
    float monto;
    cout<<"\nIngrese el monto a depositar: "; cin>>monto;
    cin.ignore();
    if(monto > 0 && monto <= 1000){
        cuenta.saldo += monto;
        cout<<"Depósito exitoso. Nuevo saldo: "<<cuenta.saldo<<endl;
    }
    else{
        cout<<"Monto invalido"<<endl;
    }
}

void retirar(cuenta &cuenta){
    float monto;
    cout<<"\nIngrese el monto a retirar: "; cin>>monto;
    if(monto <= 0){
        cout<<"Error. Monto invalido."<<endl;
    } 
    else if(monto > cuenta.saldo){
        cout<<"Fondos insuficientes. Saldo actual: "<<cuenta.saldo<<endl;
    } 
    else{
        cuenta.saldo -= monto;
        cout<<"Retiro exitoso. Saldo actual: "<<cuenta.saldo<<endl;
    }
}

void saldoActual(cuenta &cuenta){
    cout<<"Saldo actual: "<<cuenta.saldo<<endl;
}