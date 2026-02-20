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

    // NEW: Search for a value
    bool search(int key) {
        Node* current = head;
        while (current != NULL) {
            if (current->data == key) return true;
            current = current->next;
        }
        return false;
    }

    // NEW: Reverse the list (The Interview Favorite)
    void reverse() {
        Node *prev = NULL, *current = head, *next = NULL;
        while (current != NULL) {
            next = current->next; // Store next
            current->next = prev; // Reverse pointer
            prev = current; // Move prev one step
            current = next; // Move current one step
        }
        head = prev;
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
    
    cout << "Original List: ";
    list.display();
    
    list.reverse();
    cout << "Reversed List: ";
    list.display();
    
    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;
    
    return 0;
}
