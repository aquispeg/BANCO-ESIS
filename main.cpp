#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
struct cliente{
    string nombre;
    int DNI, edad, ncuenta;
};

int main(){
    int op, n, ncuenta;
    string SN,nom;
    int DNI,edad;
    cliente cli;
    cliente ctot[50];
    cliente ctotpre[50];



    do{


        system("cls");
        cout<<":::::::::::::BANCO ESIS:::::::::::::"<<endl;
        cout<<"---Menu de opciones-----------------"<<endl;
        cout<<" 1. Crear Cuenta"<<endl;
        cout<<" 2. Iniciar Sesion"<<endl;
        cout<<" 0. Salir"<<endl;
        cout<<"Elige Una Opcion: ";cin>>op;
        switch(op){
            case 1:
            cout<<"Coloque la cantidad de cuentas que va a crear: ";
            cin>>n;
            for(int i=0;i<n;i++){
            cin.ignore();
                cout<<"Nuevo Cliente:\n";
                cout<<"Ingrese su nombre: ";
                getline(cin,ctot[i].nombre);

                cout<<"Ingrese su DNI: ";
                cin>>ctot[i].DNI;
                if(ctot[i].DNI<9999999 || ctot[i].DNI>99999999){
                cout<<"El DNI ingresado no existe :("<<endl;
                }
                else{
                srand(time(0));
                ctot[i].ncuenta=rand();
                ctot[i].ncuenta=(rand()%9999)+1;

                cout<<"Su numero de cuenta es:"<<endl<<"1234-5678-9012-"<<ctot[i].ncuenta<<endl;


                }
                cout<<"======================"<<endl;

                }
            break;
            case 2:
            for(int i=0;i<n;i++){
            cin.ignore();
            cout<<"Ingrese su nombre: ";
            getline(cin,ctotpre[i].nombre);

            if(ctotpre[i].nombre==ctot[i].nombre){
            cout<<"Bienvenido :D"<<endl;
            cout<<"Su DNI es: "<<ctot[i].DNI<<endl;
            cout<<"Su numero de cuenta es: "<<"1234-5678-9012-"<<ctot[i].ncuenta<<endl;
            }

            }
            break;
            case 0:
                cout<<"¿Esta Seguro de Salir? (S/N): ";
                cin>>SN;
                if (SN=="N" || SN=="n"){
                    op=op+1;
                }
                else{
                return 1;
                }
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    }
    while (op!=0);

}

