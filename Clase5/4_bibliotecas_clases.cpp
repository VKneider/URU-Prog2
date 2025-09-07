/*
 * Archivo: 4_bibliotecas_clases.cpp
 * Descripción: Bibliotecas que utilizan clases y POO
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

/*
==================================================================================
    BIBLIOTECAS CON CLASES POO
==================================================================================
    Las bibliotecas que usan POO nos permiten:
    1. Encapsular funcionalidad compleja
    2. Crear interfaces claras y bien definidas
    3. Reutilizar código de manera eficiente
    4. Mantener el estado interno de los objetos
    5. Facilitar el testing y mantenimiento
    6. Crear sistemas modulares y escalables
*/

// ==============================================================================
// EJEMPLO 1: Biblioteca de Gestión de Archivos
// ==============================================================================

namespace GestorArchivos {
    class Archivo {
    private:
        string nombreArchivo;
        string contenido;
        bool modificado;
        time_t fechaCreacion;
        time_t fechaModificacion;

    public:
        // Constructor
        Archivo(const string& nombre) : nombreArchivo(nombre), modificado(false) {
            fechaCreacion = time(nullptr);
            fechaModificacion = fechaCreacion;
            cout << "Archivo '" << nombreArchivo << "' creado" << endl;
        }

        // Destructor
        ~Archivo() {
            cout << "Archivo '" << nombreArchivo << "' destruido" << endl;
        }

        // Getters
        string getNombre() const { return nombreArchivo; }
        string getContenido() const { return contenido; }
        bool estaModificado() const { return modificado; }
        time_t getFechaCreacion() const { return fechaCreacion; }
        time_t getFechaModificacion() const { return fechaModificacion; }

        // Métodos de contenido
        void escribirContenido(const string& nuevoContenido) {
            contenido = nuevoContenido;
            modificado = true;
            fechaModificacion = time(nullptr);
            cout << "Contenido escrito en '" << nombreArchivo << "'" << endl;
        }

        void agregarContenido(const string& textoAdicional) {
            contenido += textoAdicional;
            modificado = true;
            fechaModificacion = time(nullptr);
            cout << "Contenido agregado a '" << nombreArchivo << "'" << endl;
        }

        void limpiarContenido() {
            contenido = "";
            modificado = true;
            fechaModificacion = time(nullptr);
            cout << "Contenido limpiado en '" << nombreArchivo << "'" << endl;
        }

        // Métodos de archivo
        bool guardarEnDisco() {
            ofstream archivo(nombreArchivo);
            if (archivo.is_open()) {
                archivo << contenido;
                archivo.close();
                modificado = false;
                cout << "Archivo '" << nombreArchivo << "' guardado en disco" << endl;
                return true;
            }
            cout << "Error al guardar '" << nombreArchivo << "'" << endl;
            return false;
        }

        bool cargarDesdeDisco() {
            ifstream archivo(nombreArchivo);
            if (archivo.is_open()) {
                string linea;
                contenido = "";
                while (getline(archivo, linea)) {
                    contenido += linea + "\n";
                }
                archivo.close();
                modificado = false;
                fechaModificacion = time(nullptr);
                cout << "Archivo '" << nombreArchivo << "' cargado desde disco" << endl;
                return true;
            }
            cout << "Error al cargar '" << nombreArchivo << "'" << endl;
            return false;
        }

        // Métodos de información
        void mostrarInformacion() const {
            cout << "\n=== INFORMACIÓN DEL ARCHIVO ===" << endl;
            cout << "Nombre: " << nombreArchivo << endl;
            cout << "Tamaño: " << contenido.length() << " caracteres" << endl;
            cout << "Modificado: " << (modificado ? "Sí" : "No") << endl;
            cout << "Fecha creación: " << ctime(&fechaCreacion);
            cout << "Fecha modificación: " << ctime(&fechaModificacion);
        }

        void mostrarContenido() const {
            cout << "\n=== CONTENIDO DE '" << nombreArchivo << "' ===" << endl;
            if (contenido.empty()) {
                cout << "(Archivo vacío)" << endl;
            } else {
                cout << contenido << endl;
            }
        }
    };

