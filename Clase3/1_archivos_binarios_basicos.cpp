/*
 * Archivo: 1_archivos_binarios_basicos.cpp
 * Descripcion: Fundamentos de archivos binarios con punteros
 * Autor: Ing. Victor Kneider
 */

#include <iostream>
#include <fstream>
#include <locale>
using namespace std;

// ============================================================================
// COMPARACIÓN: ARCHIVOS TEXTO vs BINARIOS
// ============================================================================

void compararTextoVsBinario() {
    cout << "=== COMPARACIÓN: TEXTO vs BINARIO ===" << endl;
    
    int numero = 12345;
    float decimal = 3.14159f;
    char caracter = 'A';
    
    cout << "Datos originales:" << endl;
    cout << "Entero: " << numero << endl;
    cout << "Decimal: " << decimal << endl;
    cout << "Caracter: " << caracter << endl;
    
    // Escribir en archivo de texto
    ofstream archivoTexto("datos.txt");
    archivoTexto << numero << " " << decimal << " " << caracter << endl;
    archivoTexto.close();
    
    // Escribir en archivo binario
    ofstream archivoBinario("datos.bin", ios::binary);
    archivoBinario.write(reinterpret_cast<char*>(&numero), sizeof(int));
    archivoBinario.write(reinterpret_cast<char*>(&decimal), sizeof(float));
    archivoBinario.write(reinterpret_cast<char*>(&caracter), sizeof(char));
    archivoBinario.close();
    
    cout << "\n✓ Datos escritos en ambos formatos" << endl;
    cout << "Archivo texto: datos.txt" << endl;
    cout << "Archivo binario: datos.bin" << endl;
    
    cout << "\nDiferencias:" << endl;
    cout << "TEXTO:" << endl;
    cout << "  - Legible por humanos" << endl;
    cout << "  - Más espacio ocupado" << endl;
    cout << "  - Conversiones automáticas" << endl;
    cout << "  - Portabilidad entre sistemas" << endl;
    
    cout << "\nBINARIO:" << endl;
    cout << "  - No legible por humanos" << endl;
    cout << "  - Menos espacio ocupado" << endl;
    cout << "  - Sin conversiones" << endl;
    cout << "  - Más rápido" << endl;
}

// ============================================================================
// ESCRIBIR TIPOS PRIMITIVOS A ARCHIVO BINARIO
// ============================================================================

void escribirTiposPrimitivos() {
    cout << "\n=== ESCRIBIR TIPOS PRIMITIVOS A ARCHIVO BINARIO ===" << endl;
    
    // Datos de ejemplo
    int entero = 42;
    float flotante = 3.14f;
    double doble = 2.71828;
    char caracter = 'Z';
    bool booleano = true;
    
    cout << "Datos a escribir:" << endl;
    cout << "Entero: " << entero << endl;
    cout << "Flotante: " << flotante << endl;
    cout << "Doble: " << doble << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Booleano: " << (booleano ? "true" : "false") << endl;
    
    // Escribir a archivo binario
    ofstream archivo("tipos_primitivos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        return;
    }
    
    // Escribir cada tipo usando reinterpret_cast
    archivo.write(reinterpret_cast<char*>(&entero), sizeof(int));
    archivo.write(reinterpret_cast<char*>(&flotante), sizeof(float));
    archivo.write(reinterpret_cast<char*>(&doble), sizeof(double));
    archivo.write(reinterpret_cast<char*>(&caracter), sizeof(char));
    archivo.write(reinterpret_cast<char*>(&booleano), sizeof(bool));
    
    archivo.close();
    
    cout << "\n✓ Todos los tipos escritos en tipos_primitivos.bin" << endl;
}

// ============================================================================
// LEER TIPOS PRIMITIVOS DESDE ARCHIVO BINARIO
// ============================================================================

