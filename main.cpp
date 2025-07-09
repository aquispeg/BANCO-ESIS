#include <iostream>
using namespace std;
struct cliente{
    string nombre;
    int DNI;
    int edad;
};
int main(){
    int op;
    string SN;
    string nom;
    int DNI,edad;
    cliente cte, lista[50];
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
            break;
            case 2:
            break;
            case 0:
                cout<<"¿Esta Seguro de Salir? (S/N): ";
                cin>>SN;
                if (SN=="N" || SN=="n"){
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
}