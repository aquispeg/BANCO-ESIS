#include <iostream>
#include "cliente.h"

using namespace std;
int main (){
    cliente lista[50];
    int totcliente=0;
    int op;
    string SN;
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
                if(totcliente <50){
                    lista[totcliente]=registrarCliente();
                    totcliente=totcliente+1;
                    cout<<"cuenta creada correctamente"<< endl;
                }else {
                    cout<<"limite de cuentas alcanzadas"<<endl;
                }
                system("pause");
                break;
            case 2: {
                if(totcliente==0){
                    cout<<"No hay cuentas regitradas."<<endl;
                    system("pause");
                    break;
                }
            
                string contraIngresada,dniBuscado;
                cout<<"ingrese su DNI: "<<endl;
                getline(cin, dniBuscado);
                cout<<"ingrese su contraseña: "<<endl;
                getline(cin, contraIngresada);
            
                bool encontrado=false;
                for(int i=0;i<totcliente;i++){
                    if(lista[i].DNI==dniBuscado && lista[i].contrasena == contraIngresada){
                        mostrarCliente(lista[i]);
                        encontrado=true;
                        break;
                    }
                }
                if(!encontrado){
                    cout<<"DNI o contraseña incorrecta. "<<endl;
                    cout<<"---acceso denegado---"<<endl;
                }
                system("pause");
                break;
            }
            case 0:
                cout<<"¿Esta Seguro de Salir? (S/N): ";
                getline(cin, SN);
                if (SN=="N" || SN=="s"){
                    op=op+1;
                }
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        } 
    } while (op!=0);
    
    return 0;
}
