#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>
#include <vector>
#include "cliente.h"
using namespace std;

struct operacion{
    string tipo;
    float monto;
    string fecha;
};

struct cuenta {
    float saldo;
    string DNI, ncuenta;
    vector<operacion> historial;
};

void crearc_bancaria(cuenta cuentas[], int &totCuentas, string DNI);
void mostrarc_bancaria(cuenta cuentas[], cliente clientes[], int totCuentas, int i);
int buscarCuenta(cuenta cuentas[], int totCuentas, string numeroCuenta, string DNI);
#endif
