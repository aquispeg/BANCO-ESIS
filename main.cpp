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
        cout<<"\n\033[34m============= BANCO ESIS =============\033[36m\n";
        cout<<"---------- Menu de opciones ----------\n";
        cout<<" 1. Crear cuenta\n";
        cout<<" 2. Iniciar sesion\n";
        cout<<" 0. Salir\n";
        cout<<"\033[34m======================================\n";
        cout<<"\033[36mElige una opcion: \033[0m"; cin>>op;
        cin.ignore();

        switch (op) {
            case 1: {
                if ( totalClientes < 50 ) {
                    clientes[totalClientes] = registrarCliente();
                    if(cuentaExistente(clientes, totalClientes)){
                        cout<<"\033[31mError: Cuenta ya existente.\033[0m\n";
                    } else {
                    cout<<"\n\033[32mCuenta creada correctamente.\033[0m\n";
                    }
                } else {
                    cout<<"\n\033[31mLimite de cuentas alcanzado.\033[0m\n";
                }
                system("pause");
                break;
            }

            case 2: {
                encontrado = false;

                if(totalClientes == 0){
                    cout<<"\033[31mNo hay cuentas registradas.\033[0m"<<endl;
                    system("pause");
                    break;
                }

                do {
                    cout<<"Ingrese su DNI: ";
                    getline(cin, dniBuscado);
                    if (!esDniValido(dniBuscado)){
                    cout << "Error: DNI invalido. Debe tener exactamente 8 digitos numericos.\n"; 
                    }
                } while (!esDniValido(dniBuscado));
                do {
                    cout<<"Ingrese su contrasena: ";    
                    getline(cin, contraIngresada);
                    if (!esContrasenaValido(contraIngresada)){
                        cout<<"Error: Contrasena invalida. Debe tener de 4 a 10 digitos.\n";
                    }
                } while (!esContrasenaValido(contraIngresada));

                int i;
                for(i=0; i<totalClientes; i++){
                    if(clientes[i].DNI==dniBuscado && clientes[i].contrasena == contraIngresada){
                        system("cls");
                        cout<<"\n\033[32mBienvenido(a) " << clientes[i].nombre << "\033[0m\n";
                        mostrarCliente(clientes[i]);                       
                        encontrado=true;
                        system("pause");
                        break;
                    }
                }

                if(!encontrado){
                    cout<<"\n\033[31mDNI o contrasena incorrecta.";
                    cout<<"\n------Acceso denegado------\033[0m\n";
                    system("pause");
                } else {
                    do{                        
                        system("cls");
                        cout<<"\n\033[34m======= MENU DE USUARIO ======\033[36m\n";
                        cout<<" 1. Crear cuenta bancaria\n";
                        cout<<" 2. Ver cuentas\n";
                        cout<<" 3. Depositar\n";
                        cout<<" 4. Retirar\n";
                        cout<<" 5. Consultar saldo\n";
                        cout<<" 6. Mostrar perfil\n";
                        cout<<" 0. Cerrar sesion\n";
                        cout<<"\033[34m================================\n";
                        cout<<"\033[36mElige una opcion: \033[0m"; cin>>subop;

                        int index;
                        switch(subop){
                            case 1:{
                                crearc_bancaria(cuentas, totalCuentas, clientes[i].DNI);
                                break;
                            }

                            case 2:{
                                if(totalCuentas==0){
                                    cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<clientes[i].nombre<<endl;
                                } else {
                                    mostrarc_bancaria(cuentas, totalCuentas, clientes[i].DNI);
                                    }
                                break;
                            }

                            case 3:{                                                               
                                cout << "\033[36mIngrese el numero de cuenta al cual depositar: \033[0m";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    depositar(cuentas[index]);
                                }
                                break;
                            }

                            case 4:{

                                cout << "\033[36mIngrese el numero de cuenta del cual retirar: \033[0m";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    retirar(cuentas[index]);
                                }
                                break;
                            }

                            case 5:{
                                cout << "\033[36mIngrese el numero de la cuenta: \033[0m";
                                cin >> numeroCuenta;
                                index = buscarCuenta(cuentas, totalCuentas, numeroCuenta, dniBuscado);
                                if (index != -1){
                                    saldoActual(cuentas[index]);
                                }
                                break;
                            }

                            case 6:{
                                mostrarCliente(clientes[i]);
                                break;
                            }

                            case 0:{
                                cout<<"\033[36mEsta seguro de salir? (S/N): \033[0m";
                                cin.ignore();
                                getline(cin, SN);
                                if (SN=="N" || SN=="n"){
                                    subop = -1;
                                }
                                break;
                            }

                            default:
                                cout << "\033[31mError: Opcion no valida\033[0m\n";
                                system("pause");
                                break;
                        }
                        system("pause");
                        
                    } while(subop != 0);
                }
                break;
            }

            case 0:{
                cout<<"\033[36mEsta seguro de salir? (S/N): \033[0m";
                getline(cin, SN);
                if (SN=="N" || SN=="n"){
                    op=op+1;
                }
                break;
            }

            default:{
                cout << "\033[31mError: Opcion no valida\033[0m\n";
                system("pause");
                break;
            }

        }
    } while (op!=0);
    return 0;
}