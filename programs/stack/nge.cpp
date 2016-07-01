#include<iostream>


struct stack {
  int size;
  int top;
  int ptr[100];
};

bool is_full(struct stack *st1) {
  std::cout<<"Inside is full \n";
  if (st1->top >=st1->size) {
    std::cout<<"Stack is full\n";
    return 1;
  }
  return 0;
}

bool is_empty(struct stack *st1) {
  std::cout<<"Inside"<< __func__ <<"\n";
  if (st1->top <= -1) {
    std::cout<<"Stack is empty\n";
    return 1;
  }
  return 0;
}

void push (struct stack *st1, int n) {

  std::cout<<"Inside PUSH \n";
  if (!is_full(st1)) {
     st1->top += 1 ;
    st1->ptr[st1->top] = n;
    std::cout <<"Top is "<<st1->top<<"\n";
    return;
  }
  return;
}

int  pop(struct stack *st1) {

  std::cout<<"Inside POP \n";
  if(!(is_empty(st1))) {
    int x ;
    x = st1->ptr[st1->top];
    st1->top -=1;

    std::cout <<"Top is "<<st1->top<<"\n";
    return x;
  }
  return -1;
}

void nge(int arr[], int size) {

  std::cout<<"Inside NGE---"<<size<<"\n";
  struct stack st1;
  st1.top = -1;
  st1.size = size;

  push(&st1, arr[0]);
  int next, element;

  for (int i =1; i<size; ++i) {
    std::cout<<"Inside FOR "<<i<<std::endl;
    next = arr[i];
    if(!(is_empty(&st1))) {
         std::cout<<"Inside if \n";
         element = pop(&st1);
         while(next > element) {
           std::cout <<element <<"---->"<<next<<"\n";
           if(is_empty(&st1)) 
              break;
           element = pop(&st1);
         }
        if (element > next) { 
          push(&st1, element);
        }
    }
         push(&st1, next);
  }
  while (is_empty(&st1) == false) {
      element = pop(&st1);
      std::cout << element <<"---->"<<-1<<"\n";
  }
}

int main() {

  int arr[5] = {5,2,8,1,6};

  int size = sizeof(arr)/sizeof(arr[0]);
  nge(arr, size);
}