    class GestorArchivos {
    private:
        vector<Archivo*> archivos;

    public:
        ~GestorArchivos() {
            for (Archivo* archivo : archivos) {
                delete archivo;
            }
        }

        Archivo* crearArchivo(const string& nombre) {
            Archivo* nuevoArchivo = new Archivo(nombre);
            archivos.push_back(nuevoArchivo);
            return nuevoArchivo;
        }

        Archivo* buscarArchivo(const string& nombre) {
            for (Archivo* archivo : archivos) {
                if (archivo->getNombre() == nombre) {
                    return archivo;
                }
            }
            return nullptr;
        }

        void mostrarTodosArchivos() const {
            cout << "\n=== ARCHIVOS GESTIONADOS ===" << endl;
            cout << "Total: " << archivos.size() << " archivos" << endl;
            cout << "=============================" << endl;
            
            for (const Archivo* archivo : archivos) {
                archivo->mostrarInformacion();
                cout << "---" << endl;
            }
        }

        void guardarTodosArchivos() {
            cout << "\n=== GUARDANDO TODOS LOS ARCHIVOS ===" << endl;
            for (Archivo* archivo : archivos) {
                archivo->guardarEnDisco();
            }
        }
    };
}

// ==============================================================================
// EJEMPLO 2: Biblioteca de Gestión de Usuarios
// ==============================================================================

namespace GestorUsuarios {
    class Usuario {
    protected:
        string nombre;
        string email;
        string telefono;
        bool activo;
        time_t fechaRegistro;

    public:
        Usuario(const string& n, const string& e, const string& t) 
            : nombre(n), email(e), telefono(t), activo(true) {
            fechaRegistro = time(nullptr);
        }

        virtual ~Usuario() = default;

        // Getters
        string getNombre() const { return nombre; }
        string getEmail() const { return email; }
        string getTelefono() const { return telefono; }
        bool estaActivo() const { return activo; }
        time_t getFechaRegistro() const { return fechaRegistro; }

        // Setters
        void setNombre(const string& nuevoNombre) {
            if (!nuevoNombre.empty()) {
                nombre = nuevoNombre;
            }
        }

        void setEmail(const string& nuevoEmail) {
            if (nuevoEmail.find('@') != string::npos) {
                email = nuevoEmail;
            }
        }

        void setTelefono(const string& nuevoTelefono) {
            if (nuevoTelefono.length() >= 8) {
                telefono = nuevoTelefono;
            }
        }

        void activar() { activo = true; }
        void desactivar() { activo = false; }

        // Métodos virtuales
        virtual void mostrarInformacion() const {
            cout << "Usuario: " << nombre << endl;
            cout << "  Email: " << email << endl;
            cout << "  Teléfono: " << telefono << endl;
            cout << "  Estado: " << (activo ? "Activo" : "Inactivo") << endl;
            cout << "  Fecha registro: " << ctime(&fechaRegistro);
        }

        virtual string getTipoUsuario() const {
            return "Usuario";
        }

        virtual bool puedeAcceder() const {
            return activo;
        }
    };

    class Estudiante : public Usuario {
    private:
        string carrera;
        int semestre;
        double promedio;

    public:
        Estudiante(const string& n, const string& e, const string& t, 
                  const string& c, int s, double p) 
            : Usuario(n, e, t), carrera(c), semestre(s), promedio(p) {}

        // Getters específicos
        string getCarrera() const { return carrera; }
        int getSemestre() const { return semestre; }
        double getPromedio() const { return promedio; }

        // Setters específicos
        void setCarrera(const string& nuevaCarrera) {
            if (!nuevaCarrera.empty()) {
                carrera = nuevaCarrera;
            }
        }

        void setSemestre(int nuevoSemestre) {
            if (nuevoSemestre > 0 && nuevoSemestre <= 10) {
                semestre = nuevoSemestre;
            }
        }

