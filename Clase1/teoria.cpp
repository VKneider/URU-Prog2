/*
 * Archivo: teoria.cpp
 * Descripcion: Archivo teorico que explica los conceptos fundamentales del manejo de archivos en C++,
 *              incluyendo parametros de ios::, uso de reinterpret_cast y manipulacion de punteros
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring> // Para manejar cadenas en C++
using namespace std;

/*
 * Archivo teorico: ios_parametros.cpp
 *
 * Este archivo explica los parametros de ios::, el uso de reinterpret_cast, 
 * y las funciones seekp, seekg, entre otras, para trabajar con archivos en C++.
 */

/*
 * Parametros de ios:: para trabajar con archivos
 * ----------------------------------------------
 * - ios::in: Abre el archivo para lectura.
 * - ios::out: Abre el archivo para escritura. Si el archivo existe, se sobrescribe.
 * - ios::app: Abre el archivo para escritura y posiciona el puntero al final del archivo.
 * - ios::ate: Abre el archivo y posiciona el puntero al final, pero permite escribir 
 *             o leer desde cualquier parte si se cambia la posicion manualmente.
 * - ios::binary: Abre el archivo en modo binario, util para trabajar con datos en crudo.
 * - ios::trunc: Si el archivo existe, lo vacia al abrirlo.
 */

// Ejemplo de combinacion de parametros para abrir un archivo
void ejemploAperturaArchivo() {
    fstream archivo("ejemplo.dat", ios::in | ios::out | ios::binary);

    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    cout << "Archivo abierto correctamente con ios::in, ios::out e ios::binary." << endl;
    archivo.close();
}

/*
 * Funciones para manipular la posicion del puntero en archivos
 * ------------------------------------------------------------
 * - archivo.seekg(posicion, direccion): Mueve el puntero de lectura (get) a la posicion especificada.
 * - archivo.seekp(posicion, direccion): Mueve el puntero de escritura (put) a la posicion especificada.
 * - archivo.tellg(): Devuelve la posicion actual del puntero de lectura.
 * - archivo.tellp(): Devuelve la posicion actual del puntero de escritura.
 *
 * Direcciones posibles:
 * - ios::beg: Desde el inicio del archivo.
 * - ios::cur: Desde la posicion actual del puntero.
 * - ios::end: Desde el final del archivo.
 */

void ejemploPosicionPunteros() {
    fstream archivo("posiciones.dat", ios::out | ios::binary);

    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    // Escribir datos iniciales en el archivo
    archivo.write("1234567890", 10); // Escribir 10 bytes

    // Mover el puntero de escritura al tercer byte (indice 2)
    archivo.seekp(2, ios::beg);
    archivo.write("A", 1); // Sobrescribir el tercer byte con 'A'

    // Ver la posicion actual del puntero
    cout << "Posicion actual del puntero de escritura: " << archivo.tellp() << endl;

    archivo.close();
}

/*
 * Uso de reinterpret_cast
 * ------------------------
 * reinterpret_cast es una forma de convertir un puntero de un tipo a otro, 
 * sin alterar los datos que apunta. Es comunmente usado para escribir o leer 
 * estructuras en archivos binarios.
 */

struct Registro {
    int id;
    char nombre[50];
    double saldo;
};

void ejemploReinterpretCast() {
    Registro registro = {1, "Juan Perez", 1500.75};

    // Abrir el archivo para escritura en binario
    ofstream archivo("registro.dat", ios::binary);

    if (!archivo) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    // Usamos reinterpret_cast para convertir el puntero de 'registro' en un puntero a char
    archivo.write(reinterpret_cast<const char*>(&registro), sizeof(Registro));

    cout << "Registro escrito correctamente en el archivo binario." << endl;

    archivo.close();
}

/*
 * Notas adicionales:
 * ------------------
 * - ios::binary es importante al trabajar con estructuras, ya que evita 
 *   conversiones automaticas (como cambiar '\n' a '\r\n' en Windows).
 * - Las funciones seekg y seekp son utiles para acceder a datos especificos 
 *   en archivos grandes sin necesidad de leer todo el contenido.
 */

int main() {
    cout << "Ejemplo de parametros de ios:: y manipulacion de archivos.\n" << endl;

    // Demostracion de apertura de archivos con ios::
    ejemploAperturaArchivo();

    // Demostracion de manipulacion de punteros
    ejemploPosicionPunteros();

    // Demostracion de reinterpret_cast
    ejemploReinterpretCast();

    return 0;
}
