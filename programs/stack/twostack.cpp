#include <iostream>

using namespace std;

class stack {

  int size;
  int top1;
  int top2;
  int *arr;
public:
  stack(int n) {
    size = n;
    top1 = -1;
    top2 = size;
    arr = new int[size];
  }
  void push1(int n);
  void push2(int n);
  void pop1();
  void pop2();
  bool isempty();
  //bool isfull();
};

bool stack::isempty() {

  cout<<"Inside isempty"<<top1<<" "<<top2<<" \n";
  if ((top1 == -1) && (top2 == size)) {
    cout <<"Stack is empty\n";
    return 1;
  }
  return 0;
}


/*bool stack::isfull() {

  cout<<"Inside isfull"<<top1<<" "<<top2<<" \n";
  if ((top1 + top2) >= (size-1)) {
    cout <<"Stack is Full\n";
    return 1;
  }
  return 0;
} */

void stack::push1(int n) {

  cout<<"Inside push1 \n";
 /* if(isfull()) {
    cout <<"Calling isfull\n";
    return;
  }*/
  if (top1 < top2 -1) {
    arr[++top1] = n;
    cout<<"Top1 is "<<top1<<"\n";
  } else {
    cout <<"Stack is full\n";
  }
  return;
}

void stack::push2(int n) {
  cout<<"Inside push2 \n";
/*  if(isfull()) {
    cout <<"Calling isfull\n";
    return;
  }*/
  if (top1 < top2 -1) {
    arr[--top2] = n;
    cout<<"Top2 is "<<top2<<"\n";
  } else {
    cout <<"Stack is full\n";
  }
  return;
}

void stack::pop1() {
  cout <<"Inside POP111\n";
  if(isempty()) {
    cout<<"Stack is empty \n";
    return;
  }
  if (top1 > 0) {
    cout<<"Nothing to POP\n";
  }
  cout<< "Poped element is "<<arr[top1] <<"\n";
  top1--;
    cout<<"Top1 is "<<top1<<"\n";
  return;
}

void stack::pop2() {
  cout <<"Inside POP2\n";
  if(isempty()) {
    cout<<"Stack is empty \n";
    return;
  }
  if (!(top2 >= (size))) {
  cout<< "Poped element is "<<arr[top2] <<"\n";
  top2++;
    cout<<"Top2 is "<<top2<<"\n";
  } else 
    cout<<"nothing to POP\n";
  return;

}
int main() {

  stack st1(5);

  st1.push1(10);
  st1.push2(20);
  st1.push1(30);
  st1.push2(40);
  st1.push1(50);
  st1.push1(60);
  st1.pop1();
  st1.pop1();
  st1.pop2();
  st1.pop2();
  st1.pop2();
  st1.pop1();
  st1.pop1();
  return 0;
}
