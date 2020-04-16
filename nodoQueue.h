#include<iostream>
using namespace std;
template<typename T>
class nodoQueue{
public:
    T data;
    nodoQueue<T> *next;
    nodoQueue<T> *prev;
    nodoQueue<T>(){
    data=0;
    next=nullptr;
    prev=nullptr;
    }
};