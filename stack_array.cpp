#include <iostream>
using namespace std;

#define MAX 100

class Stack{
  int top;
public:
  int a[MAX];

  Stack() {top = -1;}

  bool push (int x){
    if (top>= (MAX-1)){
      cout<<"Stack Overflow\n";
      return false;
    }
    a[++top]=x;
    cout<<x<<" pushed into stack\n";
    return true;
  }
  int pop(){
    if(top<0){
      cout<<"Stack Underflow\n";
      return 0;
    }
    return a[top--];
  }
  bool isEmpty(){
    return (top<0); 
  }

};
int main (){
  class Stack s;
  s.push(10);
  s.push(20);
  s.push(30);
  cout << s.pop() << "Popped from Stack\n";
  return 0;
}