void leerTiposPrimitivos() {
    cout << "\n=== LEER TIPOS PRIMITIVOS DESDE ARCHIVO BINARIO ===" << endl;
    
    ifstream archivo("tipos_primitivos.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo tipos_primitivos.bin" << endl;
        return;
    }
    
    // Variables para leer
    int entero;
    float flotante;
    double doble;
    char caracter;
    bool booleano;
    
    // Leer cada tipo en el mismo orden que se escribió
    archivo.read(reinterpret_cast<char*>(&entero), sizeof(int));
    archivo.read(reinterpret_cast<char*>(&flotante), sizeof(float));
    archivo.read(reinterpret_cast<char*>(&doble), sizeof(double));
    archivo.read(reinterpret_cast<char*>(&caracter), sizeof(char));
    archivo.read(reinterpret_cast<char*>(&booleano), sizeof(bool));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Datos leídos:" << endl;
    cout << "Entero: " << entero << endl;
    cout << "Flotante: " << flotante << endl;
    cout << "Doble: " << doble << endl;
    cout << "Caracter: " << caracter << endl;
    cout << "Booleano: " << (booleano ? "true" : "false") << endl;
    
    cout << "\n✓ Lectura exitosa de tipos_primitivos.bin" << endl;
}

// ============================================================================
// ESCRIBIR ARREGLO DE ENTEROS CON PUNTEROS
// ============================================================================

void escribirArregloEnteros() {
    cout << "\n=== ESCRIBIR ARREGLO DE ENTEROS CON PUNTEROS ===" << endl;
    
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
    
    // Mostrar arreglo
    cout << "Arreglo creado: ";
    for (int i = 0; i < tamanio; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    // Escribir a archivo binario
    ofstream archivo("arreglo_enteros.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo." << endl;
        delete[] numeros;
        return;
    }
    
    // Escribir tamaño primero
    archivo.write(reinterpret_cast<char*>(&tamanio), sizeof(int));
    
    // Escribir arreglo completo usando puntero
    archivo.write(reinterpret_cast<char*>(numeros), tamanio * sizeof(int));
    
    archivo.close();
    
    cout << "✓ Arreglo de " << tamanio << " números escrito en arreglo_enteros.bin" << endl;
    
    // Liberar memoria
    delete[] numeros;
    numeros = nullptr;
}

// ============================================================================
// LEER ARREGLO DE ENTEROS CON PUNTEROS
// ============================================================================

void leerArregloEnteros() {
    cout << "\n=== LEER ARREGLO DE ENTEROS CON PUNTEROS ===" << endl;
    
    ifstream archivo("arreglo_enteros.bin", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo arreglo_enteros.bin" << endl;
        return;
    }
    
    // Leer tamaño
    int tamanio;
    archivo.read(reinterpret_cast<char*>(&tamanio), sizeof(int));
    
    // Crear arreglo dinámico
    int* numeros = new int[tamanio];
    
    // Leer arreglo completo usando puntero
    archivo.read(reinterpret_cast<char*>(numeros), tamanio * sizeof(int));
    
    archivo.close();
    
    // Mostrar datos leídos
    cout << "Arreglo leído (" << tamanio << " elementos): ";
    for (int i = 0; i < tamanio; i++) {
        cout << numeros[i] << " ";
    }
    cout << endl;
    
    cout << "✓ Arreglo leído correctamente desde arreglo_enteros.bin" << endl;
    
    // Liberar memoria
    delete[] numeros;
    numeros = nullptr;
}

// ============================================================================
// MANEJO ROBUSTO DE ERRORES
// ============================================================================

bool escribirConValidacion(const string& nombreArchivo, int* datos, int tamanio) {
    cout << "\n=== ESCRITURA CON VALIDACIÓN ===" << endl;
    
    // Validar parámetros
    if (nombreArchivo.empty()) {
        cout << "Error: Nombre de archivo vacío" << endl;
        return false;
    }
    
    if (datos == nullptr) {
        cout << "Error: Puntero a datos es nullptr" << endl;
        return false;
    }
    
    if (tamanio <= 0) {
        cout << "Error: Tamaño inválido" << endl;
        return false;
    }
    
    // Intentar escribir
    ofstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo crear el archivo " << nombreArchivo << endl;
        return false;
    }
    
    try {
        // Escribir tamaño
        archivo.write(reinterpret_cast<char*>(&tamanio), sizeof(int));
        
        // Escribir datos
        archivo.write(reinterpret_cast<char*>(datos), tamanio * sizeof(int));
        
        archivo.close();
        
        cout << "✓ Datos escritos correctamente en " << nombreArchivo << endl;
        return true;
        
    } catch (const exception& e) {
        cout << "Error durante escritura: " << e.what() << endl;
        archivo.close();
        return false;
    }
}

