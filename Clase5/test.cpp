/*
 * Archivo: test.cpp
 * Descripcion: Programa de prueba que demuestra el uso de la biblioteca MiLib
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include "milib.h"   // Se incluye el archivo de cabecera


int main() {
    std::cout << "Suma: " << MiLib::suma(5, 3) << std::endl; // Llamada a la funcion suma
    MiLib::mensaje();  // Llamada a la funcion mensaje
    return 0;
}
