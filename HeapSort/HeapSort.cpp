#include "HeapSort.h"

void HeapSort::ordenar(Vector& v, Metricas& metricas){
    int cantidad = v.getCantidad();
    for (int i = cantidad / 2 - 1; i >= 0; i--){
        construirHeap(v, cantidad, i, metricas);
    }

    for (int i = cantidad - 1; i > 0; i--){
        int aux = v.getDato(0);
        v.setDato(0, v.getDato(i));
        v.setDato(i, aux);
        metricas.sumarMovimientos(3);
        construirHeap(v, i, 0, metricas);
    }
    metricas.setMemoriaBytes(sizeof(int) * 5);
}

void HeapSort::construirHeap(Vector& v, int cantidad, int raiz, Metricas& metricas){

    int mayor = raiz;
    int izquierdo = 2 * raiz + 1;
    int derecho = 2 * raiz + 2;

    if (izquierdo < cantidad){
        metricas.sumarComparacion();
        if (v.getDato(izquierdo) > v.getDato(mayor)){
            mayor = izquierdo;
        }
    }

    if (derecho < cantidad){
        metricas.sumarComparacion();
        if (v.getDato(derecho) > v.getDato(mayor)){
            mayor = derecho;
        }
    }

    if (mayor != raiz){
        int aux = v.getDato(raiz);
        v.setDato(raiz, v.getDato(mayor));
        v.setDato(mayor, aux);
        metricas.sumarMovimientos(3);
        construirHeap(v, cantidad, mayor, metricas);
    }
}

void HeapSort::ordenar(LinkedList& lista, Metricas& metricas){

    int cantidad = lista.getCantidad();
    for (int i = cantidad / 2 - 1; i >= 0; i--){
        construirHeap(lista, cantidad, i, metricas);
    }

    for (int i = cantidad - 1; i > 0; i--){

        int aux = lista.getDato(0);
        lista.setDato(0, lista.getDato(i));
        lista.setDato(i, aux);
        metricas.sumarMovimientos(3);
        construirHeap(lista, i, 0, metricas);
    }
    metricas.setMemoriaBytes(sizeof(int) * 5 + sizeof(Node*) * 2);
}

void HeapSort::construirHeap(LinkedList& lista, int cantidad, int raiz, Metricas& metricas){

    int mayor = raiz;
    int izquierdo = 2 * raiz + 1;
    int derecho = 2 * raiz + 2;
    if (izquierdo < cantidad){
        metricas.sumarComparacion();
        if (lista.getDato(izquierdo) > lista.getDato(mayor)){
            mayor = izquierdo;
        }
    }

    if (derecho < cantidad){
        metricas.sumarComparacion();
        if (lista.getDato(derecho) > lista.getDato(mayor)){
            mayor = derecho;
        }
    }

    if (mayor != raiz){
        int aux = lista.getDato(raiz);
        lista.setDato(raiz, lista.getDato(mayor));
        lista.setDato(mayor, aux);
        metricas.sumarMovimientos(3);
        construirHeap(lista, cantidad, mayor, metricas);
    }
}