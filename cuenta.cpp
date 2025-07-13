#include <iostream>
#include <string>
#include "cuenta.h"

using namespace std;

void crearc_bancaria(cuenta cuentas[], int &totCuentas, string DNI) {
    cuentas[totCuentas].DNI = DNI;
    cuentas[totCuentas].ncuenta = 1000 + totCuentas;
    cuentas[totCuentas].saldo = 0;
    cout << "Cuenta creada: " << cuentas[totCuentas].ncuenta << endl;
    totCuentas++;
}

void mostrarc_bancaria(cuenta cuentas[], int totCuentas, string DNI) {
    cout << "---------Cuentas Bancarias--------" << endl;
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].DNI == DNI) {
            cout << "Numero de cuenta: " << cuentas[i].ncuenta << endl;
            cout << "Saldo: S/" << cuentas[i].saldo << endl;
        }
    }
}

int buscarCuenta(cuenta cuentas[], int totCuentas, int numeroCuenta, string DNI) {
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].ncuenta == numeroCuenta && cuentas[i].DNI == DNI) {
            return i;
        }
    }
    return -1;
}
