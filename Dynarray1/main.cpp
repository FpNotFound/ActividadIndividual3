#include <iostream>
#include "Dynarray.h"

using namespace std;

int main() {

    Dynarray<int> numeros;

    // Insertamos varios números en el Dynarray.
    numeros.insertar(10);
    numeros.insertar(20);
    numeros.insertar(30);
    numeros.insertar(40);

    cout << "Elementos insertados correctamente." << endl;
    cout << "Tamano: " << numeros.getSize() << endl;
    cout << "Capacidad: " << numeros.getCapacity() << endl;

    // Buscamos un elemento dentro del Dynarray.
    int posicion = numeros.buscar(30);

    if (posicion != -1) {
        cout << "El numero 30 se encuentra en la posicion "
             << posicion << "." << endl;
    } else {
        cout << "El numero 30 no se encuentra en el Dynarray." << endl;
    }

    // Eliminamos el elemento que esta en la posicion 1.
    numeros.eliminar(1);

    cout << "Se elimino el elemento de la posicion 1." << endl;
    cout << "Tamano actual: " << numeros.getSize() << endl;

    // Comprobamos que el elemento eliminado ya no esta.
    posicion = numeros.buscar(20);

    if (posicion == -1) {
        cout << "El numero 20 ya no se encuentra en el Dynarray." << endl;
    } else {
        cout << "El numero 20 sigue en la posicion "
             << posicion << "." << endl;
    }

    return 0;
}