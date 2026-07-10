#include "MergeSort.h"
using namespace std;

void MergeSort::ordenar(vector<int>& v){
    if (v.size() > 1){
        dividir(v, 0, v.size() - 1);
    }
}

void MergeSort::dividir(vector<int>& v, int izquierda, int derecha){

    if (izquierda < derecha){

        int medio = (izquierda + derecha) / 2;

        dividir(v, izquierda, medio);
        dividir(v, medio + 1, derecha);

        combinar(v, izquierda, medio, derecha);
    }
}

void MergeSort::combinar(vector<int>& v, int izquierda, int medio, int derecha){

    int cantidadIzquierda = medio - izquierda + 1;
    int cantidadDerecha = derecha - medio;

    vector<int> vectorIzquierda(cantidadIzquierda);
    vector<int> vectorDerecha(cantidadDerecha);

    for (int i = 0; i < cantidadIzquierda; i++){
        vectorIzquierda[i] = v[izquierda + i];
    }

    for (int j = 0; j < cantidadDerecha; j++){
        vectorDerecha[j] = v[medio + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = izquierda;

    while (i < cantidadIzquierda && j < cantidadDerecha){

        if (vectorIzquierda[i] <= vectorDerecha[j]){
            v[k] = vectorIzquierda[i];
            i++;
        }
        else{
            v[k] = vectorDerecha[j];
            j++;
        }

        k++;
    }

    while (i < cantidadIzquierda){
        v[k] = vectorIzquierda[i];
        i++;
        k++;
    }

    while (j < cantidadDerecha){
        v[k] = vectorDerecha[j];
        j++;
        k++;
    }
}