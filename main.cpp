#include <iostream>
#include "cliente.h"
#include "operaciones.h"
#include "cuenta.h"

using namespace std;

int main (){
    cliente clientes[50];
    cuenta cuentas[50];
    int totalClientes=0;
    int totalCuentas=0;
    int op, subop;
    string SN;
    string contraIngresada,dniBuscado,numeroCuenta;
    bool cuentaCreada=false;
    bool encontrado;

    do{
        system("cls");
        cout<<":::::::::::::BANCO ESIS:::::::::::::"<<endl;
        cout<<"----------Menu de opciones----------"<<endl;
        cout<<" 1. Crear cuenta"<<endl;
        cout<<" 2. Iniciar sesion"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        cin.ignore();

        switch (op) {
            case 1: {
                if ( totalClientes < 50 ) {
                    clientes[totalClientes] = registrarCliente();
                    totalClientes++;
                    cout<<"\nCuenta creada correctamente.\n";
                } else {
                    cout<<"\nLimite de cuentas alcanzado.\n";
                }
                system("pause");
                break;
            }

            case 2: {
                encontrado = false;

                if(totalClientes == 0){
                    cout<<"No hay cuentas regitradas."<<endl;
                    system("pause");
                    break;
                }

                cout<<"\nIngrese su DNI: ";
                getline(cin, dniBuscado);
                cout<<"Ingrese su contrasena: ";
                getline(cin, contraIngresada);

                int i;
                for(i=0; i<totalClientes; i++){
                    if(clientes[i].DNI==dniBuscado && clientes[i].contrasena == contraIngresada){
                        system("cls");
                        cout<<"\nBienvenido(a) " << clientes[i].nombre << "\n";
                        mostrarCliente(clientes[i]);
                        system("pause");
                        encontrado=true;
                        break;
                    }
                }

                if(!encontrado){
                    cout<<"\nDNI o contrasena incorrecta.";
                    cout<<"\n---Acceso denegado---\n";
                    system("pause");
                } else {
                    do{
                        system("cls");
                        cout<<"\n======= MENU DE USUARIO ======\n";
                        cout<<" 1. Crear cuenta bancaria\n";
                        cout<<" 2. Ver cuentas\n";
                        cout<<" 3. Depositar\n";
                        cout<<" 4. Retirar\n";
                        cout<<" 5. Consultar saldo\n";
                        cout<<" 6. Mostrar perfil\n";
                        cout<<" 0. Cerrar sesion\n";
                        cout<<"================================";
                        cout<<"Elige una opcion: "; cin>>subop;

                        int index;
                        switch(subop){
                            case 1:{
                                crearc_bancaria(cuentas, totalCuentas, clientes[i].DNI);
                                system("pause");
                                    break;
                            }

                            case 2:{
                                if(totalCuentas==0){
                                    cout<<"No hay cuentas asociadas a "<<clientes[i].nombre<<endl;
                                } else {
                                    mostrarc_bancaria(cuentas, totalCuentas, clientes[i].DNI);
                                    system("pause");
                                    }
                                break;
                            }

                            case 3:{                                                               
                                cout<<"Ingrese el numero de cuenta al cual depositar: ";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    depositar(cuentas[index]);
                                }
                                break;
                            }

                            case 4:{
                                cout << "Ingrese el numero de cuenta del cual retirar: ";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    retirar(cuentas[index]);
                                }
                                break;
                            }

                            case 5:{
                                cout << "Ingrese el numero de la cuenta: ";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    saldoActual(cuentas[index]);
                                }
                                break;
                            }

                            case 6:{
                                mostrarCliente(clientes[i]);
                                system("pause");
                                break;
                            }

                            case 0:{
                                cout<<"Esta seguro de salir? (S/N): ";
                                cin.ignore();
                                getline(cin, SN);
                                if (SN=="N" || SN=="n"){
                                    subop = -1;
                                }
                                break;
                            }

                            default:
                                cout << "Opcion no valida!\n";
                                system("pause");
                                break;
                        }

                    } while(subop != 0);
                }

                system("pause");
                break;
            }

            case 0:{
                cout << "Esta seguro de salir? (S/N): ";
                getline(cin, SN);
                if (SN=="N" || SN=="n"){
                    op=op+1;
                }
                break;
            }

            default:{
                cout << "Opcion no valida!\n";
                system("pause");
                break;
            }

        }
    } while (op!=0);
    return 0;
}
