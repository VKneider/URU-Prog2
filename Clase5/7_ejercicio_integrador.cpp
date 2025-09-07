/*
 * EJERCICIO CLASE 5 - DOCUMENTACIÓN DE BIBLIOTECA DE UTILIDADES
 * ==============================================================
 * 
 * ENUNCIADO:
 * Crear la documentación completa de una biblioteca de utilidades generales
 * que permita a otros desarrolladores entender y usar las funciones disponibles.
 * 
 * OBJETIVOS:
 * 1. Documentar funciones de utilidad de propósito general
 * 2. Crear ejemplos de uso para cada función
 * 3. Explicar la organización con namespaces
 * 4. Demostrar buenas prácticas de documentación
 * 5. Facilitar la reutilización del código
 * 
 * REQUISITOS:
 * - Crear documentación en formato markdown
 * - Incluir ejemplos de código para cada función
 * - Explicar parámetros y valores de retorno
 * - Documentar casos de uso comunes
 * - Incluir notas sobre limitaciones y consideraciones
 * 
 * ESTRUCTURA DE DOCUMENTACIÓN REQUERIDA:
 * 
 * mi_utilidades.md:
 * - Descripción general de la biblioteca
 * - Índice de funciones por categoría
 * - Documentación detallada de cada función
 * - Ejemplos de uso prácticos
 * - Notas sobre implementación
 * 
 * EJEMPLO DE DOCUMENTACIÓN:
 * 
 * # Biblioteca de Utilidades Generales
 * 
 * ## Descripción
 * Esta biblioteca proporciona funciones de utilidad comunes para operaciones
 * matemáticas, manipulación de texto, validaciones y operaciones con arreglos.
 * 
 * ## Funciones Matemáticas
 * 
 * ### calcularAreaCirculo(radio)
 * Calcula el área de un círculo dado su radio.
 * 
 * **Parámetros:**
 * - `radio` (double): Radio del círculo
 * 
 * **Retorna:**
 * - `double`: Área del círculo (π * radio²)
 * 
 * **Ejemplo:**
 * ```cpp
 * double area = calcularAreaCirculo(5.0);
 * cout << "Área: " << area << endl; // Área: 78.54
 * ```
 * 
 * **Notas:**
 * - El radio debe ser positivo
 * - Usa la constante M_PI para π
 * 
 * ### calcularAreaRectangulo(largo, ancho)
 * Calcula el área de un rectángulo dados sus dimensiones.
 * 
 * **Parámetros:**
 * - `largo` (double): Longitud del rectángulo
 * - `ancho` (double): Ancho del rectángulo
 * 
 * **Retorna:**
 * - `double`: Área del rectángulo (largo * ancho)
 * 
 * **Ejemplo:**
 * ```cpp
 * double area = calcularAreaRectangulo(10.0, 5.0);
 * cout << "Área: " << area << endl; // Área: 50.0
 * ```
 * 
 * **Notas:**
 * - Las dimensiones deben ser positivas
 * - No valida si es realmente un rectángulo
 * 
 * ## Funciones de Texto
 * 
 * ### contarVocales(texto)
 * Cuenta el número de vocales en un texto.
 * 
 * **Parámetros:**
 * - `texto` (string): Texto a analizar
 * 
 * **Retorna:**
 * - `int`: Número de vocales encontradas
 * 
 * **Ejemplo:**
 * ```cpp
 * int vocales = contarVocales("Hola Mundo");
 * cout << "Vocales: " << vocales << endl; // Vocales: 4
 * ```
 * 
 * **Notas:**
 * - Considera vocales mayúsculas y minúsculas
 * - Incluye vocales con acentos
 * 
 * ### invertirTexto(texto)
 * Invierte el orden de los caracteres en un texto.
 * 
 * **Parámetros:**
 * - `texto` (string): Texto a invertir
 * 
 * **Retorna:**
 * - `string`: Texto invertido
 * 
 * **Ejemplo:**
 * ```cpp
 * string invertido = invertirTexto("Hola");
 * cout << "Invertido: " << invertido << endl; // Invertido: aloH
 * ```
 * 
 * **Notas:**
 * - Mantiene el tipo de caracteres original
 * - No modifica el texto original
 * 
 * ## Funciones de Validación
 * 
 * ### validarEmail(email)
 * Valida el formato básico de una dirección de email.
 * 
 * **Parámetros:**
 * - `email` (string): Dirección de email a validar
 * 
 * **Retorna:**
 * - `bool`: true si el formato es válido, false en caso contrario
 * 
 * **Ejemplo:**
 * ```cpp
 * bool valido = validarEmail("usuario@dominio.com");
 * if (valido) {
 *     cout << "Email válido" << endl;
 * }
 * ```
 * 
 * **Notas:**
 * - Validación básica de formato
 * - No verifica si el dominio existe
 * - Requiere al menos un @ y un punto
 * 
 * ### validarTelefono(telefono)
 * Valida que un teléfono contenga solo números y tenga longitud correcta.
 * 
 * **Parámetros:**
 * - `telefono` (string): Número de teléfono a validar
 * 
 * **Retorna:**
 * - `bool`: true si es válido, false en caso contrario
 * 
 * **Ejemplo:**
 * ```cpp
 * bool valido = validarTelefono("0987654321");
 * if (valido) {
 *     cout << "Teléfono válido" << endl;
 * }
 * ```
 * 
 * **Notas:**
 * - Requiere exactamente 10 dígitos
 * - No acepta espacios ni guiones
 * - Formato específico para Uruguay
 * 
 * ## Funciones de Arreglos
 * 
 * ### encontrarMayor(numeros)
 * Encuentra el elemento mayor en un vector de números.
 * 
 * **Parámetros:**
 * - `numeros` (vector<int>): Vector de números enteros
 * 
 * **Retorna:**
 * - `int`: El número mayor encontrado
 * 
 * **Ejemplo:**
 * ```cpp
 * vector<int> nums = {5, 2, 8, 1, 9};
 * int mayor = encontrarMayor(nums);
 * cout << "Mayor: " << mayor << endl; // Mayor: 9
 * ```
 * 
 * **Notas:**
 * - Retorna 0 si el vector está vacío
 * - No modifica el vector original
 * - Comparación simple de enteros
 * 
 * ### calcularPromedio(numeros)
 * Calcula el promedio de los elementos en un vector.
 * 
 * **Parámetros:**
 * - `numeros` (vector<int>): Vector de números enteros
 * 
 * **Retorna:**
 * - `double`: Promedio de los números
 * 
 * **Ejemplo:**
 * ```cpp
 * vector<int> nums = {10, 20, 30, 40, 50};
 * double promedio = calcularPromedio(nums);
 * cout << "Promedio: " << promedio << endl; // Promedio: 30.0
 * ```
 * 
 * **Notas:**
 * - Retorna 0.0 si el vector está vacío
 * - Usa división entera para el cálculo
 * - Precisión limitada por el tipo double
 * 
 * ## Funciones de Utilidad
 * 
 * ### mostrarSeparador(titulo)
 * Muestra una línea separadora con título opcional.
 * 
 * **Parámetros:**
 * - `titulo` (string, opcional): Título a mostrar en el separador
 * 
 * **Retorna:**
 * - `void`: No retorna valor
 * 
 * **Ejemplo:**
 * ```cpp
 * mostrarSeparador("Sección 1");
 * // Salida: ========== Sección 1 ==========
 * ```
 * 
 * **Notas:**
 * - Usa caracteres = para el separador
 * - Título centrado entre separadores
 * - Útil para organizar salida de consola
 * 
 * ### pausar()
 * Pausa la ejecución hasta que el usuario presione Enter.
 * 
 * **Parámetros:**
 * - Ninguno
 * 
 * **Retorna:**
 * - `void`: No retorna valor
 * 
 * **Ejemplo:**
 * ```cpp
 * cout << "Presione Enter para continuar...";
 * pausar();
 * ```
 * 
 * **Notas:**
 * - Útil para pausar entre secciones
 * - No muestra mensaje automático
 * - Espera entrada del usuario
 * 
 * ## Organización con Namespaces
 * 
 * Todas las funciones están organizadas en el namespace `MiUtilidades`
 * para evitar conflictos de nombres y facilitar la organización del código.
 * 
 * **Uso:**
 * ```cpp
 * using namespace MiUtilidades;
 * 
 * // Ahora se puede usar directamente:
 * double area = calcularAreaCirculo(5.0);
 * ```
 * 
 * **O con prefijo:**
 * ```cpp
 * double area = MiUtilidades::calcularAreaCirculo(5.0);
 * ```
 * 
 * ## Consideraciones de Implementación
 * 
 * ### Separación de Archivos
 * - **mi_utilidades.h**: Declaraciones de funciones
 * - **mi_utilidades.cpp**: Implementaciones
 * - **main.cpp**: Programa de demostración
 * 
 * ### Validaciones
 * - Todas las funciones incluyen validaciones básicas
 * - Manejo de casos edge (vectores vacíos, valores negativos)
 * - Mensajes de error informativos
 * 
 * ### Rendimiento
 * - Funciones optimizadas para casos comunes
 * - Uso eficiente de memoria
 * - Evita copias innecesarias de datos
 * 
 * ## Casos de Uso Comunes
 * 
 * ### Calculadora Simple
 * ```cpp
 * double area = calcularAreaCirculo(radio);
 * double perimetro = 2 * M_PI * radio;
 * ```
 * 
 * ### Procesamiento de Texto
 * ```cpp
 * int vocales = contarVocales(texto);
 * string invertido = invertirTexto(texto);
 * bool esPalindromo = esPalindromo(texto);
 * ```
 * 
 * ### Validación de Datos
 * ```cpp
 * if (validarEmail(email) && validarTelefono(telefono)) {
 *     // Datos válidos, proceder
 * }
 * ```
 * 
 * ### Análisis de Datos
 * ```cpp
 * int mayor = encontrarMayor(datos);
 * double promedio = calcularPromedio(datos);
 * int suma = sumarElementos(datos);
 * ```
 * 
 * ## Limitaciones y Consideraciones
 * 
 * ### Limitaciones Conocidas
 * - Validaciones básicas, no exhaustivas
 * - Precisión limitada en cálculos de punto flotante
 * - No maneja caracteres especiales en texto
 * - Validaciones específicas para formato uruguayo
 * 
 * ### Mejoras Futuras
 * - Soporte para más tipos de datos
 * - Validaciones más robustas
 * - Funciones de conversión de tipos
 * - Soporte para internacionalización
 * 
 * ## Instalación y Uso
 * 
 * ### Compilación
 * ```bash
 * g++ -o programa main.cpp mi_utilidades.cpp
 * ```
 * 
 * ### Inclusión
 * ```cpp
 * #include "mi_utilidades.h"
 * using namespace MiUtilidades;
 * ```
 * 
 * ### Ejemplo Completo
 * ```cpp
 * #include "mi_utilidades.h"
 * #include <iostream>
 * using namespace std;
 * using namespace MiUtilidades;
 * 
 * int main() {
 *     // Ejemplo de uso
 *     double area = calcularAreaCirculo(5.0);
 *     cout << "Área del círculo: " << area << endl;
 *     
 *     string texto = "Hola Mundo";
 *     int vocales = contarVocales(texto);
 *     cout << "Vocales en '" << texto << "': " << vocales << endl;
 *     
 *     return 0;
 * }
 * ```
 * 
 * ## Conclusión
 * 
 * Esta biblioteca de utilidades proporciona un conjunto básico pero útil
 * de funciones para operaciones comunes en programación. Su diseño modular
 * y la documentación clara facilitan su uso y mantenimiento.
 * 
 * Para contribuir o reportar problemas, consulte la documentación del
 * proyecto o contacte al equipo de desarrollo.
 */

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