        void setPromedio(double nuevoPromedio) {
            if (nuevoPromedio >= 0.0 && nuevoPromedio <= 5.0) {
                promedio = nuevoPromedio;
            }
        }

        // Sobrescribir métodos virtuales
        void mostrarInformacion() const override {
            Usuario::mostrarInformacion();
            cout << "  Carrera: " << carrera << endl;
            cout << "  Semestre: " << semestre << endl;
            cout << "  Promedio: " << promedio << endl;
        }

        string getTipoUsuario() const override {
            return "Estudiante";
        }

        bool puedeAcceder() const override {
            return Usuario::puedeAcceder() && promedio >= 3.0;
        }
    };

    class Profesor : public Usuario {
    private:
        string departamento;
        string especialidad;
        int añosExperiencia;

    public:
        Profesor(const string& n, const string& e, const string& t, 
                const string& d, const string& esp, int años) 
            : Usuario(n, e, t), departamento(d), especialidad(esp), añosExperiencia(años) {}

        // Getters específicos
        string getDepartamento() const { return departamento; }
        string getEspecialidad() const { return especialidad; }
        int getAñosExperiencia() const { return añosExperiencia; }

        // Setters específicos
        void setDepartamento(const string& nuevoDepartamento) {
            if (!nuevoDepartamento.empty()) {
                departamento = nuevoDepartamento;
            }
        }

        void setEspecialidad(const string& nuevaEspecialidad) {
            if (!nuevaEspecialidad.empty()) {
                especialidad = nuevaEspecialidad;
            }
        }

        void setAñosExperiencia(int nuevosAños) {
            if (nuevosAños >= 0) {
                añosExperiencia = nuevosAños;
            }
        }

        // Sobrescribir métodos virtuales
        void mostrarInformacion() const override {
            Usuario::mostrarInformacion();
            cout << "  Departamento: " << departamento << endl;
            cout << "  Especialidad: " << especialidad << endl;
            cout << "  Años experiencia: " << añosExperiencia << endl;
        }

        string getTipoUsuario() const override {
            return "Profesor";
        }

        bool puedeAcceder() const override {
            return Usuario::puedeAcceder() && añosExperiencia >= 1;
        }
    };

    class GestorUsuarios {
    private:
        vector<Usuario*> usuarios;

    public:
        ~GestorUsuarios() {
            for (Usuario* usuario : usuarios) {
                delete usuario;
            }
        }

        void agregarUsuario(Usuario* usuario) {
            usuarios.push_back(usuario);
            cout << "Usuario '" << usuario->getNombre() << "' agregado al sistema" << endl;
        }

        Usuario* buscarUsuario(const string& nombre) {
            for (Usuario* usuario : usuarios) {
                if (usuario->getNombre() == nombre) {
                    return usuario;
                }
            }
            return nullptr;
        }

        void mostrarTodosUsuarios() const {
            cout << "\n=== USUARIOS REGISTRADOS ===" << endl;
            cout << "Total: " << usuarios.size() << " usuarios" << endl;
            cout << "============================" << endl;
            
            for (const Usuario* usuario : usuarios) {
                usuario->mostrarInformacion();
                cout << "---" << endl;
            }
        }

        void mostrarUsuariosPorTipo(const string& tipo) const {
            cout << "\n=== USUARIOS DE TIPO: " << tipo << " ===" << endl;
            
            bool encontrado = false;
            for (const Usuario* usuario : usuarios) {
                if (usuario->getTipoUsuario() == tipo) {
                    usuario->mostrarInformacion();
                    cout << "---" << endl;
                    encontrado = true;
                }
            }
            
            if (!encontrado) {
                cout << "No se encontraron usuarios de este tipo." << endl;
            }
        }

        int contarUsuariosActivos() const {
            int contador = 0;
            for (const Usuario* usuario : usuarios) {
                if (usuario->estaActivo()) {
                    contador++;
                }
            }
            return contador;
        }
    };
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== BIBLIOTECAS CON CLASES POO ===" << endl;
    cout << "==================================" << endl;
    
