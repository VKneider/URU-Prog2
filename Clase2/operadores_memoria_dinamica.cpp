#include <iostream>
using namespace std;
#include <locale> // Para configurar acentos

int main() {
	setlocale(LC_ALL, "spanish");
    // -------------------------------------------------------
    // Ejemplo 1: Asignación de memoria dinámica para un solo valor.
    // -------------------------------------------------------

    // Usando 'new' para asignar memoria para un solo entero
    int* ptr = new int;  // Reserva memoria dinámica para un solo entero

    // Asignamos un valor a la memoria que hemos reservado
    *ptr = 10;  // Asignamos el valor 10 al lugar de memoria apuntado por ptr

    // Mostramos el valor que almacenamos en la memoria dinámica
    cout << "Valor almacenado en la memoria dinámica (entero): " << *ptr << endl;

    // Usamos 'delete' para liberar la memoria que habíamos reservado
    delete ptr;  // Libera la memoria dinámica reservada para un solo entero
    ptr = nullptr;  // Igualamos el puntero a nullptr para evitar el uso accidental

    cout << "Memoria liberada para el entero" << endl;

    // -------------------------------------------------------
    // Ejemplo 2: Asignación de memoria dinámica para un arreglo.
    // -------------------------------------------------------

    // Usando 'new[]' para reservar memoria para un arreglo de 5 enteros
    int* arreglo = new int[5];  // Reserva memoria para 5 enteros

    // Asignamos valores a cada elemento del arreglo
    for (int i = 0; i < 5; ++i) {
        arreglo[i] = i + 1;  // Asignamos 1, 2, 3, 4, 5 a los elementos del arreglo
    }

    // Mostramos los valores almacenados en el arreglo
    cout << "Elementos del arreglo dinámico: ";
    for (int i = 0; i < 5; ++i) {
        cout << arreglo[i] << " ";  // Imprime los valores almacenados en el arreglo
    }
    cout << endl;

    // Usamos 'delete[]' para liberar la memoria reservada para el arreglo
    delete[] arreglo;  // Libera la memoria dinámica reservada para el arreglo
    arreglo = nullptr;  // Igualamos el puntero a nullptr para evitar el uso accidental

    cout << "Memoria liberada para el arreglo" << endl;

    // -------------------------------------------------------
    // Ejemplo 3: Asignación dinámica de objetos de clase.
    // -------------------------------------------------------

    // Definimos una clase simple para ilustrar la asignación de memoria para objetos
    class Persona {
    public:
        string nombre;
        int edad;

        // Constructor
        Persona(string n, int e) : nombre(n), edad(e) {}

        // Método para mostrar los datos de la persona
        void mostrarDatos() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };

    // Usamos 'new' para crear un objeto dinámico de la clase Persona
    Persona* personaPtr = new Persona("Juan", 30);  // Crea un objeto Persona dinámicamente

    // Llamamos a un método de la clase para mostrar los datos del objeto
    personaPtr->mostrarDatos();  // Accedemos al método usando el puntero

    // Usamos 'delete' para liberar la memoria asignada para el objeto
    delete personaPtr;  // Libera la memoria dinámica para el objeto
    personaPtr = nullptr;  // Igualamos el puntero a nullptr para evitar el uso accidental

    cout << "Memoria liberada para el objeto Persona" << endl;

    return 0;
}
