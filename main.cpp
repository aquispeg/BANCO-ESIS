#include <iostream>
#include <ctime>
#include "cliente.h"
#include "cuenta.h"
#include "operaciones.h"

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
    srand(time(0));

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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "\033[31mEntrada inválida. Por favor, ingrese un número.\033[0m\n";
            continue;
        }

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
                        cout<<" 7. Mostrar historial\n";
                        cout<<" 0. Cerrar sesion\n";
                        cout<<"\033[34m==============================\n";
                        cout<<"\033[36mElige una opcion: \033[0m"; cin>>subop;

                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(10000, '\n');
                            cout << "\033[31mEntrada inválida. Por favor, ingrese un número.\033[0m\n";
                            continue;
                        }

                        int index;
                        switch(subop){
                            case 1:{
                                crearc_bancaria(cuentas, totalCuentas, clientes[i].DNI);
                                break;
                            }

                            case 2:{
                                 mostrarc_bancaria(cuentas, clientes, totalCuentas, i);
                                break;
                            }

                            case 3:{                                
                                depositar(cuentas, totalCuentas, dniBuscado, clientes[i].nombre);
                                break;
                            }

                            case 4:{
                                retirar(cuentas, totalCuentas, dniBuscado, clientes[i].nombre);
                                break;
                            }

                            case 5:{
                                saldoActual(cuentas, totalCuentas, dniBuscado, clientes[i].nombre);
                                break;
                            }

                            case 6:{
                                mostrarCliente(clientes[i]);
                                break;
                            }

                            case 7:{
                                mostrarHistorial(cuentas, totalCuentas, dniBuscado, clientes[i].nombre);
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
