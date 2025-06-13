/*
 * Archivo: 1_clase.cpp
 * Descripcion: Programa que demuestra la definicion y uso basico de una clase en C++
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <locale>

using namespace std;

// Definicion de una clase
class Persona {
public:
    // Atributos (variables de la clase)
    string nombre;
    int edad;

    // Metodo para mostrar informacion de la persona
    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " anos" << endl;
    }
};

int main() {
	setlocale(LC_ALL, "Spanish");
    // Creacion de un objeto de la clase Persona
    Persona persona1;

    // Asignacion de valores a los atributos
    persona1.nombre = "Juan Perez";
    persona1.edad = 25;

    // Llamada al metodo
    persona1.mostrarInformacion();

    return 0;
}

