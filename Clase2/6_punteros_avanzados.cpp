#include <iostream>
#include <locale>
#include <string>
#include <fstream>
using namespace std;

// Estructura simple para trabajar con archivos
struct Estudiante {
    string nombre;
    int edad;
    float promedio;
};

// Función para demostrar punteros con estructuras y archivos
void demostrarPunterosConArchivos() {
    cout << "=== PUNTEROS CON ARCHIVOS Y ESTRUCTURAS ===" << endl;
    
    // Crear array dinámico de estudiantes
    int numEstudiantes;
    cout << "Ingrese número de estudiantes: ";
    cin >> numEstudiantes;
    
    Estudiante* estudiantes = new Estudiante[numEstudiantes];
    
    // Llenar datos
    cout << "Ingrese datos de los estudiantes:" << endl;
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Estudiante " << (i+1) << ":" << endl;
        cout << "  Nombre: ";
        cin.ignore();
        getline(cin, estudiantes[i].nombre);
        cout << "  Edad: ";
        cin >> estudiantes[i].edad;
        cout << "  Promedio: ";
        cin >> estudiantes[i].promedio;
    }
    
    // Escribir a archivo usando punteros
    ofstream archivo("estudiantes.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < numEstudiantes; i++) {
            archivo << estudiantes[i].nombre << "," 
                   << estudiantes[i].edad << "," 
                   << estudiantes[i].promedio << endl;
        }
        archivo.close();
        cout << "Datos guardados en archivo." << endl;
    }
    
    // Leer desde archivo usando punteros
    cout << "\nLeyendo datos desde archivo:" << endl;
    ifstream archivoLectura("estudiantes.txt");
    if (archivoLectura.is_open()) {
        string linea;
        int contador = 0;
        while (getline(archivoLectura, linea) && contador < numEstudiantes) {
            cout << "Línea " << (contador+1) << ": " << linea << endl;
            contador++;
        }
        archivoLectura.close();
    }
    
    // Liberar memoria
    delete[] estudiantes;
    estudiantes = nullptr;
    
    cout << "Memoria liberada correctamente." << endl;
    cout << endl;
}

// Función para demostrar punteros y matrices dinámicas básicas
void demostrarMatricesDinamicas() {
    cout << "=== MATRICES DINÁMICAS CON PUNTEROS ===" << endl;
    
    int filas, columnas;
    cout << "Ingrese número de filas: ";
    cin >> filas;
    cout << "Ingrese número de columnas: ";
    cin >> columnas;
    
    // Crear matriz dinámica
    int** matriz = new int*[filas];
    for (int i = 0; i < filas; i++) {
        matriz[i] = new int[columnas];
    }
    
    // Llenar matriz con datos simples
    cout << "Llenando matriz..." << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            matriz[i][j] = i * columnas + j + 1;
        }
    }
    
    // Mostrar matriz
    cout << "Matriz creada:" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }
    
    // Mostrar direcciones de memoria
    cout << "\nDirecciones de memoria:" << endl;
    for (int i = 0; i < filas; i++) {
        cout << "Fila " << i << " en: " << matriz[i] << endl;
    }
    
    // Liberar memoria correctamente
    for (int i = 0; i < filas; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
    
    cout << "Matriz liberada correctamente." << endl;
    cout << endl;
}

// Función para demostrar punteros a funciones básicos
int sumar(int a, int b) {
    return a + b;
}

int multiplicar(int a, int b) {
    return a * b;
}

int restar(int a, int b) {
    return a - b;
}

void demostrarPunterosAFunciones() {
    cout << "=== PUNTEROS A FUNCIONES BÁSICOS ===" << endl;
    
    // Array de punteros a funciones
    int (*operaciones[])(int, int) = {sumar, restar, multiplicar};
    string nombres[] = {"Sumar", "Restar", "Multiplicar"};
    
    int a = 10, b = 5;
    cout << "a = " << a << ", b = " << b << endl;
    
    for (int i = 0; i < 3; i++) {
        cout << nombres[i] << ": " << operaciones[i](a, b) << endl;
    }
    
    // Puntero a función individual
    int (*ptrFuncion)(int, int) = sumar;
    cout << "\nUsando puntero individual: " << ptrFuncion(a, b) << endl;
    
    cout << endl;
}

