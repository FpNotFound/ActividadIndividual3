#include <iostream>
#include "Dynarray.h"
#include "Producto.h"

using namespace std;

int main() {

    // Creamos un Dynarray capaz de almacenar objetos Producto.
    Dynarray<Producto> productos;

    // Creamos diferentes productos.
    Producto producto1(1, "Laptop", 899.99);
    Producto producto2(2, "Teclado", 49.99);
    Producto producto3(3, "Mouse", 24.99);

    // Insertamos los objetos en el Dynarray.
    productos.insertar(producto1);
    productos.insertar(producto2);
    productos.insertar(producto3);

    cout << "Productos almacenados en el Dynarray:" << endl;
    cout << "------------------------------------" << endl;

    // Recorremos el Dynarray y mostramos cada producto.
    for (int i = 0; i < productos.getSize(); i++) {
        productos.obtener(i).mostrar();
        cout << "------------------------------------" << endl;
    }

    return 0;
}