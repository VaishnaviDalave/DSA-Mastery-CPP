#include <iostream>
using namespace std;

# define SIZE 5

class Queue{
private:
    int items [SIZE], front, rear;
public:
    Queue(){
      front= -1;
      rear=-1;
    }
    bool isFull(){
      return (front==0 && rear == SIZE-1);
    }
    bool isEmpty(){
      return (front==-1);
    }
    void enQueue (int element){
      if (isFull()){
        cout<<"Queue is full"<<endl;
      }
      else{
        if(front==-1)front=0;
        rear++;
        items[rear]=element;
        cout<<"Inserted"<<element<<endl;
      }
    }
    int deQueue(){
      int element;
      if(isEmpty()){
        cout<<"Queue is empty"<<endl;
        return (-1);
      }
      else{
        element=items[front];
        if (front>= rear){
          front=-1;
          rear=-1;
        }
        else{front++;}
        cout<<"Deleted ->"<< element<< endl;
        return(element);
      }
    }
};
int main(){
   Queue q;
   q.enQueue(1);
   q.enQueue(2);
   q.enQueue(3);
   q.deQueue();
   return 0;
}
