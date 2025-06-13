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

    // Método para llenar la matriz con valores ingresados por el usuario
    void llenarMatriz() {
        cout << "Ingrese los valores de la matriz (" << filas << "x" << columnas << "):\n";
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << "Elemento [" << i << "][" << j << "]: ";
                cin >> datos[i][j];
            }
        }
    }

    // Método para imprimir la matriz
    void imprimirMatriz() {
    }


    // Método para transponer la matriz (por completar)
    void transponer() {
        // TODO: Implementar la transposición de la matriz
    }
};

int main() {
	setlocale(LC_ALL, "Spanish");
    int filas, columnas;

    cout << "Ingrese el número de filas: ";
    cin >> filas;
    cout << "Ingrese el número de columnas: ";
    cin >> columnas;

    Matriz matriz(filas, columnas);
    matriz.llenarMatriz();
    matriz.imprimirMatriz();

    // Los estudiantes deberán implementar los métodos adicionales

    return 0;
}

