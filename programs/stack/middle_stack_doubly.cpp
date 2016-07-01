#include <iostream>

using namespace std;

struct dl{
  int data;
  dl *prev;
  dl *next;
};

struct stack {
  int count;
  dl *head;
  dl *mid;
};

stack* createstack(int n) {
  cout<<"Inside createstack \n";
  stack *newstack = new stack;
  newstack->count = 0;
  return newstack;
}
void push(int n) {
  cout<<"Inside push \n";
  dl *newdl = new dl;
  dl->data = n;
  dl->prev = 

}

void pop() {
}

void findMiddle() {
}

void deleteMiddle() {
}

int main() {
  cout<<"Inside main function \n";
 
  stack *st = createstack();
  push(st, 10);
  push(st, 20);
  push(st, 30);
  push(st, 40);
  push(st, 50);
  push(st, 60);
  pop(st); 
  return 0;
}




