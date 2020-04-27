#include "node.h"
using namespace std;

    template <typename T>
    class Iterator {
        private:
            Node<T> * iterador;
            
        public:
            Iterator(){ iterador = nullptr; }
            Iterator(Node<T> * itera) { this->iterador = itera; }
            
            T operator * ()
            {
                return this->iterador->data;
            }
            
            void operator ++()
            {
                this->iterador = this->iterador->next;
            }
            
            bool operator == (const Iterator & it)
            {
                return this->iterador == it.iterador;
            }
            
            bool operator != (const Iterator & it)
            {
                return this->iterador != it.iterador;
            }
    };