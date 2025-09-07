/*
 * Archivo: 3_punteros_archivos_dinamicos.cpp
 * Descripcion: Arrays dinámicos con archivos binarios usando punteros
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;

// ============================================================================
// ESTRUCTURAS PARA DEMOSTRAR ARRAYS DINÁMICOS
// ============================================================================

struct Estudiante {
    int id;
    char nombre[50];
    char carrera[50];
    float promedio;
    bool activo;
};

struct Materia {
    int codigo;
    char nombre[50];
    int creditos;
    float nota;
};

// ============================================================================
// CLASE PARA MANEJAR ARRAYS DINÁMICOS CON ARCHIVOS
// ============================================================================

class GestorEstudiantes {
private:
    Estudiante* estudiantes;
    int cantidad;
    int capacidad;
    
public:
    // Constructor
    GestorEstudiantes(int capInicial = 10) : cantidad(0), capacidad(capInicial) {
        estudiantes = new Estudiante[capacidad];
        cout << "GestorEstudiantes creado con capacidad: " << capacidad << endl;
    }
    
    // Destructor
    ~GestorEstudiantes() {
        delete[] estudiantes;
        estudiantes = nullptr;
        cout << "GestorEstudiantes destruido" << endl;
    }
    
    // Agregar estudiante
    bool agregarEstudiante(const Estudiante& nuevo) {
        if (cantidad >= capacidad) {
            // Redimensionar array
            if (!redimensionarArray()) {
                return false;
            }
        }
        
        estudiantes[cantidad] = nuevo;
        cantidad++;
        cout << "Estudiante agregado. Total: " << cantidad << endl;
        return true;
    }
    
    // Mostrar todos los estudiantes
    void mostrarEstudiantes() const {
        cout << "\n=== LISTA DE ESTUDIANTES ===" << endl;
        if (cantidad == 0) {
            cout << "No hay estudiantes registrados." << endl;
            return;
        }
        
        for (int i = 0; i < cantidad; i++) {
            cout << (i + 1) << ". ID: " << estudiantes[i].id 
                 << " - " << estudiantes[i].nombre 
                 << " (" << estudiantes[i].carrera << ")" 
                 << " - Promedio: " << estudiantes[i].promedio 
                 << " - Activo: " << (estudiantes[i].activo ? "Sí" : "No") << endl;
        }
    }
    
    // Buscar estudiante por ID
    Estudiante* buscarPorID(int id) const {
        for (int i = 0; i < cantidad; i++) {
            if (estudiantes[i].id == id) {
                return &estudiantes[i];
            }
        }
        return nullptr;
    }
    
    // Guardar en archivo binario
    bool guardarEnArchivo(const string& nombreArchivo) const {
        ofstream archivo(nombreArchivo, ios::binary);
        if (!archivo) {
            cout << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
            return false;
        }
        
        // Escribir cantidad
        archivo.write(reinterpret_cast<const char*>(&cantidad), sizeof(int));
        
        // Escribir array completo
        archivo.write(reinterpret_cast<const char*>(estudiantes), cantidad * sizeof(Estudiante));
        
        archivo.close();
        cout << "✓ " << cantidad << " estudiantes guardados en " << nombreArchivo << endl;
        return true;
    }
    
    // Cargar desde archivo binario
    bool cargarDesdeArchivo(const string& nombreArchivo) {
        ifstream archivo(nombreArchivo, ios::binary);
        if (!archivo) {
            cout << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
            return false;
        }
        
        // Leer cantidad
        int cantidadArchivo;
        archivo.read(reinterpret_cast<char*>(&cantidadArchivo), sizeof(int));
        
        // Verificar si necesitamos redimensionar
        if (cantidadArchivo > capacidad) {
            delete[] estudiantes;
            capacidad = cantidadArchivo + 10; // Capacidad extra
            estudiantes = new Estudiante[capacidad];
        }
        
        // Leer array completo
        archivo.read(reinterpret_cast<char*>(estudiantes), cantidadArchivo * sizeof(Estudiante));
        
        cantidad = cantidadArchivo;
        archivo.close();
        
        cout << "✓ " << cantidad << " estudiantes cargados desde " << nombreArchivo << endl;
        return true;
    }
    
    // Obtener cantidad actual
    int getCantidad() const { return cantidad; }
    
    // Obtener capacidad actual
    int getCapacidad() const { return capacidad; }
    
private:
    // Redimensionar array dinámico
    bool redimensionarArray() {
        int nuevaCapacidad = capacidad * 2;
        Estudiante* nuevoArray = new Estudiante[nuevaCapacidad];
        
        if (!nuevoArray) {
            cout << "Error: No se pudo redimensionar el array" << endl;
            return false;
        }
        
        // Copiar datos existentes
        for (int i = 0; i < cantidad; i++) {
            nuevoArray[i] = estudiantes[i];
        }
        
        // Liberar array anterior y actualizar puntero
        delete[] estudiantes;
        estudiantes = nuevoArray;
        capacidad = nuevaCapacidad;
        
        cout << "Array redimensionado a capacidad: " << capacidad << endl;
        return true;
    }
};

// ============================================================================
// DEMOSTRACIÓN DE ARRAYS DINÁMICOS CON ARCHIVOS
// ============================================================================

void demostrarArraysDinamicos() {
    cout << "=== DEMOSTRACIÓN DE ARRAYS DINÁMICOS CON ARCHIVOS ===" << endl;
    
    // Crear gestor con capacidad inicial pequeña
    GestorEstudiantes gestor(3);
    
    cout << "Capacidad inicial: " << gestor.getCapacidad() << endl;
    
    // Agregar estudiantes (forzará redimensionamiento)
    Estudiante estudiantes[] = {
        {1, "Ana García", "Ingeniería", 8.5f, true},
        {2, "Carlos López", "Medicina", 9.2f, true},
        {3, "María Rodríguez", "Derecho", 7.8f, true},
        {4, "Pedro Martínez", "Arquitectura", 8.9f, true},
        {5, "Laura Sánchez", "Psicología", 9.0f, true}
    };
    
    cout << "\nAgregando estudiantes..." << endl;
    for (int i = 0; i < 5; i++) {
        gestor.agregarEstudiante(estudiantes[i]);
    }
    
    cout << "Capacidad final: " << gestor.getCapacidad() << endl;
    cout << "Cantidad de estudiantes: " << gestor.getCantidad() << endl;
    
    // Mostrar estudiantes
    gestor.mostrarEstudiantes();
    
    // Guardar en archivo
    gestor.guardarEnArchivo("estudiantes_dinamicos.bin");
    
    cout << "\n✓ Demostración completada" << endl;
}

// ============================================================================
// CARGA Y MANIPULACIÓN DE DATOS DESDE ARCHIVO
// ============================================================================

void cargarYManipularDatos() {
    cout << "\n=== CARGA Y MANIPULACIÓN DE DATOS DESDE ARCHIVO ===" << endl;
    
    // Crear nuevo gestor
    GestorEstudiantes gestor;
    
    // Cargar datos desde archivo
    if (gestor.cargarDesdeArchivo("estudiantes_dinamicos.bin")) {
        cout << "Datos cargados exitosamente" << endl;
        
        // Mostrar datos cargados
        gestor.mostrarEstudiantes();
        
        // Buscar estudiante específico
        int idBuscado;
        cout << "\nIngrese ID del estudiante a buscar: ";
        cin >> idBuscado;
        
        Estudiante* encontrado = gestor.buscarPorID(idBuscado);
        if (encontrado) {
            cout << "\n✓ Estudiante encontrado:" << endl;
            cout << "ID: " << encontrado->id << endl;
            cout << "Nombre: " << encontrado->nombre << endl;
            cout << "Carrera: " << encontrado->carrera << endl;
            cout << "Promedio: " << encontrado->promedio << endl;
            cout << "Activo: " << (encontrado->activo ? "Sí" : "No") << endl;
        } else {
            cout << "\n✗ Estudiante con ID " << idBuscado << " no encontrado." << endl;
        }
    }
}

// ============================================================================
// ARRAYS DE PUNTEROS A ESTRUCTURAS
// ============================================================================

void demostrarArraysPunterosEstructuras() {
    cout << "\n=== ARRAYS DE PUNTEROS A ESTRUCTURAS ===" << endl;
    
    int cantidad;
    cout << "Ingrese cantidad de materias: ";
    cin >> cantidad;
    
    // Crear array de punteros a Materia
    Materia** materias = new Materia*[cantidad];
    
    // Crear cada materia dinámicamente
    cout << "Ingrese datos de las materias:" << endl;
    for (int i = 0; i < cantidad; i++) {
        materias[i] = new Materia;
        
        cout << "\nMateria " << (i + 1) << ":" << endl;
        cout << "  Código: ";
        cin >> materias[i]->codigo;
        cout << "  Nombre: ";
        cin.ignore();
        cin.getline(materias[i]->nombre, 50);
        cout << "  Créditos: ";
        cin >> materias[i]->creditos;
        cout << "  Nota: ";
        cin >> materias[i]->nota;
    }
    
    // Mostrar materias
    cout << "\nMaterias ingresadas:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << materias[i]->codigo 
             << " - " << materias[i]->nombre 
             << " (" << materias[i]->creditos << " créditos) - Nota: " 
             << materias[i]->nota << endl;
    }
    
    // Guardar array de punteros en archivo
    ofstream archivo("materias_punteros.bin", ios::binary);
    if (archivo.is_open()) {
        // Escribir cantidad
        archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
        
        // Escribir cada materia
        for (int i = 0; i < cantidad; i++) {
            archivo.write(reinterpret_cast<char*>(materias[i]), sizeof(Materia));
        }
        
        archivo.close();
        cout << "\n✓ " << cantidad << " materias guardadas en materias_punteros.bin" << endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        delete materias[i];
        materias[i] = nullptr;
    }
    delete[] materias;
    materias = nullptr;
    
    cout << "✓ Memoria liberada correctamente" << endl;
}

// ============================================================================
// CARGAR ARRAY DE PUNTEROS DESDE ARCHIVO
// ============================================================================

void cargarArrayPunterosDesdeArchivo() {
    cout << "\n=== CARGAR ARRAY DE PUNTEROS DESDE ARCHIVO ===" << endl;
    
    ifstream archivo("materias_punteros.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo materias_punteros.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Crear array de punteros
    Materia** materias = new Materia*[cantidad];
    
    // Leer cada materia
    for (int i = 0; i < cantidad; i++) {
        materias[i] = new Materia;
        archivo.read(reinterpret_cast<char*>(materias[i]), sizeof(Materia));
    }
    
    archivo.close();
    
    // Mostrar materias leídas
    cout << "Materias cargadas desde archivo:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << materias[i]->codigo 
             << " - " << materias[i]->nombre 
             << " (" << materias[i]->creditos << " créditos) - Nota: " 
             << materias[i]->nota << endl;
    }
    
    // Calcular promedio de notas
    float sumaNotas = 0;
    for (int i = 0; i < cantidad; i++) {
        sumaNotas += materias[i]->nota;
    }
    float promedio = sumaNotas / cantidad;
    
    cout << "\nPromedio de notas: " << promedio << endl;
    
    // Liberar memoria
    for (int i = 0; i < cantidad; i++) {
        delete materias[i];
        materias[i] = nullptr;
    }
    delete[] materias;
    materias = nullptr;
    
    cout << "✓ Memoria liberada correctamente" << endl;
}

// ============================================================================
// SISTEMA COMPLETO CON PERSISTENCIA
// ============================================================================

void sistemaCompletoPersistencia() {
    cout << "\n=== SISTEMA COMPLETO CON PERSISTENCIA ===" << endl;
    
    GestorEstudiantes sistema;
    int opcion;
    
    do {
        cout << "\n=== MENÚ DEL SISTEMA ===" << endl;
        cout << "1. Agregar estudiante" << endl;
        cout << "2. Mostrar estudiantes" << endl;
        cout << "3. Buscar estudiante" << endl;
        cout << "4. Guardar en archivo" << endl;
        cout << "5. Cargar desde archivo" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                Estudiante nuevo;
                cout << "\nIngrese datos del estudiante:" << endl;
                cout << "ID: ";
                cin >> nuevo.id;
                cout << "Nombre: ";
                cin.ignore();
                cin.getline(nuevo.nombre, 50);
                cout << "Carrera: ";
                cin.getline(nuevo.carrera, 50);
                cout << "Promedio: ";
                cin >> nuevo.promedio;
                nuevo.activo = true;
                
                if (sistema.agregarEstudiante(nuevo)) {
                    cout << "✓ Estudiante agregado correctamente" << endl;
                } else {
                    cout << "✗ Error al agregar estudiante" << endl;
                }
                break;
            }
            case 2:
                sistema.mostrarEstudiantes();
                break;
            case 3: {
                int id;
                cout << "Ingrese ID del estudiante: ";
                cin >> id;
                
                Estudiante* encontrado = sistema.buscarPorID(id);
                if (encontrado) {
                    cout << "\n✓ Estudiante encontrado:" << endl;
                    cout << "Nombre: " << encontrado->nombre << endl;
                    cout << "Carrera: " << encontrado->carrera << endl;
                    cout << "Promedio: " << encontrado->promedio << endl;
                } else {
                    cout << "\n✗ Estudiante no encontrado" << endl;
                }
                break;
            }
            case 4:
                if (sistema.guardarEnArchivo("sistema_estudiantes.bin")) {
                    cout << "✓ Sistema guardado correctamente" << endl;
                } else {
                    cout << "✗ Error al guardar sistema" << endl;
                }
                break;
            case 5:
                if (sistema.cargarDesdeArchivo("sistema_estudiantes.bin")) {
                    cout << "✓ Sistema cargado correctamente" << endl;
                } else {
                    cout << "✗ Error al cargar sistema" << endl;
                }
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 6);
    
    cout << "✓ Sistema completado" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== ARRAYS DINÁMICOS CON ARCHIVOS BINARIOS ===" << endl;
    cout << "Enfoque: Gestión dinámica, persistencia, arrays de punteros\n" << endl;
    
    demostrarArraysDinamicos();
    cargarYManipularDatos();
    demostrarArraysPunterosEstructuras();
    cargarArrayPunterosDesdeArchivo();
    sistemaCompletoPersistencia();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Los arrays dinámicos permiten crecimiento automático" << endl;
    cout << "✓ La persistencia mantiene datos entre ejecuciones" << endl;
    cout << "✓ Los arrays de punteros ofrecen máxima flexibilidad" << endl;
    cout << "✓ Siempre liberar memoria en orden inverso al de asignación" << endl;
    cout << "✓ Verificar que los punteros no sean nullptr antes de usar" << endl;
    cout << "✓ La redimensión automática mejora la eficiencia" << endl;
    
    return 0;
}
