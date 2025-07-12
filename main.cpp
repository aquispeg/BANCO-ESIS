#include <iostream>
#include "cliente.h"

using namespace std;
int main (){
    int op;
    string SN;
    cliente cte;
    bool cuentaCreada=false;
    do{
        system("cls");
        cout<<":::::::::::::BANCO ESIS:::::::::::::"<<endl;
        cout<<"---Menu de opciones-----------------"<<endl;
        cout<<" 1. Crear Cuenta"<<endl;
        cout<<" 2. Iniciar Sesion"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"Elige Una Opcion: ";cin>>op;
        cin.ignore();
        switch(op){
            case 1:
            cte = registrarCliente();
            cuentaCreada=true;
            cout<<"cuenta creada correctamente"<< endl;
            system("pause");
            break;
            case 2:
            if(cuentaCreada){
                string contraIngresada;
                cout<<"ingrese su contraseña: "<<endl;
                getline(cin, contraIngresada);
                if(contraIngresada == cte.contrasena){
                    mostrarCliente(cte);
                }else{
                    cout<<"contraseña incorrecta. acceso denegado"<<endl;
                }
            }else{
                cout<<"Debe Crear una cuenta. "<< endl;
            }
            system("pause");
            break;
            case 0:
                cout<<"¿Esta Seguro de Salir? (S/N): ";
                cin>>SN;
                if (SN=="N" || SN=="s"){
                    op=op+1;
                }
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        } 
    }
    while (op!=0);
    
    return 0;
}
