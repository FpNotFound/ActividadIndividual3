#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <typename T>
class Vector {
private:
    T* datos;
    int size;

public:
    // Constructor del Vector.
    Vector(int size);

    // Destructor.
    ~Vector();

    // Permite acceder a un elemento.
    T& operator[](int posicion);

    // Devuelve el tamaño del Vector.
    int getSize() const;
};

// Reserva memoria para el Vector.
template <typename T>
Vector<T>::Vector(int size) {
    this->size = size;
    datos = new T[size];
}

// Libera la memoria utilizada.
template <typename T>
Vector<T>::~Vector() {
    delete[] datos;
}

// Permite acceder y modificar una posición.
template <typename T>
T& Vector<T>::operator[](int posicion) {
    return datos[posicion];
}

// Devuelve el número de elementos.
template <typename T>
int Vector<T>::getSize() const {
    return size;
}

#endif