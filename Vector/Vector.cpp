#include "Vector.h"

Vector::Vector(int cantidad){

    this->cantidad = cantidad;
    datos = new int[cantidad];
}

Vector::~Vector(){

    delete[] datos;
}

int Vector::getCantidad(){

    return cantidad;
}

int Vector::getDato(int posicion){

    return datos[posicion];
}

void Vector::setDato(int posicion, int valor){

    datos[posicion] = valor;
}