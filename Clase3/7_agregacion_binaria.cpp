#include <iostream>
#include <fstream>
#include <cstring> // Para usar funciones como strcpy
using namespace std;

// Estructura para los registros
struct Registro {
    int id;
    char nombre[50];
    double saldo;
};

void agregarRegistroBinario(const string& nombreArchivo, const Registro& nuevoRegistro) {
    // Abrir el archivo en modo binario y para agregar datos
    ofstream archivo(nombreArchivo, ios::binary | ios::app);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    // Escribir el nuevo registro al final del archivo
    archivo.write(reinterpret_cast<const char*>(&nuevoRegistro), sizeof(Registro));
    archivo.close();

    cout << "Registro agregado correctamente." << endl;
}

void mostrarRegistros(const string& nombreArchivo) {
    // Abrir el archivo en modo binario para lectura
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return;
    }

    Registro registro;
    cout << "\n--- Registros en el archivo ---\n";
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(Registro))) {
        cout << "ID: " << registro.id << ", Nombre: " << registro.nombre 
             << ", Saldo: " << registro.saldo << endl;
    }

    archivo.close();
}

int main() {
    string nombreArchivo = "registros.bin";

    // Agregar registros
    Registro registro1 = {1, "Juan Perez", 1500.75};
    Registro registro2 = {2, "Ana Lopez", 2250.50};
    Registro registro3 = {3, "Luis Garcia", 3100.00};

    agregarRegistroBinario(nombreArchivo, registro1);
    agregarRegistroBinario(nombreArchivo, registro2);
    agregarRegistroBinario(nombreArchivo, registro3);

    // Mostrar todos los registros
    mostrarRegistros(nombreArchivo);

    return 0;
}