    // Ejemplo 1: Gestión de archivos
    cout << "\n1. GESTIÓN DE ARCHIVOS:" << endl;
    GestorArchivos::GestorArchivos gestorArchivos;
    
    GestorArchivos::Archivo* archivo1 = gestorArchivos.crearArchivo("documento.txt");
    archivo1->escribirContenido("Este es el contenido del documento.\n");
    archivo1->agregarContenido("Línea adicional de texto.\n");
    archivo1->mostrarContenido();
    archivo1->mostrarInformacion();
    
    GestorArchivos::Archivo* archivo2 = gestorArchivos.crearArchivo("notas.txt");
    archivo2->escribirContenido("Notas importantes:\n- Reunión mañana\n- Proyecto pendiente\n");
    archivo2->mostrarContenido();
    
    gestorArchivos.mostrarTodosArchivos();
    gestorArchivos.guardarTodosArchivos();
    
    // Ejemplo 2: Gestión de usuarios
    cout << "\n2. GESTIÓN DE USUARIOS:" << endl;
    GestorUsuarios::GestorUsuarios gestorUsuarios;
    
    GestorUsuarios::Estudiante* estudiante1 = new GestorUsuarios::Estudiante(
        "Ana García", "ana@email.com", "1234567890", "Ingeniería", 5, 4.2
    );
    
    GestorUsuarios::Profesor* profesor1 = new GestorUsuarios::Profesor(
        "Carlos López", "carlos@email.com", "0987654321", "Informática", "Programación", 10
    );
    
    GestorUsuarios::Estudiante* estudiante2 = new GestorUsuarios::Estudiante(
        "María Rodríguez", "maria@email.com", "1122334455", "Medicina", 3, 2.8
    );
    
    gestorUsuarios.agregarUsuario(estudiante1);
    gestorUsuarios.agregarUsuario(profesor1);
    gestorUsuarios.agregarUsuario(estudiante2);
    
    gestorUsuarios.mostrarTodosUsuarios();
    gestorUsuarios.mostrarUsuariosPorTipo("Estudiante");
    gestorUsuarios.mostrarUsuariosPorTipo("Profesor");
    
    cout << "Usuarios activos: " << gestorUsuarios.contarUsuariosActivos() << endl;
    
    // Ejemplo de búsqueda
    GestorUsuarios::Usuario* usuarioEncontrado = gestorUsuarios.buscarUsuario("Ana García");
    if (usuarioEncontrado) {
        cout << "\nUsuario encontrado:" << endl;
        usuarioEncontrado->mostrarInformacion();
        cout << "¿Puede acceder? " << (usuarioEncontrado->puedeAcceder() ? "Sí" : "No") << endl;
    }
    
    cout << "\n=== VENTAJAS DE BIBLIOTECAS CON POO ===" << endl;
    cout << "========================================" << endl;
    cout << "✓ Encapsulación de funcionalidad" << endl;
    cout << "✓ Interfaces claras y bien definidas" << endl;
    cout << "✓ Reutilización eficiente de código" << endl;
    cout << "✓ Mantenimiento del estado interno" << endl;
    cout << "✓ Facilita testing y debugging" << endl;
    cout << "✓ Sistemas modulares y escalables" << endl;
    
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. ENCAPSULACIÓN:
 *    - Atributos privados
 *    - Métodos públicos
 *    - Control de acceso
 * 
 * 2. HERENCIA:
 *    - Reutilización de código
 *    - Polimorfismo básico
 *    - Jerarquías lógicas
 * 
 * 3. GESTIÓN DE MEMORIA:
 *    - Constructores y destructores
 *    - new y delete
 *    - RAII (Resource Acquisition Is Initialization)
 * 
 * 4. INTERFACES:
 *    - Métodos virtuales
 *    - Sobrescritura
 *    - Polimorfismo
 * 
 * 5. ORGANIZACIÓN:
 *    - Namespaces para agrupación
 *    - Separación de responsabilidades
 *    - Código modular
 */
