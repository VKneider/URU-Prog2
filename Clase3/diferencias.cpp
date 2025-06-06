#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h> // Para obtener el tamaño del archivo

using namespace std;

struct Persona {
    string nombre;
    int edad;
    float salario;
};

// Función para obtener el tamaño de un archivo
long obtenerTamanoArchivo(const string& nombreArchivo) {
    struct stat resultados;
    if (stat(nombreArchivo.c_str(), &resultados) == 0) {
        return resultados.st_size;
    }
    return -1; // Error al obtener el tamaño
}

int main() {
    Persona p1;
    p1.nombre = "Juan Pérez";
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
        // Guardamos primero el tamaño del string
        size_t tamNombre = p1.nombre.size();
        archivoBinario.write(reinterpret_cast<char*>(&tamNombre), sizeof(size_t));
        archivoBinario.write(p1.nombre.c_str(), tamNombre);
        archivoBinario.write(reinterpret_cast<char*>(&p1.edad), sizeof(int));
        archivoBinario.write(reinterpret_cast<char*>(&p1.salario), sizeof(float));
        archivoBinario.close();
    }

    // Comparar tamaños
    long tamTexto = obtenerTamanoArchivo("datos.txt");
    long tamBinario = obtenerTamanoArchivo("datos.bin");

    cout << "\nTamaño de 'datos.txt': " << tamTexto << " bytes" << endl;
    cout << "Tamaño de 'datos.bin': " << tamBinario << " bytes" << endl;

    return 0;
}

