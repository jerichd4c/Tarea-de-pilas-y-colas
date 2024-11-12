#include <iostream> 
using namespace std;

//class ListaEnlazadaSimple
template <class T>
class ListaEnlazadaSimple{
    private:
        struct Node {
            T data;
            char priority;
            Node* next;

            Node (T data, char priority) : data(data), priority(priority), next(NULL) {}
        };
        Node* head; //puntero en el inicio de la cola

    public:
        //constructor
        ListaEnlazadaSimple() : head(NULL) {}

        //destructor
        ~ListaEnlazadaSimple() {
            while (!isEmpty()) {
                sacarDeCola();
            }
        }
    //funcion para insertar un nodo al inicio de la cola con una prioridad establecida
    void insertarEnCola(T data, char priority) {
        Node* newNode = new Node(data, priority);

        // Si se insertar en la cabeza de la lista
        if (head == NULL || head->priority < priority) {
            newNode->next = head;
            head = newNode;
        } else {
            // encontrar e insertar en pos
            Node* temp = head;
            while (temp->next != NULL && temp->next->priority >= priority) {
                temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        }
    }
    //funcion para remover de cola
    void sacarDeCola() {
        if (isEmpty()) {
            cout<<"La cola esta vacia"<<endl;
            return;
        } 
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    //encontrar el elemento con la prioridad mas alta
    T front() const {
        if (isEmpty()) {
            throw runtime_error("La cola esta vacia");
        }
        return head->data;
    }
    
    bool isEmpty() const {
        return head == NULL;
    }
    //mostrar cola 
    void print() const {
        Node* temp = head;
        while (temp!=NULL) {
            cout<<"data: "<<temp->data<<" priority: "<<temp->priority<<endl;
            temp = temp->next;
        }
    }
};

int main () {

    ListaEnlazadaSimple<string> cola;

    cola.insertarEnCola("Daniel", 'A');
    cola.insertarEnCola("Pablo", 'B');
    cola.insertarEnCola("Coraline", 'C');
    cola.insertarEnCola("Alfonzo", 'D');
    cola.insertarEnCola("Lara", 'E');
    cola.insertarEnCola("Paula", 'F');
    cola.insertarEnCola("Chancho", 'G');
    cola.insertarEnCola("Luz", 'H');
    cout<<"elementos de la cola: "<<endl;
    cola.print();
    cout<<"quitando los elementos de la cola: "<<endl;
    while (!cola.isEmpty()) {
        cout<<"Head: "<<cola.front()<<endl;
        cola.sacarDeCola();
    }
    return 0;
}