// Función para demostrar punteros y cadenas de caracteres
void demostrarPunterosYCadenas() {
    cout << "=== PUNTEROS Y CADENAS DE CARACTERES ===" << endl;
    
    // Cadena estática
    const char* cadenaEstatica = "Hola Mundo";
    cout << "Cadena estática: " << cadenaEstatica << endl;
    cout << "Dirección: " << (void*)cadenaEstatica << endl;
    
    // Cadena dinámica
    char* cadenaDinamica = new char[20];
    strcpy(cadenaDinamica, "Programación C++");
    cout << "Cadena dinámica: " << cadenaDinamica << endl;
    cout << "Dirección: " << (void*)cadenaDinamica << endl;
    
    // Modificar cadena dinámica
    cadenaDinamica[0] = 'P';
    cout << "Después de modificar: " << cadenaDinamica << endl;
    
    // Liberar memoria
    delete[] cadenaDinamica;
    cadenaDinamica = nullptr;
    
    cout << "Cadena dinámica liberada." << endl;
    cout << endl;
}

// Función para demostrar punteros y estructuras simples
struct Direccion {
    string calle;
    int numero;
    string ciudad;
};

struct Persona {
    string nombre;
    int edad;
    Direccion* direccion; // Puntero a estructura
};

void demostrarPunterosYStructuras() {
    cout << "=== PUNTEROS Y ESTRUCTURAS SIMPLES ===" << endl;
    
    // Crear persona con dirección dinámica
    Persona* persona = new Persona;
    persona->nombre = "Juan Pérez";
    persona->edad = 30;
    persona->direccion = new Direccion;
    
    persona->direccion->calle = "Av. Principal";
    persona->direccion->numero = 123;
    persona->direccion->ciudad = "Montevideo";
    
    cout << "Información de la persona:" << endl;
    cout << "Nombre: " << persona->nombre << endl;
    cout << "Edad: " << persona->edad << endl;
    cout << "Dirección: " << persona->direccion->calle 
         << " " << persona->direccion->numero 
         << ", " << persona->direccion->ciudad << endl;
    
    // Liberar memoria (orden importante)
    delete persona->direccion;
    delete persona;
    persona = nullptr;
    
    cout << "Memoria liberada correctamente." << endl;
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== PUNTEROS Y ARCHIVOS EN C++ ===" << endl;
    cout << "Enfoque: Punteros con archivos, matrices dinámicas, funciones básicas\n" << endl;

    // 1. PUNTEROS CON ARCHIVOS Y ESTRUCTURAS
    demostrarPunterosConArchivos();

    // 2. MATRICES DINÁMICAS
    demostrarMatricesDinamicas();

    // 3. PUNTEROS A FUNCIONES BÁSICOS
    demostrarPunterosAFunciones();

    // 4. PUNTEROS Y CADENAS
    demostrarPunterosYCadenas();

    // 5. PUNTEROS Y ESTRUCTURAS SIMPLES
    demostrarPunterosYStructuras();

    // 6. RESUMEN DE CONCEPTOS BÁSICOS
    cout << "=== RESUMEN DE CONCEPTOS BÁSICOS ===" << endl;
    cout << "✓ Los punteros permiten trabajar con memoria dinámica eficientemente" << endl;
    cout << "✓ Las matrices dinámicas requieren liberación manual de cada fila" << endl;
    cout << "✓ Los punteros a funciones permiten programación dinámica" << endl;
    cout << "✓ Las cadenas dinámicas requieren liberación con delete[]" << endl;
    cout << "✓ Las estructuras con punteros requieren liberación en orden inverso" << endl;
    cout << "✓ Siempre verificar que los punteros no sean nullptr antes de usar" << endl;
    cout << "✓ Los punteros se integran bien con el manejo de archivos" << endl;
    cout << "✓ La memoria debe liberarse correctamente para evitar memory leaks" << endl;

    return 0;
}
