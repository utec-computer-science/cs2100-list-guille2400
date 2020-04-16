#include<iostream>
#include "node.h"
using namespace std;
template<typename T>
class LinkedList{
    Node<T> *head;
    int nodos;
public:
    LinkedList()
    { 
        this->head=nullptr;
        nodos=0;
        }
    void print();
    void push_front(T value);
    void push_back(T value);
    void insertAtMid();
    void pop_front();
    void pop_back();
    void delFromMid();
    void search(int index);

};
template<typename T>
void LinkedList<T>::print()
{
    Node<T>* nodoaimprimir = new Node<T>;
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
void LinkedList<T>:: push_front(T value){
    if(this->head==nullptr)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        cout<<"Creando lista y anadiendo al frente: " << newNode->data << "\n";
        this->head = newNode;
    }
    else
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        cout<<"Valor anadido al frente: " << newNode->data << "\n";
        newNode->next = this->head; // Uniendo nodo nuevo con el primero
        this->head = newNode;

    }
    nodos++;
}

template<typename T>
void LinkedList<T>:: push_back(T value){
    if(this->head==nullptr){
        push_front(value);
    }
    else
    {
        Node<T>* newNode = new Node<T>;
        newNode = this->head;
        Node<T>* nuevo_nodo = new Node<T>;
        while(newNode->next!=nullptr){
            newNode=newNode->next;
        }
        //Creamos nodo del siguiente al ultimo
        newNode->next=nuevo_nodo;
        nuevo_nodo->data = value;
        cout<<"Valor anadido al final: " << nuevo_nodo->data << "\n";
        nodos++;
    }
}

template<typename T>
void LinkedList<T>:: pop_front(){
    if(this->head==nullptr){
        cout<<"Lista Vacia \n";
    }
    else{
        if(nodos!=1)
        {
            Node<T> *temp= new Node<T>;
            temp = this->head->next;
            cout<<"Hemos eliminado: "<<this->head->data<<endl;
            delete this->head;
            this->head = temp;
        }
        else
        {
            cout<<"Hemos eliminado: "<<this->head->data<<endl;
            delete this->head;
            this->head=nullptr;
        }
        nodos--;
    }
}
template<typename T>
void LinkedList<T>:: pop_back(){
    if(this->head==nullptr){
        cout<<"Lista Vacia \n";
    }
    else{
        if(nodos!=1)
        {
            Node<T> *n = new Node<T>;
            n = this->head;
            while(n->next->next!=nullptr)
            {
                n=n->next;
            }
            Node<T> *temp = new Node<T>;
            temp = n->next;
            n->next=nullptr;
            cout<<"Hemos eliminado: "<<temp->data<<endl;
            delete temp;
        }
        else
        {
            delete this->head;
            this->head=nullptr;
        }
        nodos--;
    }
}
template<typename T>
void LinkedList<T>::search(int index)
{
	Node<T> *current = new Node<T>;
    current = this->head;
	int contador = 0;
	if (index == 0)
	{
		cout << "No valida" << endl;

	}
    else if (index > nodos)
	{
		cout << "El index supera el tamanio de la lista" << endl;

	}
	else
	{
		while (contador != index)
		{
			contador++;
			if (contador == index)
			{
				cout<< "Dato en la posicion index: "<<current->data << "\n";
			}
			else
			{
				current = current->next;
			}

		}
	}


}
