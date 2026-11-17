#include <iostream>
#include <string>
#include "Vector.h"

using namespace std;

// Calcula el valor total del inventario.
// Multiplica el precio por la cantidad de cada producto.
double calcularValorInventario(Vector<double>& precios,
                               Vector<int>& cantidades) {

    double total = 0;

    for (int i = 0; i < precios.getSize(); i++) {
        total += precios[i] * cantidades[i];
    }

    return total;
}

// Busca el producto que tiene el precio más alto.
int buscarProductoPrecioMayor(Vector<double>& precios) {

    int posicionMayor = 0;

    for (int i = 1; i < precios.getSize(); i++) {

        if (precios[i] > precios[posicionMayor]) {
            posicionMayor = i;
        }
    }

    return posicionMayor;
}

// Calcula el promedio de unidades vendidas por producto.
double calcularPromedioUnidades(Vector<int>& cantidades) {

    int total = 0;

    for (int i = 0; i < cantidades.getSize(); i++) {
        total += cantidades[i];
    }

    return static_cast<double>(total) / cantidades.getSize();
}

int main() {

    // Nombres de los productos.
    Vector<string> productos(5);

    productos[0] = "PC";
    productos[1] = "Teclado";
    productos[2] = "Mouse";
    productos[3] = "Monitor";
    productos[4] = "Auriculares";

    // Precio de cada producto.
    Vector<double> precios(5);

    precios[0] = 1699.00;
    precios[1] = 49.99;
    precios[2] = 24.99;
    precios[3] = 299.99;
    precios[4] = 79.99;

    // Cantidad disponible de cada producto.
    Vector<int> cantidades(5);

    cantidades[0] = 10;
    cantidades[1] = 35;
    cantidades[2] = 50;
    cantidades[3] = 15;
    cantidades[4] = 25;

    // Calculamos el valor total del inventario.
    double valorTotal =
        calcularValorInventario(precios, cantidades);

    // Buscamos el producto con mayor precio.
    int productoMayor =
        buscarProductoPrecioMayor(precios);

    // Calculamos el promedio de unidades.
    double promedio =
        calcularPromedioUnidades(cantidades);

    cout << "===== INVENTARIO DEL SUPERMERCADO =====" << endl;

    cout << "Valor total del inventario: "
         << valorTotal << " euros" << endl;

    cout << "Producto con mayor precio: "
         << productos[productoMayor] << endl;

    cout << "Precio del producto mas caro: "
         << precios[productoMayor] << " euros" << endl;

    cout << "Promedio de unidades por producto: "
         << promedio << endl;

    return 0;
}