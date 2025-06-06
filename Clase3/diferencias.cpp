#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h> // Para obtener el tama�o del archivo

using namespace std;

struct Persona {
    string nombre;
    int edad;
    float salario;
};

// Funci�n para obtener el tama�o de un archivo
long obtenerTamanoArchivo(const string& nombreArchivo) {
    struct stat resultados;
    if (stat(nombreArchivo.c_str(), &resultados) == 0) {
        return resultados.st_size;
    }
    return -1; // Error al obtener el tama�o
}

int main() {
    Persona p1;
    p1.nombre = "Juan P�rez";
    p1.edad = 30;
    p1.salario = 2500.50;

    // Guardar en archivo de texto
    ofstream archivoTexto("datos.txt");
    if (archivoTexto) {
        archivoTexto << p1.nombre << "," << p1.edad << "," << p1.salario << endl;
        archivoTexto.close();
    }

    // Guardar en archivo binario (Optimizado)
    ofstream archivoBinario("datos.bin", ios::binary);
    if (archivoBinario) {
        // Guardamos primero el tama�o del string
        size_t tamNombre = p1.nombre.size();
        archivoBinario.write(reinterpret_cast<char*>(&tamNombre), sizeof(size_t));
        archivoBinario.write(p1.nombre.c_str(), tamNombre);
        archivoBinario.write(reinterpret_cast<char*>(&p1.edad), sizeof(int));
        archivoBinario.write(reinterpret_cast<char*>(&p1.salario), sizeof(float));
        archivoBinario.close();
    }

    // Comparar tama�os
    long tamTexto = obtenerTamanoArchivo("datos.txt");
    long tamBinario = obtenerTamanoArchivo("datos.bin");

    cout << "\nTama�o de 'datos.txt': " << tamTexto << " bytes" << endl;
    cout << "Tama�o de 'datos.bin': " << tamBinario << " bytes" << endl;

    return 0;
}

