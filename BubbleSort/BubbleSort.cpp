#include "BubbleSort.h"
using namespace std;

void BubbleSort::ordenar(vector<int>& v) {

    for (int i = 0; i < v.size() - 1; i++){
        for (int j = 0; j < v.size() - i - 1; j++){
            if (v[j] > v[j + 1]){
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
            }
        }
    }
}
