#include <iostream>
#include <string>
#include <ctime>
#include "cuenta.h"
#include "operaciones.h"

using namespace std;

void depositar (cuenta cuentas[], int totalCuentas, string dniBuscado, string nombre) {
    if(totalCuentas == 0){
        cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<nombre<<endl;
        return;
    }
    int index;
    string numeroCuenta;
    cout << "\033[36m\nIngrese el numero de cuenta para realizar el deposito: \033[0m";
    cin >> numeroCuenta;
    index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
    if (index == -1){
        return;
    }
    float monto;
    cout<<"\n\033[36mIngrese el monto a depositar (Max. 1000): \033[0m"; cin >> monto;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\033[31mError: Ingrese un monto numerico valido.\033[0m\n";
        return;
    }
    cin.ignore();
    if (monto > 0 && monto <= 1000) {
        cuentas[index].saldo += monto;
        cout<<"\033[32mDeposito exitoso.\033[0m Nuevo saldo: "<<cuentas[index].saldo<<endl<<endl;

        operacion op;
        op.tipo = "Deposito: ";
        op.monto = monto;
        op.fecha = obtenerFechaActual();

        cuentas[index].historial.push_back(op);
    }
    else {
        cout<<"\033[31mError: Monto invalido.\033[0m"<<endl<<endl;
    };
}

void retirar (cuenta cuentas[], int totalCuentas, string dniBuscado, string nombre) {
    if(totalCuentas == 0){
        cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<nombre<<endl;
        return;
    }
    int index;
    string numeroCuenta;
    cout << "\033[36m\nIngrese el numero de cuenta para realizar el retiro: \033[0m";
    cin >> numeroCuenta;
    index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
    if (index == -1){
        return;
    }
    float monto;
    cout<<"\n\033[36mIngrese el monto a retirar: \033[0m"; cin>>monto;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "\033[31mError: Ingrese un monto numerico valido.\033[0m\n";
        return;
    }
    cin.ignore();
    if (monto <= 0) {
        cout<<"\033[31mError: Monto invalido.\033[0m"<<endl;
    } 
    else if (monto > cuentas[index].saldo) {
        cout<<"\033[31mFondos insuficientes.\033[0m Saldo actual: "<<cuentas[index].saldo<<endl<<endl;
    } 
    else {
        cuentas[index].saldo -= monto;
        cout<<"\033[32mRetiro exitoso.\033[0m Saldo actual: "<<cuentas[index].saldo<<endl<<endl;

        operacion op;
        op.tipo = "Retiro: ";
        op.monto = monto;
        op.fecha = obtenerFechaActual();

        cuentas[index].historial.push_back(op);
    };
}

void saldoActual (cuenta cuentas [], int totalCuentas, string dniBuscado, string nombre) {
    if(totalCuentas == 0){
        cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<nombre<<endl;
        return;
    }
    int index;
    string numeroCuenta;
    cout << "\033[36mIngrese el numero de la cuenta: \033[0m";
    cin >> numeroCuenta;
    index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
    if (index == -1){
        return;
    }
    cout << "Saldo actual: " << cuentas[index].saldo << "\n";
}

string obtenerFechaActual() {
    time_t t = time(0);
    tm* now = localtime(&t);
    char buffer[20];
    strftime(buffer, 20, "%d/%m/%Y  %H:%M", now);
    return string(buffer);
}

void mostrarHistorial(cuenta cuentas[], int totalCuentas, string dniBuscado, string nombre) {
    if(totalCuentas == 0){
        cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<nombre<<endl;
        return;
    }
    int index;
    string numeroCuenta;
    cout << "\033[36m\nIngrese el numero de cuenta para mostrar el historial: \033[0m";
    cin >> numeroCuenta;
    index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
    if (index == -1){
        return;
    }
    if (cuentas[index].historial.empty()) {
        cout << "\n\033[31mNo se han realizado operaciones en esta cuenta aun.\033[0m\n";
        return;
    }
    cout << "\n\033[34m===== Historial de operaciones de la cuenta \033[36m" << cuentas[index].ncuenta << "\033[34m =====\033[36m\n";
    for (const auto &op : cuentas[index].historial) {
        cout << "\033[36m" << op.fecha << " - " << op.tipo << " de \033[0mS/ " << op.monto << endl;
    }
    cout << "\033[34m====================================================================\033[0m\n";
}