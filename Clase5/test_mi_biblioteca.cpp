/*
 * TEST DE MI_BIBLIOTECA - PRUEBAS DE FUNCIONES
 * ============================================
 * 
 * Este archivo contiene pruebas para verificar que todas las funciones
 * de mi_biblioteca funcionen correctamente.
 * 
 * COMPILACIÓN:
 * g++ -o test_mi_biblioteca test_mi_biblioteca.cpp mi_biblioteca.cpp
 * 
 * EJECUCIÓN:
 * ./test_mi_biblioteca
 */

#include "mi_biblioteca.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;
using namespace MiBiblioteca;

// ==============================================================================
// FUNCIONES DE PRUEBA
// ==============================================================================

void probarMatematicas() {
    cout << "\n=== PRUEBAS DE FUNCIONES MATEMÁTICAS ===" << endl;
    
    // Prueba de suma
    cout << "Probando suma(5, 3): " << sumar(5, 3) << " (esperado: 8)" << endl;
    assert(sumar(5, 3) == 8);
    
    // Prueba de resta
    cout << "Probando resta(10, 4): " << restar(10, 4) << " (esperado: 6)" << endl;
    assert(restar(10, 4) == 6);
    
    // Prueba de multiplicación
    cout << "Probando multiplicación(6, 7): " << multiplicar(6, 7) << " (esperado: 42)" << endl;
    assert(multiplicar(6, 7) == 42);
    
    // Prueba de división
    cout << "Probando división(15, 3): " << dividir(15, 3) << " (esperado: 5)" << endl;
    assert(dividir(15, 3) == 5);
    
    // Prueba de división por cero
    cout << "Probando división(10, 0): " << dividir(10, 0) << " (esperado: 0)" << endl;
    assert(dividir(10, 0) == 0);
    
    cout << "✅ Todas las pruebas matemáticas pasaron!" << endl;
}

void probarTexto() {
    cout << "\n=== PRUEBAS DE FUNCIONES DE TEXTO ===" << endl;
    
    // Prueba de conversión a mayúsculas
    string texto1 = "hola mundo";
    string resultado1 = convertirMayusculas(texto1);
    cout << "Probando convertirMayusculas(\"" << texto1 << "\"): \"" << resultado1 << "\" (esperado: \"HOLA MUNDO\")" << endl;
    assert(resultado1 == "HOLA MUNDO");
    
    // Prueba de conversión a minúsculas
    string texto2 = "HOLA MUNDO";
    string resultado2 = convertirMinusculas(texto2);
    cout << "Probando convertirMinusculas(\"" << texto2 << "\"): \"" << resultado2 << "\" (esperado: \"hola mundo\")" << endl;
    assert(resultado2 == "hola mundo");
    
    // Prueba de contar caracteres
    string texto3 = "Hola";
    int caracteres = contarCaracteres(texto3);
    cout << "Probando contarCaracteres(\"" << texto3 << "\"): " << caracteres << " (esperado: 4)" << endl;
    assert(caracteres == 4);
    
    // Prueba de contar palabras
    string texto4 = "Hola mundo como estas";
    int palabras = contarPalabras(texto4);
    cout << "Probando contarPalabras(\"" << texto4 << "\"): " << palabras << " (esperado: 4)" << endl;
    assert(palabras == 4);
    
    cout << "✅ Todas las pruebas de texto pasaron!" << endl;
}

void probarValidaciones() {
    cout << "\n=== PRUEBAS DE FUNCIONES DE VALIDACIÓN ===" << endl;
    
    // Prueba de validar rango
    cout << "Probando validarRango(5, 1, 10): " << (validarRango(5, 1, 10) ? "true" : "false") << " (esperado: true)" << endl;
    assert(validarRango(5, 1, 10) == true);
    
    cout << "Probando validarRango(15, 1, 10): " << (validarRango(15, 1, 10) ? "true" : "false") << " (esperado: false)" << endl;
    assert(validarRango(15, 1, 10) == false);
    
    // Prueba de validar solo letras
    cout << "Probando validarSoloLetras(\"Hola\"): " << (validarSoloLetras("Hola") ? "true" : "false") << " (esperado: true)" << endl;
    assert(validarSoloLetras("Hola") == true);
    
    cout << "Probando validarSoloLetras(\"Hola123\"): " << (validarSoloLetras("Hola123") ? "true" : "false") << " (esperado: false)" << endl;
    assert(validarSoloLetras("Hola123") == false);
    
    // Prueba de validar solo números
    cout << "Probando validarSoloNumeros(\"12345\"): " << (validarSoloNumeros("12345") ? "true" : "false") << " (esperado: true)" << endl;
    assert(validarSoloNumeros("12345") == true);
    
    cout << "Probando validarSoloNumeros(\"123abc\"): " << (validarSoloNumeros("123abc") ? "true" : "false") << " (esperado: false)" << endl;
    assert(validarSoloNumeros("123abc") == false);
    
    cout << "✅ Todas las pruebas de validación pasaron!" << endl;
}

