#include<iostream>
#include<stdlib.h>
#include "circularNode.h"
using namespace std;
template<typename T>
class circular_linked_list{

    circularNode<T>* head;
    int nodos;
public:
    circular_linked_list()
    {
        this->head=nullptr;
        nodos=0;
    }
    void print();
    bool empty();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();

};
template<typename T>
void circular_linked_list<T>::print()
{
    circularNode<T>* nodoaimprimir = new circularNode<T>;
    nodoaimprimir = this->head;
	if (nodos == 1)
		cout << nodoaimprimir->data;
	else if (nodos == 0)
	{
		cout << "Lista vacia";
	}
	else
	{
		while (nodoaimprimir != nullptr) {
			cout << nodoaimprimir->data << " ";
			nodoaimprimir = nodoaimprimir->next;
		}
	}
	cout << endl;
}
template<typename T>
bool circular_linked_list<T>::empty()
{
    circularNode<T>* tmp = new circularNode<T>;
    this->head = tmp;
    if (tmp == nullptr) {return true;}
    else {return false;}
        }

template<typename T>
void circular_linked_list<T>::push_front(T value)
{
    circularNode<T> *temp = new circularNode<T>;
    temp -> data = value;
    temp -> next = this-> head -> next;
    this->head -> next = temp;
}

template<typename T>
void circular_linked_list<T>::push_back(T value)
{
    circularNode<T>* newNode = new circularNode<T>();
    newNode->data = value;
    newNode->next = this->head;
    if (this->head=nullptr) {
        this->head = newNode;
        this->head->next = newNode;
        this->head->prev = newNode;
       } 
    else {
    this->head->prev->next = newNode;
    newNode->prev = this->head->prev;
    this->head->prev = newNode;
    }
    nodos++;
}
template<typename T>
void circular_linked_list<T>::pop_front()
{
if (this->head != nullptr) {
    circularNode<T>* tmp = new circularNode<T>;
    this->head = tmp;
    nodos--;
    if (nodos == 0) 
        this->head = nullptr;
    else {
    this->head->prev->next = this->head->next;
    this->head->next->prev = this->head->prev;
    this->head = this->head->next;
    }
    delete tmp;
    }
}

template<typename T>
void circular_linked_list<T>::pop_back() 
{
    if (this->head != nullptr) 
    {
    circularNode<T>* tmp = new circularNode<T>;
    this->head->prev = tmp;
    nodos--;
    if (nodos == 0) 
        this->head = nullptr;
    else 
    {
    this->head->prev->prev->next = this->head;
    this->head->prev = this->head->prev->prev;
    }
    delete tmp;
    }
}

