/*
 * Archivo: 4_acceso_random_avanzado.cpp
 * Descripcion: Acceso directo y modificación en archivos binarios
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;

// ============================================================================
// ESTRUCTURAS PARA DEMOSTRAR ACCESO RANDOM
// ============================================================================

struct Empleado {
    int id;
    char nombre[50];
    char departamento[30];
    float salario;
    bool activo;
};

struct Producto {
    int codigo;
    char nombre[50];
    float precio;
    int stock;
    char categoria[30];
};

// ============================================================================
// ACCESO RANDOM BÁSICO CON SEEK
// ============================================================================

void accesoRandomBasico() {
    cout << "=== ACCESO RANDOM BÁSICO CON SEEK ===" << endl;
    
    // Crear archivo con datos de ejemplo
    Empleado empleados[] = {
        {1, "Ana García", "Ventas", 50000.0f, true},
        {2, "Carlos López", "IT", 75000.0f, true},
        {3, "María Rodríguez", "RRHH", 45000.0f, true},
        {4, "Pedro Martínez", "Finanzas", 60000.0f, true},
        {5, "Laura Sánchez", "Marketing", 55000.0f, true}
    };
    
    // Escribir empleados a archivo
    ofstream archivo("empleados_random.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        return;
    }
    
    // Escribir cantidad primero
    int cantidad = 5;
    archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Escribir todos los empleados
    archivo.write(reinterpret_cast<char*>(empleados), cantidad * sizeof(Empleado));
    archivo.close();
    
    cout << "✓ " << cantidad << " empleados escritos en empleados_random.bin" << endl;
    
    // Demostrar acceso random
    cout << "\nDemostrando acceso random:" << endl;
    
    ifstream archivoLectura("empleados_random.bin", ios::binary);
    if (!archivoLectura) {
        cout << "Error: No se pudo abrir el archivo para lectura." << endl;
        return;
    }
    
    // Leer cantidad
    int cantidadArchivo;
    archivoLectura.read(reinterpret_cast<char*>(&cantidadArchivo), sizeof(int));
    
    cout << "Total de empleados en archivo: " << cantidadArchivo << endl;
    
    // Leer empleados específicos usando seekg
    for (int i = 0; i < cantidadArchivo; i++) {
        Empleado empleado;
        
        // Posicionarse en el empleado i
        archivoLectura.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
        
        // Leer solo ese empleado
        archivoLectura.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
        
        cout << "Empleado " << (i + 1) << ": " << empleado.nombre 
             << " (ID: " << empleado.id << ") - $" << empleado.salario << endl;
    }
    
    archivoLectura.close();
    
    cout << "✓ Acceso random básico completado" << endl;
}

// ============================================================================
// MODIFICACIÓN DE REGISTROS ESPECÍFICOS
// ============================================================================

void modificarRegistroEspecifico() {
    cout << "\n=== MODIFICACIÓN DE REGISTROS ESPECÍFICOS ===" << endl;
    
    fstream archivo("empleados_random.bin", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo para modificación." << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    cout << "Hay " << cantidad << " empleados en el archivo." << endl;
    
    int indice;
    cout << "Ingrese el índice del empleado a modificar (0-" << (cantidad-1) << "): ";
    cin >> indice;
    
    if (indice < 0 || indice >= cantidad) {
        cout << "Error: Índice fuera de rango." << endl;
        archivo.close();
        return;
    }
    
    // Leer empleado actual
    Empleado empleado;
    archivo.seekg(sizeof(int) + indice * sizeof(Empleado), ios::beg);
    archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
    
    cout << "\nEmpleado actual:" << endl;
    cout << "ID: " << empleado.id << endl;
    cout << "Nombre: " << empleado.nombre << endl;
    cout << "Departamento: " << empleado.departamento << endl;
    cout << "Salario: $" << empleado.salario << endl;
    cout << "Activo: " << (empleado.activo ? "Sí" : "No") << endl;
    
    // Modificar datos
    cout << "\nIngrese nuevos datos:" << endl;
    cout << "Nuevo salario: ";
    cin >> empleado.salario;
    cout << "¿Está activo? (1=Sí, 0=No): ";
    cin >> empleado.activo;
    
    // Escribir empleado modificado
    archivo.seekp(sizeof(int) + indice * sizeof(Empleado), ios::beg);
    archivo.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
    
    archivo.close();
    
    cout << "✓ Empleado modificado y guardado en archivo" << endl;
}

// ============================================================================
// BÚSQUEDA EFICIENTE CON ACCESO RANDOM
// ============================================================================

void busquedaEficienteRandom() {
    cout << "\n=== BÚSQUEDA EFICIENTE CON ACCESO RANDOM ===" << endl;
    
    ifstream archivo("empleados_random.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    int idBuscado;
    cout << "Ingrese ID del empleado a buscar: ";
    cin >> idBuscado;
    
    bool encontrado = false;
    Empleado empleado;
    
    // Búsqueda secuencial con acceso random
    for (int i = 0; i < cantidad; i++) {
        archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
        archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
        
        if (empleado.id == idBuscado) {
            encontrado = true;
            break;
        }
    }
    
    archivo.close();
    
    if (encontrado) {
        cout << "\n✓ Empleado encontrado:" << endl;
        cout << "ID: " << empleado.id << endl;
        cout << "Nombre: " << empleado.nombre << endl;
        cout << "Departamento: " << empleado.departamento << endl;
        cout << "Salario: $" << empleado.salario << endl;
        cout << "Activo: " << (empleado.activo ? "Sí" : "No") << endl;
    } else {
        cout << "\n✗ Empleado con ID " << idBuscado << " no encontrado." << endl;
    }
}

// ============================================================================
// SISTEMA DE ÍNDICES PARA ACCESO RÁPIDO
// ============================================================================

struct IndiceEmpleado {
    int id;
    long posicion; // Posición en el archivo
};

void crearSistemaIndices() {
    cout << "\n=== SISTEMA DE ÍNDICES PARA ACCESO RÁPIDO ===" << endl;
    
    ifstream archivo("empleados_random.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Crear array de índices
    IndiceEmpleado* indices = new IndiceEmpleado[cantidad];
    
    // Construir índice
    for (int i = 0; i < cantidad; i++) {
        Empleado empleado;
        archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
        archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
        
        indices[i].id = empleado.id;
        indices[i].posicion = sizeof(int) + i * sizeof(Empleado);
    }
    
    archivo.close();
    
    // Mostrar índice
    cout << "Índice creado:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "ID: " << indices[i].id << " - Posición: " << indices[i].posicion << endl;
    }
    
    // Guardar índice en archivo separado
    ofstream archivoIndice("indice_empleados.bin", ios::binary);
    if (archivoIndice.is_open()) {
        archivoIndice.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
        archivoIndice.write(reinterpret_cast<char*>(indices), cantidad * sizeof(IndiceEmpleado));
        archivoIndice.close();
        
        cout << "\n✓ Índice guardado en indice_empleados.bin" << endl;
    }
    
    // Liberar memoria
    delete[] indices;
    indices = nullptr;
}

// ============================================================================
// BÚSQUEDA RÁPIDA USANDO ÍNDICES
// ============================================================================

void busquedaRapidaConIndices() {
    cout << "\n=== BÚSQUEDA RÁPIDA USANDO ÍNDICES ===" << endl;
    
    // Cargar índice
    ifstream archivoIndice("indice_empleados.bin", ios::binary);
    if (!archivoIndice) {
        cout << "Error: No se pudo abrir el archivo de índice." << endl;
        return;
    }
    
    int cantidad;
    archivoIndice.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    IndiceEmpleado* indices = new IndiceEmpleado[cantidad];
    archivoIndice.read(reinterpret_cast<char*>(indices), cantidad * sizeof(IndiceEmpleado));
    archivoIndice.close();
    
    int idBuscado;
    cout << "Ingrese ID del empleado a buscar: ";
    cin >> idBuscado;
    
    // Buscar en índice
    bool encontrado = false;
    long posicion = -1;
    
    for (int i = 0; i < cantidad; i++) {
        if (indices[i].id == idBuscado) {
            encontrado = true;
            posicion = indices[i].posicion;
            break;
        }
    }
    
    if (encontrado) {
        // Leer empleado directamente desde la posición encontrada
        ifstream archivo("empleados_random.bin", ios::binary);
        if (archivo.is_open()) {
            Empleado empleado;
            archivo.seekg(posicion, ios::beg);
            archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
            archivo.close();
            
            cout << "\n✓ Empleado encontrado (búsqueda rápida):" << endl;
            cout << "ID: " << empleado.id << endl;
            cout << "Nombre: " << empleado.nombre << endl;
            cout << "Departamento: " << empleado.departamento << endl;
            cout << "Salario: $" << empleado.salario << endl;
            cout << "Activo: " << (empleado.activo ? "Sí" : "No") << endl;
        }
    } else {
        cout << "\n✗ Empleado con ID " << idBuscado << " no encontrado." << endl;
    }
    
    // Liberar memoria
    delete[] indices;
    indices = nullptr;
}

// ============================================================================
// OPERACIONES CRUD COMPLETAS
// ============================================================================

void operacionesCRUDCompletas() {
    cout << "\n=== OPERACIONES CRUD COMPLETAS ===" << endl;
    
    fstream archivo("empleados_crud.bin", ios::in | ios::out | ios::binary);
    if (!archivo) {
        // Crear archivo si no existe
        archivo.open("empleados_crud.bin", ios::out | ios::binary);
        int cantidad = 0;
        archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
        archivo.close();
        
        archivo.open("empleados_crud.bin", ios::in | ios::out | ios::binary);
    }
    
    int opcion;
    do {
        cout << "\n=== MENÚ CRUD ===" << endl;
        cout << "1. Crear empleado" << endl;
        cout << "2. Leer empleado" << endl;
        cout << "3. Actualizar empleado" << endl;
        cout << "4. Eliminar empleado" << endl;
        cout << "5. Listar todos" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                // CREATE
                Empleado nuevo;
                cout << "\nIngrese datos del nuevo empleado:" << endl;
                cout << "ID: ";
                cin >> nuevo.id;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(nuevo.nombre, 50);
                cout << "Departamento: ";
                cin.getline(nuevo.departamento, 30);
                cout << "Salario: ";
                cin >> nuevo.salario;
                nuevo.activo = true;
                
                // Leer cantidad actual
                archivo.seekg(0, ios::beg);
                int cantidad;
                archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                // Escribir nuevo empleado al final
                archivo.seekp(sizeof(int) + cantidad * sizeof(Empleado), ios::beg);
                archivo.write(reinterpret_cast<char*>(&nuevo), sizeof(Empleado));
                
                // Actualizar cantidad
                cantidad++;
                archivo.seekp(0, ios::beg);
                archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                cout << "✓ Empleado creado correctamente" << endl;
                break;
            }
            case 2: {
                // READ
                int id;
                cout << "Ingrese ID del empleado: ";
                cin >> id;
                
                archivo.seekg(0, ios::beg);
                int cantidad;
                archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                bool encontrado = false;
                for (int i = 0; i < cantidad; i++) {
                    Empleado empleado;
                    archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
                    archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                    
                    if (empleado.id == id) {
                        cout << "\n✓ Empleado encontrado:" << endl;
                        cout << "ID: " << empleado.id << endl;
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Departamento: " << empleado.departamento << endl;
                        cout << "Salario: $" << empleado.salario << endl;
                        cout << "Activo: " << (empleado.activo ? "Sí" : "No") << endl;
                        encontrado = true;
                        break;
                    }
                }
                
                if (!encontrado) {
                    cout << "✗ Empleado no encontrado" << endl;
                }
                break;
            }
            case 3: {
                // UPDATE
                int id;
                cout << "Ingrese ID del empleado a actualizar: ";
                cin >> id;
                
                archivo.seekg(0, ios::beg);
                int cantidad;
                archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                bool encontrado = false;
                for (int i = 0; i < cantidad; i++) {
                    Empleado empleado;
                    archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
                    archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                    
                    if (empleado.id == id) {
                        cout << "\nEmpleado actual:" << endl;
                        cout << "Nombre: " << empleado.nombre << endl;
                        cout << "Departamento: " << empleado.departamento << endl;
                        cout << "Salario: $" << empleado.salario << endl;
                        
                        cout << "\nIngrese nuevos datos:" << endl;
                        cout << "Nuevo salario: ";
                        cin >> empleado.salario;
                        cout << "¿Está activo? (1=Sí, 0=No): ";
                        cin >> empleado.activo;
                        
                        // Escribir empleado actualizado
                        archivo.seekp(sizeof(int) + i * sizeof(Empleado), ios::beg);
                        archivo.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                        
                        cout << "✓ Empleado actualizado correctamente" << endl;
                        encontrado = true;
                        break;
                    }
                }
                
                if (!encontrado) {
                    cout << "✗ Empleado no encontrado" << endl;
                }
                break;
            }
            case 4: {
                // DELETE (marcar como inactivo)
                int id;
                cout << "Ingrese ID del empleado a eliminar: ";
                cin >> id;
                
                archivo.seekg(0, ios::beg);
                int cantidad;
                archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                bool encontrado = false;
                for (int i = 0; i < cantidad; i++) {
                    Empleado empleado;
                    archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
                    archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                    
                    if (empleado.id == id) {
                        empleado.activo = false;
                        
                        // Escribir empleado marcado como inactivo
                        archivo.seekp(sizeof(int) + i * sizeof(Empleado), ios::beg);
                        archivo.write(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                        
                        cout << "✓ Empleado marcado como inactivo" << endl;
                        encontrado = true;
                        break;
                    }
                }
                
                if (!encontrado) {
                    cout << "✗ Empleado no encontrado" << endl;
                }
                break;
            }
            case 5: {
                // LISTAR TODOS
                archivo.seekg(0, ios::beg);
                int cantidad;
                archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
                
                cout << "\n=== LISTA DE EMPLEADOS ===" << endl;
                for (int i = 0; i < cantidad; i++) {
                    Empleado empleado;
                    archivo.seekg(sizeof(int) + i * sizeof(Empleado), ios::beg);
                    archivo.read(reinterpret_cast<char*>(&empleado), sizeof(Empleado));
                    
                    cout << (i + 1) << ". " << empleado.nombre 
                         << " (ID: " << empleado.id << ") - $" << empleado.salario 
                         << " - " << (empleado.activo ? "Activo" : "Inactivo") << endl;
                }
                break;
            }
            case 6:
                cout << "Saliendo del sistema CRUD..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 6);
    
    archivo.close();
    cout << "✓ Sistema CRUD completado" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== ACCESO RANDOM AVANZADO EN ARCHIVOS BINARIOS ===" << endl;
    cout << "Enfoque: Seek, modificación, índices, búsquedas rápidas, CRUD\n" << endl;
    
    accesoRandomBasico();
    modificarRegistroEspecifico();
    busquedaEficienteRandom();
    crearSistemaIndices();
    busquedaRapidaConIndices();
    operacionesCRUDCompletas();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ seekg/seekp permiten acceso directo a posiciones específicas" << endl;
    cout << "✓ La modificación de registros es eficiente con acceso random" << endl;
    cout << "✓ Los índices aceleran las búsquedas en archivos grandes" << endl;
    cout << "✓ Las operaciones CRUD son posibles con archivos binarios" << endl;
    cout << "✓ El acceso random es más eficiente que la lectura secuencial" << endl;
    cout << "✓ Siempre verificar que las posiciones estén dentro del archivo" << endl;
    
    return 0;
}
