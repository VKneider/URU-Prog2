/*
 * Archivo: fstream.cpp
 * Descripcion: Ejemplo práctico del uso de fstream con diferentes parámetros ios::
 * Basado en teoria.cpp
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;

// Estructura para almacenar datos de estudiantes
struct Estudiante {
    int id;
    string nombre;
    float promedio;
};

// Función para mostrar el contenido actual del archivo
void mostrarContenido(const string& nombreArchivo) {
    fstream archivo(nombreArchivo, ios::in);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    string linea;
    cout << "\nContenido actual del archivo:" << endl;
    cout << setw(5) << "ID" << setw(20) << "Nombre" << setw(15) << "Promedio" << endl;
    cout << string(40, '-') << endl;

    while (getline(archivo, linea)) {
        cout << linea << endl;
    }

    archivo.close();
}

// Función para escribir un estudiante en el archivo
void escribirEstudiante(fstream& archivo, const Estudiante& est) {
    archivo << setw(5) << est.id 
            << setw(20) << est.nombre 
            << setw(15) << fixed << setprecision(2) << est.promedio << endl;
}

int main() {
    const string nombreArchivo = "estudiantes.txt";
    
    // 1. Crear y escribir en el archivo (ios::out)
    cout << "1. Creando archivo y escribiendo datos iniciales..." << endl;
    {
        // ios::out - Abre para escritura y trunca el archivo si existe
        fstream archivo(nombreArchivo, ios::out);
        if (!archivo) {
            cout << "Error al crear el archivo." << endl;
            return 1;
        }

        Estudiante estudiantes[] = {
            {1, "Ana Garcia", 9.5},
            {2, "Carlos Lopez", 8.7},
            {3, "Maria Rodriguez", 9.2}
        };

        for (const auto& est : estudiantes) {
            escribirEstudiante(archivo, est);
        }
        archivo.close();
    }

    mostrarContenido(nombreArchivo);

    // 2. Agregar un estudiante al final (ios::app | ios::out)
    cout << "\n2. Agregando un estudiante al final usando ios::app..." << endl;
    {
        // ios::app - Abre para escritura al final del archivo
        // ios::out - Necesario junto con app para escritura
        fstream archivo(nombreArchivo, ios::out | ios::app);
        Estudiante nuevoEst = {4, "Pedro Sanchez", 8.9};
        escribirEstudiante(archivo, nuevoEst);
        archivo.close();
    }

    mostrarContenido(nombreArchivo);

    // 3. Modificar un registro existente
    cout << "\n3. Modificando el estudiante con ID 2..." << endl;
    {
        // ios::in - Para leer el archivo
        fstream archivoLectura(nombreArchivo, ios::in);
        vector<Estudiante> estudiantes;
        string linea;
        int id;
        string nombre;
        float promedio;

        while (archivoLectura >> id >> ws) {
            getline(archivoLectura >> ws, nombre, ' ');
            while (nombre.length() < 19) {
                string temp;
                archivoLectura >> temp;
                nombre += " " + temp;
            }
            archivoLectura >> promedio;
            
            estudiantes.push_back({id, nombre, promedio});
        }
        archivoLectura.close();

        // Modificar el estudiante deseado
        for (auto& est : estudiantes) {
            if (est.id == 2) {
                est.promedio = 9.0;
                break;
            }
        }

        // ios::out | ios::trunc - Abre para escritura y trunca el archivo
        fstream archivoEscritura(nombreArchivo, ios::out | ios::trunc);
        for (const auto& est : estudiantes) {
            escribirEstudiante(archivoEscritura, est);
        }
        archivoEscritura.close();
    }

    mostrarContenido(nombreArchivo);

    // 4. Leer una línea específica usando ate
    cout << "\n4. Leyendo el tercer registro usando ios::ate..." << endl;
    {
        // ios::in | ios::ate - Abre para lectura y posiciona el puntero al final
        fstream archivo(nombreArchivo, ios::in | ios::ate);
        string linea;
        
        // Obtener el tamaño del archivo
        streampos tamanoArchivo = archivo.tellg();
        // Volver al inicio
        archivo.seekg(0, ios::beg);
        
        int lineaObjetivo = 3;
        int lineaActual = 0;

        while (getline(archivo, linea) && lineaActual < lineaObjetivo) {
            lineaActual++;
        }

        if (lineaActual == lineaObjetivo) {
            cout << "Tercer registro (tamaño del archivo: " << tamanoArchivo << " bytes):" << endl;
            cout << linea << endl;
        }
        
        archivo.close();
    }

    // 5. Lectura y escritura simultánea
    cout << "\n5. Lectura y escritura simultánea usando ios::in | ios::out..." << endl;
    {
        // ios::in | ios::out - Abre para lectura y escritura
        fstream archivo(nombreArchivo, ios::in | ios::out);
        string linea;
        vector<string> lineas;
        
        // Leer todas las líneas
        while (getline(archivo, linea)) {
            lineas.push_back(linea);
        }

        // Agregar un comentario al final de cada línea
        archivo.clear(); // Limpiar flags de EOF
        archivo.seekp(0, ios::beg); // Volver al inicio para escribir
        
        for (const string& l : lineas) {
            stringstream ss(l);
            int id;
            ss >> id;
            archivo << l << " // ID: " << id << endl;
        }
        
        archivo.close();
    }

    cout << "\nContenido final del archivo con comentarios agregados:" << endl;
    mostrarContenido(nombreArchivo);

    return 0;
}
