#include<iostream>
#include "DoublelinkedListNode.h"
using namespace std;
template<typename T>
class DoublelinkedList{
    DoublelinkedListNode<T> *head;
    DoublelinkedListNode<T> *tail;
    int nodos;
public:
    DoublelinkedList()
    { 
        this->head=nullptr;
        this->tail=nullptr;
        nodos=0;
        }
    void print();
    void push_front(T value);
    void push_back(T value);
    void pop_front();
    void pop_back();
    void search(int index);
    
};

template<typename T>
void DoublelinkedList<T>::print()
{
    DoublelinkedListNode<T>* nodoaimprimir = new DoublelinkedListNode<T>;
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
void DoublelinkedList<T>:: push_front(T value){
    if(this->head==nullptr)
    {
        DoublelinkedListNode<T>* newNode = new DoublelinkedListNode<T>;
        newNode->data = value;
        cout<<"Creando lista doble y anadiendo al frente: " << newNode->data << "\n";
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        DoublelinkedListNode<T>* newNode = new DoublelinkedListNode<T>;
        newNode->data = value;
        newNode->next = this->head;//Identificamos donde esta el head osea al sig. del nuevo
        newNode->prev = nullptr;
        cout<<"Valor anadido al frente: " << newNode->data << "\n";
        //prev->next = newNode; // Uniendo nodo nuevo con el primero
        //this->head = newNode;
        this->head->prev = newNode;//Donde apuntaba head (osea al primero), el anterior a ese sera el nuevo 
		this->head = newNode;

    }
    nodos++;
}

template<typename T>
void DoublelinkedList<T>:: push_back(T value)
{
    if(this->head==nullptr){
        push_front(value);
    }
    else
    {
        DoublelinkedListNode<T>* last = new DoublelinkedListNode<T>;
		last->data = value;
		last->next = nullptr;
        cout<<"Valor anadido al fondo: " << last->data << "\n";
		last->prev = this->tail;//Al que apunta el tail sera el previo de last
		this->tail->next = last;//AL que apunta tail, el siguiente sera el last
		this->tail = last;
    }
    nodos++;
}

template<typename T>
void DoublelinkedList<T>:: pop_front(){
    if(this->head==nullptr){
        cout<<"Lista Vacia \n";
    }
    else{
        if(nodos!=1)
        {
            DoublelinkedListNode<T> *temp= new DoublelinkedListNode<T>;
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
void DoublelinkedList<T>:: pop_back(){
    if(this->head==nullptr){
        cout<<"Lista Vacia \n";
    }
    else{
        if(nodos!=1)
        {
            DoublelinkedListNode<T> *temp = new DoublelinkedListNode<T>;
            temp = this->tail;
            this->tail=this->tail->prev;
            this->tail->next = nullptr;
		    delete temp;
		    temp = nullptr;
            cout<<"Hemos eliminado: "<<temp->data<<endl;
        }
        else
        {
            delete this->tail;
            this->tail =nullptr;
            this->head=nullptr;
        }
        nodos--;
    }
}
template<typename T>
void DoublelinkedList<T>::search(int index)
{
	DoublelinkedListNode<T> *current = new DoublelinkedListNode<T>;
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
