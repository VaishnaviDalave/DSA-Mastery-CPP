#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
    int items[SIZE], front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        if (front == 0 && rear == SIZE - 1) return true;
        if (front == rear + 1) return true;
        return false;
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enQueue(int element) {
        if (isFull()) {
            cout << "Queue is Full\n";
        } else {
            if (front == -1) front = 0;
            rear = (rear + 1) % SIZE; // The "Circular" logic
            items[rear] = element;
            cout << "Inserted " << element << endl;
        }
    }

    int deQueue() {
        int element;
        if (isEmpty()) {
            cout << "Queue is Empty\n";
            return -1;
        } else {
            element = items[front];
            if (front == rear) {
                front = -1;
                rear = -1;
            } else {
                front = (front + 1) % SIZE;
            }
            return element;
        }
    }
};

int main() {
    CircularQueue cq;
    cq.enQueue(10);
    cq.enQueue(20);
    cq.enQueue(30);
    cq.enQueue(40);
    cq.enQueue(50);
    cout << "Deleted: " << cq.deQueue() << endl;
    cq.enQueue(60); // This works because it's circular!
    return 0;
}
