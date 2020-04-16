#include<iostream>
#include "LinkedList.h"
#include "DoublelinkedList.h"
#include "circularlinkedList.h"
#include "Queue.h"
using namespace std;
int main(){

    LinkedList<int>* l1=new LinkedList<int>();
    l1->push_front(1);
    l1->push_front(2);
    l1->push_front(3);
    l1->push_front(4);
    l1->push_back(5);
    l1->pop_front();
    l1->pop_back();
    l1->print();
    cout<<"----------------------"<<"\n";
    DoublelinkedList<int>* d1=new DoublelinkedList<int>();
    d1->push_front(1);
    d1->push_front(2);
    d1->push_front(3);
    d1->push_back(2);
    d1->push_back(2);
    d1->print();
    d1->pop_front();
    d1->print();
    d1->search(1);
    cout<<"----------------------"<<"\n";

    //circular_linked_list<int>* c1= new circular_linked_list<int>();
    //c1->push_front(2);
    //c1->push_front(1);
    //c1->push_front(3);
    Queue<int>* q1 = new Queue<int>();
    q1->push_back(1);
    q1->push_back(2);
    q1->push_back(3);
    q1->push_back(4);
    q1->push_back(5);
    q1->print();
    q1->obtenerPrimero();
    q1->removerPrimero();
    
    return 0;
}