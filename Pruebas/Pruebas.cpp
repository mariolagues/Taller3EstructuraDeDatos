#include "Pruebas.h"

#include <iostream>
#include <chrono>
#include <iomanip>
#include <cstdlib>

#include "../Vector/Vector.h"
#include "../LinkedList/LinkedList.h"
#include "../GeneradorDatos/GeneradorDatos.h"
#include "../BubbleSort/BubbleSort.h"
#include "../MergeSort/MergeSort.h"
#include "../HeapSort/HeapSort.h"
#include "../Metricas/Metricas.h"
#include "../Validador/Validador.h"

using namespace std;
using namespace std::chrono;

int Pruebas::obtenerRepeticiones(int cantidad){
    if (cantidad <= 1000){
        return 20;
    }
    if (cantidad <= 10000){
        return 10;
    }
    if (cantidad <= 100000){
        return 3;
    }
    return 1;
}

void Pruebas::mostrarResultados(
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
){

    cout << fixed << setprecision(3);

    cout << endl;
    cout << "RESULTADO PRUEBA" << endl;
    cout << "Algoritmo: " << algoritmo << endl;
    cout << "Estructura: " << estructura << endl;
    cout << "Tipo de datos: " << tipoDatos << endl;
    cout << "Cantidad: " << cantidad << endl;
    cout << "Repeticiones: " << repeticiones << endl;
    cout << "----------------------------------------" << endl;
    cout << "Tiempo promedio: " << tiempoPromedio << " ns" << endl;
    cout << "Tiempo promedio: " << tiempoPromedio / 1000000.0 << " ms" << endl;
    cout << "Comparaciones promedio: " << comparacionesPromedio << endl;
    cout << "Movimientos promedio: " << movimientosPromedio << endl;
    cout << "Memoria auxiliar estimada: " << memoriaBytes << " bytes" << endl;
    cout << "Correctitud: " << (correcto ? "CORRECTO" : "INCORRECTO") << endl;
}

void Pruebas::probarVector(int algoritmo, int tipoDatos, int cantidad){
    int repeticiones = obtenerRepeticiones(cantidad);
    double tiempoTotal = 0;
    long long comparacionesTotal = 0;
    long long movimientosTotal = 0;
    long long memoriaBytes = 0;
    bool correcto = true;
    const char* nombreAlgoritmo;
    const char* nombreTipoDatos;

    if (algoritmo == 1){
        nombreAlgoritmo = "Bubble Sort";
    }
    else if (algoritmo == 2){
        nombreAlgoritmo = "Merge Sort";
    }
    else{
        nombreAlgoritmo = "Heap Sort";
    }

    if (tipoDatos == 1){
        nombreTipoDatos = "Aleatorio";
    }
    else if (tipoDatos == 2){
        nombreTipoDatos = "Ascendente";
    }
    else{
        nombreTipoDatos = "Descendente";
    }
    for (int repeticion = 0; repeticion < repeticiones; repeticion++){
        Vector v(cantidad);
        if (tipoDatos == 1){
            srand(1234);
            GeneradorDatos::generarAleatorio(v);
        }
        else if (tipoDatos == 2){
            GeneradorDatos::generarAscendente(v);
        }
        else{
            GeneradorDatos::generarDescendente(v);
        }
        Metricas metricas;
        auto inicio = steady_clock::now();
        if (algoritmo == 1){
            BubbleSort::ordenar(v, metricas);
        }
        else if (algoritmo == 2){
            MergeSort::ordenar(v, metricas);
        }
        else{
            HeapSort::ordenar(v, metricas);
        }
        auto fin = steady_clock::now();
        double tiempo = duration<double, nano>(fin - inicio).count();
        tiempoTotal += tiempo;
        comparacionesTotal += metricas.getComparaciones();
        movimientosTotal += metricas.getMovimientos();
        memoriaBytes = metricas.getMemoriaBytes();

        if (!Validador::estaOrdenado(v)){
            correcto = false;
        }
    }

    mostrarResultados(
        nombreAlgoritmo,
        "Vector",
        nombreTipoDatos,
        cantidad,
        repeticiones,
        tiempoTotal / repeticiones,
        comparacionesTotal / repeticiones,
        movimientosTotal / repeticiones,
        memoriaBytes,
        correcto
    );
}

void Pruebas::probarLinkedList(int algoritmo, int tipoDatos, int cantidad){
    int repeticiones = obtenerRepeticiones(cantidad);
    double tiempoTotal = 0;
    long long comparacionesTotal = 0;
    long long movimientosTotal = 0;
    long long memoriaBytes = 0;
    bool correcto = true;
    const char* nombreAlgoritmo;
    const char* nombreTipoDatos;
    if (algoritmo == 1){
        nombreAlgoritmo = "Bubble Sort";
    }
    else if (algoritmo == 2){
        nombreAlgoritmo = "Merge Sort";
    }
    else{
        nombreAlgoritmo = "Heap Sort";
    }
    if (tipoDatos == 1){
        nombreTipoDatos = "Aleatorio";
    }
    else if (tipoDatos == 2){
        nombreTipoDatos = "Ascendente";
    }
    else{
        nombreTipoDatos = "Descendente";
    }
    for (int repeticion = 0; repeticion < repeticiones; repeticion++){
        LinkedList lista;
        if (tipoDatos == 1){
            srand(1234);
            GeneradorDatos::generarAleatorio(lista, cantidad);
        }
        else if (tipoDatos == 2){
            GeneradorDatos::generarAscendente(lista, cantidad);
        }
        else{
            GeneradorDatos::generarDescendente(lista, cantidad);
        }

        Metricas metricas;
        auto inicio = steady_clock::now();
        if (algoritmo == 1){
            BubbleSort::ordenar(lista, metricas);
        }
        else if (algoritmo == 2){
            MergeSort::ordenar(lista, metricas);
        }
        else{
            HeapSort::ordenar(lista, metricas);
        }
        auto fin = steady_clock::now();
        double tiempo = duration<double, nano>(fin - inicio).count();
        tiempoTotal += tiempo;
        comparacionesTotal += metricas.getComparaciones();
        movimientosTotal += metricas.getMovimientos();
        memoriaBytes = metricas.getMemoriaBytes();
        if (!Validador::estaOrdenado(lista)){
            correcto = false;
        }
    }
    mostrarResultados(
        nombreAlgoritmo,
        "LinkedList",
        nombreTipoDatos,
        cantidad,
        repeticiones,
        tiempoTotal / repeticiones,
        comparacionesTotal / repeticiones,
        movimientosTotal / repeticiones,
        memoriaBytes,
        correcto
    );
}