#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>
#include "cuenta.h"

using namespace std;

void depositar(cuenta &);
void retirar(cuenta &);
void saldoActual(cuenta &);
void mostrarHistorial(const cuenta &);
string obtenerFechaActual();

#endif
