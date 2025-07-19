#include "cliente.h"
#include <iostream>
#include <cctype>

using namespace std;

bool esDniValido (const string &dni) {
    if (dni.length() != 8){
        return false;
    }
    for (char c : dni){
        if (!isdigit(c))
            return false;
    }
    return true;
}

bool esContrasenaValido (const string &password) {
    if (password.length() > 10 || password.length() < 4){
        return false;
    }
    return true;
}

bool cuentaExistente(cliente clientes[], int &totClientes){
    for (int i = 0; i < totClientes; i++){
        if (clientes[i].DNI == clientes[totClientes].DNI) {
           return true;
        }
    }
    totClientes++;
    return false;
}

cliente registrarCliente() {
    cliente c;
    cout<<"\n\033[36mIngrese nombre: \033[0m";
    getline(cin, c.nombre);

    do {
        cout<<"\033[36mIngrese DNI: \033[0m";
        getline(cin, c.DNI);
        if (!esDniValido(c.DNI)){
        cout << "\033[31mError: DNI invalido. Debe tener exactamente 8 digitos numericos.\033[0m\n"; 
        }
    } while (!esDniValido(c.DNI));

    do {
        cout<<"\033[36mIngrese edad: \033[0m";
        cin>>c.edad;
        if (c.edad < 18){
            cout << "\033[31mError: Debe tener al menos 18 anos para registrarse.\033[0m\n";
        }
    } while(c.edad < 18);
    cin.ignore();
    do {
        cout<<"\033[36mIngrese contrasena (4-10 max.): \033[0m";    
        getline(cin, c.contrasena);
        if (!esContrasenaValido(c.contrasena)){
            cout<<"\033[31mError: Contrasena invalida. Debe tener de 4 a 10 digitos.\033[0m\n";
        }
    } while (!esContrasenaValido(c.contrasena));

    return c;
}

void mostrarCliente(const cliente &c) {
    cout<<"\n\033[34m=== Datos del cliente ===\n";
    cout<<"\033[36mNombre: \033[0m"<<c.nombre<<endl;
    cout<<"\033[36mDNI: \033[0m"<<c.DNI<<endl;
    cout<<"\033[36mEdad: \033[0m"<<c.edad<<endl;
}
