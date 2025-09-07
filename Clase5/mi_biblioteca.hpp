/*
 * Archivo: mi_biblioteca.hpp
 * Descripción: Header de biblioteca básica con funciones de utilidad
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#ifndef MI_BIBLIOTECA_HPP
#define MI_BIBLIOTECA_HPP

#include <iostream>
#include <string>
#include <vector>

/*
==================================================================================
    BIBLIOTECA BÁSICA DE UTILIDADES
==================================================================================
    Esta biblioteca proporciona funciones básicas de utilidad para:
    1. Operaciones matemáticas simples
    2. Manipulación de strings
    3. Validaciones básicas
    4. Operaciones con vectores
*/

namespace MiBiblioteca {
    
    // ==============================================================================
    // OPERACIONES MATEMÁTICAS
    // ==============================================================================
    
    /**
     * Suma dos números enteros
     * @param a Primer número
     * @param b Segundo número
     * @return Suma de a y b
     */
    int sumar(int a, int b);
    
    /**
     * Resta dos números enteros
     * @param a Primer número
     * @param b Segundo número
     * @return Resta de a y b
     */
    int restar(int a, int b);
    
    /**
     * Multiplica dos números enteros
     * @param a Primer número
     * @param b Segundo número
     * @return Multiplicación de a y b
     */
    int multiplicar(int a, int b);
    
    /**
     * Divide dos números enteros
     * @param a Dividendo
     * @param b Divisor
     * @return División de a y b, o 0 si b es 0
     */
    int dividir(int a, int b);
    
    // ==============================================================================
    // OPERACIONES CON STRINGS
    // ==============================================================================
    
    /**
     * Convierte un string a mayúsculas
     * @param texto Texto a convertir
     * @return Texto en mayúsculas
     */
    std::string convertirMayusculas(const std::string& texto);
    
    /**
     * Convierte un string a minúsculas
     * @param texto Texto a convertir
     * @return Texto en minúsculas
     */
    std::string convertirMinusculas(const std::string& texto);
    
    /**
     * Cuenta el número de caracteres en un string
     * @param texto Texto a analizar
     * @return Número de caracteres
     */
    int contarCaracteres(const std::string& texto);
    
    /**
     * Cuenta el número de palabras en un string
     * @param texto Texto a analizar
     * @return Número de palabras
     */
    int contarPalabras(const std::string& texto);
    
    // ==============================================================================
    // VALIDACIONES
    // ==============================================================================
    
    /**
     * Valida si un número está en un rango
     * @param numero Número a validar
     * @param minimo Valor mínimo
     * @param maximo Valor máximo
     * @return true si está en el rango, false en caso contrario
     */
    bool validarRango(int numero, int minimo, int maximo);
    
    /**
     * Valida si un string contiene solo letras
     * @param texto Texto a validar
     * @return true si contiene solo letras, false en caso contrario
     */
    bool validarSoloLetras(const std::string& texto);
    
    /**
     * Valida si un string contiene solo números
     * @param texto Texto a validar
     * @return true si contiene solo números, false en caso contrario
     */
    bool validarSoloNumeros(const std::string& texto);
    
    // ==============================================================================
    // OPERACIONES CON VECTORES
    // ==============================================================================
    
    /**
     * Encuentra el elemento mayor en un vector
     * @param numeros Vector de números
     * @return Elemento mayor, o 0 si el vector está vacío
     */
    int encontrarMayor(const std::vector<int>& numeros);
    
    /**
     * Calcula el promedio de un vector
     * @param numeros Vector de números
     * @return Promedio de los números
     */
    double calcularPromedio(const std::vector<int>& numeros);
    
    /**
     * Calcula la suma de un vector
     * @param numeros Vector de números
     * @return Suma de todos los números
     */
    int calcularSuma(const std::vector<int>& numeros);
    
    // ==============================================================================
    // FUNCIONES DE UTILIDAD
    // ==============================================================================
    
    /**
     * Muestra un mensaje de bienvenida
     * @param nombre Nombre de la aplicación
     */
    void mostrarBienvenida(const std::string& nombre);
    
    /**
     * Pausa la ejecución hasta que se presione Enter
     */
    void pausar();
    
    /**
     * Muestra información de la biblioteca
     */
    void mostrarInformacion();
    
} // namespace MiBiblioteca

#endif // MI_BIBLIOTECA_HPP
