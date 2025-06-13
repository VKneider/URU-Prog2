#include <iostream>
using namespace std;
#include <locale>

// Clase base
class Persona {
protected:
    string nombre;
    int edad;

public:
    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " a�os" << endl;
    }
};

// Clase derivada
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string n, int e, string c) : Persona(n, e) {
        carrera = c;
    }

    void mostrarInformacion() {
        Persona::mostrarInformacion();
        cout << "Carrera: " << carrera << endl;
    }
};

int main() {
	setlocale(LC_ALL, "Spanish");
    Estudiante estudiante1("Laura G�mez", 21, "Ingenier�a en Computaci�n");
    estudiante1.mostrarInformacion();

    return 0;
}

