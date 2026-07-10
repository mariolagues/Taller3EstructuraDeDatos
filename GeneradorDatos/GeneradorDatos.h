#pragma once
#include <vector>

class GeneradorDatos {
    public:
    static std::vector<int> generarAleatorio(int cantidad);

    static std::vector<int> generarAscendente(int cantidad);

    static std::vector<int> generarDescendente(int cantidad);
};