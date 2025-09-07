/*
 * Archivo: mi_biblioteca.cpp
 * Descripción: Implementación de biblioteca básica con funciones de utilidad
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#include "mi_biblioteca.hpp"
#include <cctype>

namespace MiBiblioteca {
    
    // ==============================================================================
    // OPERACIONES MATEMÁTICAS
    // ==============================================================================
    
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
        return 0; // División por cero
    }
    
    // ==============================================================================
    // OPERACIONES CON STRINGS
    // ==============================================================================
    
    std::string convertirMayusculas(const std::string& texto) {
        std::string resultado = texto;
        for (char& c : resultado) {
            c = toupper(c);
        }
        return resultado;
    }
    
    std::string convertirMinusculas(const std::string& texto) {
        std::string resultado = texto;
        for (char& c : resultado) {
            c = tolower(c);
        }
        return resultado;
    }
    
    int contarCaracteres(const std::string& texto) {
        return texto.length();
    }
    
    int contarPalabras(const std::string& texto) {
        if (texto.empty()) {
            return 0;
        }
        
        int contador = 1;
        for (char c : texto) {
            if (c == ' ') {
                contador++;
            }
        }
        return contador;
    }
    
    // ==============================================================================
    // VALIDACIONES
    // ==============================================================================
    
    bool validarRango(int numero, int minimo, int maximo) {
        return numero >= minimo && numero <= maximo;
    }
    
    bool validarSoloLetras(const std::string& texto) {
        for (char c : texto) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }
    
    bool validarSoloNumeros(const std::string& texto) {
        for (char c : texto) {
            if (!isdigit(c)) {
                return false;
            }
        }
        return true;
    }
    
    // ==============================================================================
    // OPERACIONES CON VECTORES
    // ==============================================================================
    
    int encontrarMayor(const std::vector<int>& numeros) {
        if (numeros.empty()) {
            return 0;
        }
        
        int mayor = numeros[0];
        for (int num : numeros) {
            if (num > mayor) {
                mayor = num;
            }
        }
        return mayor;
    }
    
    double calcularPromedio(const std::vector<int>& numeros) {
        if (numeros.empty()) {
            return 0.0;
        }
        
        int suma = 0;
        for (int num : numeros) {
            suma += num;
        }
        return static_cast<double>(suma) / numeros.size();
    }
    
    int calcularSuma(const std::vector<int>& numeros) {
        int suma = 0;
        for (int num : numeros) {
            suma += num;
        }
        return suma;
    }
    
    // ==============================================================================
    // FUNCIONES DE UTILIDAD
    // ==============================================================================
    
    void mostrarBienvenida(const std::string& nombre) {
        std::cout << "==========================================" << std::endl;
        std::cout << "BIENVENIDO A " << convertirMayusculas(nombre) << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    
    void pausar() {
        std::cout << "\nPresione Enter para continuar...";
        std::cin.ignore();
        std::cin.get();
    }
    
    void mostrarInformacion() {
        std::cout << "\n==========================================" << std::endl;
        std::cout << "INFORMACIÓN DE LA BIBLIOTECA" << std::endl;
        std::cout << "==========================================" << std::endl;
        std::cout << "Nombre: Mi Biblioteca de Utilidades" << std::endl;
        std::cout << "Versión: 1.0" << std::endl;
        std::cout << "Autor: Ing. Victor Kneider" << std::endl;
        std::cout << "Descripción: Biblioteca básica con funciones de utilidad" << std::endl;
        std::cout << "\nFuncionalidades incluidas:" << std::endl;
        std::cout << "• Operaciones matemáticas básicas" << std::endl;
        std::cout << "• Manipulación de strings" << std::endl;
        std::cout << "• Validaciones de datos" << std::endl;
        std::cout << "• Operaciones con vectores" << std::endl;
        std::cout << "==========================================" << std::endl;
    }
    
} // namespace MiBiblioteca
