#include<iostream>

using namespace std;

class stack {
  int top;
  int size;
  int *ptr;
  public:
  stack(int n);
  void push(int n);
  int pop();
  void reverse();
  void inserttobottom(int n);
  void print();
  bool isfull();
  bool isempty();
};

stack::stack(int size)  {
  top = -1;
  this->size = size;
  ptr = new int[size];
}

void stack::push(int n) {

  if(isfull()) {
    cout<<"stack is full\n";
    return;
  }
  ptr[++top] = n;
  cout<<ptr[top]<<endl;
}

int stack::pop(){
  if(isempty()) {
    cout<<"stack is empty\n";
    return 0;
  }
  int temp = ptr[top];
  top--;
  return temp;
}

bool stack::isfull() {
  if(top > size) {
    return 1;
  }
 return 0;
}

bool stack::isempty() {
  if(top<=-1 ) {
    return 1;
  }
  return 0;
}

void stack::inserttobottom(int temp) {

  cout<<"inside insert \n";
  if(isempty()) {
    push(temp);
    return;
  }
  int value = pop();
  cout<<"print after pop in insertboo \n";
  print();
  inserttobottom(temp);
  push(value);
  return;
}

void stack::reverse() {
  if(isempty()) {
    cout<<"stack is empty \n";
    return;
  }
  int temp = 0;
  temp = pop();
  cout<<"print after pop in reverse \n";
  print();
  reverse();
  inserttobottom( temp);
  return;
}

void stack::print() {
  cout<<"printing .......\n";
  for(int i =top;i>-1; i--) {
    cout<<ptr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  stack s(5);
  s.push(5);
  s.push(3);
  s.push(1);
  s.push(2);
  s.push(33);
  s.print();
  s.reverse();
  s.print();
}
