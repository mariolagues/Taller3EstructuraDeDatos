#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"

class MergeSort {
private:
    static void dividir(Vector& v, int izquierda, int derecha);
    static void combinar(Vector& v, int izquierda, int medio, int derecha);
    static Node* ordenarNodos(Node* inicio);
    static Node* combinarNodos(Node* izquierda, Node* derecha);
    static Node* obtenerMedio(Node* inicio);
    
public:
    static void ordenar(Vector& v);
    static void ordenar(LinkedList& lista);
};