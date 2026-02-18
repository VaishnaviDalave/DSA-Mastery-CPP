#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    // Insert at the front
    void insertAtFront(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << val << " at front." << endl;
    }

    // Print the list
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;
    list.insertAtFront(30);
    list.insertAtFront(20);
    list.insertAtFront(10);
    
    cout << "Current Linked List: ";
    list.display();
    
    return 0;
}
