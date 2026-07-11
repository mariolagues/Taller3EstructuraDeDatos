#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"
#include "../Metricas/Metricas.h"

class MergeSort {
private:
    static void dividir(Vector& v, int izquierda, int derecha, Metricas& metricas);
    static void combinar(Vector& v, int izquierda, int medio, int derecha, Metricas& metricas);

    static Node* ordenarNodos(Node* inicio, Metricas& metricas);
    static Node* combinarNodos(Node* izquierda, Node* derecha, Metricas& metricas);
    static Node* obtenerMedio(Node* inicio);

public:
    static void ordenar(Vector& v, Metricas& metricas);
    static void ordenar(LinkedList& lista, Metricas& metricas);
};