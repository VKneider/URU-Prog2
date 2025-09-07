#include <iostream>
#include <string>
#include <locale> // Para configurar acentos

using namespace std;

// Programa de introducción a punteros en C++
int main() {
	setlocale(LC_ALL, "spanish");
    // 1. Declaración de punteros
    
    // -------------------------------------
    int numero = 42;       // Variable normal
    int* punteroNumero = &numero; // Puntero que almacena la dirección de memoria de la variable 'numero'


    cout << "=== Introducción a punteros ===" << endl;
    cout << "Valor de 'numero': " << numero << endl;
    cout << "Dirección de 'numero' (&numero): " << &numero << endl;
    cout << "Valor almacenado en 'punteroNumero': " << punteroNumero << endl;
    cout << "Valor al que apunta 'punteroNumero' (*punteroNumero): " << *punteroNumero << endl;

    // **Nota:** El operador '&' obtiene la dirección de memoria de una variable,
    // y el operador '*' (indirección) permite acceder al valor almacenado en esa dirección.

    cout << "\n";

    // 2. Modificación de valores a través de punteros
    // -------------------------------------
    *punteroNumero = 100; // Cambiamos el valor al que apunta el puntero
    cout << "Nuevo valor de 'numero' (modificado usando el puntero): " << numero << endl;

    cout << "\n";

    // 3. Punteros y arreglos
    // -------------------------------------
    // Los punteros están directamente relacionados con los arreglos en C++.
    // El nombre de un arreglo es un puntero al primer elemento del arreglo.

    int arreglo[] = {10, 20, 30, 40, 50};
    int* punteroArreglo = arreglo; // El nombre del arreglo es equivalente a un puntero al primer elemento

    cout << "=== Punteros y arreglos ===" << endl;
    cout << "Primer elemento del arreglo (usando puntero): " << *punteroArreglo << endl;

    // Iteramos sobre el arreglo utilizando punteros
    cout << "Elementos del arreglo (usando punteros): " << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Elemento " << i << ": " << *(punteroArreglo + i) << endl; // *(puntero + i) accede al elemento i
    }

    cout << "\n";

    // 4. Punteros y funciones
    // -------------------------------------
    // Los punteros permiten pasar variables por referencia a las funciones.

    // Función para incrementar un valor
    auto incrementar = [](int* ptr) {
        *ptr += 10; // Incrementa el valor al que apunta el puntero
    };

    cout << "=== Punteros y funciones ===" << endl;
    cout << "Valor de 'numero' antes de incrementar: " << numero << endl;
    incrementar(&numero); // Pasamos la dirección de 'numero'
    cout << "Valor de 'numero' después de incrementar: " << numero << endl;

    cout << "\n";

    // 5. Punteros dinámicos (uso de memoria dinámica)
    // -------------------------------------
    // Los punteros se utilizan para trabajar con memoria dinámica, permitiendo reservar espacio
    // en tiempo de ejecución.

    int* punteroDinamico = new int; // Asignamos espacio en memoria para un entero
    *punteroDinamico = 500;         // Almacenamos un valor en el espacio reservado

    cout << "=== Punteros dinámicos ===" << endl;
    cout << "Valor almacenado en memoria dinámica: " << *punteroDinamico << endl;
    cout << "Dirección en memoria dinámica: " << punteroDinamico << endl;

    // Es importante liberar la memoria cuando ya no la necesitemos
    delete punteroDinamico; // Liberamos la memoria asignada
    punteroDinamico = nullptr; // Buenas prácticas: evitar punteros colgantes

    cout << "\n";

    // 6. Null pointers (punteros nulos)
    // -------------------------------------
    // Un puntero nulo no apunta a ninguna dirección válida.
    int* punteroNulo = nullptr;

    cout << "=== Punteros nulos ===" << endl;
    if (punteroNulo == nullptr) {
        cout << "El puntero no apunta a ninguna dirección válida." << endl;
    }

    cout << "\n";

    // 7. Punteros a cadenas de caracteres
    // -------------------------------------
    // Los punteros se pueden usar para trabajar con cadenas de caracteres.

    const char* cadena = "Hola, mundo!";
    cout << "=== Punteros y cadenas ===" << endl;
    cout << "Cadena original: " << cadena << endl;

    // Iterar sobre una cadena utilizando un puntero
    const char* punteroCadena = cadena;
    cout << "Caracteres de la cadena (usando puntero): ";
    while (*punteroCadena != '\0') { // '\0' indica el final de la cadena
        cout << *punteroCadena << " ";
        punteroCadena++;
    }
    cout << endl;

    return 0;
}
