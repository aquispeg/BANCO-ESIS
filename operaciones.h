#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>
#include "cuenta.h"

using namespace std;

void depositar(cuenta [], int, string, string);
void retirar(cuenta [], int, string, string);
void saldoActual(cuenta [], int, string, string);
void mostrarHistorial(cuenta [], int, string, string);
string obtenerFechaActual();

#endif
