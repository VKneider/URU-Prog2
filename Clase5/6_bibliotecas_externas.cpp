/*
 * Archivo: 6_bibliotecas_externas.cpp
 * Descripción: Integración con bibliotecas externas
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <random>
using namespace std;

/*
==================================================================================
    BIBLIOTECAS EXTERNAS EN C++
==================================================================================
    Las bibliotecas externas nos permiten:
    1. Extender la funcionalidad del lenguaje
    2. Reutilizar código probado y optimizado
    3. Acceder a funcionalidades especializadas
    4. Acelerar el desarrollo de aplicaciones
    5. Mantener código actualizado y seguro
    6. Integrar con sistemas externos
*/

// ==============================================================================
// EJEMPLO 1: Simulación de biblioteca de criptografía
// ==============================================================================

namespace Criptografia {
    class Cifrador {
    private:
        string clave;
        int desplazamiento;

    public:
        Cifrador(const string& k, int d) : clave(k), desplazamiento(d) {}

        // Cifrado César simple
        string cifrarCesar(const string& texto) {
            string resultado = "";
            for (char c : texto) {
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    char cifrado = ((c - base + desplazamiento) % 26) + base;
                    resultado += cifrado;
                } else {
                    resultado += c;
                }
            }
            return resultado;
        }

        // Descifrado César
        string descifrarCesar(const string& texto) {
            string resultado = "";
            for (char c : texto) {
                if (isalpha(c)) {
                    char base = islower(c) ? 'a' : 'A';
                    char descifrado = ((c - base - desplazamiento + 26) % 26) + base;
                    resultado += descifrado;
                } else {
                    resultado += c;
                }
            }
            return resultado;
        }

        // Cifrado XOR simple
        string cifrarXOR(const string& texto) {
            string resultado = "";
            int claveIndex = 0;
            
            for (char c : texto) {
                char cifrado = c ^ clave[claveIndex % clave.length()];
                resultado += cifrado;
                claveIndex++;
            }
            return resultado;
        }

        // Descifrado XOR
        string descifrarXOR(const string& texto) {
            return cifrarXOR(texto); // XOR es simétrico
        }

        // Generar hash simple
        string generarHash(const string& texto) {
            unsigned int hash = 0;
            for (char c : texto) {
                hash = hash * 31 + c;
            }
            
            stringstream ss;
            ss << hex << hash;
            return ss.str();
        }
    };
}

// ==============================================================================
// EJEMPLO 2: Simulación de biblioteca de base de datos
// ==============================================================================

namespace BaseDatos {
    struct Registro {
        int id;
        string nombre;
        string email;
        time_t fechaCreacion;
        
        Registro(int i, const string& n, const string& e) 
            : id(i), nombre(n), email(e) {
            fechaCreacion = time(nullptr);
        }
    };

    class BaseDatos {
    private:
        vector<Registro> registros;
        int siguienteId;

    public:
        BaseDatos() : siguienteId(1) {}

        // Operaciones CRUD
        int insertar(const string& nombre, const string& email) {
            Registro nuevoRegistro(siguienteId++, nombre, email);
            registros.push_back(nuevoRegistro);
            cout << "Registro insertado con ID: " << nuevoRegistro.id << endl;
            return nuevoRegistro.id;
        }

        Registro* buscarPorId(int id) {
            for (auto& registro : registros) {
                if (registro.id == id) {
                    return &registro;
                }
            }
            return nullptr;
        }

        vector<Registro*> buscarPorNombre(const string& nombre) {
            vector<Registro*> resultados;
            for (auto& registro : registros) {
                if (registro.nombre.find(nombre) != string::npos) {
                    resultados.push_back(&registro);
                }
            }
            return resultados;
        }

        bool actualizar(int id, const string& nuevoNombre, const string& nuevoEmail) {
            Registro* registro = buscarPorId(id);
            if (registro) {
                registro->nombre = nuevoNombre;
                registro->email = nuevoEmail;
                cout << "Registro con ID " << id << " actualizado" << endl;
                return true;
            }
            return false;
        }

