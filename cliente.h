#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <string>

using namespace std;

struct cliente{
    string nombre;
    string DNI;
    int edad;
    string contrasena;
};

bool cuentaExistente(cliente clientes[], int &totCuentas) ;
bool esDniValido(const string &);
bool esContrasenaValido(const string &);
cliente registrarCliente();
void mostrarCliente(const cliente &c);

#endif