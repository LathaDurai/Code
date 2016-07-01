#include <iostream>

using namespace std;

struct stack {

  int top;
  int* ptr;
  int size;
};

void create(struct stack  &st1, int n) {
  
  cout <<"Im in Create \n";
  st1.top = -1;
  st1.size = n;
  st1.ptr = new int[n];
  cout <<"sizeof ptr "<<sizeof(st1.ptr)<<"\n";

}

bool isfull( struct stack &st1) {
  if (st1.top == st1.size) {
    cout <<" statck isfull\n";
    return 1;
  }
  return 0;
}

bool isempty(struct stack &st1) {
  if (st1.top == -1) {
    cout <<" statck is empty\n";
    return 1;;
  }
  return 0;
}

void push(struct stack &st1, int n) {

  if (isfull(st1)) {
    return;
  }
  st1.ptr[++st1.top] = n;
  cout <<"value is "<<st1.ptr[st1.top]<<"\n";
} 


void pop(struct stack &st1) {
  if (isempty(st1)) {
    return;
  }
  cout << "pop value is "<<st1.ptr[st1.top]<<"\n";
  st1.top--;
} 

void peek(struct stack &st1) {
  if (isempty(st1)) {
    return;
  }
  cout << "peek value is "<<st1.ptr[st1.top]<<"\n";
}

int main() {

  stack st1;
  create(st1, 100);
  push(st1,10);
  push(st1,20);
  push(st1,30);
  push(st1,40);
  pop(st1);
  peek(st1);
  return 0;
}
