#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"
#include "../Metricas/Metricas.h"

class HeapSort {
private:
    static void construirHeap(Vector& v, int cantidad, int raiz, Metricas& metricas);
    static void construirHeap(LinkedList& lista, int cantidad, int raiz, Metricas& metricas);

public:
    static void ordenar(Vector& v, Metricas& metricas);
    static void ordenar(LinkedList& lista, Metricas& metricas);
};