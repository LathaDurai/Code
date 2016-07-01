#include <iostream>


struct stack {
  int size;
  int top;
  char* ptr;
};

bool is_full(struct stack *st1) {
  if (st1->top >st1->size) {
    return 1;
  }
  return 0;
}

bool is_empty(struct stack *st1) {
  if (st1->top <= -1) {
    return 1;
  }
  return 0;
}

void push(struct stack *st1, int n) {
  if (is_full(st1)) {
    std::cout<<"stack is full\n";
    return;
  }
  st1->top +=1;
  st1->ptr[(st1->top)] = n;
}

char pop(struct stack *st1) {
  if (is_empty(st1)) {
    std::cout<<"stack is empty\n";
    return 0;
  }
  char x = st1->ptr[st1->top];
  st1->top -=1;
  return x;
}


void balanced(char arr[], int size) {
  std::cout <<"Inside Balanced \n";
  stack st1;
  st1.top = -1;
  st1.size = size;
  st1.ptr = new char[size]; 

  for (int i  =0; i< size; i++) {
    std::cout << "insid for"<<arr[i]<<" \n";
    if (arr[i] == '(' ||
        arr[i]== '{' ||
        arr[i] == '[' ) {
       std::cout<<"Inside first if pushiing \n";
       push(&st1,arr[i]);
    } 
    if (arr[i] == '}') {
       std::cout<<"Inside } \n";
        char check = pop(&st1);
        if (check =='{') {
             std::cout <<"Is same { } \n";
        } else {
          std::cout <<"Not balanced \n";
          return;
        }
    } else if (arr[i] == ')') {
       std::cout<<"Inside ) \n";
        char check = pop(&st1);
        if (check == '(') {
             std::cout <<"Is same () \n";
        } else {
          std::cout <<"Not balanced \n";
          return;
        }
    } else if (arr[i] == ']') {
       std::cout<<"Inside ]]]]  \n";
       char check = pop(&st1);
        if (check == '[') {
             std::cout <<"Is same [] \n";
        } else {
          std::cout <<"Not balanced \n";
          return;
        }
    } else {
      continue;
    }
  }
  std::cout <<"BALANCED \n";
  return;
   
} 


int main() {
  std::cout <<"Inside Main \n";
  char arr[] = "{a([oo])}}";
  int size = sizeof(arr)/sizeof(arr[0]);
  balanced(arr, size);
  return 0;
}
