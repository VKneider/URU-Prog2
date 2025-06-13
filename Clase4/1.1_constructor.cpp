#include <iostream>
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
        cout << "Se ha creado un objeto Persona: " << nombre << endl;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << " años" << endl;
    }

    // Destructor
    ~Persona() {
        cout << "Se ha destruido el objeto Persona: " << nombre << endl;
    }
};

int main() {
    Persona persona1("Carlos Ramírez", 40);
    persona1.mostrarInformacion();
    
    
    return 0;
}

