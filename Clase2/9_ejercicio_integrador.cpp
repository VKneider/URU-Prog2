
/*
 * EJERCICIO CLASE 2 - PUNTEROS Y ARCHIVOS
 * =======================================
 * 
 * ENUNCIADO:
 * Implementar un programa que permita:
 * 1. Guardar notas de estudiantes en un archivo de texto
 * 2. Leer y mostrar las notas guardadas
 * 3. Calcular el promedio de las notas
 * 4. Agregar nuevas notas al archivo existente
 * 
 * REQUISITOS OBLIGATORIOS:
 * - Usar punteros para manejar datos dinámicamente
 * - Usar archivos de texto (.txt) para persistencia
 * - Validar entrada del usuario (notas entre 1-20)
 * - Manejar errores de archivo correctamente
 * - Liberar memoria asignada dinámicamente
 * 
 * FUNCIONES QUE DEBE IMPLEMENTAR:
 * 1. void agregarNota(string nombreArchivo)
 * 2. void mostrarNotas(string nombreArchivo)
 * 3. float calcularPromedio(string nombreArchivo)
 * 4. void mostrarMenu()
 * 5. bool validarNota(int nota)
 * 
 * ESTRUCTURA DE DATOS:
 * struct Estudiante {
 *     string nombre;
 *     int nota;
 * };
 * 
 * FORMATO DEL ARCHIVO:
 * - Archivo: notas.txt
 * - Formato: nombre,nota (una línea por estudiante)
 * - Ejemplo:
 *   Juan,15
 *   Maria,18
 *   Pedro,12
 * 
 * MENÚ SIMPLE:
 * === Registro de Notas ===
 * 1. Agregar nota
 * 2. Ver todas las notas
 * 3. Calcular promedio
 * 4. Salir
 * Elija una opción: _
 * 
 * VALIDACIONES REQUERIDAS:
 * - Nota debe estar entre 1 y 20
 * - Nombre no puede estar vacío
 * - Verificar que el archivo se pueda abrir
 * - Manejar archivo inexistente en lectura
 * 
 * CRITERIOS DE EVALUACIÓN:
 * - Correcta implementación de archivos (40%)
 * - Uso apropiado de punteros (30%)
 * - Validación de datos (20%)
 * - Manejo de errores (10%)
 * 
 * TIEMPO ESTIMADO: 1-2 horas
 * DIFICULTAD: Básica-Medio
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// TODO: Implementar estructura Estudiante
struct Estudiante {
    // Completar aquí
};

// TODO: Implementar función de validación
bool validarNota(int nota) {
    // Completar aquí
    return false;
}

// TODO: Implementar función para agregar nota
void agregarNota(string nombreArchivo) {
    // Completar aquí
}

// TODO: Implementar función para mostrar notas
void mostrarNotas(string nombreArchivo) {
    // Completar aquí
}

// TODO: Implementar función para calcular promedio
float calcularPromedio(string nombreArchivo) {
    // Completar aquí
    return 0.0f;
}

// TODO: Implementar función del menú
void mostrarMenu() {
    // Completar aquí
}

int main() {
    string nombreArchivo = "notas.txt";
    int opcion;
    
    cout << "=== SISTEMA DE REGISTRO DE NOTAS ===" << endl;
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                agregarNota(nombreArchivo);
                break;
            case 2:
                mostrarNotas(nombreArchivo);
                break;
            case 3:
                calcularPromedio(nombreArchivo);
                break;
            case 4:
                cout << "¡Hasta luego!" << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
        
    } while (opcion != 4);
    
    return 0;
}
