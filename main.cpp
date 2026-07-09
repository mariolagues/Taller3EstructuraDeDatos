#include <iostream>

#include "BubbleSort/BubbleSort.h"
#include "MergeSort/MergeSort.h"
#include "HeapSort/HeapSort.h"
using namespace std;

int main() {
    vector<int> v = {8, 5, 2, 9, 1, 4, 7, 6, 3};

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    cout << " " << endl;

    BubbleSort::ordenar(v);

    for (int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}