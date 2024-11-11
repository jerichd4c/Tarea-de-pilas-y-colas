#include <iostream>
using namespace std;

//class node
template<class T>
class Node {
    public:
        T data;
        Node<T>* next;
        Node(T data) : data(data), next(nullptr) {}
};

//class stack
template<class T>
class Stack {
    private:
        Node<T>* top;
    public:
        Stack() : top(nullptr) {}

        void push(T data) {
            Node<T>* newNode = new Node<T>(data);
            newNode->next = top;
            top = newNode;
        }

        T pop() {
            if (!isEmpty()) {
                Node <T>* temp = top;
                T data = top->data;
                top = top->next;
                delete temp;
                return data;
            }
            // throw para evitar output infinito
            throw runtime_error("La pila esta vacia");
        }

        bool isEmpty() {
            return top == NULL;
        }

        void print() {
            Node <T>* current = top;
            while (current != NULL) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
        //funcion invertir pila 
        void invertirPila() {
            Stack<T> tempStack;
            while (!isEmpty()) {
                tempStack.push(pop());
            }
            top = tempStack.top; // Point top to the reversed stack
        }
    };

int main () {
    Stack<int> pila;
    pila.push(1);
    pila.push(2);
    pila.push(3);
    pila.push(4);
    pila.push(5);
    cout<<"pila original: ";
    pila.print();
    pila.invertirPila();
    cout<<"pila invertida: ";
    pila.print();
    return 0;
}