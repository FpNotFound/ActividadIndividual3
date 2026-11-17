#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

using namespace std;

template <typename T>
class Dynarray {
private:
    T* datos;
    int size;
    int capacity;

public:
    Dynarray();
    ~Dynarray();

    void insertar(T elemento);
    T& obtener(int posicion);

    int getSize() const;
};

template <typename T>
Dynarray<T>::Dynarray() {
    size = 0;
    capacity = 5;

    // Reservamos memoria para almacenar los elementos.
    datos = new T[capacity];
}

template <typename T>
Dynarray<T>::~Dynarray() {
    delete[] datos;
}

// Inserta un elemento al final del Dynarray.
template <typename T>
void Dynarray<T>::insertar(T elemento) {

    // Si se alcanza la capacidad, aumentamos el espacio.
    if (size == capacity) {

        capacity *= 2;

        T* nuevosDatos = new T[capacity];

        // Copiamos los elementos al nuevo espacio.
        for (int i = 0; i < size; i++) {
            nuevosDatos[i] = datos[i];
        }

        delete[] datos;
        datos = nuevosDatos;
    }

    datos[size] = elemento;
    size++;
}

// Permite acceder a un elemento mediante su posición.
template <typename T>
T& Dynarray<T>::obtener(int posicion) {
    return datos[posicion];
}

template <typename T>
int Dynarray<T>::getSize() const {
    return size;
}

#endif