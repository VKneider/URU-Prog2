/*
 * Archivo: fichero_agregacion.cpp
 * Descripcion: Programa que demuestra como agregar contenido al final de un archivo existente en C++
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // Crear un objeto de tipo ofstream con modo de apertura "append" para agregar contenido
    ofstream archivo("ejemplo.txt", ios::app); 

    // Verificar si el archivo se pudo abrir
    if (archivo.is_open()) {
        archivo << "Esta linea se agrega al final del archivo.\n";
        archivo.close(); // Cerrar el archivo
        cout << "Linea agregada al archivo correctamente." << endl;
    } else {
        cout << "No se pudo abrir el archivo para agregar contenido." << endl;
    }

    return 0;
}
