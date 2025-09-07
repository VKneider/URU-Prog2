/*
 * Archivo: 3_namespaces.cpp
 * Descripción: Organización de código con namespaces
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
    NAMESPACES EN C++
==================================================================================
    Los namespaces nos permiten:
    1. Organizar código en grupos lógicos
    2. Evitar conflictos de nombres
    3. Crear bibliotecas modulares
    4. Facilitar el mantenimiento
    5. Permitir trabajo en equipo sin conflictos
    6. Crear interfaces claras y bien definidas
*/

// ==============================================================================
// EJEMPLO 1: Namespace para operaciones matemáticas
// ==============================================================================

namespace Matematicas {
    // Constantes matemáticas
    const double PI = 3.14159265359;
    const double E = 2.71828182846;
    
    // Funciones básicas
    double suma(double a, double b) {
        return a + b;
    }
    
    double resta(double a, double b) {
        return a - b;
    }
    
    double multiplicacion(double a, double b) {
        return a * b;
    }
    
    double division(double a, double b) {
        if (b != 0) {
            return a / b;
        }
        return 0; // Manejo de error simple
    }
    
    // Funciones avanzadas
    double potencia(double base, double exponente) {
        return pow(base, exponente);
    }
    
    double raizCuadrada(double numero) {
        if (numero >= 0) {
            return sqrt(numero);
        }
        return 0; // Manejo de error simple
    }
    
    // Funciones geométricas
    double areaCirculo(double radio) {
        return PI * radio * radio;
    }
    
    double perimetroCirculo(double radio) {
        return 2 * PI * radio;
    }
    
    double areaRectangulo(double largo, double ancho) {
        return largo * ancho;
    }
    
    double perimetroRectangulo(double largo, double ancho) {
        return 2 * (largo + ancho);
    }
}

// ==============================================================================
// EJEMPLO 2: Namespace para operaciones de texto
// ==============================================================================

namespace Texto {
    // Funciones de conversión
    string convertirMayusculas(const string& texto) {
        string resultado = texto;
        for (char& c : resultado) {
            c = toupper(c);
        }
        return resultado;
    }
    
    string convertirMinusculas(const string& texto) {
        string resultado = texto;
        for (char& c : resultado) {
            c = tolower(c);
        }
        return resultado;
    }
    
    // Funciones de análisis
    int contarCaracteres(const string& texto) {
        return texto.length();
    }
    
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
    
    int contarVocales(const string& texto) {
        int contador = 0;
        string textoMin = convertirMinusculas(texto);
        
        for (char c : textoMin) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                contador++;
            }
        }
        return contador;
    }
    
    // Funciones de validación
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
    
    bool contieneSoloLetras(const string& texto) {
        for (char c : texto) {
            if (!isalpha(c) && c != ' ') {
                return false;
            }
        }
        return true;
    }
}

// ==============================================================================
// EJEMPLO 3: Namespace para operaciones de fecha y tiempo
// ==============================================================================

namespace FechaTiempo {
    // Estructura para fecha
    struct Fecha {
        int dia;
        int mes;
        int año;
        
        Fecha(int d, int m, int a) : dia(d), mes(m), año(a) {}
        
        string toString() const {
            return to_string(dia) + "/" + to_string(mes) + "/" + to_string(año);
        }
    };
    
    // Funciones de validación
    bool esFechaValida(const Fecha& fecha) {
        if (fecha.año < 1900 || fecha.año > 2100) return false;
        if (fecha.mes < 1 || fecha.mes > 12) return false;
        if (fecha.dia < 1 || fecha.dia > 31) return false;
        
        // Validación básica de días por mes
        int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (fecha.dia > diasPorMes[fecha.mes - 1]) return false;
        
        return true;
    }
    
    // Funciones de cálculo
    int calcularEdad(const Fecha& fechaNacimiento, const Fecha& fechaActual) {
        if (!esFechaValida(fechaNacimiento) || !esFechaValida(fechaActual)) {
            return -1; // Error
        }
        
        int edad = fechaActual.año - fechaNacimiento.año;
        
        if (fechaActual.mes < fechaNacimiento.mes ||
            (fechaActual.mes == fechaNacimiento.mes && fechaActual.dia < fechaNacimiento.dia)) {
            edad--;
        }
        
        return edad;
    }
    
    bool esBisiesto(int año) {
        return (año % 4 == 0 && año % 100 != 0) || (año % 400 == 0);
    }
}

// ==============================================================================
// EJEMPLO 4: Namespace anidado para operaciones avanzadas
// ==============================================================================

namespace Biblioteca {
    namespace Matematicas {
        namespace Geometria {
            double volumenEsfera(double radio) {
                return (4.0 / 3.0) * Matematicas::PI * pow(radio, 3);
            }
            
            double volumenCilindro(double radio, double altura) {
                return Matematicas::PI * pow(radio, 2) * altura;
            }
            
            double volumenCubo(double lado) {
                return pow(lado, 3);
            }
        }
        
        namespace Estadisticas {
            double calcularPromedio(const vector<double>& numeros) {
                if (numeros.empty()) return 0.0;
                
                double suma = 0;
                for (double num : numeros) {
                    suma += num;
                }
                return suma / numeros.size();
            }
            
