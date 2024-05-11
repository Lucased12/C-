#include <iostream>
#include <iomanip>
#include <cstdlib> //Para la funcion rand y srand
#include <ctime>   //Para la funcion time

using namespace std;

const int filas = 5;
const int columnas = 5;
char asientos[filas][columnas];

//Funcion para inicializar los asientos de manera aleatoria
void inicializarAsientosAleatorios() {
    srand(time(0)); //Semilla para los numeros aleatorios basada en el tiempo actual
    
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            //Generar un número aleatorio entre 0 y 1
            int aleatorio = rand() % 2;
            if (aleatorio == 0) {
                asientos[i][j] = 'o'; // 'o' representa un asiento libre
            } else {
                asientos[i][j] = 'i'; // 'x' representa un asiento ocupado
            }
        }
    }
}

//Funcion para mostrar el mapa de asientos
void mostrarMapaAsientos() {
    cout << "Mapa de asientos:\n";
    for (int i = 0; i < filas; ++i) {
        for (int j = 0; j < columnas; ++j) {
            cout << '|' << asientos[i][j] << '|';
        }
        cout << endl;
    }
}

//Funcion para reservar un asiento
void reservarAsiento(int fila, int columna) {
    if (fila >= 0 && fila < filas && columna >= 0 && columna < columnas) {
        if (asientos[fila][columna] == 'o') {
            asientos[fila][columna] = 'i'; //'i'representa un asiento ocupado
            cout << "Asiento reservado!\n";
        } else {
            cout << "No se puede reservar este asiento, esta ocupado.\n";
        }
    } else {
        cout << "Fila o columna invalida.\n";
    }
}

int main() {
    inicializarAsientosAleatorios();
    
    while (true) {
        mostrarMapaAsientos();
        
        int opcion;
        cout << "\nOpciones disponibles:\n";
        cout << "1. Reservar asiento\n";
        cout << "2. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        
        if (opcion == 1) {
            int fila, columna;
            cout << "Ingrese la fila del asiento: ";
            cin >> fila;
            cout << "Ingrese la columna del asiento: ";
            cin >> columna;
            reservarAsiento(fila - 1, columna - 1); //Con esto eliminamos la 0,0
        } else if (opcion == 2) {
            cout << "Gracias por usar el sistema de reserva!\n";
            break;
        } else {
            cout << "Opcion invalida, usar otra opcion.\n";
        }
    }

    return 0;
}

