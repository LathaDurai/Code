#include<iostream>


struct Stack {
 int size;
 int *ptr;
 int top;
};

Stack* createstack(int n) {
  Stack *newstack = new Stack;
  newstack->size = n;
  newstack->ptr = new int[5];
  newstack->top  = -1;
  return newstack;
}
  
bool is_empty(Stack *stack) {
  if((stack->top) == -1) {
    std::cout<<"stack is empty \n";
    return 1;
  }
  return 0;
}

bool is_full(Stack *stack) {
  if(stack->top == stack->size) {
    std::cout<<"Stack is full \n";
    return 1;
  }
  return 0;
} 

void push(Stack *stack, int n) {
  std::cout<<"Inside Stack push \n";
  if(is_full(stack)) {
     return;
  }
  (stack->top)++;
  stack->ptr[stack->top] = n;
}

int pop(Stack *stack) {
  std::cout<<"Inside stack pop \n";
  if(is_empty(stack)) {
    return 0;
  }
  int result = stack->ptr[stack->top];
  (stack->top)--;
  std::cout<<"Popped value is " <<result<<"\n";
  return result;
}

int top(Stack *stack) {
  std::cout<<"Inside top \n";

  int temp  =stack->ptr[stack->top];
  return temp;
}
void sorting(Stack *stack, int temp) {

  std::cout<<"Inside sorting ...\n";
  
  if(is_empty(stack) || temp > top(stack)) {
    push(stack, temp);
    return;
  }
  int val =0;
  val = pop(stack);
  sorting(stack, temp);
  push(stack, val);
  return;
}

void sort(Stack **stack) {
  std::cout<<"Inside sort \n";
  if(is_empty(*stack)) {
    return ;
  }
  int temp =0;
  temp = pop(*stack);
  sort(stack);
  sorting(*stack, temp);
  return;
}

void print(Stack *stack) {

  std::cout<<"printing \n";
  for(int i = stack->top; i> -1; --i) {
    std::cout<<stack->ptr[i]<<" ";
  }
  std::cout<<"\n";
}

int main() {

  Stack *stack = createstack(12);
  push(stack, 15);
  push(stack, 0); 
  push(stack, -1); 
  push(stack, 14); 
  push(stack, 13); 
  push(stack, 55); 
  push(stack, 2);
  push(stack, 250);
  push(stack, 215);
  push(stack, 12);
  push(stack, 8);
  push(stack, 9);
  sort(&stack);
  print(stack);
}
