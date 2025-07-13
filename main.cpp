#include <iostream>
#include "cliente.h"
#include "operaciones.h"

using namespace std;
int main (){
    cliente lista[50];
    cuenta cuentas[50];
    int totcliente=0;
    int op, subop, numeroCuenta;
    string SN;
    bool cuentaCreada=false;
    do{
        system("cls");
        cout<<":::::::::::::BANCO ESIS:::::::::::::"<<endl;
        cout<<"----------Menu de opciones----------"<<endl;
        cout<<" 1. Crear cuenta"<<endl;
        cout<<" 2. Iniciar sesion"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"Elige una opcion: ";cin>>op;
        cin.ignore();

        switch(op){
            case 1:
                if(totcliente <50){
                    lista[totcliente]=registrarCliente();
                    totcliente=totcliente+1;
                    cout<<"Cuenta creada correctamente."<< endl;
                }else {
                    cout<<"Limite de cuentas alcanzado."<<endl;
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
                cout<<"Ingrese su DNI: "<<endl;
                getline(cin, dniBuscado);
                cout<<"Ingrese su contrasena: "<<endl;
                getline(cin, contraIngresada);

                bool encontrado=false;
                int i;
                int j;
                for(i=0; i<totcliente; i++){
                    if(lista[i].DNI==dniBuscado && lista[i].contrasena == contraIngresada){
                        mostrarCliente(lista[i]);
                        encontrado=true;
                        break;
                    }
                }
                if(!encontrado){
                    cout<<"DNI o contrasena incorrecta. "<<endl;
                    cout<<"---Acceso denegado---"<<endl;
                }
                else{
                    do{
                        system("cls");
                        cout<<"==== MENU DE USUARIO ==="<<endl;
                        cout<<"Bienvenido(a) "<< lista[i].nombre<<endl;
                        cout<<"1. Crear cuenta bancaria"<<endl;
                        cout<<"2. Ver cuentas"<<endl;
                        cout<<"3. Depositar"<<endl;
                        cout<<"4. Retirar"<<endl;
                        cout<<"5. Consultar saldo"<<endl;
                        cout<<"6. Mostrar perfil"<<endl;
                        cout<<"0. Cerrar sesion"<<endl;
                        cout<<"Elige una opcion: "; cin>>subop;
                        cin.ignore();

                        switch(subop){
                            case 1:{
                            int ncbase;
                            crearc_bancaria(cuentas, totCuentas, lista[i].DNI);
                            system("pause");
                                break;}

                            case 2:{
                            mostrarc_bancaria(cuentas, totCuentas, lista[i].DNI);
                            system("pause");
                                break;}
                            case 3:
                                cout<<"Ingrese el numero de cuenta al cual depositar: "; cin>>numeroCuenta;
                                break;
                            case 4:
                                cout<<"Ingrese el numero de cuenta del cual retirar: "; cin>>numeroCuenta;
                                break;
                            case 5:
                                cout<<"Ingrese el numero de la cuenta: "; cin>>numeroCuenta;
                                break;
                            case 6:
                                mostrarCliente(lista[i]);
                                system("pause");
                                break;
                            case 0:
                                cout<<"Esta seguro de salir? (S/N): ";
                                cin.ignore();
                                getline(cin, SN);
                                if (SN=="N" || SN=="n"){
                                    subop=subop+1;
                                }
                                break;
                            default:
                                cout<<"Opcion no valida!"<<endl;
                                break;
                            }
                    } while(subop != 0);
                }
                system("pause");
                break;
            }
            case 0:
                cout<<"Esta seguro de salir? (S/N): ";
                getline(cin, SN);
                if (SN=="N" || SN=="n"){
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
