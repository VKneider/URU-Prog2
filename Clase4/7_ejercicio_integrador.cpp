/*
 * EJERCICIO CLASE 4 - PROGRAMACIÓN ORIENTADA A OBJETOS
 * =====================================================
 * 
 * ENUNCIADO:
 * Implementar un sistema de gestión de biblioteca que permita:
 * 1. Registrar diferentes tipos de materiales (Libros, Revistas, DVDs)
 * 2. Gestionar usuarios del sistema (Estudiantes, Profesores, Personal)
 * 3. Realizar préstamos y devoluciones
 * 4. Generar reportes del sistema
 * 5. Guardar y cargar datos desde archivos
 * 
 * REQUISITOS TÉCNICOS:
 * - Usar clases y objetos
 * - Implementar encapsulamiento (private/public)
 * - Usar constructores y destructores
 * - Implementar herencia simple
 * - Usar modificadores de acceso apropiados
 * - Organizar código en clases separadas
 * - Integrar con archivos (texto o binario)
 * 
 * ESTRUCTURA DE CLASES REQUERIDA:
 * 
 * MATERIAL (clase base):
 * - Código, título, autor, año, disponible
 * 
 * LIBRO (hereda de Material):
 * - Páginas, género, ISBN
 * 
 * REVISTA (hereda de Material):
 * - Número, frecuencia, ISSN
 * 
 * DVD (hereda de Material):
 * - Duración, director, tipo
 * 
 * USUARIO (clase base):
 * - ID, nombre, email, activo
 * 
 * ESTUDIANTE (hereda de Usuario):
 * - Carrera, semestre, créditos
 * 
 * PROFESOR (hereda de Usuario):
 * - Departamento, especialidad, años_experiencia
 * 
 * PERSONAL (hereda de Usuario):
 * - Cargo, salario, fecha_ingreso
 * 
 * PRÉSTAMO:
 * - Usuario, Material, fecha_préstamo, fecha_devolución
 * 
 * BIBLIOTECA (clase principal):
 * - Gestión de materiales, usuarios y préstamos
 * - Operaciones de archivo
 * - Reportes y estadísticas
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
using namespace std;

// ==============================================================================
// CLASES BASE
// ==============================================================================

// TODO: Implementar clase Material (clase base)
class Material {
    // Completar aquí: atributos privados (código, título, autor, año, disponible)
    
public:
    // TODO: Constructor con parámetros
    Material(/* parámetros */) {
        // Completar aquí: inicializar atributos
    }
    
    // TODO: Destructor
    ~Material() {
        // Completar aquí: mensaje de destrucción
    }
    
    // TODO: Getters (métodos de acceso)
    // getCodigo(), getTitulo(), getAutor(), getAnio(), isDisponible()
    
    // TODO: Setters (métodos de modificación)
    // setDisponible(bool), setCodigo(int)
    
    // TODO: Métodos virtuales
    virtual void mostrarInformacion() {
        // Completar aquí: mostrar información básica del material
    }
    
    virtual string getTipo() {
        return "Material";
    }
    
    // TODO: Métodos de préstamo
    bool prestar() {
        // Completar aquí: verificar disponibilidad y cambiar estado
        return false; // Placeholder
    }
    
    bool devolver() {
        // Completar aquí: cambiar estado a disponible
        return false; // Placeholder
    }
};

// TODO: Implementar clase Libro (hereda de Material)
class Libro : public Material {
    // Completar aquí: atributos privados (páginas, género, ISBN)
    
public:
    // TODO: Constructor
    Libro(/* parámetros */) : Material(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~Libro() {
        // Completar aquí: mensaje específico de libro
    }
    
    // TODO: Getters específicos
    // getPaginas(), getGenero(), getISBN()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa del libro
    }
    
    string getTipo() override {
        return "Libro";
    }
    
    // TODO: Método específico
    void mostrarResumen() {
        // Completar aquí: mostrar resumen del libro
    }
};

// TODO: Implementar clase Revista (hereda de Material)
class Revista : public Material {
    // Completar aquí: atributos privados (número, frecuencia, ISSN)
    
public:
    // TODO: Constructor
    Revista(/* parámetros */) : Material(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~Revista() {
        // Completar aquí: mensaje específico de revista
    }
    
    // TODO: Getters específicos
    // getNumero(), getFrecuencia(), getISSN()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa de la revista
    }
    
    string getTipo() override {
        return "Revista";
    }
    
    // TODO: Método específico
    void mostrarArticulos() {
        // Completar aquí: mostrar artículos de la revista
    }
};

// TODO: Implementar clase DVD (hereda de Material)
class DVD : public Material {
    // Completar aquí: atributos privados (duración, director, tipo)
    
public:
    // TODO: Constructor
    DVD(/* parámetros */) : Material(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~DVD() {
        // Completar aquí: mensaje específico de DVD
    }
    
    // TODO: Getters específicos
    // getDuracion(), getDirector(), getTipo()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa del DVD
    }
    
    string getTipo() override {
        return "DVD";
    }
    