        bool eliminar(int id) {
            auto it = find_if(registros.begin(), registros.end(),
                [id](const Registro& r) { return r.id == id; });
            
            if (it != registros.end()) {
                registros.erase(it);
                cout << "Registro con ID " << id << " eliminado" << endl;
                return true;
            }
            return false;
        }

        void mostrarTodos() const {
            cout << "\n=== REGISTROS EN LA BASE DE DATOS ===" << endl;
            cout << "Total: " << registros.size() << " registros" << endl;
            cout << "=====================================" << endl;
            
            for (const auto& registro : registros) {
                cout << "ID: " << registro.id << endl;
                cout << "Nombre: " << registro.nombre << endl;
                cout << "Email: " << registro.email << endl;
                cout << "Fecha: " << ctime(&registro.fechaCreacion);
                cout << "---" << endl;
            }
        }

        // Operaciones de archivo
        bool guardarEnArchivo(const string& nombreArchivo) {
            ofstream archivo(nombreArchivo);
            if (archivo.is_open()) {
                archivo << registros.size() << endl;
                for (const auto& registro : registros) {
                    archivo << registro.id << "|" << registro.nombre 
                           << "|" << registro.email << "|" << registro.fechaCreacion << endl;
                }
                archivo.close();
                cout << "Base de datos guardada en '" << nombreArchivo << "'" << endl;
                return true;
            }
            return false;
        }

        bool cargarDesdeArchivo(const string& nombreArchivo) {
            ifstream archivo(nombreArchivo);
            if (archivo.is_open()) {
                registros.clear();
                int cantidad;
                archivo >> cantidad;
                
                for (int i = 0; i < cantidad; i++) {
                    int id;
                    string nombre, email;
                    time_t fecha;
                    char separador;
                    
                    archivo >> id >> separador;
                    getline(archivo, nombre, '|');
                    getline(archivo, email, '|');
                    archivo >> fecha;
                    
                    registros.emplace_back(id, nombre, email);
                    registros.back().fechaCreacion = fecha;
                }
                
                archivo.close();
                cout << "Base de datos cargada desde '" << nombreArchivo << "'" << endl;
                return true;
            }
            return false;
        }
    };
}

// ==============================================================================
// EJEMPLO 3: Simulación de biblioteca de redes
// ==============================================================================

namespace Redes {
    class ClienteHTTP {
    private:
        string servidor;
        int puerto;
        bool conectado;

    public:
        ClienteHTTP(const string& s, int p) : servidor(s), puerto(p), conectado(false) {}

        bool conectar() {
            // Simulación de conexión
            cout << "Conectando a " << servidor << ":" << puerto << "..." << endl;
            conectado = true;
            cout << "Conexión establecida" << endl;
            return true;
        }

        void desconectar() {
            if (conectado) {
                cout << "Desconectando de " << servidor << ":" << puerto << "..." << endl;
                conectado = false;
                cout << "Desconectado" << endl;
            }
        }

        string enviarGET(const string& ruta) {
            if (!conectado) {
                return "Error: No conectado";
            }
            
            cout << "Enviando GET a " << servidor << ruta << endl;
            // Simulación de respuesta
            return "HTTP/1.1 200 OK\nContent-Type: text/html\n\n<html><body><h1>Respuesta simulada</h1></body></html>";
        }

        string enviarPOST(const string& ruta, const string& datos) {
            if (!conectado) {
                return "Error: No conectado";
            }
            
            cout << "Enviando POST a " << servidor << ruta << " con datos: " << datos << endl;
            // Simulación de respuesta
            return "HTTP/1.1 201 Created\nContent-Type: application/json\n\n{\"status\": \"success\", \"id\": 123}";
        }

        bool estaConectado() const {
            return conectado;
        }
    };

    class ServidorHTTP {
    private:
        int puerto;
        bool ejecutando;
        vector<string> rutas;

    public:
        ServidorHTTP(int p) : puerto(p), ejecutando(false) {}

        bool iniciar() {
            cout << "Iniciando servidor HTTP en puerto " << puerto << "..." << endl;
            ejecutando = true;
            cout << "Servidor iniciado y escuchando" << endl;
            return true;
        }

