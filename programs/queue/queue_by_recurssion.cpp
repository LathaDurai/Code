#include <iostream>
using namespace std;

struct Stack {

 int data;
 Stack *next;
};

struct Queue {
  Stack *st1;
};

Queue* CreateQueue() {
  cout<<"Inside CreateQueue\n";
  Queue *q = new Queue;
  q->st1 = NULL;
  return q;
}
Stack* CreateStack(int n) {
  cout<<"Inside CreateStack\n";
  Stack *st1 = new Stack;
  st1->data = n;
  st1->next = NULL;
  return st1;
}
void push(Stack **st1, int n) { 
  cout<<"Inside Push \n";
 
  Stack *temp = CreateStack(n);
  if(st1 == NULL) {
    *st1 = temp;
     return ;
  }
  temp->next = *st1;
  *st1 = temp;
}

int pop (Stack **st1) {
   cout<<"Inside POP \n";
   
   if(*st1 == NULL) {
     cout<<"Queue is underflow \n";
     return 0;
   }

   Stack *temp = *st1;
   int res = temp->data;
   *st1 = temp->next;
   delete(temp);
   return res;
}


void enqueue(Queue *q, int n) {
  cout<<"Inside Equeue "<<n<<" \n";
  push(&(q->st1), n);
}


int dequeue(Queue *q) {
  cout<<"Inside dequeue \n";
  int temp  = 0;
  int res  = 0;
  if(q->st1 == NULL) {
    cout<<"Inside deq stack is empty \n";
    exit(0);
  }
  // missed part 
  if(q->st1->next == NULL) {
    return pop(&(q->st1));
  }

  temp = pop(&(q->st1));
  cout<<"popped value is "<<temp<<"\n";
  res = dequeue(q);
  push(&(q->st1), temp);
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
  int res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
  enqueue(q, 70);
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
   res = dequeue(q);
  cout<<"Dequeue element is "<<res<<"\n";
  return 0;
}

