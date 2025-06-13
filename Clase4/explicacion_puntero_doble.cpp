#include <iostream>
#include <locale>

using namespace std;

int main() {
	setlocale(LC_ALL, "Spanish");
    cout << "=============================================\n";
    cout << "    EXPLICACIÓN DE int** EN MATRICES DINÁMICAS \n";
    cout << "=============================================\n\n";

    cout << "?? Un puntero doble (int**) se usa para representar una matriz dinámica.\n";
    cout << "?? En memoria, se asigna primero un array de punteros (filas) y luego cada puntero apunta a un array de enteros (columnas).\n\n";

    // Definir tamaño de la matriz
    int filas = 3, columnas = 3;

    cout << "?? Reservamos memoria dinámicamente para una matriz de " << filas << "x" << columnas << ".\n";

    // Paso 1: Crear un puntero doble (matriz de punteros)
    int** matriz = new int*[filas]; // Reserva memoria para las filas

    // Paso 2: Asignar memoria para cada fila
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas]; // Cada fila es un array de enteros
    }

    cout << "? Matriz dinámica creada correctamente.\n\n";

    // Paso 3: Llenar la matriz con valores de ejemplo
    cout << "?? Llenamos la matriz con valores.\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = (i + 1) * (j + 1); // Valores de ejemplo
        }
    }

    // Paso 4: Mostrar la matriz
    cout << "\n?? Mostrando la matriz en pantalla:\n";
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\n?? Ahora liberamos la memoria para evitar fugas.\n";

    // Paso 5: Liberar memoria (IMPORTANTE)
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i]; // Liberar cada fila
    }
    delete[] matriz; // Liberar el array de punteros

    cout << "? Memoria liberada correctamente.\n";

    return 0;
}