    // TODO: Método específico
    void mostrarContenido() {
        // Completar aquí: mostrar contenido del DVD
    }
};

// ==============================================================================
// CLASES DE USUARIOS
// ==============================================================================

// TODO: Implementar clase Usuario (clase base)
class Usuario {
    // Completar aquí: atributos privados (ID, nombre, email, activo)
    
public:
    // TODO: Constructor
    Usuario(/* parámetros */) {
        // Completar aquí: inicializar atributos
    }
    
    // TODO: Destructor
    ~Usuario() {
        // Completar aquí: mensaje de destrucción
    }
    
    // TODO: Getters
    // getID(), getNombre(), getEmail(), isActivo()
    
    // TODO: Setters
    // setActivo(bool), setEmail(string)
    
    // TODO: Métodos virtuales
    virtual void mostrarInformacion() {
        // Completar aquí: mostrar información básica del usuario
    }
    
    virtual string getTipoUsuario() {
        return "Usuario";
    }
    
    // TODO: Métodos comunes
    bool puedePrestar() {
        // Completar aquí: verificar si el usuario puede hacer préstamos
        return false; // Placeholder
    }
};

// TODO: Implementar clase Estudiante (hereda de Usuario)
class Estudiante : public Usuario {
    // Completar aquí: atributos privados (carrera, semestre, créditos)
    
public:
    // TODO: Constructor
    Estudiante(/* parámetros */) : Usuario(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~Estudiante() {
        // Completar aquí: mensaje específico de estudiante
    }
    
    // TODO: Getters específicos
    // getCarrera(), getSemestre(), getCreditos()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa del estudiante
    }
    
    string getTipoUsuario() override {
        return "Estudiante";
    }
    
    // TODO: Método específico
    void mostrarProgreso() {
        // Completar aquí: mostrar progreso académico
    }
};

// TODO: Implementar clase Profesor (hereda de Usuario)
class Profesor : public Usuario {
    // Completar aquí: atributos privados (departamento, especialidad, años_experiencia)
    
public:
    // TODO: Constructor
    Profesor(/* parámetros */) : Usuario(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~Profesor() {
        // Completar aquí: mensaje específico de profesor
    }
    
    // TODO: Getters específicos
    // getDepartamento(), getEspecialidad(), getAniosExperiencia()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa del profesor
    }
    
    string getTipoUsuario() override {
        return "Profesor";
    }
    
    // TODO: Método específico
    void mostrarExperiencia() {
        // Completar aquí: mostrar experiencia del profesor
    }
};

// TODO: Implementar clase Personal (hereda de Usuario)
class Personal : public Usuario {
    // Completar aquí: atributos privados (cargo, salario, fecha_ingreso)
    
public:
    // TODO: Constructor
    Personal(/* parámetros */) : Usuario(/* parámetros padre */) {
        // Completar aquí: inicializar atributos específicos
    }
    
    // TODO: Destructor
    ~Personal() {
        // Completar aquí: mensaje específico de personal
    }
    
    // TODO: Getters específicos
    // getCargo(), getSalario(), getFechaIngreso()
    
    // TODO: Sobrescribir métodos virtuales
    void mostrarInformacion() override {
        // Completar aquí: mostrar información completa del personal
    }
    
    string getTipoUsuario() override {
        return "Personal";
    }
    
    // TODO: Método específico
    void mostrarAntiguedad() {
        // Completar aquí: mostrar antigüedad en el trabajo
    }
};

// ==============================================================================
// CLASE DE PRÉSTAMOS
// ==============================================================================

// TODO: Implementar clase Prestamo
class Prestamo {
    // Completar aquí: atributos privados (usuario, material, fechas)
    
public:
    // TODO: Constructor
    Prestamo(/* parámetros */) {
        // Completar aquí: inicializar préstamo
    }
    
    // TODO: Destructor
    ~Prestamo() {
        // Completar aquí: mensaje de destrucción
    }
    
    // TODO: Getters
    // getUsuario(), getMaterial(), getFechaPrestamo(), getFechaDevolucion()
    
    // TODO: Métodos
    void mostrarInformacion() {
        // Completar aquí: mostrar información del préstamo
    }
    
    bool estaVencido() {
        // Completar aquí: verificar si el préstamo está vencido
        return false; // Placeholder
    }
    
    void devolver() {
        // Completar aquí: marcar como devuelto
    }
};

// ==============================================================================
// CLASE PRINCIPAL DEL SISTEMA
// ==============================================================================

// TODO: Implementar clase Biblioteca
class Biblioteca {
    // Completar aquí: atributos privados (vectores de materiales, usuarios, préstamos)
    
public:
    // TODO: Constructor
    Biblioteca() {
        // Completar aquí: inicializar sistema
    }
    
    // TODO: Destructor
    ~Biblioteca() {
        // Completar aquí: limpiar recursos
    }
    
    // TODO: Métodos de gestión de materiales
    void agregarMaterial(Material* material) {
        // Completar aquí: agregar material al sistema
    }
    
    Material* buscarMaterial(int codigo) {
        // Completar aquí: buscar material por código
        return nullptr; // Placeholder
    }
    
