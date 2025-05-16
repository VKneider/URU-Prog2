/*
 * Archivo: fichero_lectura.cpp
 * Descripcion: Programa que demuestra la lectura basica de archivos usando C++
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <fstream> // Libreria para manejar archivos
#include <string> // Para usar strings
using namespace std;

int main() {
    // Crear un objeto de tipo ifstream para leer el archivo
    ifstream archivo("ejemplo.txt"); 

    // Verificar si el archivo se pudo abrir
    if (archivo.is_open()) {
        string linea;
        cout << "Contenido del archivo:\n";
        while (getline(archivo, linea)) { // Leer linea por linea
            cout << linea << endl;
        }
        archivo.close(); // Cerrar el archivo
    } else {
        cout << "No se pudo abrir el archivo para lectura." << endl;
    }

    return 0;
}
