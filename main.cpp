#include <iostream>
#include "cliente.h"
#include "operaciones.h"
#include "cuenta.h"

using namespace std;
int main (){
    cliente clientes[50];
    cuenta cuentas[50];
    int totcliente=0;
    int totCuentas=0;
    int op, subop;
    string SN;
    string contraIngresada,dniBuscado;
    bool cuentaCreada=false;
    bool encontrado;
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
                    clientes[totcliente]=registrarCliente();
                    totcliente=totcliente+1;
                    cout<<"Cuenta creada correctamente."<< endl << endl;
                }else {
                    cout<<"Limite de cuentas alcanzado."<<endl << endl;
                }
                system("pause");
                break;
            case 2:
                encontrado = false;
                if(totcliente==0){
                    cout<<"No hay cuentas regitradas."<<endl;
                    system("pause");
                    break;
                }

                cout<<"Ingrese su DNI: "<<endl;
                getline(cin, dniBuscado);
                cout<<"Ingrese su contrasena: "<<endl;
                getline(cin, contraIngresada);

                int i;
                for(i=0; i<totcliente; i++){
                    if(clientes[i].DNI==dniBuscado && clientes[i].contrasena == contraIngresada){
                        mostrarCliente(clientes[i]);
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
                        cout<<"Bienvenido(a) "<< clientes[i].nombre<<endl;
                        cout<<"1. Crear cuenta bancaria"<<endl;
                        cout<<"2. Ver cuentas"<<endl;
                        cout<<"3. Depositar"<<endl;
                        cout<<"4. Retirar"<<endl;
                        cout<<"5. Consultar saldo"<<endl;
                        cout<<"6. Mostrar perfil"<<endl;
                        cout<<"0. Cerrar sesion"<<endl;
                        cout<<"Elige una opcion: "; cin>>subop;
                        cin.ignore();
                        int index;
                        switch(subop){
                            case 1:
                            int ncbase;
                            crearc_bancaria(cuentas, totCuentas, clientes[i].DNI);
                            system("pause");
                                break;

                            case 2:
                            mostrarc_bancaria(cuentas, totCuentas, clientes[i].DNI);
                            system("pause");
                                break;
                            case 3:{
                                int numeroCuenta;
                                cout<<"Ingrese el numero de cuenta al cual depositar: ";
                                cin>>numeroCuenta;
                                index = buscarCuenta(cuentas, totCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    depositar(cuentas[index]);
                                }
                                break;
                            }
                            case 4:{
                                int numeroCuenta;
                                cout<<"Ingrese el numero de cuenta del cual retirar: ";
                                cin>>numeroCuenta;
                                index = buscarCuenta(cuentas, totCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    retirar(cuentas[index]);
                                }
                                break;
                            }
                            case 5:{
                                int numeroCuenta;
                                cout<<"Ingrese el numero de la cuenta: ";
                                cin>>numeroCuenta;
                                index = buscarCuenta(cuentas, totCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    saldoActual(cuentas[index]);
                                } 
                                break;
                            }
                            case 6:
                                mostrarCliente(clientes[i]);
                                system("pause");
                                break;
                            case 0:
                                cout<<"Esta seguro de salir? (S/N): ";
                                cin.ignore();
                                getline(cin, SN);
                                if (SN=="N" || SN=="n"){
                                    subop = -1;
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