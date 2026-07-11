#pragma once

class Vector {
private:
    int* datos;
    int cantidad;

public:
    Vector(int cantidad);
    ~Vector();

    int getCantidad();
    int getDato(int posicion);
    void setDato(int posicion, int valor);
};