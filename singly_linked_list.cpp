#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;

public:
    LinkedList() { head = NULL; }

    void insertAtFront(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = head;
        head = newNode;
    }

    // NEW: Delete a node by value
    void deleteNode(int key) {
        Node *temp = head, *prev = NULL;

        // Case 1: If head node itself holds the key
        if (temp != NULL && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << "Deleted " << key << endl;
            return;
        }

        // Case 2: Search for the key
        while (temp != NULL && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        // Case 3: Key not found
        if (temp == NULL) return;

        // Unlink the node from linked list
        prev->next = temp->next;
        delete temp;
        cout << "Deleted " << key << endl;
    }

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
    
    cout << "Before deletion: ";
    list.display();
    
    list.deleteNode(20); // Deleting middle element
    
    cout << "After deletion: ";
    list.display();
    
    return 0;
}
