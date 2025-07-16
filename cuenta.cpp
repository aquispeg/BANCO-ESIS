#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "cuenta.h"

using namespace std;

void crearc_bancaria(cuenta cuentas[], int &totCuentas, string DNI) {
    srand(time(0));
    int nrandom=(rand()%99)+10;
    string ncuenta="5400-1234-5678-";
    ncuenta+=to_string(nrandom);
    cuentas[totCuentas].DNI = DNI;
    cuentas[totCuentas].ncuenta=ncuenta;
    cuentas[totCuentas].saldo = 0;
    cout << "\033[32m\nCuenta bancaria creada correctamente.\n\033[0m";
    cout << "\033[36mNumero de la nueva cuenta: \033[0m" << cuentas[totCuentas].ncuenta << endl;
    totCuentas++;
}

void mostrarc_bancaria(cuenta cuentas[], int totCuentas, string DNI) {
    cout << "\033[34m\n---------Cuentas Bancarias--------\033[36m" << endl << endl;
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].DNI == DNI) {
            cout << "\033[36mNumero de cuenta: \033[0m" << cuentas[i].ncuenta << endl;
            cout << "\033[36mSaldo: \033[0mS/" << cuentas[i].saldo << endl;
            cout << "\033[34m----------------------------------\033[0m" << endl;
        }
    }
}

int buscarCuenta(cuenta cuentas[], int totCuentas, string numeroCuenta, string DNI) {
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].ncuenta == numeroCuenta && cuentas[i].DNI == DNI) {
            return i;
        }
    }
    cout << "\033[31mError: Cuenta no encontrada.\033[0m"<<endl<<endl;
    return -1;
}
