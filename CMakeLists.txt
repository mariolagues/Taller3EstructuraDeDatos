cmake_minimum_required(VERSION 4.2)
project(Taller3EstructuraDeDatos)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller3EstructuraDeDatos main.cpp
        BubbleSort/BubbleSort.h
        BubbleSort/BubbleSort.cpp
        MergeSort/MergeSort.h
        MergeSort/MergeSort.cpp
        HeapSort/HeapSort.h
        HeapSort/HeapSort.cpp
        GeneradorDatos/GeneradorDatos.h
        GeneradorDatos/GeneradorDatos.cpp
        Vector/Vector.h
        Vector/Vector.cpp
        LinkedList/Node.h
        LinkedList/Node.cpp
        LinkedList/LinkedList.h
        LinkedList/LinkedList.cpp
)
