#include <iostream>
#include <locale>
using namespace std;

class Matriz {
private:
    int filas;
    int columnas;
    int** datos;

public:
    // Constructor
    Matriz(int f, int c) : filas(f), columnas(c) {
        datos = new int*[filas];
        for (int i = 0; i < filas; i++) {
            datos[i] = new int[columnas];
            for (int j = 0; j < columnas; j++) {
                datos[i][j] = 0; // Inicializa con ceros
            }
        }
    }

    // Destructor
    ~Matriz() {
        for (int i = 0; i < filas; i++) {
            delete[] datos[i];
        }
        delete[] datos;
    }

    // M�todo para llenar la matriz con valores ingresados por el usuario
    void llenarMatriz() {
        cout << "Ingrese los valores de la matriz (" << filas << "x" << columnas << "):\n";
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> datos[i][j];
            }
        }
    }

    // M�todo para imprimir la matriz
    void imprimirMatriz() {
    }


    // M�todo para transponer la matriz (por completar)
    void transponer() {
        // TODO: Implementar la transposici�n de la matriz
    }
};

int main() {
	setlocale(LC_ALL, "Spanish");
    int filas, columnas;

    cout << "Ingrese el n�mero de filas: ";
    cin >> filas;
    cout << "Ingrese el n�mero de columnas: ";
    cin >> columnas;

    Matriz matriz(filas, columnas);
    matriz.llenarMatriz();
    matriz.imprimirMatriz();

    // Los estudiantes deber�n implementar los m�todos adicionales

    return 0;
}

