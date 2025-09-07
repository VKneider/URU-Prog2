#include <iostream>
#include <locale>
#include <string>
#include <stdexcept>
using namespace std;

// Función para demostrar memory leak
void demostrarMemoryLeak() {
    cout << "=== DEMOSTRACIÓN DE MEMORY LEAK ===" << endl;
    cout << "Creando puntero sin liberar memoria..." << endl;
    int* ptrLeak = new int(999);
    cout << "Valor asignado: " << *ptrLeak << endl;
    cout << "Dirección: " << ptrLeak << endl;
    // ¡INTENCIONALMENTE NO LIBERAMOS LA MEMORIA!
    // delete ptrLeak; // Esta línea está comentada para demostrar el leak
    cout << "PUNTERO ABANDONADO - MEMORY LEAK CREADO!" << endl;
    cout << "La memoria nunca se liberará hasta que termine el programa." << endl;
    cout << endl;
}

// Función para demostrar puntero colgante
void demostrarPunteroColgante() {
    cout << "=== DEMOSTRACIÓN DE PUNTERO COLGANTE ===" << endl;
    int* ptrColgante = new int(777);
    cout << "Valor original: " << *ptrColgante << endl;
    cout << "Dirección original: " << ptrColgante << endl;
    
    delete ptrColgante; // Liberamos la memoria
    cout << "Memoria liberada." << endl;
    
    // ¡PELIGRO! El puntero aún apunta a memoria liberada
    cout << "PUNTERO COLGANTE - Apunta a memoria liberada!" << endl;
    cout << "Dirección del puntero colgante: " << ptrColgante << endl;
    // *ptrColgante = 100; // ¡CRASH! No hagas esto
    
    // SOLUCIÓN: Asignar nullptr después de delete
    ptrColgante = nullptr;
    cout << "Solución: Asignar nullptr después de delete" << endl;
    cout << "Nueva dirección: " << ptrColgante << endl;
    cout << endl;
}

// Función para demostrar doble liberación
void demostrarDobleLiberacion() {
    cout << "=== DEMOSTRACIÓN DE DOBLE LIBERACIÓN ===" << endl;
    int* ptr = new int(555);
    cout << "Memoria asignada: " << *ptr << endl;
    
    delete ptr; // Primera liberación - OK
    cout << "Primera liberación exitosa." << endl;
    
    // ptr = nullptr; // Comentado para demostrar el error
    
    cout << "¡PELIGRO! Intentando liberar la misma memoria dos veces..." << endl;
    // delete ptr; // ¡CRASH! No hagas esto - descomenta para ver el crash
    cout << "Solución: Asignar nullptr después del primer delete" << endl;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== GUÍA COMPLETA DE PUNTEROS Y MEMORIA DINÁMICA ===" << endl;
    cout << "Enfoque: Punteros, Memory Leaks, Punteros Colgantes y Buenas Prácticas\n" << endl;

    // 1. PUNTEROS BÁSICOS Y MEMORIA DINÁMICA
    cout << "1. PUNTEROS BÁSICOS Y MEMORIA DINÁMICA:" << endl;
    cout << "----------------------------------------" << endl;
    
    int* punteroEntero = new int(42);
    cout << "Valor almacenado: " << *punteroEntero << endl;
    cout << "Dirección de memoria: " << punteroEntero << endl;
    cout << "Dirección del puntero: " << &punteroEntero << endl;
    
    delete punteroEntero;
    punteroEntero = nullptr; // BUENA PRÁCTICA
    cout << "Memoria liberada correctamente.\n" << endl;

    // 2. ARREGLOS DINÁMICOS CON VALIDACIÓN
    cout << "2. ARREGLOS DINÁMICOS CON VALIDACIÓN:" << endl;
    cout << "-------------------------------------" << endl;
    
    int tamanio;
    cout << "Ingrese el tamaño del arreglo: ";
    cin >> tamanio;
    
    // VALIDACIÓN DE ENTRADA
    if (tamanio <= 0) {
        cout << "Error: El tamaño debe ser positivo. Usando tamaño por defecto (5)." << endl;
        tamanio = 5;
    }
    
    int* arreglo = new int[tamanio];
    cout << "Arreglo de " << tamanio << " elementos creado." << endl;
    
    // Llenar arreglo
    for (int i = 0; i < tamanio; i++) {
        arreglo[i] = (i + 1) * 10;
    }
    
    // Mostrar usando aritmética de punteros
    cout << "Elementos (usando aritmética de punteros): ";
    for (int i = 0; i < tamanio; i++) {
        cout << *(arreglo + i) << " ";
    }
    cout << endl;
    
    delete[] arreglo;
    arreglo = nullptr;
    cout << "Arreglo liberado correctamente.\n" << endl;

    // 3. ESTRUCTURAS DINÁMICAS
    cout << "3. ESTRUCTURAS DINÁMICAS:" << endl;
    cout << "-------------------------" << endl;
    
    struct Persona {
        string nombre;
        int edad;
        
        Persona(string n = "", int e = 0) : nombre(n), edad(e) {}
        
        void mostrar() {
            cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        }
    };
    
    Persona* persona = new Persona("Ana", 25);
    cout << "Persona creada dinámicamente:" << endl;
    persona->mostrar();
    cout << "Dirección: " << persona << endl;
    
    delete persona;
    persona = nullptr;
    cout << "Estructura liberada correctamente.\n" << endl;

    // 4. PUNTEROS A PUNTEROS
    cout << "4. PUNTEROS A PUNTEROS:" << endl;
    cout << "----------------------" << endl;
    
    int valor = 100;
    int* ptr1 = &valor;
    int** ptr2 = &ptr1;
    
    cout << "Valor original: " << valor << endl;
    cout << "Dirección de valor: " << &valor << endl;
    cout << "ptr1 apunta a: " << ptr1 << endl;
    cout << "ptr2 apunta a: " << ptr2 << endl;
    cout << "Acceso a valor a través de ptr2: " << **ptr2 << endl;
    cout << "Modificando valor a través de ptr2..." << endl;
    **ptr2 = 200;
    cout << "Nuevo valor: " << valor << endl;
    cout << endl;

    // 5. DEMOSTRACIONES DE ERRORES COMUNES
    cout << "5. ERRORES COMUNES CON PUNTEROS:" << endl;
    cout << "--------------------------------" << endl;
    
    demostrarMemoryLeak();
    demostrarPunteroColgante();
    demostrarDobleLiberacion();

    // 6. BUENAS PRÁCTICAS
    cout << "6. BUENAS PRÁCTICAS:" << endl;
    cout << "-------------------" << endl;
    cout << "✓ Siempre inicializar punteros" << endl;
    cout << "✓ Verificar que new no retorne nullptr" << endl;
    cout << "✓ Liberar memoria con delete/delete[]" << endl;
    cout << "✓ Asignar nullptr después de delete" << endl;
    cout << "✓ Usar delete[] para arreglos" << endl;
    cout << "✓ Validar entrada del usuario" << endl;
    cout << "✓ Evitar punteros colgantes" << endl;
    cout << "✓ Evitar memory leaks" << endl;
    cout << "✓ Evitar doble liberación" << endl;

    return 0;
}
