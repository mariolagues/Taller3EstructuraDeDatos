#include <iostream>
#include <cstdlib>
#include <ctime>

#include "LinkedList/LinkedList.h"
#include "GeneradorDatos/GeneradorDatos.h"
#include "BubbleSort/BubbleSort.h"
#include "MergeSort/MergeSort.h"
#include "HeapSort/HeapSort.h"

using namespace std;

void imprimirLista(LinkedList& lista){

    Node* actual = lista.getInicio();

    while (actual != nullptr){
        cout << actual->getDato() << " ";
        actual = actual->getNext();
    }

    cout << endl;
}

int main(){

    srand(time(NULL));

    int cantidad = 10;

    LinkedList bubble;
    LinkedList merge;
    LinkedList heap;

    GeneradorDatos::generarAleatorio(bubble, cantidad);
    GeneradorDatos::generarAleatorio(merge, cantidad);
    GeneradorDatos::generarAleatorio(heap, cantidad);

    cout << "lista bubble antes:" << endl;
    imprimirLista(bubble);

    BubbleSort::ordenar(bubble);

    cout << "lista bubble despues:" << endl;
    imprimirLista(bubble);

    cout << endl << "lista merge antes:" << endl;
    imprimirLista(merge);

    MergeSort::ordenar(merge);

    cout << "lista merge despues:" << endl;
    imprimirLista(merge);

    cout << endl << "lista heap antes:" << endl;
    imprimirLista(heap);

    HeapSort::ordenar(heap);

    cout << "lista heap despues:" << endl;
    imprimirLista(heap);

    return 0;
}