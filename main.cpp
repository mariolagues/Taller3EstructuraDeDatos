#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "BubbleSort/BubbleSort.h"
#include "MergeSort/MergeSort.h"
#include "HeapSort/HeapSort.h"
#include "GeneradorDatos/GeneradorDatos.h"
using namespace std;

int main() {

    srand(time(NULL));

    int cantidad = 10;

    vector<int> v = GeneradorDatos::generarAleatorio(cantidad);

    cout << "Vector generado:" << endl;

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl << endl;

    BubbleSort::ordenar(v);

    cout << "Vector ordenado con Bubble Sort:" << endl;

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << endl;

    return 0;
}