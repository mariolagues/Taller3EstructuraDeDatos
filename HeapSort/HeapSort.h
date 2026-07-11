#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"


class HeapSort {
private:
    static void construirHeap(Vector& v, int cantidad, int raiz);
    static void construirHeap(LinkedList& lista, int cantidad, int raiz);

public:
    static void ordenar(Vector& v);
    static void ordenar(LinkedList& lista);
};