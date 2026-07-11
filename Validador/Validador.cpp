#include "Validador.h"

bool Validador::estaOrdenado(Vector& v){
    for (int i = 0; i < v.getCantidad() - 1; i++){
        if (v.getDato(i) > v.getDato(i + 1)){
            return false;
        }
    }
    return true;
}

bool Validador::estaOrdenado(LinkedList& lista){
    Node* actual = lista.getInicio();
    while (actual != nullptr && actual->getNext() != nullptr){
        if (actual->getDato() > actual->getNext()->getDato()){
            return false;
        }
        actual = actual->getNext();
    }
    return true;
}