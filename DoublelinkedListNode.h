#include<iostream>
using namespace std;
template<typename T>
class DoublelinkedListNode{
public:
    T data;
    DoublelinkedListNode<T> *next;
    DoublelinkedListNode<T> *prev;
    DoublelinkedListNode<T>(){
        data=0;
        next=nullptr;
        prev=nullptr;
    }
};