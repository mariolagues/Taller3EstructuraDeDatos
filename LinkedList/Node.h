#pragma once

class Node {
private:
    int dato;
    Node* next;

public:
    Node(int dato);
    ~Node();

    int getDato();
    void setDato(int dato);

    Node* getNext();
    void setNext(Node* next);
};