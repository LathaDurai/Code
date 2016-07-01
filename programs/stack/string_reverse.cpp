#include <iostream>

using namespace std;

class stack {
  int size;
  int top;
  char *ptr;
  public:
  stack(int x) {
    size = x;
    top = -1;
    ptr = new char[size];
  }
  void push (int n);
  char pop();
  bool isEmpty();
  bool isFull();
  void reverse(char arr[]);
};

bool stack::isFull() {
  if (top >size) {
    return 1;
  }
  return 0;
}

bool stack::isEmpty() {
  if (top <= -1) {
    return 1;
  }
  return 0;
}

void stack::push(int n) {
  if (isFull()) {
    std::cout<<"stack is full\n";
    return;
  }
  top +=1;
  ptr[(top)] = n;
}

char stack::pop() {
  if (isEmpty()) {
    std::cout<<"stack is empty\n";
    return 0;
  }
  char x = ptr[top];
  top -=1;
  return x;
}

void stack::reverse(char arr[]) {
int i = 0;
      cout<<"Inside Reverse \n";   
    // insert the array in stack 
    // by one by one
    for(; i<size; ++i) {
      push(arr[i]);
    }

    // pop and storeit to array
    for(int j =top,  k = 0; j>=0 ; j--, k++) {
      arr[k] = pop();
      cout<<arr[k];
    } 
    cout<<"\n";
}

int main() {

  char arr[] = "lathaBaskar";
  int size = sizeof(arr)/sizeof(arr[0]);
  stack s1(size);
  s1.reverse(arr);
  return 0;
}
