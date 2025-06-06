/*
 * Archivo: 5_menu.cpp
 * Descripcion: Programa que implementa un sistema de gestion de personas con almacenamiento en archivo binario
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// Definicion de la estructura Persona
struct Persona {
    char nombre[50];
    int edad;
};

// Arreglo dinamico de estructuras
vector<Persona> personas;

// Funcion para agregar una persona al arreglo
void agregarPersona() {
    Persona nueva;
    cout << "Ingrese nombre: ";
    cin.ignore();
    cin.getline(nueva.nombre, 50);
    cout << "Ingrese edad: ";
    cin >> nueva.edad;
    personas.push_back(nueva);
    cout << "Persona agregada con exito.\n";
}

// Funcion para mostrar todas las personas almacenadas
void mostrarPersonas() {
    if (personas.empty()) {
        cout << "No hay personas almacenadas.\n";
        return;
    }
    cout << "\nLista de Personas:\n";
    for (size_t i = 0; i < personas.size(); i++) {
        cout << i + 1 << ". Nombre: " << personas[i].nombre << ", Edad: " << personas[i].edad << endl;
    }
}

// Funcion para guardar el arreglo en un archivo binario
void guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo para escritura.\n";
        return;
    }
    size_t cantidad = personas.size();
    archivo.write(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));
    archivo.write(reinterpret_cast<char*>(personas.data()), cantidad * sizeof(Persona));
    archivo.close();
    cout << "Datos guardados en " << nombreArchivo << " exitosamente.\n";
}

// Funcion para leer los datos desde el archivo binario
void leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo para lectura.\n";
        return;
    }
    size_t cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    vector<Persona> temp(cantidad);
    archivo.read(reinterpret_cast<char*>(temp.data()), cantidad * sizeof(Persona));

    archivo.close();
    cout << "Datos leidos correctamente desde " << nombreArchivo << ".\n";

    // Mostrar los datos leidos
    cout << "\nPersonas en el archivo:\n";
    for (size_t i = 0; i < temp.size(); i++) {
        cout << i + 1 << ". Nombre: " << temp[i].nombre << ", Edad: " << temp[i].edad << endl;
    }
}

// Funcion para cargar los datos del archivo en la variable del programa
void cargarDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (!archivo) {
        cerr << "Error al abrir el archivo para cargar datos.\n";
        return;
    }
    size_t cantidad;
    archivo.read(reinterpret_cast<char*>(&cantidad), sizeof(cantidad));

    personas.resize(cantidad);
    archivo.read(reinterpret_cast<char*>(personas.data()), cantidad * sizeof(Persona));

    archivo.close();
    cout << "Datos cargados en la variable del programa desde " << nombreArchivo << ".\n";
}

// Funcion para mostrar el menu
void menu() {
    int opcion;
    string nombreArchivo = "datos.bin";

    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Agregar persona\n";
        cout << "2. Mostrar personas\n";
        cout << "3. Guardar en archivo binario\n";
        cout << "4. Leer desde archivo binario\n";
        cout << "5. Cargar archivo en variable\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarPersona();
                break;
            case 2:
                mostrarPersonas();
                break;
            case 3:
                guardarEnArchivo(nombreArchivo);
                break;
            case 4:
                leerDesdeArchivo(nombreArchivo);
                break;
            case 5:
                cargarDesdeArchivo(nombreArchivo);
                break;
            case 6:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo.\n";
        }
    } while (opcion != 6);
}

int main() {
    menu(); // Iniciar el menu
    return 0;
}

