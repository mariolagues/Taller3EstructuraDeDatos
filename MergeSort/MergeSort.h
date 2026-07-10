#pragma once
#include <vector>

class MergeSort {
    private:
    static void dividir(std::vector<int>& v, int izquierda, int derecha);
    static void combinar(std::vector<int>& v, int izquierda, int medio, int derecha);
    
    public:
    static void ordenar(std::vector<int> &v);
};