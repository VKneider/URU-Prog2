/*
 * Archivo: 2_separacion_archivos.cpp
 * Descripción: Demuestra la separación de código en archivos .h y .cpp
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este código es de uso personal y está protegido por derechos de autor. 
 * Queda prohibida su copia, distribución o modificación sin autorización expresa del autor.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
==================================================================================
    SEPARACIÓN DE ARCHIVOS EN C++
==================================================================================
    La separación de archivos nos permite:
    1. Dividir el código en módulos lógicos
    2. Separar la interfaz (.h) de la implementación (.cpp)
    3. Facilitar la compilación independiente
    4. Mejorar la organización del proyecto
    5. Permitir reutilización de código
    6. Facilitar el trabajo en equipo
*/

// ==============================================================================
// EJEMPLO: Sistema de Gestión de Productos
// ==============================================================================

// Clase Producto (simulando que estaría en Producto.h)
class Producto {
private:
    string nombre;
    double precio;
    int stock;
    string categoria;

public:
    // Constructor
    Producto(string n, double p, int s, string c) 
        : nombre(n), precio(p), stock(s), categoria(c) {}
    
    // Getters
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
    int getStock() const { return stock; }
    string getCategoria() const { return categoria; }
    
    // Setters
    void setPrecio(double nuevoPrecio) {
        if (nuevoPrecio > 0) {
            precio = nuevoPrecio;
        }
    }
    
    void setStock(int nuevoStock) {
        if (nuevoStock >= 0) {
            stock = nuevoStock;
        }
    }
    
    // Métodos
    void mostrarInformacion() const {
        cout << "Producto: " << nombre << endl;
        cout << "  Precio: $" << precio << endl;
        cout << "  Stock: " << stock << " unidades" << endl;
        cout << "  Categoría: " << categoria << endl;
    }
    
    bool estaDisponible() const {
        return stock > 0;
    }
    
    void reducirStock(int cantidad) {
        if (cantidad > 0 && cantidad <= stock) {
            stock -= cantidad;
        }
    }
};

// Clase Inventario (simulando que estaría en Inventario.h)
class Inventario {
private:
    vector<Producto> productos;
    string nombreInventario;

public:
    Inventario(string nombre) : nombreInventario(nombre) {}
    
    // Métodos de gestión
    void agregarProducto(const Producto& producto) {
        productos.push_back(producto);
        cout << "Producto '" << producto.getNombre() << "' agregado al inventario" << endl;
    }
    
    Producto* buscarProducto(const string& nombre) {
        for (auto& producto : productos) {
            if (producto.getNombre() == nombre) {
                return &producto;
            }
        }
        return nullptr;
    }
    
    void mostrarInventario() const {
        cout << "\n=== INVENTARIO: " << nombreInventario << " ===" << endl;
        cout << "Total de productos: " << productos.size() << endl;
        cout << "=====================================" << endl;
        
        for (const auto& producto : productos) {
            producto.mostrarInformacion();
            cout << "---" << endl;
        }
    }
    
    void mostrarProductosPorCategoria(const string& categoria) const {
        cout << "\n=== PRODUCTOS DE CATEGORÍA: " << categoria << " ===" << endl;
        
        bool encontrado = false;
        for (const auto& producto : productos) {
            if (producto.getCategoria() == categoria) {
                producto.mostrarInformacion();
                cout << "---" << endl;
                encontrado = true;
            }
        }
        
        if (!encontrado) {
            cout << "No se encontraron productos en esta categoría." << endl;
        }
    }
    
    double calcularValorTotal() const {
        double total = 0.0;
        for (const auto& producto : productos) {
            total += producto.getPrecio() * producto.getStock();
        }
        return total;
    }
    
    int contarProductosDisponibles() const {
        int contador = 0;
        for (const auto& producto : productos) {
            if (producto.estaDisponible()) {
                contador++;
            }
        }
        return contador;
    }
};

// ==============================================================================
// EJEMPLO: Funciones de utilidad (simulando que estarían en Utilidades.h)
// ==============================================================================

namespace Utilidades {
    // Función para formatear precio
    string formatearPrecio(double precio) {
        return "$" + to_string(precio).substr(0, to_string(precio).find('.') + 3);
    }
    
    // Función para validar nombre de producto
    bool validarNombreProducto(const string& nombre) {
        return !nombre.empty() && nombre.length() >= 2 && nombre.length() <= 50;
    }
    
    // Función para limpiar string
    string limpiarString(const string& texto) {
        string resultado = "";
        for (char c : texto) {
            if (isalnum(c) || c == ' ') {
                resultado += c;
            }
        }
        return resultado;
    }
    
    // Función para mostrar separador
    void mostrarSeparador(const string& titulo = "") {
        cout << "\n";
        if (!titulo.empty()) {
            cout << "=== " << titulo << " ===" << endl;
        }
        cout << string(50, '=') << endl;
    }
}

