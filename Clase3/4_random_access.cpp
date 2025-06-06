#include <iostream>
#include <fstream>

using namespace std;

struct Persona {
    char nombre[20];
    int edad;
};

void escribirArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return;
    }

    Persona personas[3] = {
        {"Juan", 25},
        {"Maria", 30},
        {"Pedro", 40}
    };

    archivo.write(reinterpret_cast<char*>(personas), sizeof(personas));
    archivo.close();
    cout << "Datos escritos correctamente en " << nombreArchivo << endl;
}

void leerPersona(const string& nombreArchivo, int indice) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura.\n";
        return;
    }

    Persona persona;
    archivo.seekg(indice * sizeof(Persona), ios::beg);  // Posicionarse en el índice deseado
    archivo.read(reinterpret_cast<char*>(&persona), sizeof(Persona));

    if (!archivo) {
        cerr << "Error al leer la persona en el índice " << indice << endl;
    } else {
        cout << "Persona #" << indice + 1 << ": " << persona.nombre << ", " << persona.edad << " años" << endl;
    }

    archivo.close();
}

int main() {
    string nombreArchivo = "personas.bin";

    escribirArchivo(nombreArchivo);

    int indice;
    cout << "Ingrese el índice de la persona que desea leer (0-2): ";
    cin >> indice;

    leerPersona(nombreArchivo, indice);

    return 0;
}

