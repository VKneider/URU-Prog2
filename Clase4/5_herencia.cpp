/*
 * Archivo: 4_herencia.cpp
 * Descripcion: Ejemplos prácticos de herencia para organizar mejor el código
 * Autor: Ing. Victor Kneider
 * Derechos de uso: Este codigo es de uso personal y esta protegido por derechos de autor. 
 * Queda prohibida su copia, distribucion o modificacion sin autorizacion expresa del autor.
 */

#include <iostream>
#include <locale>
#include <string>
using namespace std;

/*
==================================================================================
    HERENCIA SIMPLE PARA ORGANIZACIÓN DE CÓDIGO
==================================================================================
    La herencia nos permite:
    1. Reutilizar código común
    2. Organizar mejor nuestras clases
    3. Crear jerarquías lógicas
    4. Evitar duplicación de código
*/

// ==============================================================================
// EJEMPLO 1: Sistema de Biblioteca - Organización por tipo de material
// ==============================================================================

class Material {
protected:
    string titulo;
    string autor;
    int anioPublicacion;
    bool disponible;

public:
    Material(string t, string a, int anio) 
        : titulo(t), autor(a), anioPublicacion(anio), disponible(true) {
        cout << "Material '" << titulo << "' registrado" << endl;
    }

    void mostrarInfo() {
        cout << "Título: " << titulo << ", Autor: " << autor 
             << ", Año: " << anioPublicacion << ", Disponible: " 
             << (disponible ? "Sí" : "No") << endl;
    }

    void prestar() {
        if (disponible) {
            disponible = false;
            cout << "Material '" << titulo << "' prestado" << endl;
        } else {
            cout << "Material '" << titulo << "' no disponible" << endl;
        }
    }

    void devolver() {
        disponible = true;
        cout << "Material '" << titulo << "' devuelto" << endl;
    }
};

// Libro hereda de Material - Agrega páginas y género
class Libro : public Material {
private:
    int paginas;
    string genero;

public:
    Libro(string t, string a, int anio, int pag, string gen) 
        : Material(t, a, anio), paginas(pag), genero(gen) {
        cout << "Libro '" << titulo << "' agregado (Género: " << genero << ")" << endl;
    }

    void mostrarInfo() {
        Material::mostrarInfo();
        cout << "  Tipo: Libro, Páginas: " << paginas << ", Género: " << genero << endl;
    }

    void leerResumen() {
        cout << "Resumen del libro '" << titulo << "': [Contenido del resumen...]" << endl;
    }
};

// Revista hereda de Material - Agrega número y frecuencia
class Revista : public Material {
private:
    int numero;
    string frecuencia;

public:
    Revista(string t, string a, int anio, int num, string freq) 
        : Material(t, a, anio), numero(num), frecuencia(freq) {
        cout << "Revista '" << titulo << "' agregada (Número: " << numero << ")" << endl;
    }

    void mostrarInfo() {
        Material::mostrarInfo();
        cout << "  Tipo: Revista, Número: " << numero << ", Frecuencia: " << frecuencia << endl;
    }

    void verArticulos() {
        cout << "Artículos de la revista '" << titulo << "': [Lista de artículos...]" << endl;
    }
};

// ==============================================================================
// EJEMPLO 2: Sistema de Empleados - Organización por tipo de trabajo
// ==============================================================================

class Empleado {
protected:
    string nombre;
    int id;
    double salarioBase;

public:
    Empleado(string n, int i, double sal) 
        : nombre(n), id(i), salarioBase(sal) {
        cout << "Empleado " << nombre << " registrado (ID: " << id << ")" << endl;
    }

    void mostrarInfo() {
        cout << "Empleado: " << nombre << " (ID: " << id << ")" << endl;
    }

    double calcularSalario() {
        return salarioBase;
    }
};

// Vendedor hereda de Empleado - Agrega comisiones
class Vendedor : public Empleado {
private:
    double comisionPorcentaje;
    double ventasMes;

public:
    Vendedor(string n, int i, double sal, double com) 
        : Empleado(n, i, sal), comisionPorcentaje(com), ventasMes(0) {
        cout << "Vendedor " << nombre << " registrado" << endl;
    }

    void agregarVenta(double monto) {
        ventasMes += monto;
        cout << "Venta de $" << monto << " registrada para " << nombre << endl;
    }

    double calcularSalario() {
        double comision = ventasMes * (comisionPorcentaje / 100);
        return salarioBase + comision;
    }

    void mostrarInfo() {
        Empleado::mostrarInfo();
        cout << "  Tipo: Vendedor, Ventas del mes: $" << ventasMes 
             << ", Comisión: " << comisionPorcentaje << "%" << endl;
    }
};

// Gerente hereda de Empleado - Agrega bonificaciones
class Gerente : public Empleado {
private:
    double bonificacion;
    int empleadosACargo;

public:
    Gerente(string n, int i, double sal, double bon, int empleados) 
        : Empleado(n, i, sal), bonificacion(bon), empleadosACargo(empleados) {
        cout << "Gerente " << nombre << " registrado" << endl;
    }

    double calcularSalario() {
        return salarioBase + bonificacion;
    }

    void mostrarInfo() {
        Empleado::mostrarInfo();
        cout << "  Tipo: Gerente, Bonificación: $" << bonificacion 
             << ", Empleados a cargo: " << empleadosACargo << endl;
    }
};

int main() {
    setlocale(LC_ALL, "Spanish");
    
    cout << "=== EJEMPLO 1: SISTEMA DE BIBLIOTECA ===" << endl;
    cout << "=========================================" << endl;
    
    // Crear materiales usando herencia
    Libro libro1("El Quijote", "Cervantes", 1605, 863, "Novela");
    Revista revista1("National Geographic", "Varios", 2023, 245, "Mensual");
    
    cout << "\nInformación de materiales:" << endl;
    libro1.mostrarInfo();
    revista1.mostrarInfo();
    
    cout << "\nAcciones específicas:" << endl;
    libro1.leerResumen();
    revista1.verArticulos();
    
    cout << "\n=== EJEMPLO 2: SISTEMA DE EMPLEADOS ===" << endl;
    cout << "=======================================" << endl;
    
    // Crear empleados usando herencia
    Vendedor vendedor1("Ana García", 101, 2000, 5);
    Gerente gerente1("Carlos López", 201, 4000, 1000, 5);
    
    cout << "\nInformación de empleados:" << endl;
    vendedor1.mostrarInfo();
    gerente1.mostrarInfo();
    
    cout << "\nSalarios calculados:" << endl;
    vendedor1.agregarVenta(10000);
    cout << "Salario vendedor: $" << vendedor1.calcularSalario() << endl;
    cout << "Salario gerente: $" << gerente1.calcularSalario() << endl;
    
    cout << "\n=== VENTAJAS DE LA HERENCIA ===" << endl;
    cout << "================================" << endl;
    cout << "✓ Reutilización de código común" << endl;
    cout << "✓ Organización lógica de clases" << endl;
    cout << "✓ Fácil mantenimiento" << endl;
    cout << "✓ Extensibilidad del código" << endl;
    cout << "✓ Jerarquías claras y comprensibles" << endl;

    return 0;
}