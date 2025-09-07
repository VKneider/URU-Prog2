#include <iostream>
#include <string>
#include <locale>
#include <vector>
using namespace std;

// Función que modifica un entero usando paso por referencia
void incrementar(int &numero) {
    numero += 10; // Incrementa el valor en 10
}

// Función que intercambia dos valores usando paso por referencia
void intercambiar(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// Función que modifica una cadena usando paso por referencia
void agregarTexto(string &texto, const string &nuevoTexto) {
    texto += nuevoTexto; // Concatenar texto al final
}

// Función que devuelve múltiples resultados usando paso por referencia
void calcularCuadradoYCubo(int numero, int &cuadrado, int &cubo) {
    cuadrado = numero * numero; // Calcula el cuadrado
    cubo = numero * numero * numero; // Calcula el cubo
}

// Función que modifica un puntero usando paso por referencia
void modificarPuntero(int* &ptr, int nuevoValor) {
    if (ptr != nullptr) {
        *ptr = nuevoValor;
    } else {
        ptr = new int(nuevoValor);
    }
}

// Función que modifica un arreglo usando punteros
void llenarArreglo(int* arreglo, int tamanio, int valorInicial) {
    for (int i = 0; i < tamanio; i++) {
        arreglo[i] = valorInicial + i;
    }
}

// Función que modifica un vector usando paso por referencia
void procesarVector(vector<int> &vec) {
    for (int &elemento : vec) {
        elemento *= 2; // Duplicar cada elemento
    }
}

// Función que demuestra paso por referencia con estructuras
struct Punto {
    int x, y;
    
    Punto(int x = 0, int y = 0) : x(x), y(y) {}
    
    void mostrar() const {
        cout << "(" << x << ", " << y << ")";
    }
};

void moverPunto(Punto &punto, int dx, int dy) {
    punto.x += dx;
    punto.y += dy;
}

// Función que demuestra paso por referencia con punteros a estructuras
void modificarPunto(Punto* &punto, int nuevaX, int nuevaY) {
    if (punto != nullptr) {
        punto->x = nuevaX;
        punto->y = nuevaY;
    } else {
        punto = new Punto(nuevaX, nuevaY);
    }
}

// Función que demuestra paso por referencia con arreglos dinámicos
void redimensionarArreglo(int* &arreglo, int &tamanio, int nuevoTamanio) {
    if (arreglo != nullptr) {
        delete[] arreglo;
    }
    
    arreglo = new int[nuevoTamanio];
    tamanio = nuevoTamanio;
    
    // Inicializar con valores por defecto
    for (int i = 0; i < tamanio; i++) {
        arreglo[i] = 0;
    }
}

// Función que demuestra paso por referencia con múltiples punteros
void intercambiarPunteros(int* &ptr1, int* &ptr2) {
    int* temp = ptr1;
    ptr1 = ptr2;
    ptr2 = temp;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== GUÍA COMPLETA DE PASO POR REFERENCIA Y PUNTEROS ===" << endl;
    cout << "Enfoque: Referencias, Punteros, Arreglos, Estructuras\n" << endl;

    // 1. REFERENCIAS BÁSICAS
    cout << "1. REFERENCIAS BÁSICAS:" << endl;
    cout << "----------------------" << endl;
    
    int valor = 5;
    cout << "Antes de incrementar, valor = " << valor << endl;
    incrementar(valor);
    cout << "Después de incrementar, valor = " << valor << endl;

    int x = 10, y = 20;
    cout << "\nAntes de intercambiar: x = " << x << ", y = " << y << endl;
    intercambiar(x, y);
    cout << "Después de intercambiar: x = " << x << ", y = " << y << endl;

    string mensaje = "Hola";
    cout << "\nAntes de modificar, mensaje = \"" << mensaje << "\"" << endl;
    agregarTexto(mensaje, ", mundo!");
    cout << "Después de modificar, mensaje = \"" << mensaje << "\"" << endl;

    int numero = 3, cuadrado, cubo;
    calcularCuadradoYCubo(numero, cuadrado, cubo);
    cout << "\nPara el número " << numero << ":" << endl;
    cout << "Cuadrado = " << cuadrado << endl;
    cout << "Cubo = " << cubo << endl;
    cout << endl;

    // 2. PUNTEROS Y REFERENCIAS
    cout << "2. PUNTEROS Y REFERENCIAS:" << endl;
    cout << "--------------------------" << endl;
    
    int* ptr = new int(100);
    cout << "Puntero original: " << ptr << " -> " << *ptr << endl;
    
    modificarPuntero(ptr, 200);
    cout << "Después de modificar: " << ptr << " -> " << *ptr << endl;
    
    delete ptr;
    ptr = nullptr;
    cout << "Puntero liberado." << endl;
    cout << endl;

    // 3. ARREGLOS Y PUNTEROS
    cout << "3. ARREGLOS Y PUNTEROS:" << endl;
    cout << "----------------------" << endl;
    
    int tamanio = 5;
    int* arreglo = new int[tamanio];
    
    llenarArreglo(arreglo, tamanio, 10);
    cout << "Arreglo llenado: ";
    for (int i = 0; i < tamanio; i++) {
        cout << arreglo[i] << " ";
    }
    cout << endl;
    
    delete[] arreglo;
    arreglo = nullptr;
    cout << "Arreglo liberado." << endl;
    cout << endl;

    // 4. VECTORES Y REFERENCIAS
    cout << "4. VECTORES Y REFERENCIAS:" << endl;
    cout << "-------------------------" << endl;
    
    vector<int> numeros = {1, 2, 3, 4, 5};
    cout << "Vector original: ";
    for (int n : numeros) {
        cout << n << " ";
    }
    cout << endl;
    
    procesarVector(numeros);
    cout << "Vector procesado: ";
    for (int n : numeros) {
        cout << n << " ";
    }
    cout << endl;
    cout << endl;

    // 5. ESTRUCTURAS Y REFERENCIAS
    cout << "5. ESTRUCTURAS Y REFERENCIAS:" << endl;
    cout << "----------------------------" << endl;
    
    Punto punto(5, 10);
    cout << "Punto original: ";
    punto.mostrar();
    cout << endl;
    
    moverPunto(punto, 3, -2);
    cout << "Punto movido: ";
    punto.mostrar();
    cout << endl;
    cout << endl;

    // 6. PUNTEROS A ESTRUCTURAS
    cout << "6. PUNTEROS A ESTRUCTURAS:" << endl;
    cout << "-------------------------" << endl;
    
    Punto* ptrPunto = new Punto(1, 1);
    cout << "Punto original: ";
    ptrPunto->mostrar();
    cout << endl;
    
    modificarPunto(ptrPunto, 7, 8);
    cout << "Punto modificado: ";
    ptrPunto->mostrar();
    cout << endl;
    
    delete ptrPunto;
    ptrPunto = nullptr;
    cout << "Puntero a estructura liberado." << endl;
    cout << endl;

    // 7. ARREGLOS DINÁMICOS Y REFERENCIAS
    cout << "7. ARREGLOS DINÁMICOS Y REFERENCIAS:" << endl;
    cout << "-----------------------------------" << endl;
    
    int* arregloDinamico = nullptr;
    int tamanioDinamico = 0;
    
    cout << "Redimensionando arreglo a 3 elementos..." << endl;
    redimensionarArreglo(arregloDinamico, tamanioDinamico, 3);
    cout << "Tamaño: " << tamanioDinamico << endl;
    cout << "Elementos: ";
    for (int i = 0; i < tamanioDinamico; i++) {
        cout << arregloDinamico[i] << " ";
    }
    cout << endl;
    
    cout << "Redimensionando arreglo a 5 elementos..." << endl;
    redimensionarArreglo(arregloDinamico, tamanioDinamico, 5);
    cout << "Tamaño: " << tamanioDinamico << endl;
    cout << "Elementos: ";
    for (int i = 0; i < tamanioDinamico; i++) {
        cout << arregloDinamico[i] << " ";
    }
    cout << endl;
    
    delete[] arregloDinamico;
    arregloDinamico = nullptr;
    cout << "Arreglo dinámico liberado." << endl;
    cout << endl;

    // 8. INTERCAMBIO DE PUNTEROS
    cout << "8. INTERCAMBIO DE PUNTEROS:" << endl;
    cout << "---------------------------" << endl;
    
    int* ptr1 = new int(100);
    int* ptr2 = new int(200);
    
    cout << "Antes del intercambio:" << endl;
    cout << "ptr1: " << ptr1 << " -> " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << " -> " << *ptr2 << endl;
    
    intercambiarPunteros(ptr1, ptr2);
    cout << "\nDespués del intercambio:" << endl;
    cout << "ptr1: " << ptr1 << " -> " << *ptr1 << endl;
    cout << "ptr2: " << ptr2 << " -> " << *ptr2 << endl;
    
    delete ptr1;
    delete ptr2;
    ptr1 = ptr2 = nullptr;
    cout << "Punteros liberados." << endl;
    cout << endl;

    // 9. RESUMEN Y BUENAS PRÁCTICAS
    cout << "=== RESUMEN Y BUENAS PRÁCTICAS ===" << endl;
    cout << "✓ Las referencias son alias para variables existentes" << endl;
    cout << "✓ Las referencias no pueden ser reasignadas" << endl;
    cout << "✓ Los punteros pueden ser nullptr y reasignados" << endl;
    cout << "✓ Usar referencias para parámetros de salida simples" << endl;
    cout << "✓ Usar punteros para parámetros opcionales o arrays" << endl;
    cout << "✓ Siempre verificar punteros antes de usar" << endl;
    cout << "✓ Liberar memoria asignada dinámicamente" << endl;
    cout << "✓ Asignar nullptr después de delete" << endl;

    return 0;
}
