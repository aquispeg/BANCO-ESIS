#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "cuenta.h"
#include "cliente.h"

using namespace std;

void crearc_bancaria(cuenta cuentas[], int &totCuentas, string DNI) {
    bool repetido;
    string ncuenta;
    do {
        repetido = false;
        int nrandom=(rand()%9000)+1000;
        ncuenta="5400-1234-5678-";
        ncuenta+=to_string(nrandom);

        for (int i = 0; i < totCuentas; i++) {
            if (cuentas[i].ncuenta == ncuenta){
                repetido = true;
                break;
            }
        }
    } while (repetido);

    cuentas[totCuentas].DNI = DNI;
    cuentas[totCuentas].ncuenta=ncuenta;
    cuentas[totCuentas].saldo = 0;
    cout << "\033[32m\nCuenta bancaria creada correctamente.\n\033[0m";
    cout << "\033[36mNumero de la nueva cuenta: \033[0m" << cuentas[totCuentas].ncuenta << endl;
    totCuentas++;
}

void mostrarc_bancaria(cuenta cuentas[], cliente clientes[] ,int totCuentas, int index) {
    int inom;
    
    if(totCuentas==0){
        cout<<"\n\033[36mNo hay cuentas asociadas a \033[0m"<<clientes[index].nombre<<endl;
        return;
    }

    time_t tiempo = time(0);
    char horayfecha[80];
    strftime(horayfecha, 80, "%d/%m/%Y %H:%M:%S", localtime(&tiempo));

    for(int i=0;i<totCuentas;i++){
        if(clientes[i].DNI==clientes[index].DNI){
            inom=i;
        }
    }

    cout<<"\033[34m\n----------------------------------------------------------------------\033[0m"<<endl;
    cout<<"\033[36m\t\t\t      BANCO ESIS\033[0m"<<endl;
    cout<<"\033[34m----------------------------------------------------------------------\033[0m"<<endl;
    cout<<"\t\t\t\t\t\t"<<horayfecha<<endl;
    cout<<"\033[93m  Usuario: \033[0m"<<clientes[inom].nombre<<"\t\t"<<endl;
    cout<<"\033[34m----------------------------------------------------------------------\033[0m"<<endl;
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].DNI == clientes[index].DNI) {
            cout<<"\033[36m  Numero de cuenta: \033[0m"<<cuentas[i].ncuenta << endl;
            cout<<"\033[32m  Saldo:\033[0m S/"<<cuentas[i].saldo<<"\t"<<endl;
            cout<<"\033[34m----------------------------------------------------------------------\033[0m"<<endl;
        }
    }
}

int buscarCuenta(cuenta cuentas[], int totCuentas, string numeroCuenta, string DNI) {
    for (int i = 0; i < totCuentas; i++) {
        if (cuentas[i].ncuenta == numeroCuenta && cuentas[i].DNI == DNI) {
            return i;
        }
    }
    cout << "\033[31mError: Cuenta no encontrada.\033[0m"<<endl<<endl;
    return -1;
}
