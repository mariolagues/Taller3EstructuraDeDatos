#include "HeapSort.h"

void HeapSort::ordenar(Vector& v){
    int cantidad = v.getCantidad();

    for (int i = cantidad / 2 - 1; i >= 0; i--){
        construirHeap(v, cantidad, i);
    }

    for (int i = cantidad - 1; i > 0; i--){

        int aux = v.getDato(0);
        v.setDato(0, v.getDato(i));
        v.setDato(i, aux);

        construirHeap(v, i, 0);
    }

}
void HeapSort::construirHeap(Vector& v, int cantidad, int raiz) {
    int mayor = raiz;
    int izquierdo = 2 * raiz + 1;
    int derecho = 2 * raiz + 2;

    if (izquierdo < cantidad && v.getDato(izquierdo) > v.getDato(mayor)){
        mayor = izquierdo;
    }

    if (derecho < cantidad && v.getDato(derecho) > v.getDato(mayor)){
        mayor = derecho;
    }

    if (mayor != raiz){

        int aux = v.getDato(raiz);
        v.setDato(raiz, v.getDato(mayor));
        v.setDato(mayor, aux);

        construirHeap(v, cantidad, mayor);
    }
}

void HeapSort::ordenar(LinkedList& lista){
    int cantidad = lista.getCantidad();
    for (int i = cantidad / 2 - 1; i >= 0; i--){
        construirHeap(lista, cantidad, i);
    }
    for (int i = cantidad - 1; i > 0; i--){

        int aux = lista.getDato(0);
        lista.setDato(0, lista.getDato(i));
        lista.setDato(i, aux);

        construirHeap(lista, i, 0);
    }
}

void HeapSort::construirHeap(LinkedList& lista, int cantidad, int raiz){
    int mayor = raiz;
    int izquierdo = 2 * raiz + 1;
    int derecho = 2 * raiz + 2;

    if (izquierdo < cantidad &&
        lista.getDato(izquierdo) > lista.getDato(mayor)){
        mayor = izquierdo;
        }
    if (derecho < cantidad &&
        lista.getDato(derecho) > lista.getDato(mayor)){
        mayor = derecho;
        }
    if (mayor != raiz){

        int aux = lista.getDato(raiz);
        lista.setDato(raiz, lista.getDato(mayor));
        lista.setDato(mayor, aux);

        construirHeap(lista, cantidad, mayor);
    }
}