#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    // Explicación general de archivos de texto y binarios
    cout << "=== DIFERENCIAS ENTRE ARCHIVOS DE TEXTO Y BINARIOS ===\n\n";

    cout << "1. Archivos de Texto:\n";
    cout << "- Almacenan datos en formato legible para humanos.\n";
    cout << "- Se pueden abrir y editar con cualquier editor de texto.\n";
    cout << "- Ocupan más espacio porque requieren caracteres adicionales (como espacios o saltos de línea).\n";
    cout << "- Más fáciles de depurar, pero menos eficientes en términos de velocidad de acceso.\n\n";

    cout << "2. Archivos Binarios:\n";
    cout << "- Almacenan datos en formato binario (ceros y unos) optimizado para máquinas.\n";
    cout << "- No son legibles directamente por humanos.\n";
    cout << "- Ocupan menos espacio porque no tienen caracteres extras.\n";
    cout << "- Son más rápidos para leer y escribir grandes volúmenes de datos.\n\n";

    cout << "=== EJEMPLO PRÁCTICO ===\n";

    struct Persona {
        char nombre[30];
        int edad;
        float altura;
    };

    vector<Persona> personas = {
        {"Carlos", 25, 1.75},
        {"Maria", 30, 1.65},
        {"Juan", 22, 1.80}
    };

    // Guardar en archivo de texto
    ofstream archivoTxt("datos.txt");
    if (archivoTxt) {
        for (const auto& p : personas) {
            archivoTxt << p.nombre << " " << p.edad << " " << p.altura << endl;
        }
        archivoTxt.close();
        cout << "Datos guardados en 'datos.txt' (formato texto).\n";
    } else {
        cout << "Error al abrir 'datos.txt'.\n";
    }

    // Guardar en archivo binario
    ofstream archivoBin("datos.bin", ios::binary);
    if (archivoBin) {
        for (const auto& p : personas) {
            archivoBin.write(reinterpret_cast<const char*>(&p), sizeof(Persona));
        }
        archivoBin.close();
        cout << "Datos guardados en 'datos.bin' (formato binario).\n";
    } else {
        cout << "Error al abrir 'datos.bin'.\n";
    }

    // Leer desde archivo binario
    cout << "\n=== LEYENDO DESDE ARCHIVO BINARIO ===\n";
    ifstream archivoBinLectura("datos.bin", ios::binary);
    if (archivoBinLectura) {
        Persona p;
        while (archivoBinLectura.read(reinterpret_cast<char*>(&p), sizeof(Persona))) {
            cout << "Nombre: " << p.nombre << ", Edad: " << p.edad << ", Altura: " << p.altura << "m\n";
        }
        archivoBinLectura.close();
    } else {
        cout << "Error al abrir 'datos.bin' para lectura.\n";
    }

    return 0;
}