        void detener() {
            if (ejecutando) {
                cout << "Deteniendo servidor HTTP..." << endl;
                ejecutando = false;
                cout << "Servidor detenido" << endl;
            }
        }

        void agregarRuta(const string& ruta) {
            rutas.push_back(ruta);
            cout << "Ruta '" << ruta << "' agregada al servidor" << endl;
        }

        void mostrarRutas() const {
            cout << "\n=== RUTAS DEL SERVIDOR ===" << endl;
            for (const string& ruta : rutas) {
                cout << "GET " << ruta << endl;
            }
        }

        bool estaEjecutando() const {
            return ejecutando;
        }
    };
}

// ==============================================================================
// EJEMPLO 4: Simulación de biblioteca de gráficos
// ==============================================================================

namespace Graficos {
    struct Punto {
        int x, y;
        Punto(int x, int y) : x(x), y(y) {}
    };

    struct Color {
        int r, g, b;
        Color(int r, int g, int b) : r(r), g(g), b(b) {}
    };

    class Canvas {
    private:
        int ancho, alto;
        vector<vector<Color>> pixeles;

    public:
        Canvas(int w, int h) : ancho(w), alto(h) {
            pixeles.resize(alto, vector<Color>(ancho, Color(0, 0, 0)));
            cout << "Canvas creado: " << ancho << "x" << alto << endl;
        }

        void limpiar() {
            for (auto& fila : pixeles) {
                for (auto& pixel : fila) {
                    pixel = Color(0, 0, 0);
                }
            }
            cout << "Canvas limpiado" << endl;
        }

        void dibujarPunto(int x, int y, const Color& color) {
            if (x >= 0 && x < ancho && y >= 0 && y < alto) {
                pixeles[y][x] = color;
            }
        }

        void dibujarLinea(const Punto& inicio, const Punto& fin, const Color& color) {
            cout << "Dibujando línea de (" << inicio.x << "," << inicio.y 
                 << ") a (" << fin.x << "," << fin.y << ")" << endl;
            
            // Algoritmo simple de línea
            int dx = abs(fin.x - inicio.x);
            int dy = abs(fin.y - inicio.y);
            int sx = inicio.x < fin.x ? 1 : -1;
            int sy = inicio.y < fin.y ? 1 : -1;
            int err = dx - dy;

            int x = inicio.x, y = inicio.y;
            while (true) {
                dibujarPunto(x, y, color);
                if (x == fin.x && y == fin.y) break;
                
                int e2 = 2 * err;
                if (e2 > -dy) {
                    err -= dy;
                    x += sx;
                }
                if (e2 < dx) {
                    err += dx;
                    y += sy;
                }
            }
        }

        void dibujarRectangulo(const Punto& esquina1, const Punto& esquina2, const Color& color) {
            cout << "Dibujando rectángulo de (" << esquina1.x << "," << esquina1.y 
                 << ") a (" << esquina2.x << "," << esquina2.y << ")" << endl;
            
            // Dibujar las cuatro líneas del rectángulo
            dibujarLinea(esquina1, Punto(esquina2.x, esquina1.y), color);
            dibujarLinea(Punto(esquina2.x, esquina1.y), esquina2, color);
            dibujarLinea(esquina2, Punto(esquina1.x, esquina2.y), color);
            dibujarLinea(Punto(esquina1.x, esquina2.y), esquina1, color);
        }

