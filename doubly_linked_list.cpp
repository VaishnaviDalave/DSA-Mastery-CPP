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

        if (head != NULL) 
            head->prev = newNode;
        head = newNode;
    }

    void deleteNode(Node* del){
        if(head==NULL|| del==NULL)return;
        if(head==del)head=del->next;
        if(del->next!=NULL)del->next->prev=del->prev;
        if(del->prev!=NULL)del->prev->next=del->next;
        delete del;
        cout<<"Node deleted successfully."<<endl;
    }
    Node* getHead() {return head; }
    void displayForward(){
        Node* temp=head;
        while (temp!= NULL){
            cout<< temp->data << " <-> ";
            temp = temp->next;
        }
        cout<< "NULL" << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insertAtFront(30);
    dll.insertAtFront(20);
    dll.insertAtFront(10);
    
    cout << "Initial List : ";
    dll.displayForward();

dll.deleteNode(dll.getHead());
    cout<< "After Deleting Head :";
    dll.displayForward();
    
    return 0;
}
