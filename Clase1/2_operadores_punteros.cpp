#include <iostream>
#include <locale>
#include <string>
using namespace std;

// Función para demostrar aritmética de punteros
void demostrarAritmeticaPunteros() {
    cout << "=== ARITMÉTICA DE PUNTEROS ===" << endl;
    
    int arreglo[] = {10, 20, 30, 40, 50};
    int* ptr = arreglo; // ptr apunta al primer elemento
    
    cout << "Arreglo: ";
    for (int i = 0; i < 5; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    cout << "Dirección base del arreglo: " << arreglo << endl;
    cout << "ptr apunta a: " << ptr << endl;
    
    // Aritmética de punteros
    cout << "\nAritmética de punteros:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "ptr + " << i << " = " << (ptr + i) 
             << " -> valor: " << *(ptr + i) << endl;
    }
    
    // Comparación de punteros
    cout << "\nComparación de punteros:" << endl;
    int* ptr2 = arreglo + 2; // Apunta al tercer elemento
    cout << "ptr2 = ptr + 2: " << ptr2 << endl;
    cout << "ptr2 - ptr = " << (ptr2 - ptr) << " elementos" << endl;
    cout << "ptr < ptr2? " << (ptr < ptr2) << endl;
    
    cout << endl;
}

// Función para demostrar punteros a funciones
void funcionEjemplo() {
    cout << "Función ejecutada a través de puntero!" << endl;
}

void demostrarPunterosAFunciones() {
    cout << "=== PUNTEROS A FUNCIONES ===" << endl;
    
    // Declarar un puntero a función que no recibe parámetros y no retorna nada
    void (*ptrFuncion)() = funcionEjemplo;
    
    cout << "Dirección de la función: " << (void*)ptrFuncion << endl;
    cout << "Llamando función a través del puntero:" << endl;
    ptrFuncion(); // Llamada a través del puntero
    
    cout << endl;
}