bool leerConValidacion(const string& nombreArchivo, int*& datos, int& tamanio) {
    cout << "\n=== LECTURA CON VALIDACIÓN ===" << endl;
    
    // Validar parámetros
    if (nombreArchivo.empty()) {
        cout << "Error: Nombre de archivo vacío" << endl;
        return false;
    }
    
    // Intentar leer
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo " << nombreArchivo << endl;
        return false;
    }
    
    try {
        // Leer tamaño
        archivo.read(reinterpret_cast<char*>(&tamanio), sizeof(int));
        
        if (tamanio <= 0) {
            cout << "Error: Tamaño inválido en archivo" << endl;
            archivo.close();
            return false;
        }
        
        // Crear arreglo dinámico
        datos = new int[tamanio];
        
        // Leer datos
        archivo.read(reinterpret_cast<char*>(datos), tamanio * sizeof(int));
        
        archivo.close();
        
        cout << "✓ Datos leídos correctamente desde " << nombreArchivo << endl;
        return true;
        
    } catch (const exception& e) {
        cout << "Error durante lectura: " << e.what() << endl;
        archivo.close();
        if (datos != nullptr) {
            delete[] datos;
            datos = nullptr;
        }
        return false;
    }
}

void demostrarManejoErrores() {
    cout << "\n=== DEMOSTRACIÓN DE MANEJO DE ERRORES ===" << endl;
    
    // Crear datos de prueba
    int datos[] = {10, 20, 30, 40, 50};
    int tamanio = 5;
    
    // Escribir con validación
    bool escrituraOK = escribirConValidacion("datos_validados.bin", datos, tamanio);
    
    if (escrituraOK) {
        // Leer con validación
        int* datosLeidos = nullptr;
        int tamanioLeido;
        
        bool lecturaOK = leerConValidacion("datos_validados.bin", datosLeidos, tamanioLeido);
        
        if (lecturaOK) {
            cout << "Datos leídos: ";
            for (int i = 0; i < tamanioLeido; i++) {
                cout << datosLeidos[i] << " ";
            }
            cout << endl;
            
            // Liberar memoria
            delete[] datosLeidos;
            datosLeidos = nullptr;
        }
    }
    
    // Probar casos de error
    cout << "\nProbando casos de error:" << endl;
    
    // Archivo con nombre vacío
    escribirConValidacion("", datos, tamanio);
    
    // Datos nullptr
    escribirConValidacion("test.bin", nullptr, tamanio);
    
    // Tamaño inválido
    escribirConValidacion("test.bin", datos, -1);
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== ARCHIVOS BINARIOS BÁSICOS CON PUNTEROS ===" << endl;
    cout << "Enfoque: Tipos primitivos, arrays dinámicos, validación de errores\n" << endl;
    
    compararTextoVsBinario();
    escribirTiposPrimitivos();
    leerTiposPrimitivos();
    escribirArregloEnteros();
    leerArregloEnteros();
    demostrarManejoErrores();
    
    cout << "\n=== RESUMEN ===" << endl;
    cout << "✓ Los archivos binarios son más eficientes que los de texto" << endl;
    cout << "✓ reinterpret_cast convierte punteros para escritura/lectura binaria" << endl;
    cout << "✓ Los arrays dinámicos se pueden escribir/leer como unidades completas" << endl;
    cout << "✓ Siempre validar parámetros y manejar errores" << endl;
    cout << "✓ Liberar memoria después de usar arrays dinámicos" << endl;
    cout << "✓ El orden de escritura debe coincidir con el de lectura" << endl;
    
    return 0;
}
