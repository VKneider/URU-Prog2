#include <iostream>
#include <locale>
#include <string>
#include <cstring>
using namespace std;

// Clase para demostrar deep clone y shallow clone
class Persona {
private:
    string nombre;
    int edad;
    int* puntuaciones;  // Puntero a arreglo dinámico
    int numPuntuaciones;

public:
    // Constructor
    Persona(string n, int e, int* punt, int num) 
        : nombre(n), edad(e), numPuntuaciones(num) {
        if (num > 0 && punt != nullptr) {
            puntuaciones = new int[numPuntuaciones];
            for (int i = 0; i < numPuntuaciones; i++) {
                puntuaciones[i] = punt[i];
            }
        } else {
            puntuaciones = nullptr;
            numPuntuaciones = 0;
        }
        cout << "Constructor: Persona " << nombre << " creada" << endl;
    }
    
    // Constructor de copia (shallow clone por defecto)
    Persona(const Persona& otra) 
        : nombre(otra.nombre), edad(otra.edad), numPuntuaciones(otra.numPuntuaciones) {
        cout << "Constructor de copia (SHALLOW): " << nombre << " copiada" << endl;
        
        // SHALLOW CLONE: Solo copiamos la dirección del puntero
        puntuaciones = otra.puntuaciones;  // ¡PELIGRO! Ambos objetos comparten la misma memoria
    }
    
    // Destructor
    ~Persona() {
        cout << "Destructor: Persona " << nombre << " destruida" << endl;
        if (puntuaciones != nullptr) {
            delete[] puntuaciones;
            puntuaciones = nullptr;
        }
    }
    
    // Método para mostrar información
    void mostrar() const {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
        cout << "Puntuaciones: ";
        if (puntuaciones != nullptr) {
            for (int i = 0; i < numPuntuaciones; i++) {
                cout << puntuaciones[i] << " ";
            }
        } else {
            cout << "Sin puntuaciones";
        }
        cout << " (Dirección: " << (void*)puntuaciones << ")" << endl;
    }
    
    // Método para modificar puntuaciones
    void modificarPuntuacion(int indice, int nuevaPuntuacion) {
        if (puntuaciones != nullptr && indice >= 0 && indice < numPuntuaciones) {
            puntuaciones[indice] = nuevaPuntuacion;
            cout << "Puntuación " << indice << " modificada a " << nuevaPuntuacion << endl;
        }
    }
    
    // Método para obtener dirección de puntuaciones (para demostración)
    int* getPuntuaciones() const {
        return puntuaciones;
    }
    
    // Método estático para crear deep clone
    static Persona* crearDeepClone(const Persona& original) {
        cout << "Creando DEEP CLONE de " << original.nombre << endl;
        
        Persona* copia = new Persona(original.nombre, original.edad, 
                                   original.puntuaciones, original.numPuntuaciones);
        return copia;
    }
    
    // Método estático para crear shallow clone
    static Persona* crearShallowClone(const Persona& original) {
        cout << "Creando SHALLOW CLONE de " << original.nombre << endl;
        
        Persona* copia = new Persona(original.nombre, original.edad, 
                                   original.puntuaciones, original.numPuntuaciones);
        
        // SHALLOW CLONE: Hacer que compartan la misma memoria
        delete[] copia->puntuaciones;  // Liberar la memoria que se asignó
        copia->puntuaciones = original.puntuaciones;  // Compartir la misma dirección
        copia->numPuntuaciones = original.numPuntuaciones;
        
        return copia;
    }
};

// Función para demostrar shallow clone
void demostrarShallowClone() {
    cout << "=== DEMOSTRACIÓN DE SHALLOW CLONE ===" << endl;
    cout << "=====================================" << endl;
    
    // Crear objeto original
    int puntuaciones[] = {85, 92, 78, 96};
    Persona original("Ana", 25, puntuaciones, 4);
    
    cout << "\nObjeto original:" << endl;
    original.mostrar();
    
    // Crear shallow clone usando constructor de copia
    Persona copiaShallow = original;  // Constructor de copia (shallow)
    
    cout << "\nShallow clone (constructor de copia):" << endl;
    copiaShallow.mostrar();
    
    // Verificar si comparten la misma memoria
    cout << "\nVerificación de memoria compartida:" << endl;
    cout << "Original - Dirección de puntuaciones: " << (void*)original.getPuntuaciones() << endl;
    cout << "Copia - Dirección de puntuaciones: " << (void*)copiaShallow.getPuntuaciones() << endl;
    cout << "¿Comparten memoria? " << (original.getPuntuaciones() == copiaShallow.getPuntuaciones() ? "SÍ" : "NO") << endl;
    
    // Modificar el original
    cout << "\nModificando puntuación del original..." << endl;
    original.modificarPuntuacion(0, 100);
    
    cout << "\nDespués de modificar el original:" << endl;
    cout << "Original:" << endl;
    original.mostrar();
    cout << "Copia (shallow):" << endl;
    copiaShallow.mostrar();
    
    cout << "\n¡PROBLEMA! La copia también se modificó porque comparten la misma memoria." << endl;
    cout << "Esto puede causar problemas inesperados." << endl;
}

