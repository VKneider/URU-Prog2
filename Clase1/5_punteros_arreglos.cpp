/*
 * Archivo: 5_punteros_arreglos.cpp
 * Descripcion: Demostracion de punteros con arreglos estaticos y dinamicos
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <locale>
using namespace std;

// ============================================================================
// PUNTEROS CON ARREGLOS ESTÁTICOS
// ============================================================================

void demostrarArreglosEstaticos() {
    cout << "=== PUNTEROS CON ARREGLOS ESTÁTICOS ===" << endl;
    
    // Arreglo estático
    int numeros[5] = {10, 20, 30, 40, 50};
    
    // Puntero apuntando al primer elemento
    int* ptr = numeros; // Equivale a: int* ptr = &numeros[0];
    
    cout << "Arreglo estático: ";
    for (int i = 0; i < 5; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    // Acceso usando puntero
    cout << "Acceso con puntero: ";
    for (int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " "; // Aritmética de punteros
    }
    cout << endl;
    
    // Acceso usando notación de arreglo con puntero
    cout << "Notación de arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << ptr[i] << " ";
    }
    cout << endl;
    
    // Mostrar direcciones de memoria
    cout << "Direcciones de memoria:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "numeros[" << i << "] = " << numeros[i] 
             << " en dirección: " << &numeros[i] << endl;
    }
}

// ============================================================================
// PUNTEROS CON ARREGLOS DINÁMICOS
// ============================================================================

void demostrarArreglosDinamicos() {
    cout << "\n=== PUNTEROS CON ARREGLOS DINÁMICOS ===" << endl;
    
    int tamanio;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    
    // Crear arreglo dinámico
    int* arregloDinamico = new int[tamanio];
    
    // Llenar el arreglo
    cout << "Ingrese " << tamanio << " números:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Elemento " << i << ": ";
        cin >> arregloDinamico[i];
    }
    
    // Mostrar el arreglo
    cout << "Arreglo dinámico: ";
    for (int i = 0; i < tamanio; i++) {
        cout << arregloDinamico[i] << " ";
    }
    cout << endl;
    
    // Mostrar usando aritmética de punteros
    cout << "Usando aritmética de punteros: ";
    for (int i = 0; i < tamanio; i++) {
        cout << *(arregloDinamico + i) << " ";
    }
    cout << endl;
    
    // Liberar memoria
    delete[] arregloDinamico;
    arregloDinamico = nullptr;
    
    cout << "✓ Memoria liberada correctamente" << endl;
}

// ============================================================================
// ARREGLOS DE PUNTEROS
// ============================================================================

void demostrarArreglosDePunteros() {
    cout << "\n=== ARREGLOS DE PUNTEROS ===" << endl;
    
    // Arreglo de punteros a enteros
    int* punteros[3];
    
    // Asignar memoria dinámica a cada puntero
    for (int i = 0; i < 3; i++) {
        punteros[i] = new int(i * 10 + 5); // Valores: 5, 15, 25
    }
    
    // Mostrar valores
    cout << "Valores en arreglo de punteros:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "punteros[" << i << "] apunta a: " << *punteros[i] 
             << " en dirección: " << punteros[i] << endl;
    }
    
    // Modificar valores
    cout << "\nModificando valores..." << endl;
    for (int i = 0; i < 3; i++) {
        *punteros[i] *= 2; // Duplicar cada valor
    }
    
    // Mostrar valores modificados
    cout << "Valores después de modificar:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "punteros[" << i << "] = " << *punteros[i] << endl;
    }
    
    // Liberar memoria de cada puntero
    for (int i = 0; i < 3; i++) {
        delete punteros[i];
        punteros[i] = nullptr;
    }
    
    cout << "✓ Memoria de todos los punteros liberada" << endl;
}

// ============================================================================
// COMPARACIÓN: ESTÁTICO vs DINÁMICO
// ============================================================================

void compararEstaticoDinamico() {
    cout << "\n=== COMPARACIÓN: ESTÁTICO vs DINÁMICO ===" << endl;
    
    // Arreglo estático
    int estatico[3] = {100, 200, 300};
    cout << "Arreglo estático:" << endl;
    cout << "  Tamaño fijo: " << sizeof(estatico) / sizeof(int) << " elementos" << endl;
    cout << "  Memoria en stack" << endl;
    cout << "  Se libera automáticamente" << endl;
    
    // Arreglo dinámico
    int* dinamico = new int[3]{400, 500, 600};
    cout << "\nArreglo dinámico:" << endl;
    cout << "  Tamaño variable en tiempo de ejecución" << endl;
    cout << "  Memoria en heap" << endl;
    cout << "  Requiere liberación manual" << endl;
    
    // Mostrar valores
    cout << "\nValores:" << endl;
    cout << "Estático: ";
    for (int i = 0; i < 3; i++) {
        cout << estatico[i] << " ";
    }
    cout << endl;
    
    cout << "Dinámico: ";
    for (int i = 0; i < 3; i++) {
        cout << dinamico[i] << " ";
    }
    cout << endl;
    
    // Liberar memoria dinámica
    delete[] dinamico;
    dinamico = nullptr;
    
    cout << "\n✓ Ventajas del dinámico:" << endl;
    cout << "  - Tamaño variable" << endl;
    cout << "  - Más memoria disponible" << endl;
    cout << "  - Flexibilidad" << endl;
    
    cout << "\n✓ Ventajas del estático:" << endl;
    cout << "  - Más rápido" << endl;
    cout << "  - Sin riesgo de memory leaks" << endl;
    cout << "  - Más simple" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== PUNTEROS CON ARREGLOS ===" << endl;
    cout << "Enfoque: Arrays estáticos, dinámicos y arreglos de punteros\n" << endl;
    
    demostrarArreglosEstaticos();
    demostrarArreglosDinamicos();
    demostrarArreglosDePunteros();
    compararEstaticoDinamico();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Los punteros pueden apuntar a elementos de arreglos" << endl;
    cout << "✓ La aritmética de punteros permite navegar por arreglos" << endl;
    cout << "✓ Los arreglos dinámicos requieren liberación manual" << endl;
    cout << "✓ Los arreglos de punteros permiten estructuras flexibles" << endl;
    cout << "✓ Siempre liberar memoria asignada con new" << endl;
    
    return 0;
}
