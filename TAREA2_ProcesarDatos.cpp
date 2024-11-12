#include<iostream>
#include<string>
using namespace std;

//class Node
template <class T>
class Node {
    public:
    T data;
    char priority;
    Node<T>* next;
    Node(T data, char priority) : data(data), priority(priority), next(nullptr) {}
};

// class Queue
template <class T>
class Queue {
    private:
    Node <T>* head;
    Node <T>* tail;
    public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push (T data, char priority) {
        Node <T>* newNode = new Node<T>(data, priority);
        if (tail) { 
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    //funcion para procesar por prioridad

    void processByPriority (char priority) {
        Node <T>* current = head;
        Node <T>* prev = NULL;
        cout << "Procesando prioridad " << priority << ":" << endl;

        while (current!=NULL) {
            if (current->priority == priority) {
                cout << current->data <<" ";
                //remover nodo
                if (prev) {
                    prev->next = current->next;
                } else {
                    head = current->next;
                }
                Node <T>* temp = current;
                current = current->next;
                
                if (temp == tail) tail = prev; //en caso de que se tenga que actualizar la cola
                delete temp;
        } else {
            prev = current;
            current = current->next;
        }
    }
    cout<<endl;
    }
    bool isEmpty() {
        return head==NULL;
    }
};


int main () {
    Queue<string> pila;

    pila.push("Daniel", 'B');
    pila.push("Pablo", 'C');
    pila.push("Coraline", 'D');
    pila.push("Alfonzo", 'A');
    pila.push("Lara", 'C');
    pila.push("Paula", 'A');
    pila.push("Chancho", 'A');
    pila.push("Luz", 'A');
    pila.push("Daniel", 'E');
    //procesarlos
    char prioridades[] = {'A', 'B', 'C', 'D','E'};
    for (char priority : prioridades) {
        pila.processByPriority(priority);
    }
    return 0;
}
