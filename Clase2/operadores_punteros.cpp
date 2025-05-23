#include <iostream>
#include <locale> // Para configurar acentos
using namespace std;

int main() {
	setlocale(LC_ALL, "spanish");
    cout << "Ejemplo profundo de los operadores & y * en C++\n" << endl;

    // OPERADOR & (DIRECCIÓN DE MEMORIA)
    cout << "1. Operador & (Dirección de Memoria):\n";
    int numero = 42; // Declaramos una variable normal
    cout << "Valor de 'numero': " << numero << endl;
    cout << "Dirección de memoria de 'numero' (&numero): " << &numero << endl;
    cout << "El operador & nos permite obtener la dirección en la memoria donde se almacena la variable.\n" << endl;

    // OPERADOR * (DESREFERENCIACIÓN)
    cout << "2. Operador * (Desreferenciación):\n";
    int *puntero = &numero; // Creamos un puntero que almacena la dirección de 'numero'
    cout << "El puntero almacena la dirección de memoria de 'numero': " << puntero << endl;
    cout << "El operador * nos permite acceder al valor almacenado en esa dirección:\n";
    cout << "Valor obtenido usando *puntero: " << *puntero << endl;
    cout << "Es decir, *puntero desreferencia la dirección y accede al valor original.\n" << endl;

    // RELACIÓN ENTRE & Y *
    cout << "3. Relación entre & y *:\n";

    // Ejemplo 1: Uso directo de & y *
    cout << "Ejemplo 1:\n";
    cout << "Si aplicamos *(&numero), obtenemos el valor original de 'numero': " << *(&numero) << endl;
    cout << "Esto demuestra que & y * son operadores inversos entre sí.\n" << endl;

    // Ejemplo 2: Verificación práctica
    cout << "Ejemplo 2:\n";
    int *puntero2 = &numero; // Creamos otro puntero
    cout << "Dirección de memoria almacenada en puntero2: " << puntero2 << endl;
    cout << "Valor en la dirección de puntero2 usando *puntero2: " << *puntero2 << endl;
    cout << "Si aplicamos &(*puntero2), recuperamos la dirección de memoria almacenada en puntero2: " 
         << &(*puntero2) << endl;
    cout << "Esto demuestra que aplicar & sobre * regresa al valor original del puntero.\n" << endl;

    // Ejemplo 3: Cambiando el valor original
    cout << "Ejemplo 3:\n";
    cout << "Valor actual de 'numero': " << numero << endl;
    *(&numero) = 99; // Cambiamos el valor original usando * y &
    cout << "Nuevo valor de 'numero' después de modificarlo con *(&numero): " << numero << endl;
    cout << "Esto muestra que podemos modificar valores directamente al combinar & y *.\n" << endl;

    // Ejemplo 4: Arreglos y relación entre & y *
    cout << "Ejemplo 4 (con arreglos):\n";
    int arreglo[3] = {5, 10, 15};
    cout << "Dirección del primer elemento del arreglo (&arreglo[0]): " << &arreglo[0] << endl;
    cout << "Valor del primer elemento usando *(&arreglo[0]): " << *(&arreglo[0]) << endl;
    cout << "El operador & recupera la dirección del elemento y * accede al valor en esa dirección.\n" << endl;

    // Ejemplo 5: Niveles más profundos
    cout << "Ejemplo 5 (Niveles más profundos):\n";
    int **punteroDoble = &puntero; // Puntero a un puntero
    cout << "Dirección almacenada en punteroDoble: " << punteroDoble << endl;
    cout << "Dirección almacenada en puntero (usando *punteroDoble): " << *punteroDoble << endl;
    cout << "Valor original de 'numero' (usando **punteroDoble): " << **punteroDoble << endl;
    cout << "Aquí usamos dos niveles de desreferenciación para recuperar el valor original.\n" << endl;

    // CONCLUSIÓN
    cout << "Conclusión:\n";
    cout << "El operador & obtiene la dirección de memoria de una variable.\n";
    cout << "El operador * desreferencia un puntero para acceder al valor almacenado en esa dirección.\n";
    cout << "Cuando se usan juntos (& y *), se cancelan mutuamente, permitiendo manipular datos y direcciones dinámicamente.\n";

    return 0;
}