// Función para demostrar deep clone
void demostrarDeepClone() {
    cout << "\n\n=== DEMOSTRACIÓN DE DEEP CLONE ===" << endl;
    cout << "===================================" << endl;
    
    // Crear objeto original
    int puntuaciones[] = {90, 88, 95, 87};
    Persona original("Carlos", 30, puntuaciones, 4);
    
    cout << "\nObjeto original:" << endl;
    original.mostrar();
    
    // Crear deep clone
    Persona* copiaDeep = Persona::crearDeepClone(original);
    
    cout << "\nDeep clone:" << endl;
    copiaDeep->mostrar();
    
    // Verificar si tienen memoria independiente
    cout << "\nVerificación de memoria independiente:" << endl;
    cout << "Original - Dirección de puntuaciones: " << (void*)original.getPuntuaciones() << endl;
    cout << "Copia - Dirección de puntuaciones: " << (void*)copiaDeep->getPuntuaciones() << endl;
    cout << "¿Tienen memoria independiente? " << (original.getPuntuaciones() != copiaDeep->getPuntuaciones() ? "SÍ" : "NO") << endl;
    
    // Modificar el original
    cout << "\nModificando puntuación del original..." << endl;
    original.modificarPuntuacion(1, 100);
    
    cout << "\nDespués de modificar el original:" << endl;
    cout << "Original:" << endl;
    original.mostrar();
    cout << "Copia (deep):" << endl;
    copiaDeep->mostrar();
    
    cout << "\n¡PERFECTO! La copia no se modificó porque tiene memoria independiente." << endl;
    
    // Liberar memoria
    delete copiaDeep;
    copiaDeep = nullptr;
}

// Función para demostrar problemas con shallow clone
void demostrarProblemasShallowClone() {
    cout << "\n\n=== PROBLEMAS CON SHALLOW CLONE ===" << endl;
    cout << "====================================" << endl;
    
    Persona* persona1 = nullptr;
    Persona* persona2 = nullptr;
    
    {
        cout << "Creando persona1 en scope local..." << endl;
        int puntuaciones[] = {70, 80, 90};
        Persona temp("María", 28, puntuaciones, 3);
        persona1 = Persona::crearShallowClone(temp);
        persona2 = Persona::crearShallowClone(temp);
        
        cout << "\npersona1:" << endl;
        persona1->mostrar();
        cout << "persona2:" << endl;
        persona2->mostrar();
        
        cout << "\n¿Comparten memoria? " << (persona1->getPuntuaciones() == persona2->getPuntuaciones() ? "SÍ" : "NO") << endl;
    } // temp se destruye aquí, liberando su memoria
    
    cout << "\nDespués de que temp se destruye:" << endl;
    cout << "persona1:" << endl;
    persona1->mostrar();  // ¡PELIGRO! Acceso a memoria liberada
    cout << "persona2:" << endl;
    persona2->mostrar();  // ¡PELIGRO! Acceso a memoria liberada
    
    cout << "\n¡CRASH INMINENTE! Ambas personas apuntan a memoria liberada." << endl;
    cout << "Esto es exactamente por qué necesitamos deep clone." << endl;
    
    // Liberar memoria (aunque ya esté corrupta)
    delete persona1;
    delete persona2;
}

