#include <iostream>
#include "nodoQueue.h"
using namespace std;
template<typename T>
class Queue{
    nodoQueue<T>* head;
public:
    Queue(){
        this->head=nullptr;
    }
    void print();
    bool empty();
    void push_back(T value);
    void obtenerPrimero();
    void removerPrimero();
};

template<typename T>
void Queue<T>::print()
{
    if(this->head==nullptr)
    {
        cout << "Lista vacia " << endl;
    }
    else
    {
        cout << "El queue es el siguiente: ";
        nodoQueue<T> *temporal = new nodoQueue<T>;
        temporal = this->head;
        //While the next node is not the head (circular)
        while(temporal->next != this->head)
        {
            //Display value + ' '
            cout << temporal->data << " ";
            //Move temp to next node
            temporal = temporal->next;
        }
        //Print last value
        cout << temporal->data << endl;
    }
}
template<typename T>
bool Queue<T>::empty()
{
    if(this->head == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}
template<typename T>
void Queue<T>::push_back(T value)
{
    nodoQueue<T>* newNode = new nodoQueue<T>;
    newNode->data = value;
    cout<< "Se ha anadido el valor al queue "<< value << "\n";
    if(this->head==nullptr){
        newNode->next = newNode;
        newNode->prev = newNode;
        this->head = newNode;
    }
    else{
        nodoQueue<T> *temporal = new nodoQueue<T>;
        temporal = this->head;
        temporal = temporal->prev;
        newNode->next = head;
        newNode->prev = temporal;
        temporal->next = newNode;
        this->head->prev = newNode;;
    }

}
template<typename T>
void Queue<T>::obtenerPrimero()
{
    nodoQueue<T> *temporal = new nodoQueue<T>;
    temporal= this->head;
    if(this->head=nullptr)
    {
        cout<<"No hay valores"<<"\n";
    }
    else
    {
        cout<< "El primer valor es: "<< temporal->data << "\n";
    }
}
template<typename T>
void Queue<T>::removerPrimero()
{   
    if(this->head==nullptr)
    {
        cout << "Lista vacia" << endl;
        return;
    }
    else if(this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
    }
        //If list has more than one element
    else
    {
        nodoQueue<T> *temporal = new nodoQueue<T>;
        nodoQueue<T> *nuevolider = new nodoQueue<T>;
        temporal = this->head;
        nuevolider = this->head->next;
        nuevolider->prev = temporal->prev;
        temporal->prev->next = nuevolider;
        this->head = nuevolider;
        delete(temporal);
    }
}
