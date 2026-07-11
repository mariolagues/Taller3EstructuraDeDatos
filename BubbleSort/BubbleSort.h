#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"
#include "../Metricas/Metricas.h"

class BubbleSort {
public:
    static void ordenar(Vector& v,  Metricas& metricas);
    static void ordenar(LinkedList& lista,  Metricas& metricas);
};