    void mostrarMateriales() {
        // Completar aquí: mostrar todos los materiales
    }
    
    // TODO: Métodos de gestión de usuarios
    void agregarUsuario(Usuario* usuario) {
        // Completar aquí: agregar usuario al sistema
    }
    
    Usuario* buscarUsuario(int id) {
        // Completar aquí: buscar usuario por ID
        return nullptr; // Placeholder
    }
    
    void mostrarUsuarios() {
        // Completar aquí: mostrar todos los usuarios
    }
    
    // TODO: Métodos de préstamos
    bool realizarPrestamo(int idUsuario, int codigoMaterial) {
        // Completar aquí: realizar préstamo
        return false; // Placeholder
    }
    
    bool devolverMaterial(int idUsuario, int codigoMaterial) {
        // Completar aquí: devolver material
        return false; // Placeholder
    }
    
    void mostrarPrestamos() {
        // Completar aquí: mostrar todos los préstamos
    }
    
    // TODO: Métodos de archivos
    void guardarDatos(const string& archivoMateriales, const string& archivoUsuarios, const string& archivoPrestamos) {
        // Completar aquí: guardar datos en archivos
    }
    
    void cargarDatos(const string& archivoMateriales, const string& archivoUsuarios, const string& archivoPrestamos) {
        // Completar aquí: cargar datos desde archivos
    }
    
    // TODO: Métodos de reportes
    void generarReporteMateriales() {
        // Completar aquí: reporte de materiales por tipo
    }
    
    void generarReporteUsuarios() {
        // Completar aquí: reporte de usuarios por tipo
    }
    
    void generarReportePrestamos() {
        // Completar aquí: reporte de préstamos activos y vencidos
    }
    
    void mostrarEstadisticas() {
        // Completar aquí: estadísticas generales del sistema
    }
};

// ==============================================================================
// FUNCIONES DEL MENÚ
// ==============================================================================

// TODO: Implementar función del menú principal
void mostrarMenu() {
    // Completar aquí: mostrar opciones del menú
}

// TODO: Implementar función del menú de materiales
void menuMateriales(Biblioteca& biblioteca) {
    // Completar aquí: submenú para gestión de materiales
}

// TODO: Implementar función del menú de usuarios
void menuUsuarios(Biblioteca& biblioteca) {
    // Completar aquí: submenú para gestión de usuarios
}

// TODO: Implementar función del menú de préstamos
void menuPrestamos(Biblioteca& biblioteca) {
    // Completar aquí: submenú para gestión de préstamos
}

// TODO: Implementar función del menú de reportes
void menuReportes(Biblioteca& biblioteca) {
    // Completar aquí: submenú para reportes
}

int main() {
    Biblioteca biblioteca;
    int opcion;
    
    cout << "=== SISTEMA DE GESTIÓN DE BIBLIOTECA ===" << endl;
    cout << "Implemente las clases y métodos marcados con TODO para completar el ejercicio." << endl;
    
    // TODO: Cargar datos iniciales desde archivos
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // TODO: Gestión de materiales
                break;
            case 2:
                // TODO: Gestión de usuarios
                break;
            case 3:
                // TODO: Gestión de préstamos
                break;
            case 4:
                // TODO: Reportes
                break;
            case 5:
                // TODO: Guardar datos
                break;
            case 6:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 6);
    
    // TODO: Guardar datos antes de salir
    
    cout << "Sistema finalizado." << endl;
    return 0;
}

/*
 * PISTAS PARA LA IMPLEMENTACIÓN:
 * 
 * 1. ESTRUCTURA DE CLASES:
 *    - Material como clase base con atributos comunes
 *    - Libro, Revista, DVD heredan de Material
 *    - Usuario como clase base para usuarios
 *    - Estudiante, Profesor, Personal heredan de Usuario
 * 
 * 2. ENCAPSULAMIENTO:
 *    - Atributos privados con getters/setters
 *    - Métodos públicos para operaciones
 *    - Validaciones en setters
 * 
 * 3. HERENCIA:
 *    - Usar protected para atributos accesibles por clases hijas
 *    - Sobrescribir métodos virtuales
 *    - Llamar constructores padre con lista de inicialización
 * 
 * 4. CONSTRUCTORES/DESTRUCTORES:
 *    - Inicializar todos los atributos
 *    - Mensajes informativos
 *    - Limpiar recursos en destructores
 * 
 * 5. ARCHIVOS:
 *    - Usar archivos de texto para simplicidad
 *    - Formato: tipo|datos|datos|...
 *    - Manejar errores de archivos
 * 
 * 6. VALIDACIONES:
 *    - Códigos únicos para materiales
 *    - IDs únicos para usuarios
 *    - Verificar disponibilidad antes de préstamos
 *    - Validar fechas y datos de entrada
 * 
 * CONCEPTOS CLAVE:
 * - Herencia simple para organización
 * - Encapsulamiento para seguridad
 * - Polimorfismo básico con métodos virtuales
 * - Separación de responsabilidades
 * - Gestión de memoria con punteros
 * - Integración con archivos
 */
