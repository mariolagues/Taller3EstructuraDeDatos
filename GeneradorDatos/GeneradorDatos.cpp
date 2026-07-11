#include "GeneradorDatos.h"
#include <cstdlib>
using namespace std;

void GeneradorDatos::generarAleatorio(Vector& v){

    for (int i = 0; i < v.getCantidad(); i++){
        v.setDato(i, rand() % v.getCantidad() + 1);
    }
}

void GeneradorDatos::generarAscendente(Vector& v){

    for (int i = 0; i < v.getCantidad(); i++){
        v.setDato(i, i + 1);
    }
}

void GeneradorDatos::generarDescendente(Vector& v){

    int numero = v.getCantidad();

    for (int i = 0; i < v.getCantidad(); i++){
        v.setDato(i, numero);
        numero--;
    }
}

void GeneradorDatos::generarAleatorio(LinkedList& lista, int cantidad){

    for (int i = 0; i < cantidad; i++){
        lista.agregarInicio(rand() % cantidad + 1);
    }
}

void GeneradorDatos::generarAscendente(LinkedList& lista, int cantidad){

    for (int i = cantidad; i >= 1; i--){
        lista.agregarInicio(i);
    }
}

void GeneradorDatos::generarDescendente(LinkedList& lista, int cantidad){

    for (int i = 1; i <= cantidad; i++){
        lista.agregarInicio(i);
    }
}