// ==============================================================================
// EJEMPLO: Clase de reportes (simulando que estaría en Reportes.h)
// ==============================================================================

class GeneradorReportes {
public:
    static void generarReporteInventario(const Inventario& inventario) {
        Utilidades::mostrarSeparador("REPORTE DE INVENTARIO");
        
        cout << "Inventario: " << inventario.calcularValorTotal() << endl;
        cout << "Productos disponibles: " << inventario.contarProductosDisponibles() << endl;
        
        inventario.mostrarInventario();
    }
    
    static void generarReporteCategoria(const Inventario& inventario, const string& categoria) {
        Utilidades::mostrarSeparador("REPORTE POR CATEGORÍA");
        
        inventario.mostrarProductosPorCategoria(categoria);
    }
    
    static void generarReporteResumen(const Inventario& inventario) {
        Utilidades::mostrarSeparador("REPORTE RESUMEN");
        
        cout << "Valor total del inventario: " << Utilidades::formatearPrecio(inventario.calcularValorTotal()) << endl;
        cout << "Productos disponibles: " << inventario.contarProductosDisponibles() << endl;
        cout << "Estado: " << (inventario.contarProductosDisponibles() > 0 ? "ACTIVO" : "SIN STOCK") << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== SEPARACIÓN DE ARCHIVOS EN C++ ===" << endl;
    cout << "======================================" << endl;
    
    // Crear inventario
    Inventario inventario("Tienda Principal");
    
    // Crear productos
    Producto producto1("Laptop HP", 899.99, 5, "Electrónicos");
    Producto producto2("Mouse Logitech", 25.50, 20, "Accesorios");
    Producto producto3("Teclado Mecánico", 89.99, 8, "Accesorios");
    Producto producto4("Monitor Samsung", 299.99, 3, "Electrónicos");
    Producto producto5("Cable USB", 12.99, 50, "Accesorios");
    
    // Agregar productos al inventario
    inventario.agregarProducto(producto1);
    inventario.agregarProducto(producto2);
    inventario.agregarProducto(producto3);
    inventario.agregarProducto(producto4);
    inventario.agregarProducto(producto5);
    
    // Mostrar inventario completo
    inventario.mostrarInventario();
    
    // Buscar producto específico
    Producto* productoEncontrado = inventario.buscarProducto("Laptop HP");
    if (productoEncontrado) {
        cout << "\nProducto encontrado:" << endl;
        productoEncontrado->mostrarInformacion();
    }
    
    // Mostrar productos por categoría
    inventario.mostrarProductosPorCategoria("Electrónicos");
    inventario.mostrarProductosPorCategoria("Accesorios");
    
    // Generar reportes
    GeneradorReportes::generarReporteResumen(inventario);
    
    // Ejemplo de validación
    cout << "\n=== VALIDACIONES ===" << endl;
    cout << "¿'Laptop HP' es nombre válido? " << (Utilidades::validarNombreProducto("Laptop HP") ? "Sí" : "No") << endl;
    cout << "¿'' es nombre válido? " << (Utilidades::validarNombreProducto("") ? "Sí" : "No") << endl;
    cout << "Precio formateado: " << Utilidades::formatearPrecio(899.99) << endl;
    
    cout << "\n=== VENTAJAS DE LA SEPARACIÓN ===" << endl;
    cout << "===================================" << endl;
    cout << "✓ Código más organizado" << endl;
    cout << "✓ Compilación más rápida" << endl;
    cout << "✓ Reutilización de código" << endl;
    cout << "✓ Trabajo en equipo eficiente" << endl;
    cout << "✓ Mantenimiento más fácil" << endl;
    cout << "✓ Separación de responsabilidades" << endl;
    
    return 0;
}

/*
 * ESTRUCTURA DE ARCHIVOS RECOMENDADA:
 * 
 * Producto.h:
 * - Declaración de la clase Producto
 * - Declaración de métodos públicos
 * - Definición de atributos privados
 * 
 * Producto.cpp:
 * - Implementación de todos los métodos
 * - Inclusión de Producto.h
 * - Lógica de negocio
 * 
 * Inventario.h:
 * - Declaración de la clase Inventario
 * - Declaración de métodos públicos
 * - Definición de atributos privados
 * 
 * Inventario.cpp:
 * - Implementación de métodos de Inventario
 * - Inclusión de Inventario.h y Producto.h
 * - Lógica de gestión
 * 
 * Utilidades.h:
 * - Declaración de funciones de utilidad
 * - Namespace para organización
 * 
 * Utilidades.cpp:
 * - Implementación de funciones de utilidad
 * - Inclusión de Utilidades.h
 * 
 * main.cpp:
 * - Función principal
 * - Inclusión de todos los headers
 * - Lógica de la aplicación
 * 
 * CONCEPTOS CLAVE:
 * - Separación de interfaz e implementación
 * - Compilación independiente
 * - Reutilización de código
 * - Organización modular
 * - Trabajo en equipo
 */
