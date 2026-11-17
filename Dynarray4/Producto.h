#ifndef PRODUCTO_H
#define PRODUCTO_H

#include <iostream>
#include <string>

using namespace std;

class Producto {
private:
    int codigo;
    string nombre;
    double precio;

public:
    // Constructor vacío.
    Producto();

    // Constructor con los datos del producto.
    Producto(int codigo, string nombre, double precio);

    // Muestra la información del producto.
    void mostrar() const;
};

// Inicializa un producto vacío.
Producto::Producto() {
    codigo = 0;
    nombre = "";
    precio = 0.0;
}

// Inicializa los atributos del producto.
Producto::Producto(int codigo, string nombre, double precio) {
    this->codigo = codigo;
    this->nombre = nombre;
    this->precio = precio;
}

// Muestra los datos del producto.
void Producto::mostrar() const {
    cout << "Codigo: " << codigo << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Precio: " << precio << " euros" << endl;
}

#endif