        void mostrarCanvas() const {
            cout << "\n=== CANVAS " << ancho << "x" << alto << " ===" << endl;
            for (int y = 0; y < alto; y++) {
                for (int x = 0; x < ancho; x++) {
                    const Color& color = pixeles[y][x];
                    if (color.r > 0 || color.g > 0 || color.b > 0) {
                        cout << "█";
                    } else {
                        cout << " ";
                    }
                }
                cout << endl;
            }
        }
    };
}

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== BIBLIOTECAS EXTERNAS EN C++ ===" << endl;
    cout << "===================================" << endl;
    
    // Ejemplo 1: Criptografía
    cout << "\n1. BIBLIOTECA DE CRIPTOGRAFÍA:" << endl;
    Criptografia::Cifrador cifrador("miClaveSecreta", 3);
    
    string textoOriginal = "Hola Mundo";
    string textoCifrado = cifrador.cifrarCesar(textoOriginal);
    string textoDescifrado = cifrador.descifrarCesar(textoCifrado);
    
    cout << "Texto original: " << textoOriginal << endl;
    cout << "Texto cifrado: " << textoCifrado << endl;
    cout << "Texto descifrado: " << textoDescifrado << endl;
    
    string hash = cifrador.generarHash(textoOriginal);
    cout << "Hash: " << hash << endl;
    
    // Ejemplo 2: Base de datos
    cout << "\n2. BIBLIOTECA DE BASE DE DATOS:" << endl;
    BaseDatos::BaseDatos bd;
    
    int id1 = bd.insertar("Ana García", "ana@email.com");
    int id2 = bd.insertar("Carlos López", "carlos@email.com");
    int id3 = bd.insertar("María Rodríguez", "maria@email.com");
    
    bd.mostrarTodos();
    
    BaseDatos::Registro* registro = bd.buscarPorId(id2);
    if (registro) {
        cout << "Registro encontrado: " << registro->nombre << endl;
    }
    
    bd.actualizar(id1, "Ana García López", "ana.garcia@email.com");
    bd.guardarEnArchivo("base_datos.txt");
    
    // Ejemplo 3: Redes
    cout << "\n3. BIBLIOTECA DE REDES:" << endl;
    Redes::ClienteHTTP cliente("localhost", 8080);
    cliente.conectar();
    
    string respuesta = cliente.enviarGET("/api/usuarios");
    cout << "Respuesta GET: " << respuesta.substr(0, 50) << "..." << endl;
    
    respuesta = cliente.enviarPOST("/api/usuarios", "{\"nombre\": \"Juan\"}");
    cout << "Respuesta POST: " << respuesta.substr(0, 50) << "..." << endl;
    
    cliente.desconectar();
    
    Redes::ServidorHTTP servidor(8080);
    servidor.iniciar();
    servidor.agregarRuta("/api/usuarios");
    servidor.agregarRuta("/api/productos");
    servidor.mostrarRutas();
    servidor.detener();
    
    // Ejemplo 4: Gráficos
    cout << "\n4. BIBLIOTECA DE GRÁFICOS:" << endl;
    Graficos::Canvas canvas(20, 10);
    canvas.limpiar();
    
    Graficos::Color rojo(255, 0, 0);
    Graficos::Color verde(0, 255, 0);
    Graficos::Color azul(0, 0, 255);
    
    canvas.dibujarPunto(5, 5, rojo);
    canvas.dibujarLinea(Graficos::Punto(2, 2), Graficos::Punto(8, 8), verde);
    canvas.dibujarRectangulo(Graficos::Punto(10, 3), Graficos::Punto(18, 7), azul);
    
    canvas.mostrarCanvas();
    
    cout << "\n=== VENTAJAS DE BIBLIOTECAS EXTERNAS ===" << endl;
    cout << "=========================================" << endl;
    cout << "✓ Funcionalidad extendida" << endl;
    cout << "✓ Código probado y optimizado" << endl;
    cout << "✓ Desarrollo más rápido" << endl;
    cout << "✓ Mantenimiento simplificado" << endl;
    cout << "✓ Integración con sistemas externos" << endl;
    cout << "✓ Actualizaciones automáticas" << endl;
    
    return 0;
}

/*
 * CONCEPTOS CLAVE:
 * 
 * 1. INTEGRACIÓN:
 *    - Inclusión de headers
 *    - Linking de bibliotecas
 *    - Configuración del compilador
 * 
 * 2. TIPOS DE BIBLIOTECAS:
 *    - Estáticas (.lib, .a)
 *    - Dinámicas (.dll, .so)
 *    - Header-only
 * 
 * 3. GESTIÓN DE DEPENDENCIAS:
 *    - Package managers
 *    - Versionado
 *    - Compatibilidad
 * 
 * 4. DOCUMENTACIÓN:
 *    - APIs bien documentadas
 *    - Ejemplos de uso
 *    - Referencias completas
 * 
 * 5. LICENCIAS:
 *    - Open source
 *    - Comercial
 *    - Restricciones de uso
 */
