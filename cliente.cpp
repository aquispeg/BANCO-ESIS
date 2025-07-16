#include "cliente.h"
#include <iostream>

using namespace std;

cliente registrarCliente() {
    cliente c;
    cout<<"Ingrese nombre: ";
    getline(cin, c.nombre);

    cout<<"Ingrese DNI: ";
    getline(cin, c.DNI);
    
    cout<<"Ingrese edad: ";
    cin>>c.edad;
    cin.ignore();

    cout<<"Ingrese contrasena: ";
    getline(cin, c.contrasena);

    return c;
}

void mostrarCliente(const cliente &c) {
    cout<<"\n===Datos del cliente===\n";
    cout<<"Nombre: "<<c.nombre<<endl;
    cout<<"DNI: "<<c.DNI<<endl;
    cout<<"Edad: "<<c.edad<<endl;
}
