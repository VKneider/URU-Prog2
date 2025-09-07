/*
 * Archivo: 6_punteros_estructuras.cpp
 * Descripcion: Demostracion de punteros con estructuras y acceso a miembros
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <locale>
#include <string>
using namespace std;

// ============================================================================
// ESTRUCTURA BÁSICA
// ============================================================================

struct Persona {
    string nombre;
    int edad;
    float salario;
};

// ============================================================================
// PUNTERO A ESTRUCTURA SIMPLE
// ============================================================================

void demostrarPunteroEstructura() {
    cout << "=== PUNTERO A ESTRUCTURA SIMPLE ===" << endl;
    
    // Crear estructura en memoria dinámica
    Persona* persona = new Persona;
    
    // Acceso a miembros usando ->
    persona->nombre = "Juan Pérez";
    persona->edad = 25;
    persona->salario = 50000.0;
    
    cout << "Información de la persona:" << endl;
    cout << "Nombre: " << persona->nombre << endl;
    cout << "Edad: " << persona->edad << endl;
    cout << "Salario: $" << persona->salario << endl;
    
    // Mostrar direcciones
    cout << "\nDirecciones de memoria:" << endl;
    cout << "Estructura completa: " << persona << endl;
    cout << "Campo nombre: " << &persona->nombre << endl;
    cout << "Campo edad: " << &persona->edad << endl;
    cout << "Campo salario: " << &persona->salario << endl;
    
    // Liberar memoria
    delete persona;
    persona = nullptr;
    
    cout << "✓ Memoria liberada correctamente" << endl;
}

// ============================================================================
// ARREGLO DE ESTRUCTURAS CON PUNTEROS
// ============================================================================

void demostrarArregloEstructuras() {
    cout << "\n=== ARREGLO DE ESTRUCTURAS CON PUNTEROS ===" << endl;
    
    int cantidad;
    cout << "Ingrese cantidad de personas: ";
    cin >> cantidad;
    
    // Crear arreglo dinámico de estructuras
    Persona* personas = new Persona[cantidad];
    
    // Llenar datos
    cout << "Ingrese datos de las personas:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "\nPersona " << (i + 1) << ":" << endl;
        cout << "  Nombre: ";
        cin.ignore();
        getline(cin, personas[i].nombre);
        cout << "  Edad: ";
        cin >> personas[i].edad;
        cout << "  Salario: ";
        cin >> personas[i].salario;
    }
    
    // Mostrar datos usando punteros
    cout << "\nLista de personas:" << endl;
    Persona* ptr = personas; // Puntero al primer elemento
    
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << ptr->nombre 
             << " (" << ptr->edad << " años) - $" << ptr->salario << endl;
        ptr++; // Mover al siguiente elemento
    }
    
    // Calcular promedio de salarios
    float sumaSalarios = 0;
    for (int i = 0; i < cantidad; i++) {
        sumaSalarios += personas[i].salario;
    }
    float promedio = sumaSalarios / cantidad;
    
    cout << "\nPromedio de salarios: $" << promedio << endl;
    
    // Liberar memoria
    delete[] personas;
    personas = nullptr;
    
    cout << "✓ Memoria del arreglo liberada" << endl;
}

// ============================================================================
// ESTRUCTURAS CON PUNTEROS COMO MIEMBROS
// ============================================================================

struct Estudiante {
    string nombre;
    int* notas;        // Puntero a arreglo de notas
    int cantidadNotas;
};

void demostrarEstructuraConPunteros() {
    cout << "\n=== ESTRUCTURA CON PUNTEROS COMO MIEMBROS ===" << endl;
    
    Estudiante* estudiante = new Estudiante;
    
    cout << "Ingrese nombre del estudiante: ";
    cin.ignore();
    getline(cin, estudiante->nombre);
    
    cout << "Ingrese cantidad de notas: ";
    cin >> estudiante->cantidadNotas;
    
    // Crear arreglo dinámico de notas
    estudiante->notas = new int[estudiante->cantidadNotas];
    
    // Llenar notas
    cout << "Ingrese las notas:" << endl;
    for (int i = 0; i < estudiante->cantidadNotas; i++) {
        cout << "Nota " << (i + 1) << ": ";
        cin >> estudiante->notas[i];
    }
    
    // Mostrar información
    cout << "\nInformación del estudiante:" << endl;
    cout << "Nombre: " << estudiante->nombre << endl;
    cout << "Notas: ";
    for (int i = 0; i < estudiante->cantidadNotas; i++) {
        cout << estudiante->notas[i] << " ";
    }
    cout << endl;
    
    // Calcular promedio
    float suma = 0;
    for (int i = 0; i < estudiante->cantidadNotas; i++) {
        suma += estudiante->notas[i];
    }
    float promedio = suma / estudiante->cantidadNotas;
    cout << "Promedio: " << promedio << endl;
    
    // Liberar memoria (orden importante)
    delete[] estudiante->notas;  // Primero el arreglo de notas
    delete estudiante;           // Luego la estructura
    estudiante = nullptr;
    
    cout << "✓ Memoria liberada correctamente" << endl;
}

// ============================================================================
// ARREGLO DE PUNTEROS A ESTRUCTURAS
// ============================================================================

void demostrarArregloPunterosEstructuras() {
    cout << "\n=== ARREGLO DE PUNTEROS A ESTRUCTURAS ===" << endl;
    
    int cantidad;
    cout << "Ingrese cantidad de empleados: ";
    cin >> cantidad;
    
    // Arreglo de punteros a Persona
    Persona** empleados = new Persona*[cantidad];
    
    // Crear cada estructura dinámicamente
    for (int i = 0; i < cantidad; i++) {
        empleados[i] = new Persona;
        
        cout << "\nEmpleado " << (i + 1) << ":" << endl;
        cout << "  Nombre: ";
        cin.ignore();
        getline(cin, empleados[i]->nombre);
        cout << "  Edad: ";
        cin >> empleados[i]->edad;
        cout << "  Salario: ";
        cin >> empleados[i]->salario;
    }
    
    // Mostrar información
    cout << "\nLista de empleados:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << empleados[i]->nombre 
             << " (" << empleados[i]->edad << " años) - $" 
             << empleados[i]->salario << endl;
    }
    
    // Encontrar empleado con mayor salario
    Persona* mayorSalario = empleados[0];
    for (int i = 1; i < cantidad; i++) {
        if (empleados[i]->salario > mayorSalario->salario) {
            mayorSalario = empleados[i];
        }
    }
    
    cout << "\nEmpleado con mayor salario:" << endl;
    cout << "Nombre: " << mayorSalario->nombre << endl;
    cout << "Salario: $" << mayorSalario->salario << endl;
    
    // Liberar memoria (orden importante)
    for (int i = 0; i < cantidad; i++) {
        delete empleados[i];
        empleados[i] = nullptr;
    }
    delete[] empleados;
    empleados = nullptr;
    
    cout << "✓ Memoria de todos los empleados liberada" << endl;
}

// ============================================================================
// FUNCIONES CON PUNTEROS A ESTRUCTURAS
// ============================================================================

// Función que recibe puntero a estructura
void mostrarPersona(const Persona* p) {
    if (p == nullptr) {
        cout << "Error: Puntero nulo" << endl;
        return;
    }
    
    cout << "Nombre: " << p->nombre << endl;
    cout << "Edad: " << p->edad << endl;
    cout << "Salario: $" << p->salario << endl;
}

// Función que modifica estructura a través de puntero
void aumentarSalario(Persona* p, float porcentaje) {
    if (p == nullptr) {
        cout << "Error: Puntero nulo" << endl;
        return;
    }
    
    p->salario *= (1 + porcentaje / 100);
    cout << "Salario aumentado en " << porcentaje << "%" << endl;
}

void demostrarFuncionesConPunteros() {
    cout << "\n=== FUNCIONES CON PUNTEROS A ESTRUCTURAS ===" << endl;
    
    Persona* persona = new Persona;
    persona->nombre = "María García";
    persona->edad = 30;
    persona->salario = 60000.0;
    
    cout << "Información original:" << endl;
    mostrarPersona(persona);
    
    cout << "\nAumentando salario en 10%..." << endl;
    aumentarSalario(persona, 10);
    
    cout << "\nInformación actualizada:" << endl;
    mostrarPersona(persona);
    
    delete persona;
    persona = nullptr;
    
    cout << "✓ Memoria liberada" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== PUNTEROS CON ESTRUCTURAS ===" << endl;
    cout << "Enfoque: Acceso a miembros, arreglos de estructuras, funciones\n" << endl;
    
    demostrarPunteroEstructura();
    demostrarArregloEstructuras();
    demostrarEstructuraConPunteros();
    demostrarArregloPunterosEstructuras();
    demostrarFuncionesConPunteros();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Usar -> para acceder a miembros de estructura a través de puntero" << endl;
    cout << "✓ Los arreglos de estructuras permiten manejar múltiples objetos" << endl;
    cout << "✓ Las estructuras pueden tener punteros como miembros" << endl;
    cout << "✓ Los arreglos de punteros a estructuras ofrecen máxima flexibilidad" << endl;
    cout << "✓ Siempre liberar memoria en orden inverso al de asignación" << endl;
    cout << "✓ Verificar que los punteros no sean nullptr antes de usar" << endl;
    
    return 0;
}
