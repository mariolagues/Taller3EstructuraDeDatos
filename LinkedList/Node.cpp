#include "Node.h"

Node::Node(int dato){
    this->dato = dato;
    this->next = nullptr;
}

Node::~Node(){
}

int Node::getDato(){
    return this->dato;
}

void Node::setDato(int dato){
    this->dato = dato;
}

Node* Node::getNext(){
    return this->next;
}

void Node::setNext(Node* next){
    this->next = next;
}