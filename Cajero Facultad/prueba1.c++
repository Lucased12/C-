//Proyecto Lucas Ducamp UTN
//Tecnicatura Universitaria En Programacion.

#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    //Variable para almacenar el saldo inicial del usuario
    int saldo = 0;

    //Solicitar al usuario que ingrese su saldo inicial
    cout << "\n\n";
    cout << "Ingrese su saldo inicial: ";
    cin >> saldo;

    //Ciclo while para que el usuario pueda realizar transacciones
    while (true) {
        //Mostrar opciones
        cout << "\nOpciones disponibles:\n";
        cout << "1 - Consultar saldo\n";
        cout << "2 - Retirar dinero\n";
        cout << "3 - Depositar dinero\n";
        cout << "4 - Salir\n";
        cout << "Seleccione una opción: ";

        //Variable para almacenar la opcion
        int opcion;
        cin >> opcion;

        //Realizar la operacion
        switch(opcion) {
            case 1:
                //Consultar saldo
                cout << "Su saldo actual es: " << saldo << " $\n";
                break;
            case 2: {
                //Retirar dinero
                int cantidad;
                cout << "Ingrese la cantidad que desea retirar: ";
                cin >> cantidad;

                //Verificar que la cantidad sea válida y que no exceda el saldo disponible
                if (cantidad <= 0) {
                    cout << "Cantidad invalida\n";
                } else if (cantidad > saldo) {
                    cout << "Saldo insuficiente\n";
                } else {
                    saldo -= cantidad;
                    cout << "Ha retirado " << cantidad << " $. Su saldo actual es de: " << saldo << " pesos\n";
                }
                break;
            }
            case 3: {
                //Depositar dinero
                int cantidad;
                cout << "Ingrese la cantidad que desea depositar: ";
                cin >> cantidad;

                //Verificar que la cantidad sea válida
                if (cantidad <= 0) {
                    cout << "Cantidad invalida\n";
                } else {
                    saldo += cantidad;
                    cout << "Ha depositado " << cantidad << " $. Su saldo actual es de: " << saldo << " pesos\n";
                }
                break;
            }
            case 4:
                //Salir del programa
                cout << "Gracias por utilizar el cajero. Hasta luego!\n";
                exit(0);
            default:
                //Mostrar erro
                cout << "Opcion invalida. Por favor seleccione una opción valida.\n";
                exit(0);
        }
    }

    return 0;
}
