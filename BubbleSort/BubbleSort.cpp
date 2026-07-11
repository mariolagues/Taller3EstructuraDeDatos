#include "BubbleSort.h"

void BubbleSort::ordenar(Vector& v, Metricas& metricas){
    for (int i = 0; i < v.getCantidad() - 1; i++){
        for (int j = 0; j < v.getCantidad() - i - 1; j++){
            metricas.sumarComparacion();
            if (v.getDato(j) > v.getDato(j + 1)){
                int aux = v.getDato(j);
                v.setDato(j, v.getDato(j + 1));
                v.setDato(j + 1, aux);
                metricas.sumarMovimientos(3);
            }
        }
    }
    metricas.setMemoriaBytes(sizeof(int));
}

void BubbleSort::ordenar(LinkedList& lista, Metricas& metricas){
    for (int i = 0; i < lista.getCantidad() - 1; i++){
        Node* actual = lista.getInicio();
        for (int j = 0; j < lista.getCantidad() - i - 1; j++){
            Node* siguiente = actual->getNext();
            metricas.sumarComparacion();
            if (actual->getDato() > siguiente->getDato()){
                int aux = actual->getDato();
                actual->setDato(siguiente->getDato());
                siguiente->setDato(aux);
                metricas.sumarMovimientos(3);
            }
            actual = actual->getNext();
        }
    }
    metricas.setMemoriaBytes(sizeof(int) + sizeof(Node*) * 2);
}