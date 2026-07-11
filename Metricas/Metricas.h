#pragma once

class Metricas {
private:
    long long comparaciones;
    long long movimientos;
    long long memoriaBytes;
    double tiempoNanosegundos;
    bool correcto;

public:
    Metricas();

    void reiniciar();

    void sumarComparacion();
    void sumarMovimiento();
    void sumarMovimientos(long long cantidad);

    void setMemoriaBytes(long long memoriaBytes);
    void setTiempoNanosegundos(double tiempoNanosegundos);
    void setCorrecto(bool correcto);

    long long getComparaciones();
    long long getMovimientos();
    long long getMemoriaBytes();
    double getTiempoNanosegundos();
    bool getCorrecto();
    
};