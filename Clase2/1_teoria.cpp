/*
 * Archivo: 1_teoria.cpp
 * Descripcion: Conceptos fundamentales del manejo de archivos en C++
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
using namespace std;

// ============================================================================
// PARÁMETROS DE ios:: PARA ARCHIVOS
// ============================================================================
// ios::in    - Lectura
// ios::out   - Escritura (sobrescribe)
// ios::app   - Escritura al final
// ios::binary - Modo binario
// ios::ate   - Posición al final
// ios::trunc - Vaciar archivo existente

void demostrarParametrosIOS() {
    cout << "=== PARÁMETROS DE ios:: ===" << endl;
    
    // Combinación de parámetros
    fstream archivo("ejemplo.dat", ios::in | ios::out | ios::binary);
    
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    
    cout << "✓ Archivo abierto con ios::in | ios::out | ios::binary" << endl;
    archivo.close();
}

// ============================================================================
// MANIPULACIÓN DE POSICIÓN EN ARCHIVOS
// ============================================================================
// seekg(pos, dir) - Mover puntero de lectura
// seekp(pos, dir) - Mover puntero de escritura
// tellg()         - Posición actual de lectura
// tellp()         - Posición actual de escritura
// ios::beg        - Desde el inicio
// ios::cur        - Desde posición actual
// ios::end        - Desde el final

void demostrarPosicionPunteros() {
    cout << "\n=== MANIPULACIÓN DE POSICIÓN ===" << endl;
    
    fstream archivo("posiciones.dat", ios::out | ios::binary);
    
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    
    // Escribir datos iniciales
    archivo.write("1234567890", 10);
    cout << "✓ Datos escritos: 1234567890" << endl;
    
    // Mover puntero y sobrescribir
    archivo.seekp(2, ios::beg);
    archivo.write("A", 1);
    cout << "✓ Sobrescrito en posición 2: 12A4567890" << endl;
    
    // Mostrar posición actual
    cout << "✓ Posición actual: " << archivo.tellp() << endl;
    
    archivo.close();
}

// ============================================================================
// REINTERPRET_CAST - CONVERSIÓN SIMPLE DE TIPOS
// ============================================================================
// Convierte un puntero de un tipo a otro sin cambiar los datos
// Ejemplo: int* → char* para escribir en archivo

void demostrarReinterpretCast() {
    cout << "\n=== REINTERPRET_CAST ===" << endl;
    
    // Ejemplo 1: Convertir int a char* para archivo
    int numero = 42;
    cout << "Número original: " << numero << endl;
    
    ofstream archivo("numero.dat", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo." << endl;
        return;
    }
    
    // reinterpret_cast convierte int* a char* para escribir
    archivo.write(reinterpret_cast<const char*>(&numero), sizeof(int));
    cout << "✓ Número escrito como bytes en archivo" << endl;
    archivo.close();
    
    // Ejemplo 2: Leer de vuelta
    ifstream archivoLectura("numero.dat", ios::binary);
    if (!archivoLectura) {
        cout << "Error: No se pudo leer el archivo." << endl;
        return;
    }
    
    int numeroLeido;
    archivoLectura.read(reinterpret_cast<char*>(&numeroLeido), sizeof(int));
    cout << "✓ Número leído: " << numeroLeido << endl;
    archivoLectura.close();
    
    cout << "→ reinterpret_cast permite escribir/leer cualquier tipo como bytes" << endl;
}

// ============================================================================
// EJEMPLO PRÁCTICO: SISTEMA DE REGISTROS
// ============================================================================

void ejemploPractico() {
    cout << "\n=== EJEMPLO PRÁCTICO ===" << endl;
    
    // Crear múltiples registros
    Registro registros[] = {
        {1, "Ana Garcia", 2500.50},
        {2, "Carlos Lopez", 1800.25},
        {3, "Maria Rodriguez", 3200.75}
    };
    
    // Escribir todos los registros
    ofstream archivo("registros.dat", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        return;
    }
    
    for (int i = 0; i < 3; i++) {
        archivo.write(reinterpret_cast<const char*>(&registros[i]), sizeof(Registro));
    }
    archivo.close();
    
    cout << "✓ 3 registros escritos en archivo binario" << endl;
    
    // Leer registro específico (el segundo)
    ifstream archivoLectura("registros.dat", ios::binary);
    if (!archivoLectura) {
        cout << "Error: No se pudo abrir para lectura." << endl;
        return;
    }
    
    Registro registroLeido;
    archivoLectura.seekg(1 * sizeof(Registro), ios::beg); // Posición del segundo registro
    archivoLectura.read(reinterpret_cast<char*>(&registroLeido), sizeof(Registro));
    
    cout << "✓ Registro leído: ID=" << registroLeido.id 
         << ", Nombre=" << registroLeido.nombre 
         << ", Saldo=" << registroLeido.saldo << endl;
    
    archivoLectura.close();
}

int main() {
    cout << "=== CONCEPTOS FUNDAMENTALES DE ARCHIVOS EN C++ ===" << endl;
    cout << "Enfoque: Parámetros ios::, manipulación de posición, reinterpret_cast\n" << endl;
    
    demostrarParametrosIOS();
    demostrarPosicionPunteros();
    demostrarReinterpretCast();
    ejemploPractico();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ ios::binary evita conversiones automáticas" << endl;
    cout << "✓ seekg/seekp permiten acceso directo a posiciones" << endl;
    cout << "✓ reinterpret_cast convierte tipos de punteros" << endl;
    cout << "✓ Útil para estructuras y datos binarios" << endl;
    
    return 0;
}