/*
==================================================================================
    SIMULACIÓN DE ARCHIVOS SEPARADOS
==================================================================================
    En un proyecto real, este código estaría dividido en:
    - mi_utilidades.h (declaraciones)
    - mi_utilidades.cpp (implementaciones)
    - main.cpp (programa principal)
*/

// ==============================================================================
// NAMESPACE: MiUtilidades (simulando mi_utilidades.h/mi_utilidades.cpp)
// ==============================================================================

namespace MiUtilidades {
    
    // ==============================================================================
    // FUNCIONES MATEMÁTICAS
    // ==============================================================================
    
    // TODO: Implementar función para calcular área de círculo
    double calcularAreaCirculo(double radio) {
        // Completar aquí: área = π * radio²
        return 0.0; // Placeholder
    }
    
    // TODO: Implementar función para calcular área de rectángulo
    double calcularAreaRectangulo(double largo, double ancho) {
        // Completar aquí: área = largo * ancho
        return 0.0; // Placeholder
    }
    
    // TODO: Implementar función para calcular distancia entre puntos
    double calcularDistancia(double x1, double y1, double x2, double y2) {
        // Completar aquí: distancia = √((x2-x1)² + (y2-y1)²)
        return 0.0; // Placeholder
    }
    
    // TODO: Implementar función para verificar si un número es par
    bool esPar(int numero) {
        // Completar aquí: verificar si numero % 2 == 0
        return false; // Placeholder
    }
    
