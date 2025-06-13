#include <iostream>
using namespace std;

class Persona {
public:
    virtual void presentarse() {
        cout << "Soy una persona." << endl;
    }
};

class Estudiante : public Persona {
public:
    void presentarse() override {
        cout << "Soy un estudiante." << endl;
    }
};

class Profesor : public Persona {
public:
    void presentarse() override {
        cout << "Soy un profesor." << endl;
    }
};

int main() {
    Persona* p1 = new Estudiante();
    Persona* p2 = new Profesor();

    p1->presentarse();  // Llamará a la versión de Estudiante
    p2->presentarse();  // Llamará a la versión de Profesor

    delete p1;
    delete p2;

    return 0;
}

