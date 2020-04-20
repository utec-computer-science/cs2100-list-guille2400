#include<iostream>
#include <ostream>
#include "node.h"
using namespace std;
template <typename T>
class List {
protected:
        Node<T> *head;
        Node<T> *tail;
        int nodos;
public:

        /*
        List(T*){ 
			//Constructor  parametro, 
			//llena una lista a partir de un array
        }
*/
        List(Node<T>* newNode){ 
			head=newNode;
            tail=newNode;
        }

        List(){
            head=nullptr;
            tail=nullptr;
            nodos=0;
        }
        ~List(){
            clear();
        }
		  // Retorna una referencia al primer elemento
        T front(){

            if(this->head!= nullptr)
                return this->head->data;
            cout << "La lista esta vacia"<< "\n";
            }
        
		  // Retorna una referencia al ultimo elemento
		T back(){
            if(this->tail!= nullptr)
                return this->tail->data;
            cout << "La lista esta vacia"<< "\n";
        }
        
		  // Inserta un elemento al final
        void push_back(const T& element){
            Node<T>* newNode =new Node<T>;
            newNode->data=element;
            if(this->head==nullptr)
                this->head=this->tail=newNode;
            else{
            this->tail->next=newNode;
            this->tail=newNode;}
            this->nodos++;
            
        }
		  // Inserta un elemento al inicio
        void push_front(const T& element)
        {
        Node<T>* newNode=new Node<T>();
        newNode->data=element;
        newNode->next=this->head;
        if(this->head==nullptr)
            this->tail=newNode;
        this->head=newNode;
        this->nodos++;
        }

		  // Quita el ultimo elemento y retorna una referencia
        void pop_back(){
             if(this->nodos!=0){
            Node<T>* auxtail=this->tail; 
            Node<T>* auxhead=this->head;
            while(auxhead->next!=auxtail)
            {auxhead=auxhead->next;}
            this->tail=auxhead;
            this->tail->next= nullptr;
            delete auxtail;
            this->nodos--;
            if(this->nodos==0){
                this->head=nullptr;
                this->tail=nullptr;}
        }
        }

  		  // Quita el primer elemento y retorna una referencia
        void pop_front()
        {
            if(this->head!= nullptr)
            {
            Node<T>* aux=this->head;
            this->head=this->head->next;
            delete aux;
            this->nodos--;
            if(this->nodos==0)
                this->tail= nullptr;
                }
        }

		  // Acceso aleatorio
        T& operator[] (const int& index) {
        if(this->head!= nullptr && index<this->nodos){
            int contador=0;
            Node<T>* aux=this->head;
            while(contador!=index){
                aux=aux->next;
                contador++;
            }
            return aux->data;
        }
        throw out_of_range("This index doesnt exist");
    }
        
		  // la lista esta vacia?
        bool empty(){
            return nodos==0;
        }

		  // retorna el tamaño de la lista
        unsigned int size(){
            return nodos;
        }

		  // Elimina toda la lista
        void clear(){
            while (this->nodos != 0)
            {pop_front();}
        }
          //ELiminar por posicion
        void erase(T &index)
        {
        Node<T> *aux = this->head;
        if(index==1){
        this->head = aux->next;
        delete aux;
        }
        for(int i=0; i<index-2;i++){
        aux = aux->next;
        }
         Node<T> *aux2 = aux->next;
        aux->next = aux2->next;
        delete aux2;
        } 
		// ordena la lista
        void sort(){
            Node<T> *aux;
            Node<T> *temp;
            for (int i = size()-1; i >= 0; i--) {
                aux = head;
                temp = head->next;
                for (int j = 0; j < size()-1; j++) 
                {
                 if (aux->data > temp->data) {
                swap(aux->data, temp->data);
                }
                aux = temp;
                temp = temp->next;
                }
            }
            
        }

		// invierte la lista
        void reverse(){
            if(this->nodos>1){
            Node<T>* before= nullptr;
            Node<T>* actual= this->head;
            Node<T>* after= actual->next;
            while(actual!= nullptr){
                actual->next=before;
                before=actual;
                actual=after;
                if(after!= nullptr)
                    after=after->next;}
            Node<T>* temporal= this->head;
            this->head=this->tail;
            this->tail=temporal;}
        }

		  // Imprime la lista con cout
        template<typename __T>
        inline friend ostream& operator<<
        (ostream& os, const List &lista){
            Node<T>* pointer = lista.head;
            while(pointer != nullptr){
                os<<pointer->data << " ";
                pointer = pointer->next;
            }
            return os;
        }
        void print()
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

    
};

int main (int, char*[]){

    List<int>* l1= new List<int>;
    l1->push_front(50);
    l1->push_front(2);
    l1->push_back(100);
    l1->print();
    l1->pop_front();
    l1->print();
    l1->reverse();
    l1->print();
    l1->sort();
    l1->print();
    return 0;
}