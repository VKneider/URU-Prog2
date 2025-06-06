#include <iostream>
#include <fstream>

using namespace std;

// Variable 
int miVariableEstatica = 42; // Valor inicial

// Funcion para guardar la variable en un archivo binario
void guardarEnArchivo(const string& nombreArchivo) {
    ofstream archivo(nombreArchivo, ios::binary);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<const char*>(&miVariableEstatica), sizeof(miVariableEstatica));
        archivo.close();
        cout << "Valor guardado en " << nombreArchivo << endl;
    } else {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
    }
}

int main() {
    guardarEnArchivo("variable.bin"); // Guardar el valor en un archivo binario
    return 0;
}