// Función para demostrar punteros constantes
void demostrarPunterosConstantes() {
    cout << "=== PUNTEROS CONSTANTES ===" << endl;
    
    int valor1 = 100;
    int valor2 = 200;
    
    // Puntero constante (no se puede cambiar a qué apunta)
    int* const ptrConstante = &valor1;
    cout << "Puntero constante apunta a: " << ptrConstante << endl;
    cout << "Valor: " << *ptrConstante << endl;
    
    // Podemos cambiar el valor, pero no la dirección
    *ptrConstante = 150;
    cout << "Después de cambiar valor: " << *ptrConstante << endl;
    // ptrConstante = &valor2; // ¡ERROR! No se puede cambiar la dirección
    
    // Puntero a constante (no se puede cambiar el valor)
    const int* ptrAConstante = &valor1;
    cout << "Puntero a constante apunta a: " << ptrAConstante << endl;
    cout << "Valor (solo lectura): " << *ptrAConstante << endl;
    // *ptrAConstante = 300; // ¡ERROR! No se puede cambiar el valor
    ptrAConstante = &valor2; // Pero sí se puede cambiar la dirección
    cout << "Ahora apunta a: " << ptrAConstante << endl;
    
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== GUÍA AVANZADA DE OPERADORES DE PUNTEROS ===" << endl;
    cout << "Enfoque: Operadores & y *, Aritmética, Punteros a Funciones\n" << endl;

    // 1. OPERADORES FUNDAMENTALES & y *
    cout << "1. OPERADORES FUNDAMENTALES & y *:" << endl;
    cout << "----------------------------------" << endl;
    
    int numero = 42;
    cout << "Variable 'numero':" << endl;
    cout << "  Valor: " << numero << endl;
    cout << "  Dirección (&numero): " << &numero << endl;
    cout << "  Tamaño: " << sizeof(numero) << " bytes" << endl;
    
    int* puntero = &numero;
    cout << "\nPuntero 'puntero':" << endl;
    cout << "  Dirección del puntero (&puntero): " << &puntero << endl;
    cout << "  Valor del puntero (puntero): " << puntero << endl;
    cout << "  Valor apuntado (*puntero): " << *puntero << endl;
    cout << "  Tamaño del puntero: " << sizeof(puntero) << " bytes" << endl;
    
    // Demostrar que & y * son operadores inversos
    cout << "\nRelación inversa entre & y *:" << endl;
    cout << "  &numero = " << &numero << endl;
    cout << "  puntero = " << puntero << endl;
    cout << "  *puntero = " << *puntero << endl;
    cout << "  *(&numero) = " << *(&numero) << " (mismo que numero)" << endl;
    cout << "  &(*puntero) = " << &(*puntero) << " (mismo que puntero)" << endl;
    
    cout << endl;

    // 2. PUNTEROS A PUNTEROS (MÚLTIPLES NIVELES)
    cout << "2. PUNTEROS A PUNTEROS:" << endl;
    cout << "----------------------" << endl;
    
    int** punteroDoble = &puntero;
    int*** punteroTriple = &punteroDoble;
    
    cout << "Niveles de indirección:" << endl;
    cout << "  numero = " << numero << endl;
    cout << "  puntero = " << puntero << endl;
    cout << "  punteroDoble = " << punteroDoble << endl;
    cout << "  punteroTriple = " << punteroTriple << endl;
    
    cout << "\nAcceso a través de múltiples niveles:" << endl;
    cout << "  *puntero = " << *puntero << endl;
    cout << "  **punteroDoble = " << **punteroDoble << endl;
    cout << "  ***punteroTriple = " << ***punteroTriple << endl;
    
    // Modificar valor a través de múltiples niveles
    ***punteroTriple = 999;
    cout << "\nDespués de ***punteroTriple = 999:" << endl;
    cout << "  numero = " << numero << endl;
    
    cout << endl;

    // 3. ARITMÉTICA DE PUNTEROS
    demostrarAritmeticaPunteros();

    // 4. PUNTEROS A FUNCIONES
    demostrarPunterosAFunciones();

    // 5. PUNTEROS CONSTANTES
    demostrarPunterosConstantes();

    // 6. PUNTEROS Y ARREGLOS DINÁMICOS
    cout << "=== PUNTEROS Y ARREGLOS DINÁMICOS ===" << endl;
    
    int tamanio = 4;
    int* arregloDinamico = new int[tamanio];
    
    // Llenar arreglo
    for (int i = 0; i < tamanio; i++) {
        arregloDinamico[i] = (i + 1) * 100;
    }
    
    cout << "Arreglo dinámico usando notación de arreglo:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "arregloDinamico[" << i << "] = " << arregloDinamico[i] << endl;
    }
    
    cout << "\nMismo arreglo usando aritmética de punteros:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "*(arregloDinamico + " << i << ") = " << *(arregloDinamico + i) << endl;
    }
    
    cout << "\nDirecciones de memoria:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "&arregloDinamico[" << i << "] = " << &arregloDinamico[i] << endl;
    }
    
    delete[] arregloDinamico;
    arregloDinamico = nullptr;
    cout << "\nArreglo dinámico liberado." << endl;
    cout << endl;

    // 7. PUNTEROS Y ESTRUCTURAS
    cout << "=== PUNTEROS Y ESTRUCTURAS ===" << endl;
    
    struct Estudiante {
        string nombre;
        int edad;
        float promedio;
    };
    
    Estudiante estudiante = {"María", 20, 8.5};
    Estudiante* ptrEstudiante = &estudiante;
    
    cout << "Acceso a estructura a través de puntero:" << endl;
    cout << "  (*ptrEstudiante).nombre = " << (*ptrEstudiante).nombre << endl;
    cout << "  ptrEstudiante->nombre = " << ptrEstudiante->nombre << endl;
    cout << "  ptrEstudiante->edad = " << ptrEstudiante->edad << endl;
    cout << "  ptrEstudiante->promedio = " << ptrEstudiante->promedio << endl;
    
    // Modificar a través del puntero
    ptrEstudiante->edad = 21;
    ptrEstudiante->promedio = 9.0;
    
    cout << "\nDespués de modificar:" << endl;
    cout << "  edad = " << estudiante.edad << endl;
    cout << "  promedio = " << estudiante.promedio << endl;
    
    cout << endl;

    // 8. RESUMEN Y BUENAS PRÁCTICAS
    cout << "=== RESUMEN Y BUENAS PRÁCTICAS ===" << endl;
    cout << "✓ & obtiene la dirección de memoria de una variable" << endl;
    cout << "✓ * desreferencia un puntero para acceder al valor" << endl;
    cout << "✓ & y * son operadores inversos" << endl;
    cout << "✓ La aritmética de punteros permite navegar por arreglos" << endl;
    cout << "✓ Los punteros a funciones permiten programación dinámica" << endl;
    cout << "✓ Los punteros constantes protegen contra modificaciones" << endl;
    cout << "✓ Siempre liberar memoria dinámica con delete/delete[]" << endl;
    cout << "✓ Asignar nullptr después de delete" << endl;

    return 0;
}
