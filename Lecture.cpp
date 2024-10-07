#include<iostream>
using namespace std;
// ---------------------------------------------------------
template <typename T>
class Node {
private:    
    T data;
    Node* next; 
public:
    Node(T val) : data(val), next(nullptr) {}
    T getData() const { return data; }
    void setData(T val) { data = val; }
    Node* getNext() const { return next; }
    void setNext(Node* node) { next = node; }        
};
// ---------------------------------------------------------
template <typename T>
class LinkedList {
private:
    Node<T>* head;
public:
    LinkedList() : head(nullptr) {}

    void insertAtStart(T val) {
        Node<T>* newNode = new Node<T>(val);
        newNode->setNext(head);
        head = newNode;
    }

    void insertAtEnd(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head  = newNode;
        } else {
            Node<T>* current = head;
            while (current->getNext() != nullptr) {
                current = current->getNext();
            }
            current -> setNext(newNode);
        }
    }

    void deleteByValue(T val) {
        if (head != nullptr) {
            if (head->getData() == val) {
                Node<T>* temp = head;
                head = head->getNext();
                delete temp;
            } else {
                Node<T>* current = head;
                while (current->getNext() != nullptr &&
                       current->getNext()->getData() != val) {
                    current = current->getNext();    
                } 
                if (current -> getNext() != nullptr) {
                    Node<T>* temp = current->getNext();
                    current->setNext(current -> getNext()->getNext());
                    delete temp;
                }
            }
        }
    }
    void print() {
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->getData() << " ";
            current = current->getNext();
        }
        cout << endl;
    }
    bool search(T val) {
        bool found = false;
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->getData() == val) {
                found = true;
                break;
            }
            current = current->getNext();
        }
        return found;
    }
};



int main ()
{
    LinkedList<int> list;
    list.insertAtStart(20);
    list.insertAtEnd(30);
    list.insertAtStart(10);
    list.insertAtEnd(40);
    cout << "Linked List: ";
    list.print();
    int d = 30;
    list.deleteByValue(d);
    cout << "Deleted " << d << " : ";
    list.print();
    int s = 30;
    if (list.search(s)) 
        cout << s << " is in the list.\n";
    else
        cout << s << " is not in the list.\n";
    LinkedList<string> list2;
    list2.insertAtStart("Hello");
    list2.insertAtEnd("CS136");
    list2.insertAtStart("Testing Linked List ");
    list2.print();
    return 0;
}