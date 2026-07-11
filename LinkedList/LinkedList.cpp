#include "LinkedList.h"

LinkedList::LinkedList(){
    this->inicio = nullptr;
    this->cantidad = 0;
}

LinkedList::~LinkedList(){
    Node* actual = this->inicio;

    while (actual != nullptr){
        Node* eliminar = actual;
        actual = actual->getNext();
        delete eliminar;
    }

    this->inicio = nullptr;
    this->cantidad = 0;
}

void LinkedList::agregar(int dato){
    Node* nuevo = new Node(dato);

    if (this->inicio == nullptr){
        this->inicio = nuevo;
    }
    else{
        Node* actual = this->inicio;

        while (actual->getNext() != nullptr){
            actual = actual->getNext();
        }

        actual->setNext(nuevo);
    }

    this->cantidad++;
}

void LinkedList::agregarInicio(int dato){
    Node* nuevo = new Node(dato);

    nuevo->setNext(this->inicio);
    this->inicio = nuevo;

    this->cantidad++;
}

int LinkedList::getCantidad(){
    return this->cantidad;
}

Node* LinkedList::getNodo(int posicion){
    if (posicion < 0 || posicion >= this->cantidad){
        return nullptr;
    }

    Node* actual = this->inicio;

    for (int i = 0; i < posicion; i++){
        actual = actual->getNext();
    }

    return actual;
}

int LinkedList::getDato(int posicion){
    Node* actual = getNodo(posicion);

    if (actual == nullptr){
        return -1;
    }

    return actual->getDato();
}

void LinkedList::setDato(int posicion, int dato){
    Node* actual = getNodo(posicion);

    if (actual != nullptr){
        actual->setDato(dato);
    }
}

Node* LinkedList::getInicio(){
    return this->inicio;
}

void LinkedList::setInicio(Node* inicio){
    this->inicio = inicio;
}