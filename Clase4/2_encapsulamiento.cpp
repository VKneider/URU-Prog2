#include <iostream>
#include <locale>

using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    // Constructor
    Persona(string n, int e) {
        nombre = n;
        edad = e;
    }

    // Métodos para acceder a los atributos
    string getNombre() {
        return nombre;
    }

    int getEdad() {
        return edad;
    }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 0) {
            edad = nuevaEdad;
        } else {
            cout << "La edad no puede ser negativa." << endl;
        }
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " años" << endl;
    }
};

int main() {
	setlocale(LC_ALL, "Spanish");
    Persona persona1("María López", 30);

    // Se accede a los datos a través de métodos
    cout << "Nombre: " << persona1.getNombre() << endl;
    cout << "Edad antes de cambio: " << persona1.getEdad() << endl;

    persona1.setEdad(35);
    cout << "Edad después de cambio: " << persona1.getEdad() << endl;

    return 0;
}

