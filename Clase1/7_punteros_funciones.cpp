/*
 * Archivo: 7_punteros_funciones.cpp
 * Descripcion: Demostracion de punteros a funciones basicos
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <locale>
using namespace std;

// ============================================================================
// FUNCIONES BÁSICAS PARA DEMOSTRAR
// ============================================================================

int sumar(int a, int b) {
    return a + b;
}

int restar(int a, int b) {
    return a - b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int dividir(int a, int b) {
    if (b != 0) {
        return a / b;
    }
    cout << "Error: División por cero" << endl;
    return 0;
}

// ============================================================================
// PUNTERO A FUNCIÓN INDIVIDUAL
// ============================================================================

void demostrarPunteroIndividual() {
    cout << "=== PUNTERO A FUNCIÓN INDIVIDUAL ===" << endl;
    
    // Declarar puntero a función que toma dos int y retorna int
    int (*operacion)(int, int);
    
    // Asignar función sumar al puntero
    operacion = sumar;
    
    int a = 10, b = 5;
    cout << "a = " << a << ", b = " << b << endl;
    
    // Usar el puntero para llamar la función
    cout << "Suma usando puntero: " << operacion(a, b) << endl;
    
    // Cambiar a función restar
    operacion = restar;
    cout << "Resta usando puntero: " << operacion(a, b) << endl;
    
    // Cambiar a función multiplicar
    operacion = multiplicar;
    cout << "Multiplicación usando puntero: " << operacion(a, b) << endl;
    
    cout << "✓ Puntero a función individual funcionando" << endl;
}

// ============================================================================
// ARREGLO DE PUNTEROS A FUNCIONES
// ============================================================================

void demostrarArregloPunterosFunciones() {
    cout << "\n=== ARREGLO DE PUNTEROS A FUNCIONES ===" << endl;
    
    // Arreglo de punteros a funciones
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar, dividir};
    string nombres[] = {"Sumar", "Restar", "Multiplicar", "Dividir"};
    
    int a, b;
    cout << "Ingrese dos números:" << endl;
    cout << "Primer número: ";
    cin >> a;
    cout << "Segundo número: ";
    cin >> b;
    
    cout << "\nResultados de todas las operaciones:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << nombres[i] << ": " << operaciones[i](a, b) << endl;
    }
    
    cout << "✓ Arreglo de punteros a funciones funcionando" << endl;
}

// ============================================================================
// MENÚ CON PUNTEROS A FUNCIONES
// ============================================================================

void mostrarMenuOperaciones() {
    cout << "\n=== MENÚ DE OPERACIONES ===" << endl;
    cout << "1. Sumar" << endl;
    cout << "2. Restar" << endl;
    cout << "3. Multiplicar" << endl;
    cout << "4. Dividir" << endl;
    cout << "5. Salir" << endl;
    cout << "Elija una operación: ";
}

void demostrarMenuConPunteros() {
    cout << "\n=== MENÚ CON PUNTEROS A FUNCIONES ===" << endl;
    
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar, dividir};
    string nombres[] = {"Sumar", "Restar", "Multiplicar", "Dividir"};
    
    int opcion;
    int a, b;
    
    do {
        mostrarMenuOperaciones();
        cin >> opcion;
        
        if (opcion >= 1 && opcion <= 4) {
            cout << "Ingrese dos números:" << endl;
            cout << "Primer número: ";
            cin >> a;
            cout << "Segundo número: ";
            cin >> b;
            
            int resultado = operaciones[opcion - 1](a, b);
            cout << "Resultado de " << nombres[opcion - 1] 
                 << ": " << resultado << endl;
        } else if (opcion == 5) {
            cout << "Saliendo..." << endl;
        } else {
            cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 5);
    
    cout << "✓ Menú con punteros a funciones funcionando" << endl;
}

// ============================================================================
// FUNCIONES CON DIFERENTES FIRMAS
// ============================================================================

void saludar() {
    cout << "¡Hola desde función sin parámetros!" << endl;
}

void saludarConNombre(string nombre) {
    cout << "¡Hola " << nombre << "!" << endl;
}

int obtenerNumero() {
    return 42;
}

void demostrarDiferentesFirmas() {
    cout << "\n=== FUNCIONES CON DIFERENTES FIRMAS ===" << endl;
    
    // Puntero a función sin parámetros y sin retorno
    void (*funcionVoid)() = saludar;
    funcionVoid();
    
    // Puntero a función con parámetro string
    void (*funcionString)(string) = saludarConNombre;
    funcionString("Juan");
    
    // Puntero a función que retorna int
    int (*funcionInt)() = obtenerNumero;
    cout << "Número obtenido: " << funcionInt() << endl;
    
    cout << "✓ Diferentes firmas de funciones funcionando" << endl;
}

// ============================================================================
// FUNCIÓN QUE RECIBE PUNTERO A FUNCIÓN COMO PARÁMETRO
// ============================================================================

// Función que recibe un puntero a función como parámetro
void ejecutarOperacion(int a, int b, int (*operacion)(int, int), string nombre) {
    cout << "Ejecutando " << nombre << "..." << endl;
    int resultado = operacion(a, b);
    cout << "Resultado: " << resultado << endl;
}

void demostrarFuncionConPunteroParametro() {
    cout << "\n=== FUNCIÓN CON PUNTERO A FUNCIÓN COMO PARÁMETRO ===" << endl;
    
    int a = 20, b = 4;
    
    cout << "a = " << a << ", b = " << b << endl;
    
    // Pasar diferentes funciones como parámetros
    ejecutarOperacion(a, b, sumar, "Suma");
    ejecutarOperacion(a, b, restar, "Resta");
    ejecutarOperacion(a, b, multiplicar, "Multiplicación");
    ejecutarOperacion(a, b, dividir, "División");
    
    cout << "✓ Función con puntero a función como parámetro funcionando" << endl;
}

// ============================================================================
// CASO PRÁCTICO: CALCULADORA SIMPLE
// ============================================================================

void calculadoraSimple() {
    cout << "\n=== CALCULADORA SIMPLE CON PUNTEROS ===" << endl;
    
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar, dividir};
    string nombres[] = {"+", "-", "*", "/"};
    
    int a, b, opcion;
    
    cout << "=== CALCULADORA ===" << endl;
    cout << "Ingrese primer número: ";
    cin >> a;
    cout << "Ingrese segundo número: ";
    cin >> b;
    
    cout << "\nOperaciones disponibles:" << endl;
    for (int i = 0; i < 4; i++) {
        cout << (i + 1) << ". " << nombres[i] << endl;
    }
    
    cout << "Elija operación (1-4): ";
    cin >> opcion;
    
    if (opcion >= 1 && opcion <= 4) {
        int resultado = operaciones[opcion - 1](a, b);
        cout << "\n" << a << " " << nombres[opcion - 1] << " " << b 
             << " = " << resultado << endl;
    } else {
        cout << "Operación inválida" << endl;
    }
    
    cout << "✓ Calculadora con punteros a funciones funcionando" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== PUNTEROS A FUNCIONES ===" << endl;
    cout << "Enfoque: Punteros individuales, arreglos, menús, parámetros\n" << endl;
    
    demostrarPunteroIndividual();
    demostrarArregloPunterosFunciones();
    demostrarMenuConPunteros();
    demostrarDiferentesFirmas();
    demostrarFuncionConPunteroParametro();
    calculadoraSimple();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Los punteros a funciones permiten programación dinámica" << endl;
    cout << "✓ Los arreglos de punteros a funciones crean menús flexibles" << endl;
    cout << "✓ Las funciones pueden recibir punteros a funciones como parámetros" << endl;
    cout << "✓ Útil para callbacks, menús dinámicos y programación modular" << endl;
    cout << "✓ La sintaxis es: tipo_retorno (*nombre_puntero)(parámetros)" << endl;
    
    return 0;
}
