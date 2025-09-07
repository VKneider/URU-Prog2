/*
 * EJERCICIO CLASE 3 - ARCHIVOS BINARIOS Y SISTEMAS COMPLETOS
 * ==========================================================
 * 
 * ENUNCIADO:
 * Implementar un sistema de gestión de inventario que permita:
 * 1. Agregar productos al inventario
 * 2. Mostrar todos los productos
 * 3. Buscar un producto por código
 * 4. Modificar el stock de un producto
 * 5. Guardar el inventario en archivo binario
 * 6. Cargar el inventario desde archivo binario
 * 7. Generar reporte de productos con stock bajo
 * 
 * REQUISITOS TÉCNICOS:
 * - Usar archivos binarios para persistencia
 * - Implementar acceso aleatorio para búsquedas rápidas
 * - Usar punteros y memoria dinámica
 * - Validar datos de entrada
 * - Manejar errores de archivos
 * - Implementar menú interactivo
 * 
 * ESTRUCTURA DEL PRODUCTO:
 * - Código (int): identificador único
 * - Nombre (char[50]): nombre del producto
 * - Precio (float): precio unitario
 * - Stock (int): cantidad en inventario
 * - Stock mínimo (int): nivel mínimo de stock
 */

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// TODO: Definir estructura Producto
struct Producto {
    // Completar aquí: código, nombre, precio, stock, stock_minimo
};

// TODO: Implementar función para agregar producto
void agregarProducto(Producto* inventario, int& cantidad) {
    // Completar aquí:
    // 1. Validar que hay espacio en el inventario
    // 2. Solicitar datos del producto
    // 3. Validar que el código no exista
    // 4. Agregar producto al inventario
    // 5. Incrementar contador
}

// TODO: Implementar función para mostrar productos
void mostrarProductos(Producto* inventario, int cantidad) {
    // Completar aquí:
    // 1. Verificar si hay productos
    // 2. Mostrar encabezado de tabla
    // 3. Recorrer inventario y mostrar cada producto
}

// TODO: Implementar función de búsqueda por código
int buscarProducto(Producto* inventario, int cantidad, int codigo) {
    // Completar aquí:
    // 1. Recorrer inventario
    // 2. Comparar códigos
    // 3. Retornar índice si encuentra, -1 si no
}

// TODO: Implementar función para modificar stock
void modificarStock(Producto* inventario, int cantidad) {
    // Completar aquí:
    // 1. Solicitar código del producto
    // 2. Buscar producto
    // 3. Si existe, solicitar nuevo stock
    // 4. Validar stock (no negativo)
    // 5. Actualizar stock
}

// TODO: Implementar función para guardar en archivo binario
void guardarInventario(Producto* inventario, int cantidad, const string& nombreArchivo) {
    // Completar aquí:
    // 1. Abrir archivo en modo binario para escritura
    // 2. Escribir cantidad de productos
    // 3. Escribir array de productos
    // 4. Cerrar archivo
    // 5. Manejar errores
}

// TODO: Implementar función para cargar desde archivo binario
int cargarInventario(Producto* inventario, const string& nombreArchivo) {
    // Completar aquí:
    // 1. Abrir archivo en modo binario para lectura
    // 2. Leer cantidad de productos
    // 3. Leer array de productos
    // 4. Cerrar archivo
    // 5. Retornar cantidad cargada
    // 6. Manejar errores
}

// TODO: Implementar función para reporte de stock bajo
void reporteStockBajo(Producto* inventario, int cantidad) {
    // Completar aquí:
    // 1. Recorrer inventario
    // 2. Comparar stock actual vs stock mínimo
    // 3. Mostrar productos con stock bajo
    // 4. Calcular estadísticas
}

// TODO: Implementar función del menú principal
void mostrarMenu() {
    // Completar aquí:
    // Mostrar opciones numeradas del menú
}

// TODO: Implementar función para inicializar inventario
void inicializarInventario(Producto* inventario, int& cantidad) {
    // Completar aquí:
    // Cargar datos desde archivo si existe
}

int main() {
    const int MAX_PRODUCTOS = 100;
    Producto* inventario = new Producto[MAX_PRODUCTOS];
    int cantidad = 0;
    string nombreArchivo = "inventario.bin";
    int opcion;
    
    cout << "=== SISTEMA DE GESTIÓN DE INVENTARIO ===" << endl;
    
    // TODO: Inicializar inventario cargando desde archivo
    
    do {
        mostrarMenu();
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                // TODO: Agregar producto
                break;
            case 2:
                // TODO: Mostrar productos
                break;
            case 3:
                // TODO: Buscar producto
                break;
            case 4:
                // TODO: Modificar stock
                break;
            case 5:
                // TODO: Guardar inventario
                break;
            case 6:
                // TODO: Cargar inventario
                break;
            case 7:
                // TODO: Reporte stock bajo
                break;
            case 8:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
        }
    } while (opcion != 8);
    
    // TODO: Guardar inventario antes de salir
    delete[] inventario;
    return 0;
}

/*
 * PISTAS PARA LA IMPLEMENTACIÓN:
 * 
 * 1. Para validar código único:
 *    - Usar función buscarProducto() antes de agregar
 * 
 * 2. Para acceso aleatorio en archivos:
 *    - Usar seekg() y seekp() para posicionarse
 *    - Calcular posición: indice * sizeof(Producto)
 * 
 * 3. Para manejo de errores:
 *    - Verificar si archivo se abre correctamente
 *    - Usar try-catch si es necesario
 * 
 * 4. Para validaciones:
 *    - Precio > 0
 *    - Stock >= 0
 *    - Código > 0
 *    - Nombre no vacío
 * 
 * 5. Para el reporte:
 *    - Contar productos con stock bajo
 *    - Calcular valor total del inventario
 *    - Mostrar productos críticos
 */