    // TODO: Implementar función para calcular factorial
    long long calcularFactorial(int n) {
        // Completar aquí: factorial de n (n!)
        return 0; // Placeholder
    }
    
    // ==============================================================================
    // FUNCIONES DE TEXTO
    // ==============================================================================
    
    // TODO: Implementar función para contar vocales
    int contarVocales(const string& texto) {
        // Completar aquí: contar a, e, i, o, u (mayúsculas y minúsculas)
        return 0; // Placeholder
    }
    
    // TODO: Implementar función para invertir texto
    string invertirTexto(const string& texto) {
        // Completar aquí: invertir el orden de los caracteres
        return ""; // Placeholder
    }
    
    // TODO: Implementar función para verificar palíndromo
    bool esPalindromo(const string& texto) {
        // Completar aquí: verificar si se lee igual de izquierda a derecha
        return false; // Placeholder
    }
    
    // TODO: Implementar función para capitalizar texto
    string capitalizarTexto(const string& texto) {
        // Completar aquí: primera letra mayúscula, resto minúsculas
        return ""; // Placeholder
    }
    
    // TODO: Implementar función para contar palabras
    int contarPalabras(const string& texto) {
        // Completar aquí: contar palabras separadas por espacios
        return 0; // Placeholder
    }
    
    // ==============================================================================
    // FUNCIONES DE VALIDACIÓN
    // ==============================================================================
    
