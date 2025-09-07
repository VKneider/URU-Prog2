#include <iostream>
using namespace std;

/*
==================================================================================
    MODIFICADORES DE ACCESO EN C++
==================================================================================
    En C++, los modificadores de acceso (`private`, `protected`, `public`)
    determinan cómo los miembros de una clase pueden ser accedidos desde fuera
    de la clase o desde clases derivadas.

    Existen tres tipos principales:
    1. `private`    -> Solo accesible dentro de la misma clase.
    2. `protected`  -> Accesible dentro de la misma clase y por clases derivadas.
    3. `public`     -> Accesible desde cualquier parte del programa.
*/

/* ==============================================================================
    1. EJEMPLO DE `private`
=============================================================================== */
/*
    - Los atributos y métodos `private` solo pueden ser accedidos dentro de la misma clase.
    - No se pueden modificar ni leer directamente desde fuera.
*/

class CuentaBancaria {
private:
    double saldo; // Este atributo está oculto fuera de la clase.

public:
    CuentaBancaria(double saldoInicial) {
        saldo = saldoInicial;
    }

    void depositar(double cantidad) {
        saldo += cantidad;
        cout << "Depósito realizado. Nuevo saldo: $" << saldo << endl;
    }

    void retirar(double cantidad) {
        if (cantidad <= saldo) {
            saldo -= cantidad;
            cout << "Retiro realizado. Nuevo saldo: $" << saldo << endl;
        } else {
            cout << "Saldo insuficiente." << endl;
        }
    }

    // Método público para obtener el saldo
    double obtenerSaldo() {
        return saldo;
    }
};

int main() {
    CuentaBancaria cuenta(1000);
    cuenta.depositar(500);
    cuenta.retirar(300);
    
    // cout << cuenta.saldo;  // ? ERROR: saldo es privado y no puede accederse directamente

    cout << "Saldo actual: $" << cuenta.obtenerSaldo() << endl;

    return 0;
}

/*
    Salida esperada:
    Depósito realizado. Nuevo saldo: $1500
    Retiro realizado. Nuevo saldo: $1200
    Saldo actual: $1200
*/

/* ==============================================================================
    2. EJEMPLO DE `protected`
=============================================================================== */
/*
    - `protected` funciona similar a `private`, pero las clases derivadas sí pueden acceder.
*/

class Persona {
protected:
    string nombre;  // Solo accesible desde la misma clase y clases hijas.

public:
    Persona(string nombre) {
        this->nombre = nombre;
    }

    void mostrarNombre() {
        cout << "Nombre: " << nombre << endl;
    }
};

class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string nombre, string carrera) : Persona(nombre) {
        this->carrera = carrera;
    }

    void mostrarInformacion() {
        cout << "Nombre: " << nombre << ", Carrera: " << carrera << endl;
    }
};

int main() {
    Estudiante estudiante("Ana Torres", "Ingeniería de Software");

    // estudiante.nombre = "Pedro"; // ? ERROR: nombre es `protected` y no accesible desde fuera.

    estudiante.mostrarInformacion(); 

    return 0;
}

/*
    Salida esperada:
    Nombre: Ana Torres, Carrera: Ingeniería de Software
*/

/* ==============================================================================
    3. EJEMPLO DE `public`
=============================================================================== */
/*
    - `public` permite que atributos y métodos sean accesibles desde cualquier parte del programa.
*/

class Vehiculo {
public:
    string marca;
    int anio;

    void mostrarDetalles() {
        cout << "Marca: " << marca << ", Año: " << anio << endl;
    }
};

int main() {
    Vehiculo auto1;
    auto1.marca = "Toyota";
    auto1.anio = 2022;

    auto1.mostrarDetalles(); // ? Se puede acceder a los atributos porque son `public`

    return 0;
}

/*
    Salida esperada:
    Marca: Toyota, Año: 2022
*/

/* ==============================================================================
    4. COMBINANDO `private`, `protected` Y `public`
=============================================================================== */
/*
    - Un ejemplo más complejo donde usamos los tres niveles de acceso.
*/

class Empleado {
private:
    double salario; // Solo accesible dentro de la clase.

protected:
    string departamento; // Accesible dentro de la clase y sus hijos.

public:
    string nombre;

    Empleado(string nombre, string departamento, double salario) {
        this->nombre = nombre;
        this->departamento = departamento;
        this->salario = salario;
    }

    void mostrarInformacion() {
        cout << "Empleado: " << nombre << ", Departamento: " << departamento << endl;
    }

    // Método público para modificar el salario
    void cambiarSalario(double nuevoSalario) {
        salario = nuevoSalario;
    }

    void mostrarSalario() {
        cout << "Salario: $" << salario << endl;
    }
};

class Gerente : public Empleado {
public:
    Gerente(string nombre, string departamento, double salario)
        : Empleado(nombre, departamento, salario) {}

    void cambiarDepartamento(string nuevoDepartamento) {
        departamento = nuevoDepartamento; // ? `protected` permite que lo modifiquemos en la subclase
    }
};

int main() {
    Gerente gerente("Carlos López", "Ventas", 5000);

    gerente.mostrarInformacion();
    
    gerente.cambiarDepartamento("Marketing");
    gerente.mostrarInformacion();

    gerente.cambiarSalario(6000);
    gerente.mostrarSalario();

    return 0;
}

/*
    Salida esperada:
    Empleado: Carlos López, Departamento: Ventas
    Empleado: Carlos López, Departamento: Marketing
    Salario: $6000
*/

