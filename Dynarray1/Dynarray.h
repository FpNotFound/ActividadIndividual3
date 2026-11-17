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
    void eliminar(int posicion);
    int buscar(T elemento) const;

    int getSize() const;
    int getCapacity() const;
};

template <typename T>
Dynarray<T>::Dynarray() {
    size = 0;
    capacity = 5;
    datos = new T[capacity];
}

template <typename T>
Dynarray<T>::~Dynarray() {
    delete[] datos;
}

template <typename T>
void Dynarray<T>::insertar(T elemento) {
    if (size == capacity) {
        capacity *= 2;

        T* nuevosDatos = new T[capacity];

        for (int i = 0; i < size; i++) {
            nuevosDatos[i] = datos[i];
        }

        delete[] datos;
        datos = nuevosDatos;
    }

    datos[size] = elemento;
    size++;
}

template <typename T>
void Dynarray<T>::eliminar(int posicion) {
    if (posicion < 0 || posicion >= size) {
        cout << "Posicion no valida." << endl;
        return;
    }

    for (int i = posicion; i < size - 1; i++) {
        datos[i] = datos[i + 1];
    }

    size--;
}

template <typename T>
int Dynarray<T>::buscar(T elemento) const {
    for (int i = 0; i < size; i++) {
        if (datos[i] == elemento) {
            return i;
        }
    }

    return -1;
}

template <typename T>
int Dynarray<T>::getSize() const {
    return size;
}

template <typename T>
int Dynarray<T>::getCapacity() const {
    return capacity;
}

#endif