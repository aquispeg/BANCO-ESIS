#include "cliente.h"
#include <iostream>

using namespace std;

cliente registrarCliente() {
    cliente c;
    cout<<"\nIngrese nombre: ";
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
    cout<<"\n\033[34m=== Datos del cliente ===\n";
    cout<<"\033[36mNombre: \033[0m"<<c.nombre<<endl;
    cout<<"\033[36mDNI: \033[0m"<<c.DNI<<endl;
    cout<<"\033[36mEdad: \033[0m"<<c.edad<<endl;
}
