#include<iostream>
#include<string>
using namespace std;
//estructura nodo
template<typename T>
struct Node{
    int priority;
    Node<T>* next;
    
    struct QueueNode {
        T data;
        QueueNode* next;
    };
    QueueNode* queueHead;
    Node(int p) : priority(p), next(nullptr), queueHead(nullptr) {}
};

//clase de lista enlazada simple
template <typename T>
class SimpleList{
    private:
        Node<T>* head;
    public:
        SimpleList() : head(nullptr) {}

        ~SimpleList() {
            while (head) {
            Node<T>* temp = head;
            head = head->next;

            //liberar la cola interna
            typename Node<T>::QueueNode* queueTemp = temp->queueHead;
            while (queueTemp) {
                typename Node<T>::QueueNode* qTemp = queueTemp;
                queueTemp = queueTemp->next;
                delete qTemp;
            }
            delete temp;
            }
        }
        //funcion para insertar un nodo de prioridad
        void insertPriority(int priority) {

            //verificar si la prioridad ya existe
            Node<T>* current = head;
            while (current) {
                if (current->priority == priority) {
                    cout<<"Prioridad: "<<priority<<" ya existe, no se duplicara\n";
                    return;
                }
                current = current->next;

            }
            Node<T>* newNode = new Node<T>(priority);

            //insertar en orden de prioridad
            if (!head || head->priority > priority) {
                newNode->next = head;
                head = newNode;
            } else {
                Node<T>* current = head;
                while (current->next && current->next->priority < priority) {
                    current = current->next;
                }
                newNode->next = current->next;
                current->next = newNode;
            }
        }
            //funcion para insertar datos en la cola de un nodo especifico

            void insertData(int priority, T data) {
                Node<T>* current = head;
                while (current && current->priority != priority) {
                    current = current->next;
                }
                if (current) {
                    typename Node<T>::QueueNode* newQueueNode = new typename Node<T>::QueueNode{data, nullptr};
                    if (!current->queueHead) {
                        current->queueHead = newQueueNode;
                    } else {
                        typename Node<T>::QueueNode* queueCurrent = current->queueHead;
                        while (queueCurrent->next) {
                            queueCurrent = queueCurrent->next;
                        }
                        queueCurrent->next = newQueueNode;
                        }
                    } else {
                            cout<<"Prioridad no encontrada: "<<priority<<endl;
                        }
                    }
        //funcion para imprimir la lista
        void printList() {
            Node<T>* current = head;
            while (current) {
                cout << "Prioridad: " << current->priority <<"\nDatos: ";
                typename Node<T>::QueueNode* queueCurrent = current->queueHead;
                while (queueCurrent) {
                    cout << queueCurrent->data << " ";
                    queueCurrent = queueCurrent->next;
                }
                cout<<"\n";
                current = current->next;
            }
        }
    };
//implementacion
int main() {
    //crear lista
    SimpleList<string> lista;

    //insertar prioridades
    lista.insertPriority(2);  
    lista.insertPriority(1);  
    lista.insertPriority(3);  

    //insertar datos en colas internas
    lista.insertData(1, "persona 1");  
    lista.insertData(2, "persona 2");  
    lista.insertData(3, "persona 3");  
    lista.insertData(3, "persona 4");  
    lista.insertData(1, "persona 5");  
    // intentar agregar datos a una prioridad inexistente
    lista.insertData(4, "persona 6");  //prioridad 4 no existe

    //imprimir lista inicial
    cout << "Lista actual:\n";
    lista.printList();

    //agregar más prioridades y datos
    lista.insertPriority(0); //nueva prioridad 0
    lista.insertData(0, "persona 7");
    lista.insertData(2, "persona 8");  

    //insertar datos en una cola interna ya llena
    lista.insertData(3, "persona 9");

    //lista despues de insersion 
    cout << "\nLista despues de agregar mas prioridades y datos:\n";
    lista.printList();

    //caso: agregar prioridad ya existente (sin efecto)
    lista.insertPriority(1);  //prioridad 1 ya existe, no debe duplicarse

    //caso: agregar datos a una prioridad con solo un elemento
    lista.insertData(0, "persona 10");

    //imprimir lista final
    cout << "\nLista final despues de todos los cambios:\n";
    lista.printList();

    return 0;
}
