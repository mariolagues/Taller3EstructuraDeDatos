#pragma once
#include "Node.h"

class LinkedList {
private:
    Node* inicio;
    int cantidad;

public:
    LinkedList();
    ~LinkedList();

    void agregar(int dato);
    void agregarInicio(int dato);

    int getCantidad();
    int getDato(int posicion);
    void setDato(int posicion, int dato);

    Node* getInicio();
    Node* getNodo(int posicion);

    void setInicio(Node* inicio);
};