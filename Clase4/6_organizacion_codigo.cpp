/*
 * Archivo: 5_organizacion_codigo.cpp
 * Descripcion: Demuestra cómo organizar mejor el código usando POO con separación de archivos
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <locale>
#include <string>
#include <vector>
using namespace std;

/*
==================================================================================
    ORGANIZACIÓN DE CÓDIGO CON POO
==================================================================================
    Cuando nuestros programas crecen, es importante organizar el código para:
    1. Mejorar la legibilidad
    2. Facilitar el mantenimiento
    3. Permitir trabajo en equipo
    4. Evitar duplicación de código
    5. Separar responsabilidades
*/

// ==============================================================================
// EJEMPLO: Sistema de Gestión de Estudiantes
// ==============================================================================

// Clase para manejar datos de un estudiante
class Estudiante {
private:
    string nombre;
    string apellido;
    int edad;
    string carrera;
    vector<double> notas;

public:
    // Constructor
    Estudiante(string n, string a, int e, string c) 
        : nombre(n), apellido(a), edad(e), carrera(c) {
        cout << "Estudiante " << nombre << " " << apellido << " registrado" << endl;
    }

    // Getters
    string getNombre() const { return nombre; }
    string getApellido() const { return apellido; }
    int getEdad() const { return edad; }
    string getCarrera() const { return carrera; }

    // Métodos para manejar notas
    void agregarNota(double nota) {
        if (nota >= 0 && nota <= 20) {
            notas.push_back(nota);
            cout << "Nota " << nota << " agregada a " << nombre << endl;
        } else {
            cout << "Nota inválida. Debe estar entre 0 y 20" << endl;
        }
    }

    double calcularPromedio() const {
        if (notas.empty()) return 0.0;
        
        double suma = 0;
        for (double nota : notas) {
            suma += nota;
        }
        return suma / notas.size();
    }

    void mostrarInformacion() const {
        cout << "Estudiante: " << nombre << " " << apellido << endl;
        cout << "  Edad: " << edad << " años" << endl;
        cout << "  Carrera: " << carrera << endl;
        cout << "  Promedio: " << calcularPromedio() << endl;
        cout << "  Notas: ";
        for (double nota : notas) {
            cout << nota << " ";
        }
        cout << endl;
    }
};

// Clase para manejar la lista de estudiantes
class GestionEstudiantes {
private:
    vector<Estudiante> estudiantes;

public:
    // Agregar estudiante
    void agregarEstudiante(const Estudiante& estudiante) {
        estudiantes.push_back(estudiante);
        cout << "Estudiante agregado al sistema" << endl;
    }

    // Buscar estudiante por nombre
    Estudiante* buscarEstudiante(string nombre) {
        for (auto& est : estudiantes) {
            if (est.getNombre() == nombre) {
                return &est;
            }
        }
        return nullptr;
    }

    // Mostrar todos los estudiantes
    void mostrarTodosEstudiantes() const {
        cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
        cout << "Total: " << estudiantes.size() << " estudiantes" << endl;
        cout << "=============================" << endl;
        
        for (const auto& est : estudiantes) {
            est.mostrarInformacion();
            cout << "---" << endl;
        }
    }

    // Calcular promedio general
    double calcularPromedioGeneral() const {
        if (estudiantes.empty()) return 0.0;
        
        double sumaTotal = 0;
        int contador = 0;
        
        for (const auto& est : estudiantes) {
            sumaTotal += est.calcularPromedio();
            contador++;
        }
        
        return sumaTotal / contador;
    }

    // Mostrar estadísticas
    void mostrarEstadisticas() const {
        cout << "\n=== ESTADÍSTICAS ===" << endl;
        cout << "Total estudiantes: " << estudiantes.size() << endl;
        cout << "Promedio general: " << calcularPromedioGeneral() << endl;
        
        // Contar por carrera
        cout << "\nEstudiantes por carrera:" << endl;
        vector<string> carreras;
        vector<int> contadores;
        
        for (const auto& est : estudiantes) {
            string carrera = est.getCarrera();
            bool encontrado = false;
            
            for (int i = 0; i < carreras.size(); i++) {
                if (carreras[i] == carrera) {
                    contadores[i]++;
                    encontrado = true;
                    break;
                }
            }
            
            if (!encontrado) {
                carreras.push_back(carrera);
                contadores.push_back(1);
            }
        }
        
        for (int i = 0; i < carreras.size(); i++) {
            cout << "  " << carreras[i] << ": " << contadores[i] << " estudiantes" << endl;
        }
    }
};

// ==============================================================================
// EJEMPLO: Sistema de Archivos (simulado)
// ==============================================================================

class ArchivoEstudiantes {
private:
    string nombreArchivo;

public:
    ArchivoEstudiantes(string archivo) : nombreArchivo(archivo) {}

    // Simular guardado en archivo
    void guardarEstudiantes(const GestionEstudiantes& gestion) {
        cout << "\n=== GUARDANDO EN ARCHIVO ===" << endl;
        cout << "Archivo: " << nombreArchivo << endl;
        cout << "Formato: nombre|apellido|edad|carrera|promedio" << endl;
        cout << "Datos guardados correctamente" << endl;
    }

    // Simular carga desde archivo
    void cargarEstudiantes(GestionEstudiantes& gestion) {
        cout << "\n=== CARGANDO DESDE ARCHIVO ===" << endl;
        cout << "Archivo: " << nombreArchivo << endl;
        cout << "Datos cargados correctamente" << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== SISTEMA DE GESTIÓN DE ESTUDIANTES ===" << endl;
    cout << "===========================================" << endl;
    
    // Crear sistema de gestión
    GestionEstudiantes sistema;
    ArchivoEstudiantes archivo("estudiantes.txt");
    
    // Crear algunos estudiantes
    Estudiante est1("Ana", "García", 20, "Ingeniería");
    Estudiante est2("Carlos", "López", 22, "Medicina");
    Estudiante est3("María", "Rodríguez", 21, "Ingeniería");
    
    // Agregar notas
    est1.agregarNota(18);
    est1.agregarNota(16);
    est1.agregarNota(19);
    
    est2.agregarNota(17);
    est2.agregarNota(20);
    
    est3.agregarNota(15);
    est3.agregarNota(17);
    est3.agregarNota(18);
    est3.agregarNota(16);
    
    // Agregar al sistema
    sistema.agregarEstudiante(est1);
    sistema.agregarEstudiante(est2);
    sistema.agregarEstudiante(est3);
    
    // Mostrar información
    sistema.mostrarTodosEstudiantes();
    sistema.mostrarEstadisticas();
    
    // Simular operaciones de archivo
    archivo.guardarEstudiantes(sistema);
    archivo.cargarEstudiantes(sistema);
    
    cout << "\n=== VENTAJAS DE ESTA ORGANIZACIÓN ===" << endl;
    cout << "======================================" << endl;
    cout << "✓ Separación clara de responsabilidades" << endl;
    cout << "✓ Código más legible y mantenible" << endl;
    cout << "✓ Fácil de extender y modificar" << endl;
    cout << "✓ Reutilización de componentes" << endl;
    cout << "✓ Trabajo en equipo más eficiente" << endl;
    cout << "✓ Testing y debugging más sencillo" << endl;

    return 0;
}
