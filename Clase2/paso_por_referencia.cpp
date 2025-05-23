#include <iostream>
#include <string>
#include <locale> // Para configurar acentos

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

int main() {
    cout << "Ejemplo de paso por referencia en C++\n" << endl;
	setlocale(LC_ALL, "spanish");
    // Ejemplo 1: Modificar una variable usando referencia
    int valor = 5;
    cout << "Antes de incrementar, valor = " << valor << endl;
    incrementar(valor);
    cout << "Después de incrementar, valor = " << valor << endl;

    // Ejemplo 2: Intercambiar valores usando referencia
    int x = 10, y = 20;
    cout << "\nAntes de intercambiar: x = " << x << ", y = " << y << endl;
    intercambiar(x, y);
    cout << "Después de intercambiar: x = " << x << ", y = " << y << endl;

    // Ejemplo 3: Modificar una cadena usando referencia
    string mensaje = "Hola";
    cout << "\nAntes de modificar, mensaje = \"" << mensaje << "\"" << endl;
    agregarTexto(mensaje, ", mundo!");
    cout << "Después de modificar, mensaje = \"" << mensaje << "\"" << endl;

    // Ejemplo 4: Devolver múltiples valores usando referencia
    int numero = 3, cuadrado, cubo;
    calcularCuadradoYCubo(numero, cuadrado, cubo);
    cout << "\nPara el número " << numero << ":" << endl;
    cout << "Cuadrado = " << cuadrado << endl;
    cout << "Cubo = " << cubo << endl;

    return 0;
}