void probarVectores() {
    cout << "\n=== PRUEBAS DE FUNCIONES DE VECTORES ===" << endl;
    
    // Crear vector de prueba
    vector<int> numeros = {10, 5, 8, 3, 12, 7};
    
    // Prueba de encontrar mayor
    int mayor = encontrarMayor(numeros);
    cout << "Probando encontrarMayor({10, 5, 8, 3, 12, 7}): " << mayor << " (esperado: 12)" << endl;
    assert(mayor == 12);
    
    // Prueba de calcular promedio
    double promedio = calcularPromedio(numeros);
    cout << "Probando calcularPromedio({10, 5, 8, 3, 12, 7}): " << promedio << " (esperado: 7.5)" << endl;
    assert(promedio == 7.5);
    
    // Prueba de calcular suma
    int suma = calcularSuma(numeros);
    cout << "Probando calcularSuma({10, 5, 8, 3, 12, 7}): " << suma << " (esperado: 45)" << endl;
    assert(suma == 45);
    
    cout << "✅ Todas las pruebas de vectores pasaron!" << endl;
}

void probarUtilidades() {
    cout << "\n=== PRUEBAS DE FUNCIONES DE UTILIDAD ===" << endl;
    
    // Prueba de mostrar bienvenida
    cout << "Probando mostrarBienvenida(\"Juan\"):" << endl;
    mostrarBienvenida("Juan");
    
    // Prueba de mostrar información
    cout << "\nProbando mostrarInformacion():" << endl;
    mostrarInformacion();
    
    cout << "\n✅ Todas las pruebas de utilidades pasaron!" << endl;
}

void probarCasosEdge() {
    cout << "\n=== PRUEBAS DE CASOS EDGE ===" << endl;
    
    // Vector vacío
    vector<int> vacio;
    cout << "Probando encontrarMayor con vector vacío: " << encontrarMayor(vacio) << " (esperado: 0)" << endl;
    assert(encontrarMayor(vacio) == 0);
    
    cout << "Probando calcularPromedio con vector vacío: " << calcularPromedio(vacio) << " (esperado: 0.0)" << endl;
    assert(calcularPromedio(vacio) == 0.0);
    
    // String vacío
    cout << "Probando contarCaracteres con string vacío: " << contarCaracteres("") << " (esperado: 0)" << endl;
    assert(contarCaracteres("") == 0);
    
    cout << "Probando contarPalabras con string vacío: " << contarPalabras("") << " (esperado: 0)" << endl;
    assert(contarPalabras("") == 0);
    
    cout << "✅ Todas las pruebas de casos edge pasaron!" << endl;
}

void mostrarMenu() {
    cout << "\n=== MENÚ DE PRUEBAS DE MI_BIBLIOTECA ===" << endl;
    cout << "1. Probar funciones matemáticas" << endl;
    cout << "2. Probar funciones de texto" << endl;
    cout << "3. Probar funciones de validación" << endl;
    cout << "4. Probar funciones de vectores" << endl;
    cout << "5. Probar funciones de utilidad" << endl;
    cout << "6. Probar casos edge" << endl;
    cout << "7. Ejecutar todas las pruebas" << endl;
    cout << "8. Salir" << endl;
    cout << "Seleccione una opción: ";
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== TEST DE MI_BIBLIOTECA ===" << endl;
    cout << "Este programa prueba todas las funciones de mi_biblioteca." << endl;
    
    int opcion;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                probarMatematicas();
                break;
            case 2:
                probarTexto();
                break;
            case 3:
                probarValidaciones();
                break;
            case 4:
                probarVectores();
                break;
            case 5:
                probarUtilidades();
                break;
            case 6:
                probarCasosEdge();
                break;
            case 7:
                cout << "\n=== EJECUTANDO TODAS LAS PRUEBAS ===" << endl;
                probarMatematicas();
                probarTexto();
                probarValidaciones();
                probarVectores();
                probarUtilidades();
                probarCasosEdge();
                cout << "\n🎉 ¡TODAS LAS PRUEBAS COMPLETADAS EXITOSAMENTE!" << endl;
                break;
            case 8:
                cout << "Saliendo del programa de pruebas..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
        
        if (opcion != 8) {
            cout << "\nPresione Enter para continuar...";
            cin.ignore();
            cin.get();
        }
    } while (opcion != 8);
    
    cout << "Programa de pruebas finalizado." << endl;
    return 0;
}

/*
 * NOTAS SOBRE LAS PRUEBAS:
 * 
 * 1. USO DE ASSERT:
 *    - assert() verifica que la condición sea verdadera
 *    - Si falla, el programa termina con error
 *    - Útil para verificar que las funciones funcionen correctamente
 * 
 * 2. CASOS DE PRUEBA:
 *    - Pruebas normales con valores esperados
 *    - Casos edge (vectores vacíos, strings vacíos)
 *    - Casos límite (división por cero, rangos inválidos)
 * 
 * 3. COBERTURA:
 *    - Todas las funciones de mi_biblioteca están probadas
 *    - Se incluyen ejemplos de uso
 *    - Se verifican valores de retorno esperados
 * 
 * 4. COMPILACIÓN:
 *    - Requiere mi_biblioteca.hpp y mi_biblioteca.cpp
 *    - Usar: g++ -o test_mi_biblioteca test_mi_biblioteca.cpp mi_biblioteca.cpp
 * 
 * 5. EJECUCIÓN:
 *    - Ejecutar: ./test_mi_biblioteca
 *    - Seleccionar opciones del menú
 *    - Verificar que todas las pruebas pasen
 */
