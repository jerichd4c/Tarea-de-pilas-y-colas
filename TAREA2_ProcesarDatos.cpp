#include<iostream>
#include<string>
using namespace std;

//class Node
template <class T>
class Node {
    public:
    char priority;
    T data;
    Node<T>* next;
    Node(char priority, T data) : priority(priority), data(data), next(nullptr) {}
};

// class Queue para first in first out
template <class T>
class Queue {
    private:
    Node <T>* head;
    Node <T>* tail;
    public:
    Queue() : head(nullptr), tail(nullptr) {}

    void push (T data, char priority) {
        Node <T>* newNode = new Node<T>(priority,data);
        if (tail) { 
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }
    // Procesar los elementos en orden de prioridad sin alterar el orden original de la cola
    void processByPriority(const string& priorityOrder) {
        for (char priority : priorityOrder) {
            int count = 0;
            int size =this->getSize();
            cout<<"procesando prioridad "<<priority<<":"<<endl;
            for (int i = 0; i < size; i++) {
                Node<T>* current = this->pop();
                if (current->priority == priority) {
                    cout<<current->data<<endl;
                    delete current; //procesar y eliminar
                } else {
                    //re-queue el elemento
                    this->push(current->data, current->priority);
                    delete current; //se eelimina nodo tempora
                }
            }
            cout<<endl;
        }
    }

    //funcion para (FIFO)

    Node<T>* pop() {
        if (head==nullptr) {
            throw runtime_error("La cola esta vacia");
    }
    Node <T>* temp = head;
    head = head->next;
    if (!head) {
        tail=nullptr; // si la lista queda vacia se actualiza tail
    }
    return temp;
    }
    //funcion para saber el tamaño de la cola
    int getSize() {
        int size = 0;
        Node<T>* temp = head;
        while (temp) {
            size++;
            temp = temp->next;
        }
        return size;
    }
    //funcion isEmpty para verificar cola vacia
    bool isEmpty() const {
        return head == nullptr;
    }
};

int main () {
    Queue<string> cola;

    cola.push("Daniel", 'B');
    cola.push("Pablo", 'C');
    cola.push("Coraline", 'D');
    cola.push("Alfonzo", 'A');
    cola.push("Lara", 'C');
    cola.push("Paula", 'A');
    cola.push("Chancho", 'A');
    cola.push("Luz", 'A');
    cola.push("Daniel", 'E');
    //procesarlos
    string prioridades = "ABCDE";
    cola.processByPriority(prioridades);
    return 0;
}
