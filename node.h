#include<iostream>
using namespace std;
template <typename T>
class Node {
public:
    T data;
    Node<T> *next;

};