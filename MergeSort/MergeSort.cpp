#include "MergeSort.h"

void MergeSort::ordenar(Vector& v, Metricas& metricas){
    if (v.getCantidad() > 1){
        dividir(v, 0, v.getCantidad() - 1, metricas);
    }
    metricas.setMemoriaBytes(sizeof(int) * v.getCantidad());
}

void MergeSort::dividir(Vector& v, int izquierda, int derecha, Metricas& metricas){
    if (izquierda < derecha){
        int medio = izquierda + (derecha - izquierda) / 2;
        dividir(v, izquierda, medio, metricas);
        dividir(v, medio + 1, derecha, metricas);
        combinar(v, izquierda, medio, derecha, metricas);
    }
}

void MergeSort::combinar(Vector& v, int izquierda, int medio, int derecha, Metricas& metricas){
    int cantidadIzquierda = medio - izquierda + 1;
    int cantidadDerecha = derecha - medio;
    int* vectorIzquierda = new int[cantidadIzquierda];
    int* vectorDerecha = new int[cantidadDerecha];

    for (int i = 0; i < cantidadIzquierda; i++){
        vectorIzquierda[i] = v.getDato(izquierda + i);
        metricas.sumarMovimiento();
    }
    for (int j = 0; j < cantidadDerecha; j++){
        vectorDerecha[j] = v.getDato(medio + 1 + j);
        metricas.sumarMovimiento();
    }
    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < cantidadIzquierda && j < cantidadDerecha){
        metricas.sumarComparacion();
        if (vectorIzquierda[i] <= vectorDerecha[j]){
            v.setDato(k, vectorIzquierda[i]);
            i++;
        }
        else{
            v.setDato(k, vectorDerecha[j]);
            j++;
        }
        metricas.sumarMovimiento();
        k++;
    }

    while (i < cantidadIzquierda){
        v.setDato(k, vectorIzquierda[i]);
        metricas.sumarMovimiento();
        i++;
        k++;
    }

    while (j < cantidadDerecha){
        v.setDato(k, vectorDerecha[j]);
        metricas.sumarMovimiento();
        j++;
        k++;
    }

    delete[] vectorIzquierda;
    delete[] vectorDerecha;
}

void MergeSort::ordenar(LinkedList& lista, Metricas& metricas){
    lista.setInicio(ordenarNodos(lista.getInicio(), metricas));
    metricas.setMemoriaBytes(sizeof(Node*) * 6);
}

Node* MergeSort::ordenarNodos(Node* inicio, Metricas& metricas){
    if (inicio == nullptr || inicio->getNext() == nullptr){
        return inicio;
    }
    Node* medio = obtenerMedio(inicio);
    Node* derecha = medio->getNext();
    medio->setNext(nullptr);
    metricas.sumarMovimiento();
    Node* izquierdaOrdenada = ordenarNodos(inicio, metricas);
    Node* derechaOrdenada = ordenarNodos(derecha, metricas);
    return combinarNodos(izquierdaOrdenada, derechaOrdenada, metricas);
}

Node* MergeSort::combinarNodos(Node* izquierda, Node* derecha, Metricas& metricas){
    if (izquierda == nullptr){
        return derecha;
    }
    if (derecha == nullptr){
        return izquierda;
    }
    metricas.sumarComparacion();
    if (izquierda->getDato() <= derecha->getDato()){
        izquierda->setNext(
            combinarNodos(izquierda->getNext(), derecha, metricas)
        );
        metricas.sumarMovimiento();
        return izquierda;
    }
    else{
        derecha->setNext(
            combinarNodos(izquierda, derecha->getNext(), metricas)
        );
        metricas.sumarMovimiento();
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