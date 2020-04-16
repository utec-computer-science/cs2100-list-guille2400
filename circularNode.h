#include<iostream>
using namespace std;
template<typename T>
class circularNode{
public:
    T data;
    circularNode<T> *next;
    circularNode<T> *prev;
    circularNode<T>(){
        data=0;
        next=nullptr;
        prev=nullptr;
    }
};