// Función para demostrar implementación correcta de deep clone
void demostrarImplementacionCorrecta() {
    cout << "\n\n=== IMPLEMENTACIÓN CORRECTA DE DEEP CLONE ===" << endl;
    cout << "=============================================" << endl;
    
    // Crear objeto original
    int puntuaciones[] = {95, 87, 92, 89, 91};
    Persona original("Roberto", 35, puntuaciones, 5);
    
    cout << "\nObjeto original:" << endl;
    original.mostrar();
    
    // Crear deep clone correcto
    Persona* copiaCorrecta = Persona::crearDeepClone(original);
    
    cout << "\nDeep clone correcto:" << endl;
    copiaCorrecta->mostrar();
    
    // Modificar ambos independientemente
    cout << "\nModificando original..." << endl;
    original.modificarPuntuacion(0, 100);
    
    cout << "Modificando copia..." << endl;
    copiaCorrecta->modificarPuntuacion(1, 50);
    
    cout << "\nResultado final:" << endl;
    cout << "Original:" << endl;
    original.mostrar();
    cout << "Copia:" << endl;
    copiaCorrecta->mostrar();
    
    cout << "\n¡PERFECTO! Ambos objetos son completamente independientes." << endl;
    
    // Liberar memoria
    delete copiaCorrecta;
    copiaCorrecta = nullptr;
}

// Función para demostrar clonación de arreglos de objetos
void demostrarClonacionArreglos() {
    cout << "\n\n=== CLONACIÓN DE ARREGLOS DE OBJETOS ===" << endl;
    cout << "=========================================" << endl;
    
    // Crear arreglo original
    Persona** personas = new Persona*[3];
    int puntuaciones1[] = {85, 90};
    int puntuaciones2[] = {78, 82, 88};
    int puntuaciones3[] = {95, 97, 92, 89};
    
    personas[0] = new Persona("Alice", 25, puntuaciones1, 2);
    personas[1] = new Persona("Bob", 30, puntuaciones2, 3);
    personas[2] = new Persona("Charlie", 28, puntuaciones3, 4);
    
    cout << "\nArreglo original:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Persona " << i << ": ";
        personas[i]->mostrar();
    }
    
    // Crear deep clone del arreglo
    Persona** copiaArreglo = new Persona*[3];
    for (int i = 0; i < 3; i++) {
        copiaArreglo[i] = Persona::crearDeepClone(*personas[i]);
    }
    
    cout << "\nArreglo clonado (deep):" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Persona " << i << ": ";
        copiaArreglo[i]->mostrar();
    }
    
    // Modificar el original
    cout << "\nModificando arreglo original..." << endl;
    personas[0]->modificarPuntuacion(0, 999);
    
    cout << "\nDespués de modificar el original:" << endl;
    cout << "Original:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Persona " << i << ": ";
        personas[i]->mostrar();
    }
    cout << "Copia:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "Persona " << i << ": ";
        copiaArreglo[i]->mostrar();
    }
    
    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete personas[i];
        delete copiaArreglo[i];
    }
    delete[] personas;
    delete[] copiaArreglo;
    
    cout << "\nMemoria liberada correctamente." << endl;
}

int main() {
    setlocale(LC_ALL, "spanish");
    cout << "=== DEEP CLONE vs SHALLOW CLONE CON PUNTEROS ===" << endl;
    cout << "Enfoque: Clonación de objetos con memoria dinámica\n" << endl;

    // 1. Demostrar shallow clone
    demostrarShallowClone();

    // 2. Demostrar deep clone
    demostrarDeepClone();

    // 3. Demostrar problemas con shallow clone
    demostrarProblemasShallowClone();

    // 4. Demostrar implementación correcta
    demostrarImplementacionCorrecta();

    // 5. Demostrar clonación de arreglos
    demostrarClonacionArreglos();

    // 6. Resumen y buenas prácticas
    cout << "\n\n=== RESUMEN Y BUENAS PRÁCTICAS ===" << endl;
    cout << "===================================" << endl;
    cout << "✓ SHALLOW CLONE: Copia solo las direcciones de punteros" << endl;
    cout << "  - Ventaja: Más rápido y usa menos memoria" << endl;
    cout << "  - Desventaja: Objetos comparten memoria (peligroso)" << endl;
    cout << "  - Uso: Solo cuando los objetos no se modificarán" << endl;
    cout << endl;
    cout << "✓ DEEP CLONE: Copia todo el contenido de la memoria" << endl;
    cout << "  - Ventaja: Objetos completamente independientes" << endl;
    cout << "  - Desventaja: Más lento y usa más memoria" << endl;
    cout << "  - Uso: Cuando los objetos pueden modificarse independientemente" << endl;
    cout << endl;
    cout << "✓ REGLAS IMPORTANTES:" << endl;
    cout << "  - Siempre implementar destructor que libere memoria" << endl;
    cout << "  - Implementar constructor de copia para deep clone" << endl;
    cout << "  - Usar deep clone cuando haya punteros a memoria dinámica" << endl;
    cout << "  - Verificar que no haya memory leaks" << endl;
    cout << "  - Verificar que no haya punteros colgantes" << endl;

    return 0;
}
