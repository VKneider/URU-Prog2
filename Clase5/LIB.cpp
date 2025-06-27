/*
 * Archivo: LIB.cpp
 * Descripcion: Implementacion de una biblioteca simple que proporciona funciones basicas de suma y mensajes
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>  // Libreria estandar para entrada y salida
#include "LIB.HPP"   // Se incluye el archivo de cabecera

namespace MiLib {  
    // Implementacion de la funcion que suma dos numeros
    int suma(int a, int b) {
        return a + b;
    }

    // Implementacion de la funcion que muestra un mensaje
    void mensaje() {
        std::cout << "Hola desde MiLib!" << std::endl;
    }
}

