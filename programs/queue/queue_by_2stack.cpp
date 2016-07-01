#include<iostream>

using namespace std;

struct Stack {
  int data;
  Stack* next;
};

struct Queue {
  Stack *stack1;
  Stack *stack2;
};

Queue* CreateQueue() {
  Queue *q = new Queue;
  q->stack1 = NULL;
  q->stack2 = NULL;
  return q;
}

Stack* CreateStack(int n) {
  Stack* st = new Stack;
  st->data = n;
  st->next = NULL;
  return st;
}

void push(Stack **s, int n) {

  Stack* temp = CreateStack(n);

  if(s== NULL) {
    cout<<"stack is NULL\n";
    *s = temp;
    return;
  }
  temp->next = *s;
  *s = temp;
}

int pop(Stack** st) {

  int value = 0;
  Stack* current = *st;
  value = current->data;
  *st = current->next;
  delete(current);
  cout<<"Value is "<<value<<"\n";
  return value;
}

void enqueue(Queue *q, int n) {
  cout<<"Inside Enqueue "<<n<<" \n";

  push(&q->stack1, n);

}  

int dequeue(Queue *q) {
  cout<<"Inside Dequeue \n";
  int res  = 0;
  if((q->stack1 == NULL) && ( q->stack2 == NULL)) {
    cout<<"Queue is underflow\n";
    return 0;
  }
  if(q->stack2 == NULL) {
    while(q->stack1!=NULL) {
       int temp =  pop(&q->stack1);
       push(&q->stack2, temp);
    }
    res = pop(&q->stack2);
    return res;
  }
  res = pop(&q->stack2);
  return res;
}

int main() {

  Queue *q = CreateQueue();
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  enqueue(q, 60);
  int res = 0;
  res = dequeue(q);
  cout<<"Dequeue value is "<<res<<"\n"; 
  int res1 = dequeue(q);
  cout<<"Dequeue value is "<<res1<<"\n"; 
  int res2 = dequeue(q);
  cout<<"Dequeue value is "<<res2<<"\n"; 
  int res3 = dequeue(q);
  cout<<"Dequeue value is "<<res3<<"\n"; 
  int res4 = dequeue(q);
  cout<<"Dequeue value is "<<res4<<"\n"; 
  int res5 = dequeue(q);
  cout<<"Dequeue value is "<<res5<<"\n"; 
  enqueue(q, 50);
  int res6 = dequeue(q);
  cout<<"Dequeue value is "<<res6<<"\n"; 
}
