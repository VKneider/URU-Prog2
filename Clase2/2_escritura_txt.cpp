/*
 * Archivo: fichero_escritura.cpp
 * Descripcion: Programa que demuestra la escritura basica en archivos usando C++
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <fstream> // Libreria para manejar archivos
using namespace std;

int main() {
    // Crear un objeto de tipo ofstream para escribir en el archivo
    ofstream archivo("ejemplo.txt"); 

    // Verificar si el archivo se pudo abrir
    if (archivo.is_open()) {
        archivo << "Hola, Programacion 2\n"; // Escribir en el archivo
        archivo << "Este es un ejemplo de manejo de archivos en C++\n";
        archivo.close(); // Cerrar el archivo
        cout << "Datos escritos en el archivo correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escritura." << endl;
    }

    return 0;
}
