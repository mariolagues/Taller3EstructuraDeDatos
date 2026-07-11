#include "Metricas.h"

Metricas::Metricas(){
    reiniciar();
}

void Metricas::reiniciar(){
    this->comparaciones = 0;
    this->movimientos = 0;
    this->memoriaBytes = 0;
    this->tiempoNanosegundos = 0;
    this->correcto = false;
}

void Metricas::sumarComparacion(){

    this->comparaciones++;
}

void Metricas::sumarMovimiento(){

    this->movimientos++;
}

void Metricas::sumarMovimientos(long long cantidad){

    this->movimientos += cantidad;
}

void Metricas::setMemoriaBytes(long long memoriaBytes){

    this->memoriaBytes = memoriaBytes;
}

void Metricas::setTiempoNanosegundos(double tiempoNanosegundos){

    this->tiempoNanosegundos = tiempoNanosegundos;
}

void Metricas::setCorrecto(bool correcto){

    this->correcto = correcto;
}

long long Metricas::getComparaciones(){

    return this->comparaciones;
}

long long Metricas::getMovimientos(){

    return this->movimientos;
}

long long Metricas::getMemoriaBytes(){

    return this->memoriaBytes;
}

double Metricas::getTiempoNanosegundos(){

    return this->tiempoNanosegundos;
}

bool Metricas::getCorrecto(){

    return this->correcto;
}