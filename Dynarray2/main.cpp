#include <iostream>
#include <string>
#include "Dynarray.h"

using namespace std;

int main() {

    Dynarray<string> palabras;

    // Insertamos diferentes cadenas de texto.
    palabras.insertar("Gato");
    palabras.insertar("Puro");
    palabras.insertar("Laptop");
    palabras.insertar("Arbol");
    palabras.insertar("Perro");

    cout << "Palabras originales:" << endl;
    palabras.mostrar();

    // Ordenamos las palabras alfabéticamente.
    palabras.ordenar();

    cout << "\nPalabras ordenadas alfabeticamente:" << endl;
    palabras.mostrar();

    // Buscamos una palabra específica.
    string palabraBuscada = "Laptop";

    int posicion = palabras.buscar(palabraBuscada);

    if (posicion != -1) {
        cout << "\nLa palabra " << palabraBuscada
             << " se encuentra en la posicion "
             << posicion << "." << endl;
    } else {
        cout << "\nLa palabra " << palabraBuscada
             << " no se encuentra en el Dynarray." << endl;
    }

    return 0;
}