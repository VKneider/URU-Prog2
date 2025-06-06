#include <iostream>
#include <fstream>

using namespace std;

// Variable  global
int miVariableEstatica = 0; // Se inicializa en 0, pero se sobrescribir� con el valor del archivo

// Funcion para leer la variable desde un archivo binario
void leerDesdeArchivo(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&miVariableEstatica), sizeof(miVariableEstatica));
        archivo.close();
        cout << "Valor le�do desde " << nombreArchivo << ": " << miVariableEstatica << endl;
    } else {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
    }
}

int main() {
    leerDesdeArchivo("variable.bin"); // Leer el valor desde el archivo binario
    return 0;
}

