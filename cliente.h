#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;
struct cliente{
    string nombre;
    string DNI;
    int edad;
    string contrasena;
};
cliente registrarCliente();
void mostrarCliente(const cliente &c);

#endif