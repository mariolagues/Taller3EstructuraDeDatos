#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"

class GeneradorDatos {
public:
    static void generarAleatorio(Vector& v);
    static void generarAscendente(Vector& v);
    static void generarDescendente(Vector& v);

    static void generarAleatorio(LinkedList& lista, int cantidad);
    static void generarAscendente(LinkedList& lista, int cantidad);
    static void generarDescendente(LinkedList& lista, int cantidad);


};