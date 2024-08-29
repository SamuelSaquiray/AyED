#include <iostream>
using namespace std;
template <typename T>
struct Node {
    T data;
    Node* next;
    
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class ForwardList {
 
public:
    Node<T>* head; 
    ForwardList() : head(nullptr) {}

    ~ForwardList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    T front(){
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            return temp;
        }
    }
    T back(){
        Node<T>* current = head;
        while(current->next != nullptr){
            current=current->next;
        }
        return current->data;    
    }
    void push_back(T value){
        if(head!=nullptr){
        Node<T>* newNode = new Node<T>(value);
        Node<T>* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=newNode;
        }
        else this->push_front(value);
    }
    void push_front(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }
    
    void pop_front() {
        if (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }
    
    void pop_back(){
        if(head!=nullptr){
        Node<T>* current=head;
        Node<T>* newLast;
        while(current->next!=nullptr){
            newLast=current;
            current=current->next;

        }
        newLast->next=nullptr;
        delete current;
        }
    }
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }
    T operator[](int x){
        Node<T>* current = head;
        while (current !=nullptr && x){
            current = current->next;
            x--;
        }
        return current->data;
        
    }
    bool empty(){
        if(head==nullptr)
            return true;   
        else false;
    } 
    int size() {
        Node<T>* current = head;
        int sizeT=0;
        while (current != nullptr) {
            sizeT++;
            current = current->next;
        }
        return sizeT;
    }
    void clear(){
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
    }
    //head=3-> 4-> 5-> nullptr
    void reverse() {
        Node<T>* prev=nullptr;
        Node<T>* current =head;
        Node<T>* next=nullptr;
        while(current !=nullptr){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        head=prev;
    }

};

int main() {
    ForwardList<int> list;
    list.push_front(10);
    list.push_front(20);
    list.push_front(30);
    list.push_back(40);
    cout << "Elementos en la lista: ";
    list.print();
    
    list.pop_back();
    cout<<"elemento numero 2 de la lista:\n";
    cout<<list[10];

    cout << "\nDespués de eliminar el primer elemento: ";
    list.print();
    cout<<"el ultimo\n";
    cout<<list.back();
    cout<<"lista invertida";
    list.reverse();
    list.print();
    return 0;
}
