#include "Pruebas/Pruebas.h"

int main(){

    Pruebas::probarVector(2, 3, 10000);
    Pruebas::probarVector(1, 1, 100);
    Pruebas::probarVector(2, 1, 100);
    Pruebas::probarVector(3, 1, 100);

    Pruebas::probarLinkedList(1, 1, 100);
    Pruebas::probarLinkedList(2, 1, 100);
    Pruebas::probarLinkedList(3, 1, 100);

    return 0;
}