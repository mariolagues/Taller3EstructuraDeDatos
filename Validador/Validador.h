#pragma once
#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"

class Validador {
public:
    static bool estaOrdenado(Vector& v);
    static bool estaOrdenado(LinkedList& lista);
};