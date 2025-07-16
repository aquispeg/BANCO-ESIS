#include <iostream>
#include <string>
#include <ctime>
#include "cuenta.h"

using namespace std;

void depositar (cuenta &cuenta) {
    float monto;
    cout<<"\n\033[36mIngrese el monto a depositar (Max. 1000): \033[0m"; cin >> monto;
    cin.ignore();
    if (monto > 0 && monto <= 1000) {
        cuenta.saldo += monto;
        cout<<"\033[32mDeposito exitoso.\033[0m Nuevo saldo: "<<cuenta.saldo<<endl<<endl;

        operacion op;
        op.tipo = "Deposito: ";
        op.monto = monto;
        op.fecha = obtenerFechaActual();

        cuenta.historial.push_back(op);
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

        operacion op;
        op.tipo = "Retiro: ";
        op.monto = monto;
        op.fecha = obtenerFechaActual();

        cuenta.historial.push_back(op);
    };
}

void saldoActual (cuenta &cuenta) {
    cout << "Saldo actual: " << cuenta.saldo << "\n";
}

string obtenerFechaActual() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buffer[20];
    strftime(buffer, 20, "%d/%m/%Y  %H:%M", now);
    return string(buffer);
}

void mostrarHistorial(const cuenta &c) {
    if (c.historial.empty()) {
        cout << "\n\033[31mNo se han realizado operaciones en esta cuenta aun.\033[0m\n";
        return;
    }
    cout << "\n\033[34m===== Historial de operaciones de la cuenta \033[36m" << c.ncuenta << "\033[34m =====\033[36m\n";
    for (const auto &op : c.historial) {
        cout << "\033[36m" << op.fecha << " - " << op.tipo << " de \033[0mS/ " << op.monto << endl;
    }
    cout << "\033[34m====================================================================\033[0m\n";
}