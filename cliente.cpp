#include "cliente.h"
#include <iostream>
using namespace std;


cliente registrarCliente(){
    cliente c;
    cout<<"Ingrese Nombre: ";
    getline(cin, c.nombre);

    cout<<"ingrese DNI: ";
    getline(cin, c.DNI);
    
    cout<<"ingrese edad: ";
    cin>>c.edad;
    cin.ignore();

    return c;
}

void mostrarCliente(const cliente &c){
    cout<<"===Datos del cliente==="<<endl;
    cout<<"Nombre: "<<c.nombre<<endl;
    cout<<"DNI: "<<c.DNI<<endl;
    cout<<"Edad: "<<c.edad<<endl;
}
