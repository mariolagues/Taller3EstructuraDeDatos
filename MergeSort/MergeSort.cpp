#include "MergeSort.h"

void MergeSort::ordenar(Vector& v){
    if (v.getCantidad() > 1){
        dividir(v, 0, v.getCantidad() - 1);
    }
}

void MergeSort::dividir(Vector& v, int izquierda, int derecha){

    if (izquierda < derecha){

        int medio = izquierda + (derecha - izquierda) / 2;

        dividir(v, izquierda, medio);
        dividir(v, medio + 1, derecha);

        combinar(v, izquierda, medio, derecha);
    }
}

void MergeSort::combinar(Vector& v, int izquierda, int medio, int derecha){
    int cantidadIzquierda = medio - izquierda + 1;
    int cantidadDerecha = derecha - medio;

    int* vectorIzquierda = new int[cantidadIzquierda];
    int* vectorDerecha = new int[cantidadDerecha];

    for (int i = 0; i < cantidadIzquierda; i++){
        vectorIzquierda[i] = v.getDato(izquierda + i);
    }

    for (int j = 0; j < cantidadDerecha; j++){
        vectorDerecha[j] = v.getDato(medio + 1 + j);
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < cantidadIzquierda && j < cantidadDerecha){

        if (vectorIzquierda[i] <= vectorDerecha[j]){
            v.setDato(k, vectorIzquierda[i]);
            i++;
        }
        else{
            v.setDato(k, vectorDerecha[j]);
            j++;
        }
        k++;
    }

    while (i < cantidadIzquierda){
        v.setDato(k, vectorIzquierda[i]);
        i++;
        k++;
    }

    while (j < cantidadDerecha){
        v.setDato(k, vectorDerecha[j]);
        j++;
        k++;
    }

    delete[] vectorIzquierda;
    delete[] vectorDerecha;
}

void MergeSort::ordenar(LinkedList& lista){
    lista.setInicio(ordenarNodos(lista.getInicio()));
}

Node* MergeSort::ordenarNodos(Node* inicio){
    if (inicio == nullptr || inicio->getNext() == nullptr){
        return inicio;
    }
    Node* medio = obtenerMedio(inicio);
    Node* derecha = medio->getNext();
    medio->setNext(nullptr);
    Node* izquierdaOrdenada = ordenarNodos(inicio);
    Node* derechaOrdenada = ordenarNodos(derecha);
    return combinarNodos(izquierdaOrdenada, derechaOrdenada);
}

Node* MergeSort::combinarNodos(Node* izquierda, Node* derecha){
    if (izquierda == nullptr){
        return derecha;
    }
    if (derecha == nullptr){
        return izquierda;
    }
    if (izquierda->getDato() <= derecha->getDato()){
        izquierda->setNext(combinarNodos(izquierda->getNext(), derecha));
        return izquierda;
    }
    else{
        derecha->setNext(combinarNodos(izquierda, derecha->getNext()));
        return derecha;
    }
}

Node* MergeSort::obtenerMedio(Node* inicio){
    Node* lento = inicio;
    Node* rapido = inicio->getNext();
    while (rapido != nullptr && rapido->getNext() != nullptr){
        lento = lento->getNext();
        rapido = rapido->getNext()->getNext();
    }

    return lento;
}