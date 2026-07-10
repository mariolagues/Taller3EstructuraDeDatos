#include "GeneradorDatos.h"
#include <cstdlib>
using namespace std;

vector<int> GeneradorDatos::generarAleatorio(int cantidad){

    vector<int> v;

    for (int i = 0; i < cantidad; i++){
        v.push_back(rand() % cantidad + 1);
    }

    return v;
}

vector<int> GeneradorDatos::generarAscendente(int cantidad){

    vector<int> v;

    for (int i = 1; i <= cantidad; i++){
        v.push_back(i);
    }

    return v;
}

vector<int> GeneradorDatos::generarDescendente(int cantidad){

    vector<int> v;

    for (int i = cantidad; i >= 1; i--){
        v.push_back(i);
    }

    return v;
}