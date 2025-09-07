/*
 * Archivo: 7_punteros_archivos_avanzados.cpp
 * Descripcion: Punteros con archivos binarios avanzados
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

// ============================================================================
// ESTRUCTURA PARA DEMOSTRAR ARCHIVOS BINARIOS
// ============================================================================

struct Producto {
    char nombre[50];
    float precio;
    int cantidad;
    bool activo;
};

// ============================================================================
// ESCRIBIR ARREGLO DE ENTEROS A ARCHIVO BINARIO
// ============================================================================

void escribirArregloEnteros() {
    cout << "=== ESCRIBIR ARREGLO DE ENTEROS A ARCHIVO BINARIO ===" << endl;
    
    int tamanio;
    cout << "Ingrese tamaño del arreglo: ";
    cin >> tamanio;
    
    // Crear arreglo dinámico
    int* numeros = new int[tamanio];
    
    // Llenar arreglo
    cout << "Ingrese " << tamanio << " números:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Número " << (i + 1) << ": ";
        cin >> numeros[i];
    }
    
    // Escribir a archivo binario
    ofstream archivo("numeros.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        delete[] numeros;
        return;
    }
    
    // Escribir tamaño primero
    archivo.write(reinterpret_cast<char*>(&tamanio), sizeof(int));
    
    // Escribir arreglo completo
    archivo.write(reinterpret_cast<char*>(numeros), tamanio * sizeof(int));
    
    archivo.close();
    
    cout << "✓ Arreglo de " << tamanio << " números escrito en numeros.bin" << endl;
    
    // Liberar memoria
    delete[] numeros;
    numeros = nullptr;
}

// ============================================================================
// LEER ARREGLO DE ENTEROS DESDE ARCHIVO BINARIO
// ============================================================================

void leerArregloEnteros() {
    cout << "\n=== LEER ARREGLO DE ENTEROS DESDE ARCHIVO BINARIO ===" << endl;
    
    ifstream archivo("numeros.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo numeros.bin" << endl;
        return;
    }
    
    // Leer tamaño
    int tamanio;
    archivo.read(reinterpret_cast<char*>(&tamanio), sizeof(int));
    
    // Crear arreglo dinámico
    int* numeros = new int[tamanio];
    
    // Leer arreglo completo
    archivo.read(reinterpret_cast<char*>(numeros), tamanio * sizeof(int));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Datos leídos del archivo:" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "numeros[" << i << "] = " << numeros[i] << endl;
    }
    
    cout << "✓ Arreglo de " << tamanio << " números leído correctamente" << endl;
    
    // Liberar memoria
    delete[] numeros;
    numeros = nullptr;
}

// ============================================================================
// ESCRIBIR ARREGLO DE ESTRUCTURAS A ARCHIVO BINARIO
// ============================================================================

void escribirArregloEstructuras() {
    cout << "\n=== ESCRIBIR ARREGLO DE ESTRUCTURAS A ARCHIVO BINARIO ===" << endl;
    
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
    
    // Escribir a archivo binario
    ofstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        delete[] productos;
        return;
    }
    
    // Escribir cantidad primero
    archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    // Escribir arreglo de estructuras
    archivo.write(reinterpret_cast<char*>(productos), cantidad * sizeof(Producto));
    
    archivo.close();
    
    cout << "✓ " << cantidad << " productos escritos en productos.bin" << endl;
    
    // Liberar memoria
    delete[] productos;
    productos = nullptr;
}

// ============================================================================
// LEER ARREGLO DE ESTRUCTURAS DESDE ARCHIVO BINARIO
// ============================================================================

void leerArregloEstructuras() {
    cout << "\n=== LEER ARREGLO DE ESTRUCTURAS DESDE ARCHIVO BINARIO ===" << endl;
    
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
    
    // Leer arreglo de estructuras
    archivo.read(reinterpret_cast<char*>(productos), cantidad * sizeof(Producto));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Productos leídos del archivo:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << (i + 1) << ". " << productos[i].nombre 
             << " - Precio: $" << productos[i].precio 
             << " - Cantidad: " << productos[i].cantidad 
             << " - Activo: " << (productos[i].activo ? "Sí" : "No") << endl;
    }
    
    cout << "✓ " << cantidad << " productos leídos correctamente" << endl;
    
    // Liberar memoria
    delete[] productos;
    productos = nullptr;
}

// ============================================================================
// ACCESO RANDOM A ESTRUCTURAS EN ARCHIVO BINARIO
// ============================================================================

void accesoRandomEstructuras() {
    cout << "\n=== ACCESO RANDOM A ESTRUCTURAS EN ARCHIVO BINARIO ===" << endl;
    
    ifstream archivo("productos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo productos.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    cout << "Hay " << cantidad << " productos en el archivo." << endl;
    
    int indice;
    cout << "Ingrese el índice del producto a leer (0-" << (cantidad-1) << "): ";
    cin >> indice;
    
    if (indice < 0 || indice >= cantidad) {
        cout << "Error: Índice fuera de rango." << endl;
        archivo.close();
        return;
    }
    
    // Posicionarse en la estructura deseada
    // Saltar el tamaño (sizeof(int)) + índice * tamaño de estructura
    archivo.seekg(sizeof(int) + indice * sizeof(Producto), ios::beg);
    
    // Leer solo esa estructura
    Producto producto;
    archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto));
    
    archivo.close();
    
    // Mostrar producto leído
    cout << "\nProducto en índice " << indice << ":" << endl;
    cout << "Nombre: " << producto.nombre << endl;
    cout << "Precio: $" << producto.precio << endl;
    cout << "Cantidad: " << producto.cantidad << endl;
    cout << "Activo: " << (producto.activo ? "Sí" : "No") << endl;
    
    cout << "✓ Acceso random exitoso" << endl;
}

// ============================================================================
// MODIFICAR ESTRUCTURA ESPECÍFICA EN ARCHIVO BINARIO
// ============================================================================

void modificarEstructuraEnArchivo() {
    cout << "\n=== MODIFICAR ESTRUCTURA ESPECÍFICA EN ARCHIVO BINARIO ===" << endl;
    
    fstream archivo("productos.bin", ios::in | ios::out | ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo productos.bin" << endl;
        return;
    }
    
    // Leer cantidad
    int cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(int));
    
    cout << "Hay " << cantidad << " productos en el archivo." << endl;
    
    int indice;
    cout << "Ingrese el índice del producto a modificar (0-" << (cantidad-1) << "): ";
    cin >> indice;
    
    if (indice < 0 || indice >= cantidad) {
        cout << "Error: Índice fuera de rango." << endl;
        archivo.close();
        return;
    }
    
    // Leer producto actual
    archivo.seekg(sizeof(int) + indice * sizeof(Producto), ios::beg);
    Producto producto;
    archivo.read(reinterpret_cast<char*>(&producto), sizeof(Producto));
    
    cout << "\nProducto actual:" << endl;
    cout << "Nombre: " << producto.nombre << endl;
    cout << "Precio: $" << producto.precio << endl;
    cout << "Cantidad: " << producto.cantidad << endl;
    
    // Modificar datos
    cout << "\nIngrese nuevos datos:" << endl;
    cout << "Nuevo precio: ";
    cin >> producto.precio;
    cout << "Nueva cantidad: ";
    cin >> producto.cantidad;
    
    // Escribir producto modificado
    archivo.seekp(sizeof(int) + indice * sizeof(Producto), ios::beg);
    archivo.write(reinterpret_cast<char*>(&producto), sizeof(Producto));
    
    archivo.close();
    
    cout << "✓ Producto modificado y guardado en archivo" << endl;
}

// ============================================================================
// DEMOSTRACIÓN COMPLETA: SISTEMA DE INVENTARIO SIMPLE
// ============================================================================

void sistemaInventarioSimple() {
    cout << "\n=== SISTEMA DE INVENTARIO SIMPLE ===" << endl;
    
    int opcion;
    do {
        cout << "\n=== MENÚ DE INVENTARIO ===" << endl;
        cout << "1. Agregar productos" << endl;
        cout << "2. Ver todos los productos" << endl;
        cout << "3. Ver producto específico" << endl;
        cout << "4. Modificar producto" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opción: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                escribirArregloEstructuras();
                break;
            case 2:
                leerArregloEstructuras();
                break;
            case 3:
                accesoRandomEstructuras();
                break;
            case 4:
                modificarEstructuraEnArchivo();
                break;
            case 5:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida" << endl;
        }
        
    } while (opcion != 5);
    
    cout << "✓ Sistema de inventario completado" << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== PUNTEROS CON ARCHIVOS BINARIOS AVANZADOS ===" << endl;
    cout << "Enfoque: Arrays dinámicos, estructuras, acceso random, modificación\n" << endl;
    
    escribirArregloEnteros();
    leerArregloEnteros();
    escribirArregloEstructuras();
    leerArregloEstructuras();
    accesoRandomEstructuras();
    modificarEstructuraEnArchivo();
    sistemaInventarioSimple();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Los punteros permiten escribir/leer arrays completos a archivos binarios" << endl;
    cout << "✓ reinterpret_cast convierte punteros para escritura/lectura binaria" << endl;
    cout << "✓ El acceso random permite leer/modificar estructuras específicas" << endl;
    cout << "✓ Los archivos binarios son eficientes para estructuras complejas" << endl;
    cout << "✓ Siempre liberar memoria después de usar arrays dinámicos" << endl;
    cout << "✓ Verificar que los archivos se abran correctamente antes de usar" << endl;
    
    return 0;
}