            double calcularDesviacionEstandar(const vector<double>& numeros) {
                if (numeros.size() < 2) return 0.0;
                
                double promedio = calcularPromedio(numeros);
                double suma = 0;
                
                for (double num : numeros) {
                    suma += pow(num - promedio, 2);
                }
                
                return sqrt(suma / (numeros.size() - 1));
            }
        }
    }
}

// ==============================================================================
// EJEMPLO 5: Uso de using para simplificar el código
// ==============================================================================

// Alias para namespaces largos
namespace Geo = Biblioteca::Matematicas::Geometria;
namespace Stats = Biblioteca::Matematicas::Estadisticas;

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== NAMESPACES EN C++ ===" << endl;
    cout << "=========================" << endl;
    
    // Ejemplo 1: Operaciones matemáticas
    cout << "\n1. OPERACIONES MATEMÁTICAS:" << endl;
    cout << "Suma: " << Matematicas::suma(5, 3) << endl;
    cout << "Multiplicación: " << Matematicas::multiplicacion(4, 7) << endl;
    cout << "Potencia: " << Matematicas::potencia(2, 8) << endl;
    cout << "Área del círculo (radio=5): " << Matematicas::areaCirculo(5) << endl;
    cout << "Perímetro del rectángulo (10x5): " << Matematicas::perimetroRectangulo(10, 5) << endl;
    
    // Ejemplo 2: Operaciones de texto
    cout << "\n2. OPERACIONES DE TEXTO:" << endl;
    string texto = "Hola Mundo";
    cout << "Texto original: " << texto << endl;
    cout << "En mayúsculas: " << Texto::convertirMayusculas(texto) << endl;
    cout << "En minúsculas: " << Texto::convertirMinusculas(texto) << endl;
    cout << "Número de caracteres: " << Texto::contarCaracteres(texto) << endl;
    cout << "Número de palabras: " << Texto::contarPalabras(texto) << endl;
    cout << "Número de vocales: " << Texto::contarVocales(texto) << endl;
    cout << "¿Es palíndromo 'anita lava la tina'? " << (Texto::esPalindromo("anita lava la tina") ? "Sí" : "No") << endl;
    
    // Ejemplo 3: Operaciones de fecha
    cout << "\n3. OPERACIONES DE FECHA:" << endl;
    FechaTiempo::Fecha fechaNacimiento(15, 6, 1990);
    FechaTiempo::Fecha fechaActual(20, 12, 2023);
    
    cout << "Fecha de nacimiento: " << fechaNacimiento.toString() << endl;
    cout << "Fecha actual: " << fechaActual.toString() << endl;
    cout << "¿Es fecha válida? " << (FechaTiempo::esFechaValida(fechaNacimiento) ? "Sí" : "No") << endl;
    cout << "Edad: " << FechaTiempo::calcularEdad(fechaNacimiento, fechaActual) << " años" << endl;
    cout << "¿2024 es bisiesto? " << (FechaTiempo::esBisiesto(2024) ? "Sí" : "No") << endl;
    
    // Ejemplo 4: Namespaces anidados
    cout << "\n4. NAMESPACES ANIDADOS:" << endl;
    cout << "Volumen de esfera (radio=3): " << Biblioteca::Matematicas::Geometria::volumenEsfera(3) << endl;
    cout << "Volumen de cilindro (r=2, h=5): " << Biblioteca::Matematicas::Geometria::volumenCilindro(2, 5) << endl;
    cout << "Volumen de cubo (lado=4): " << Biblioteca::Matematicas::Geometria::volumenCubo(4) << endl;
    
    // Ejemplo 5: Uso de alias
    cout << "\n5. USO DE ALIAS:" << endl;
    cout << "Volumen de esfera (usando alias): " << Geo::volumenEsfera(3) << endl;
    
    vector<double> numeros = {1, 2, 3, 4, 5};
    cout << "Promedio: " << Stats::calcularPromedio(numeros) << endl;
    cout << "Desviación estándar: " << Stats::calcularDesviacionEstandar(numeros) << endl;
    
    cout << "\n=== VENTAJAS DE LOS NAMESPACES ===" << endl;
    cout << "===================================" << endl;
    cout << "✓ Organización lógica del código" << endl;
    cout << "✓ Evita conflictos de nombres" << endl;
    cout << "✓ Facilita el trabajo en equipo" << endl;
    cout << "✓ Crea interfaces claras" << endl;
    cout << "✓ Permite bibliotecas modulares" << endl;
    cout << "✓ Mejora la mantenibilidad" << endl;
    
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. DECLARACIÓN DE NAMESPACES:
 *    - namespace Nombre { ... }
 *    - Pueden ser anidados
 *    - Pueden tener alias
 * 
 * 2. USO DE NAMESPACES:
 *    - NombreCompleto::funcion()
 *    - using namespace Nombre;
 *    - using Nombre::funcion;
 * 
 * 3. ORGANIZACIÓN:
 *    - Agrupar funciones relacionadas
 *    - Evitar conflictos de nombres
 *    - Crear interfaces claras
 * 
 * 4. ALIAS:
 *    - namespace Alias = NombreCompleto;
 *    - Simplifica el uso de namespaces largos
 * 
 * 5. NAMESPACES ANIDADOS:
 *    - Biblioteca::Matematicas::Geometria
 *    - Organización jerárquica
 *    - Separación clara de responsabilidades
 */
