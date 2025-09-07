/*
 * Archivo: 2_estructuras_archivos.cpp
 * Descripcion: Estructuras en archivos binarios con punteros
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
#include <locale>
#include <string>
using namespace std;

// ============================================================================
// ESTRUCTURAS PARA DEMOSTRAR ARCHIVOS BINARIOS
// ============================================================================

struct Producto {
    char nombre[50];
    float precio;
    int cantidad;
    bool activo;
};

struct Cliente {
    int id;
    char nombre[50];
    char email[100];
    float saldo;
    bool vip;
};

struct Venta {
    int idVenta;
    int idCliente;
    char fecha[20];
    float total;
    int cantidadProductos;
};

// ============================================================================
// ESCRIBIR ESTRUCTURA SIMPLE A ARCHIVO BINARIO
// ============================================================================

void escribirEstructuraSimple() {
    cout << "=== ESCRIBIR ESTRUCTURA SIMPLE A ARCHIVO BINARIO ===" << endl;
    
    Producto producto;
    
    cout << "Ingrese datos del producto:" << endl;
    cout << "Nombre: ";
    cin.ignore();
    cin.getline(producto.nombre, 50);
    cout << "Precio: ";
    cin >> producto.precio;
    cout << "Cantidad: ";
    cin >> producto.cantidad;
    producto.activo = true;
    
    // Escribir a archivo binario
    ofstream archivo("producto.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        return;
    }
    
    // Escribir estructura completa usando reinterpret_cast
    archivo.write(reinterpret_cast<char*>(&producto), sizeof(Producto));
    archivo.close();
    
    cout << "✓ Producto escrito en producto.bin" << endl;
    cout << "Tamaño de la estructura: " << sizeof(Producto) << " bytes" << endl;
}

// ============================================================================
// LEER ESTRUCTURA SIMPLE DESDE ARCHIVO BINARIO
// ============================================================================

void leerEstructuraSimple() {
    cout << "\n=== LEER ESTRUCTURA SIMPLE DESDE ARCHIVO BINARIO ===" << endl;
    
    ifstream archivo("producto.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo producto.bin" << endl;
        return;
    }
    
    Producto producto;
    
    // Leer estructura completa
    archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto));
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Datos del producto:" << endl;
    cout << "Nombre: " << producto.nombre << endl;
    cout << "Precio: $" << producto.precio << endl;
    cout << "Cantidad: " << producto.cantidad << endl;
    cout << "Activo: " << (producto.activo ? "Sí" : "No") << endl;
    
    cout << "✓ Producto leído correctamente" << endl;
}

// ============================================================================
// ESCRIBIR ARREGLO DE ESTRUCTURAS CON PUNTEROS
// ============================================================================

void escribirArregloEstructuras() {
    cout << "\n=== ESCRIBIR ARREGLO DE ESTRUCTURAS CON PUNTEROS ===" << endl;
    
    int cantidad;
    cout << "Ingrese cantidad de productos: ";
    cin >> cantidad;
    
    // Crear arreglo dinámico de estructuras
    Producto* productos = new Producto[cantidad];
    
    // Llenar datos
    cout << "Ingrese datos de los productos:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "\nProducto " << (i + 1) << ":" << endl;
        cout << "  Nombre: ";
        cin.ignore();
        cin.getline(productos[i].nombre, 50);
        cout << "  Precio: ";
        cin >> productos[i].precio;
        cout << "  Cantidad: ";
        cin >> productos[i].cantidad;
        productos[i].activo = true;
    }
    
    // Mostrar datos ingresados
    cout << "\nProductos ingresados:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << productos[i].nombre 
             << " - $" << productos[i].precio 
             << " - Cantidad: " << productos[i].cantidad << endl;
    }
    
    // Escribir a archivo binario
    ofstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        delete[] productos;
        return;
    }
    
    // Escribir cantidad primero
    archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Escribir arreglo completo usando puntero
    archivo.write(reinterpret_cast<char*>(productos), cantidad * sizeof(Producto));
    
    archivo.close();
    
    cout << "\n✓ " << cantidad << " productos escritos en productos.bin" << endl;
    cout << "Tamaño total: " << (sizeof(int) + cantidad * sizeof(Producto)) << " bytes" << endl;
    
    // Liberar memoria
    delete[] productos;
    productos = nullptr;
}

// ============================================================================
// LEER ARREGLO DE ESTRUCTURAS CON PUNTEROS
// ============================================================================

void leerArregloEstructuras() {
    cout << "\n=== LEER ARREGLO DE ESTRUCTURAS CON PUNTEROS ===" << endl;
    
    ifstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo productos.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Crear arreglo dinámico
    Producto* productos = new Producto[cantidad];
    
    // Leer arreglo completo usando puntero
    archivo.read(reinterpret_cast<char*>(productos), cantidad * sizeof(Producto));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Productos leídos del archivo (" << cantidad << " elementos):" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << productos[i].nombre 
             << " - $" << productos[i].precio 
             << " - Cantidad: " << productos[i].cantidad 
             << " - Activo: " << (productos[i].activo ? "Sí" : "No") << endl;
    }
    
    cout << "\n✓ " << cantidad << " productos leídos correctamente" << endl;
    
    // Liberar memoria
    delete[] productos;
    productos = nullptr;
}

// ============================================================================
// ESTRUCTURAS MÚLTIPLES EN UN ARCHIVO
// ============================================================================

void escribirMultiplesEstructuras() {
    cout << "\n=== ESCRIBIR MÚLTIPLES ESTRUCTURAS EN UN ARCHIVO ===" << endl;
    
    // Crear datos de ejemplo
    Cliente cliente = {1, "Juan Pérez", "juan@email.com", 1500.50f, true};
    Producto producto = {"Laptop", 999.99f, 5, true};
    Venta venta = {1001, 1, "2024-01-15", 999.99f, 1};
    
    cout << "Datos a escribir:" << endl;
    cout << "Cliente: " << cliente.nombre << " (ID: " << cliente.id << ")" << endl;
    cout << "Producto: " << producto.nombre << " ($" << producto.precio << ")" << endl;
    cout << "Venta: ID " << venta.idVenta << " - $" << venta.total << endl;
    
    // Escribir todas las estructuras en un archivo
    ofstream archivo("datos_completos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        return;
    }
    
    // Escribir cada estructura
    archivo.write(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
    archivo.write(reinterpret_cast<char*>(&producto), sizeof(Producto));
    archivo.write(reinterpret_cast<char*>(&venta), sizeof(Venta));
    
    archivo.close();
    
    cout << "\n✓ Todas las estructuras escritas en datos_completos.bin" << endl;
    cout << "Tamaño total: " << (sizeof(Cliente) + sizeof(Producto) + sizeof(Venta)) << " bytes" << endl;
}

// ============================================================================
// LEER MÚLTIPLES ESTRUCTURAS DESDE UN ARCHIVO
// ============================================================================

void leerMultiplesEstructuras() {
    cout << "\n=== LEER MÚLTIPLES ESTRUCTURAS DESDE UN ARCHIVO ===" << endl;
    
    ifstream archivo("datos_completos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo datos_completos.bin" << endl;
        return;
    }
    
    // Leer cada estructura en el mismo orden
    Cliente cliente;
    Producto producto;
    Venta venta;
    
    archivo.read(reinterpret_cast<char*>(&cliente), sizeof(Cliente));
    archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto));
    archivo.read(reinterpret_cast<char*>(&venta), sizeof(Venta));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Datos leídos:" << endl;
    cout << "\nCliente:" << endl;
    cout << "  ID: " << cliente.id << endl;
    cout << "  Nombre: " << cliente.nombre << endl;
    cout << "  Email: " << cliente.email << endl;
    cout << "  Saldo: $" << cliente.saldo << endl;
    cout << "  VIP: " << (cliente.vip ? "Sí" : "No") << endl;
    
    cout << "\nProducto:" << endl;
    cout << "  Nombre: " << producto.nombre << endl;
    cout << "  Precio: $" << producto.precio << endl;
    cout << "  Cantidad: " << producto.cantidad << endl;
    cout << "  Activo: " << (producto.activo ? "Sí" : "No") << endl;
    
    cout << "\nVenta:" << endl;
    cout << "  ID Venta: " << venta.idVenta << endl;
    cout << "  ID Cliente: " << venta.idCliente << endl;
    cout << "  Fecha: " << venta.fecha << endl;
    cout << "  Total: $" << venta.total << endl;
    cout << "  Cantidad Productos: " << venta.cantidadProductos << endl;
    
    cout << "\n✓ Todas las estructuras leídas correctamente" << endl;
}

// ============================================================================
// BÚSQUEDA EN ARCHIVO DE ESTRUCTURAS
// ============================================================================

void buscarProductoPorNombre() {
    cout << "\n=== BÚSQUEDA EN ARCHIVO DE ESTRUCTURAS ===" << endl;
    
    ifstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo productos.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    string nombreBuscado;
    cout << "Ingrese nombre del producto a buscar: ";
    cin.ignore();
    getline(cin, nombreBuscado);
    
    bool encontrado = false;
    Producto producto;
    
    // Buscar producto por nombre
    for (int i = 0; i < cantidad; i++) {
        archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto));
        
        if (string(producto.nombre) == nombreBuscado) {
            encontrado = true;
            break;
        }
    }
    
    archivo.close();
    
    if (encontrado) {
        cout << "\n✓ Producto encontrado:" << endl;
        cout << "Nombre: " << producto.nombre << endl;
        cout << "Precio: $" << producto.precio << endl;
        cout << "Cantidad: " << producto.cantidad << endl;
        cout << "Activo: " << (producto.activo ? "Sí" : "No") << endl;
    } else {
        cout << "\n✗ Producto '" << nombreBuscado << "' no encontrado." << endl;
    }
}

// ============================================================================
// CALCULAR ESTADÍSTICAS DE PRODUCTOS
// ============================================================================

void calcularEstadisticasProductos() {
    cout << "\n=== CALCULAR ESTADÍSTICAS DE PRODUCTOS ===" << endl;
    
    ifstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo productos.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    if (cantidad == 0) {
        cout << "No hay productos en el archivo." << endl;
        archivo.close();
        return;
    }
    
    // Leer todos los productos
    Producto* productos = new Producto[cantidad];
    archivo.read(reinterpret_cast<char*>(productos), cantidad * sizeof(Producto));
    archivo.close();
    
    // Calcular estadísticas
    float sumaPrecios = 0;
    float precioMaximo = productos[0].precio;
    float precioMinimo = productos[0].precio;
    int totalCantidad = 0;
    int productosActivos = 0;
    
    for (int i = 0; i < cantidad; i++) {
        sumaPrecios += productos[i].precio;
        totalCantidad += productos[i].cantidad;
        
        if (productos[i].precio > precioMaximo) {
            precioMaximo = productos[i].precio;
        }
        
        if (productos[i].precio < precioMinimo) {
            precioMinimo = productos[i].precio;
        }
        
        if (productos[i].activo) {
            productosActivos++;
        }
    }
    
    float precioPromedio = sumaPrecios / cantidad;
    
    // Mostrar estadísticas
    cout << "Estadísticas de productos:" << endl;
    cout << "Total de productos: " << cantidad << endl;
    cout << "Productos activos: " << productosActivos << endl;
    cout << "Precio promedio: $" << precioPromedio << endl;
    cout << "Precio máximo: $" << precioMaximo << endl;
    cout << "Precio mínimo: $" << precioMinimo << endl;
    cout << "Total en inventario: " << totalCantidad << " unidades" << endl;
    cout << "Valor total del inventario: $" << (sumaPrecios * totalCantidad) << endl;
    
    cout << "\n✓ Estadísticas calculadas correctamente" << endl;
    
    // Liberar memoria
    delete[] productos;
    productos = nullptr;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== ESTRUCTURAS EN ARCHIVOS BINARIOS CON PUNTEROS ===" << endl;
    cout << "Enfoque: Estructuras simples, arrays dinámicos, búsquedas, estadísticas\n" << endl;
    
    escribirEstructuraSimple();
    leerEstructuraSimple();
    escribirArregloEstructuras();
    leerArregloEstructuras();
    escribirMultiplesEstructuras();
    leerMultiplesEstructuras();
    buscarProductoPorNombre();
    calcularEstadisticasProductos();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Las estructuras se escriben/leen como unidades completas" << endl;
    cout << "✓ Los arrays de estructuras permiten manejar múltiples registros" << endl;
    cout << "✓ Múltiples tipos de estructuras pueden coexistir en un archivo" << endl;
    cout << "✓ La búsqueda secuencial permite encontrar registros específicos" << endl;
    cout << "✓ Las estadísticas se calculan fácilmente sobre arrays de estructuras" << endl;
    cout << "✓ Siempre liberar memoria después de usar arrays dinámicos" << endl;
    cout << "✓ El orden de escritura debe coincidir con el de lectura" << endl;
    
    return 0;
}