    // TODO: Implementar función para validar email
    bool validarEmail(const string& email) {
        // Completar aquí: verificar formato básico de email
        return false; // Placeholder
    }
    
    // TODO: Implementar función para validar teléfono
    bool validarTelefono(const string& telefono) {
        // Completar aquí: verificar que sean solo números y longitud correcta
        return false; // Placeholder
    }
    
    // TODO: Implementar función para validar rango de números
    bool validarRango(int numero, int minimo, int maximo) {
        // Completar aquí: verificar que numero esté entre minimo y maximo
        return false; // Placeholder
    }
    
    // TODO: Implementar función para validar edad
    bool validarEdad(int edad) {
        // Completar aquí: verificar que edad esté entre 0 y 120
        return false; // Placeholder
    }
    
    // ==============================================================================
    // FUNCIONES DE ARREGLOS
    // ==============================================================================
    
    // TODO: Implementar función para encontrar mayor elemento
    int encontrarMayor(const vector<int>& numeros) {
        // Completar aquí: encontrar el número mayor en el vector
        return 0; // Placeholder
    }
    
    // TODO: Implementar función para encontrar menor elemento
    int encontrarMenor(const vector<int>& numeros) {
        // Completar aquí: encontrar el número menor en el vector
        return 0; // Placeholder
    }
    
