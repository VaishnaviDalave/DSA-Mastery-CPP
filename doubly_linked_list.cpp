#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev; // New pointer for bidirectional navigation
};

class DoublyLinkedList {
    Node* head;

public:
    DoublyLinkedList() { head = NULL; }

    void insertAtFront(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << "Inserted " << val << " at front." << endl;
    }

    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtFront(30);
    dll.insertAtFront(20);
    dll.insertAtFront(10);
    
    cout << "Doubly Linked List (Forward): ";
    dll.displayForward();
    
    return 0;
}
