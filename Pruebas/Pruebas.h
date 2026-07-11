#pragma once

class Pruebas {
private:
    static int obtenerRepeticiones(int cantidad);
    static void mostrarResultados(
        const char* algoritmo,
        const char* estructura,
        const char* tipoDatos,
        int cantidad,
        int repeticiones,
        double tiempoPromedio,
        long long comparacionesPromedio,
        long long movimientosPromedio,
        long long memoriaBytes,
        bool correcto
    );

public:
    static void probarVector(int algoritmo, int tipoDatos, int cantidad);
    static void probarLinkedList(int algoritmo, int tipoDatos, int cantidad);
};