    // TODO: Implementar función para calcular promedio
    double calcularPromedio(const vector<int>& numeros) {
        // Completar aquí: calcular promedio de los números
        return 0.0; // Placeholder
    }
    
    // TODO: Implementar función para sumar elementos
    int sumarElementos(const vector<int>& numeros) {
        // Completar aquí: sumar todos los elementos del vector
        return 0; // Placeholder
    }
    
    // TODO: Implementar función para buscar elemento
    bool buscarElemento(const vector<int>& numeros, int elemento) {
        // Completar aquí: buscar si elemento existe en el vector
        return false; // Placeholder
    }
    
    // ==============================================================================
    // FUNCIONES DE UTILIDAD
    // ==============================================================================
    
    // TODO: Implementar función para mostrar separador
    void mostrarSeparador(const string& titulo = "") {
        // Completar aquí: mostrar línea separadora con título opcional
    }
    
    // TODO: Implementar función para pausar
    void pausar() {
        // Completar aquí: pausar hasta presionar Enter
    }
    
    // TODO: Implementar función para mostrar información
    void mostrarInformacion() {
        // Completar aquí: mostrar información de la biblioteca
    }
}

// ==============================================================================
// FUNCIONES DEL MENÚ DE DEMOSTRACIÓN
// ==============================================================================

// TODO: Implementar función del menú principal
void mostrarMenu() {
    // Completar aquí: mostrar opciones del menú
}

// TODO: Implementar función para probar matemáticas
void probarMatematicas() {
    // Completar aquí: probar funciones matemáticas
}

// TODO: Implementar función para probar texto
void probarTexto() {
    // Completar aquí: probar funciones de texto
}

// TODO: Implementar función para probar validaciones
void probarValidaciones() {
    // Completar aquí: probar funciones de validación
}

// TODO: Implementar función para probar arreglos
void probarArreglos() {
    // Completar aquí: probar funciones de arreglos
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    int opcion;
    
    cout << "=== DEMOSTRACIÓN DE BIBLIOTECA DE UTILIDADES ===" << endl;
    cout << "Implemente las funciones marcadas con TODO para completar el ejercicio." << endl;
    
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
                probarArreglos();
                break;
            case 5:
                MiUtilidades::mostrarInformacion();
                break;
            case 6:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
        
        if (opcion != 6) {
            MiUtilidades::pausar();
        }
    } while (opcion != 6);
    
    cout << "Programa finalizado." << endl;
    return 0;
}

/*
 * PISTAS PARA LA IMPLEMENTACIÓN:
 * 
 * 1. FUNCIONES MATEMÁTICAS:
 *    - Usar M_PI para π (pi)
 *    - Usar pow() para potencias
 *    - Usar sqrt() para raíz cuadrada
 * 
 * 2. FUNCIONES DE TEXTO:
 *    - Usar toupper() y tolower() para conversión
 *    - Usar isalpha() para verificar letras
 *    - Usar length() para obtener tamaño
 * 
 * 3. VALIDACIONES:
 *    - Usar find() para buscar caracteres
 *    - Usar isdigit() para verificar números
 *    - Verificar longitudes con length()
 * 
 * 4. ARREGLOS:
 *    - Usar size() para obtener tamaño
 *    - Usar [] para acceder a elementos
 *    - Usar bucles for para recorrer
 * 
 * 5. ORGANIZACIÓN:
 *    - Separar en archivos .h y .cpp
 *    - Usar namespaces para agrupar
 *    - Documentar todas las funciones
 * 
 * CONCEPTOS CLAVE:
 * - Separación de interfaz e implementación
 * - Organización con namespaces
 * - Funciones de propósito general
 * - Validación de datos
 * - Reutilización de código
 * - Documentación clara
 */
