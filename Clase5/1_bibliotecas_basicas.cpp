/*
 * Archivo: 1_bibliotecas_basicas.cpp
 * Descripción: Conceptos fundamentales de bibliotecas en C++
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
==================================================================================
    BIBLIOTECAS EN C++
==================================================================================
    Las bibliotecas en C++ son colecciones de funciones, clases y objetos
    predefinidos que nos permiten:
    1. Reutilizar código existente
    2. Organizar mejor nuestros programas
    3. Separar la implementación de la interfaz
    4. Facilitar el mantenimiento y actualización
    5. Trabajar en equipo de manera eficiente
*/

// ==============================================================================
// EJEMPLO 1: Funciones matemáticas básicas
// ==============================================================================

// Función para calcular el área de un círculo
double calcularAreaCirculo(double radio) {
    return M_PI * radio * radio;
}

// Función para calcular el perímetro de un rectángulo
double calcularPerimetroRectangulo(double largo, double ancho) {
    return 2 * (largo + ancho);
}

// Función para calcular la distancia entre dos puntos
double calcularDistancia(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// ==============================================================================
// EJEMPLO 2: Funciones de utilidad para strings
// ==============================================================================

// Función para convertir texto a mayúsculas
string convertirMayusculas(const string& texto) {
    string resultado = texto;
    for (char& c : resultado) {
        c = toupper(c);
    }
    return resultado;
}

// Función para contar palabras en un texto
int contarPalabras(const string& texto) {
    if (texto.empty()) return 0;
    
    int contador = 1;
    for (char c : texto) {
        if (c == ' ') {
            contador++;
        }
    }
    return contador;
}

// Función para verificar si un texto es palíndromo
bool esPalindromo(const string& texto) {
    string textoLimpio = "";
    for (char c : texto) {
        if (isalpha(c)) {
            textoLimpio += tolower(c);
        }
    }
    
    int inicio = 0;
    int fin = textoLimpio.length() - 1;
    
    while (inicio < fin) {
        if (textoLimpio[inicio] != textoLimpio[fin]) {
            return false;
        }
        inicio++;
        fin--;
    }
    return true;
}

// ==============================================================================
// EJEMPLO 3: Funciones para manejo de vectores
// ==============================================================================

// Función para encontrar el elemento mayor en un vector
int encontrarMayor(const vector<int>& numeros) {
    if (numeros.empty()) return 0;
    
    int mayor = numeros[0];
    for (int num : numeros) {
        if (num > mayor) {
            mayor = num;
        }
    }
    return mayor;
}

// Función para calcular el promedio de un vector
double calcularPromedio(const vector<int>& numeros) {
    if (numeros.empty()) return 0.0;
    
    int suma = 0;
    for (int num : numeros) {
        suma += num;
    }
    return static_cast<double>(suma) / numeros.size();
}

// Función para ordenar un vector (bubble sort simple)
void ordenarVector(vector<int>& numeros) {
    int n = numeros.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                swap(numeros[j], numeros[j + 1]);
            }
        }
    }
}

// ==============================================================================
// EJEMPLO 4: Funciones de validación
// ==============================================================================

// Función para validar email
bool validarEmail(const string& email) {
    size_t arroba = email.find('@');
    size_t punto = email.find('.', arroba);
    
    return arroba != string::npos && 
           punto != string::npos && 
           punto > arroba + 1 &&
           punto < email.length() - 1;
}

// Función para validar número de teléfono
bool validarTelefono(const string& telefono) {
    if (telefono.length() != 10) return false;
    
    for (char c : telefono) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

// Función para validar edad
bool validarEdad(int edad) {
    return edad >= 0 && edad <= 120;
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== EJEMPLOS DE BIBLIOTECAS BÁSICAS ===" << endl;
    cout << "=======================================" << endl;
    
    // Ejemplo 1: Funciones matemáticas
    cout << "\n1. FUNCIONES MATEMÁTICAS:" << endl;
    cout << "Área del círculo (radio=5): " << calcularAreaCirculo(5) << endl;
    cout << "Perímetro del rectángulo (10x5): " << calcularPerimetroRectangulo(10, 5) << endl;
    cout << "Distancia entre (0,0) y (3,4): " << calcularDistancia(0, 0, 3, 4) << endl;
    
    // Ejemplo 2: Funciones de strings
    cout << "\n2. FUNCIONES DE STRINGS:" << endl;
    string texto = "Hola Mundo";
    cout << "Texto original: " << texto << endl;
    cout << "En mayúsculas: " << convertirMayusculas(texto) << endl;
    cout << "Número de palabras: " << contarPalabras(texto) << endl;
    cout << "¿Es palíndromo 'anita lava la tina'? " << (esPalindromo("anita lava la tina") ? "Sí" : "No") << endl;
    
    // Ejemplo 3: Funciones de vectores
    cout << "\n3. FUNCIONES DE VECTORES:" << endl;
    vector<int> numeros = {5, 2, 8, 1, 9, 3};
    cout << "Vector original: ";
    for (int num : numeros) cout << num << " ";
    cout << endl;
    
    cout << "Elemento mayor: " << encontrarMayor(numeros) << endl;
    cout << "Promedio: " << calcularPromedio(numeros) << endl;
    
    ordenarVector(numeros);
    cout << "Vector ordenado: ";
    for (int num : numeros) cout << num << " ";
    cout << endl;
    
    // Ejemplo 4: Funciones de validación
    cout << "\n4. FUNCIONES DE VALIDACIÓN:" << endl;
    cout << "¿'usuario@email.com' es email válido? " << (validarEmail("usuario@email.com") ? "Sí" : "No") << endl;
    cout << "¿'1234567890' es teléfono válido? " << (validarTelefono("1234567890") ? "Sí" : "No") << endl;
    cout << "¿25 es edad válida? " << (validarEdad(25) ? "Sí" : "No") << endl;
    
    cout << "\n=== VENTAJAS DE LAS BIBLIOTECAS ===" << endl;
    cout << "====================================" << endl;
    cout << "✓ Reutilización de código" << endl;
    cout << "✓ Organización del programa" << endl;
    cout << "✓ Facilita el mantenimiento" << endl;
    cout << "✓ Permite trabajo en equipo" << endl;
    cout << "✓ Reduce duplicación de código" << endl;
    cout << "✓ Mejora la legibilidad" << endl;
    
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. BIBLIOTECAS ESTÁNDAR:
 *    - <iostream>: entrada/salida
 *    - <string>: manejo de cadenas
 *    - <vector>: contenedores dinámicos
 *    - <cmath>: funciones matemáticas
 * 
 * 2. FUNCIONES DE UTILIDAD:
 *    - Encapsulan lógica común
 *    - Reciben parámetros
 *    - Retornan valores
 *    - Pueden ser reutilizadas
 * 
 * 3. VALIDACIONES:
 *    - Verifican datos de entrada
 *    - Retornan valores booleanos
 *    - Previenen errores
 * 
 * 4. ORGANIZACIÓN:
 *    - Funciones agrupadas por propósito
 *    - Nombres descriptivos
 *    - Documentación clara
 *    - Separación de responsabilidades
 */
