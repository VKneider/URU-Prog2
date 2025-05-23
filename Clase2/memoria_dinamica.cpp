#include <iostream>
#include <locale> // Para configurar acentos
using namespace std;

int main() {
	setlocale(LC_ALL, "spanish");
    cout << "Ejemplo de Asignación de Memoria Dinámica en C++\n" << endl;

    // Asignación dinámica para una sola variable
    cout << "1. Asignación dinámica para una sola variable:\n";
    int *punteroEntero = new int; // Reserva memoria para un entero
    *punteroEntero = 42;         // Asignamos un valor a esa memoria
    cout << "Valor almacenado en la memoria dinámica: " << *punteroEntero << endl;
    cout << "Dirección de memoria asignada: " << punteroEntero << endl;
    delete punteroEntero;        // Liberamos la memoria asignada
    punteroEntero = nullptr;     // Evitamos punteros colgantes
    cout << "Memoria liberada.\n" << endl;

    // Asignación dinámica para un arreglo
    cout << "2. Asignación dinámica para un arreglo:\n";
    int tamanio;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;

    int *arreglo = new int[tamanio]; // Reserva memoria para un arreglo de enteros
    cout << "Ingrese " << tamanio << " números:\n";
    for (int i = 0; i < tamanio; i++) {
        cin >> arreglo[i]; // Llenamos el arreglo
    }

    cout << "Números almacenados en el arreglo dinámico:\n";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;

    delete[] arreglo;           // Liberamos la memoria asignada al arreglo
    arreglo = nullptr;          // Evitamos punteros colgantes
    cout << "Memoria para el arreglo liberada.\n" << endl;

    // Asignación dinámica para una estructura
    struct Persona {
        string nombre;
        int edad;
    };

    cout << "3. Asignación dinámica para una estructura:\n";
    Persona *persona = new Persona; // Reserva memoria para una estructura
    cout << "Ingrese el nombre: ";
    cin >> persona->nombre;
    cout << "Ingrese la edad: ";
    cin >> persona->edad;

    cout << "Datos de la persona almacenados dinámicamente:\n";
    cout << "Nombre: " << persona->nombre << ", Edad: " << persona->edad << endl;

    delete persona;             // Liberamos la memoria asignada a la estructura
    persona = nullptr;          // Evitamos punteros colgantes
    cout << "Memoria para la estructura liberada.\n" << endl;

    return 0;
}
