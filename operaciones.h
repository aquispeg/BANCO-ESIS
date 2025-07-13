#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <iostream>
#include <string>
using namespace std;

struct cuenta{
    int ncuenta;
    float saldo;
    string DNI;
};

void depositar(cuenta &, float);
void retirar(cuenta &, float);
void saldoActual(cuenta &);

#endif