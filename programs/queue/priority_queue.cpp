#include<iostream>

using namespace std;

struct Node {
  int pri;
  int data;
  Node *next;
};

struct Queue {
  Node *front;
  Node *rear;
};

Node* createNode(int n, int p) {

  cout<<"Inside "<<__func__<<endl;
  Node *newnode = new Node;
  newnode->pri = p;
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}

Queue* createQueue() {
  //cout<<"Inside "<<__func__<<endl;
  Queue *q = new Queue;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void enqueue(Queue *q, int n, int p) {
  //cout<<"Enqueue "<< n <<" "<<p<<endl;

  Node *temp = createNode(n, p);

  if(q->rear == NULL) {

    q->rear=q->front = temp;
    return;
  }

  q->rear->next = temp;
  q->rear = temp;
}

Node* gethighpriority(Queue *q) {
  cout<<"inside "<<__func__<<"\n";
  Node *current = q->front;
  Node *temp = q->front;
  
  if(q->rear == NULL  && q->front == NULL) {
    return 0;
  }


  while(current->next != NULL) {
     if(temp->pri <  current->next->pri) {
       temp = current->next;
     }
     current = current->next;
  }
  return temp;
}
        

void DeleteHighPriority(Queue *q, Node* temp) {

  cout<<"Inside DeleteHighpriority \n";
  Node *prev = NULL;
  Node *next = NULL;
  Node *current = q->front;

  Node *high = temp;
  while(current != NULL) {

     if(current->pri == temp->pri) {
       cout<<"Pri matched "<<current->data<<"\n";
       prev->next = current->next;
       if(current->next == NULL) {
         q->rear = prev;
       }
       delete current;
       return;
     }
     prev = current;
     current = current->next;
     
  }
  return ;
}

Node* dequeue( Queue *q) {
  cout<<"Inside "<<__func__<<endl;
  if(q->front == NULL) {
    cout<<"Queue is underflow\n";
    return 0;
  }

  Node *temp = q->front;
  q->front = q->front->next;

  if(q->front == NULL) {
      q->rear = NULL;
  }
  return temp;
}

void print(Queue *q) {
  cout<<"Printing .........\n";
  Node* current = q->front;
  while(current != NULL) {
     cout<<current->data<<" "<<current->pri<<"\n";
     current = current->next;
  }
}

int main() {

  Queue *q = createQueue();
  enqueue(q, 10, 3);
  enqueue(q, 20, 5);
  enqueue(q, 30, 2);
  enqueue(q, 40, 1);
  enqueue(q, 50, 7);
  enqueue(q, 50, 9); 
  print(q);
  Node* temp1 =  gethighpriority(q);
  cout<<" Highest priority is "<< temp1->pri<<"\n";
  Node *temp = dequeue(q);
  if( temp!= NULL) {
     cout<<"dequeue value is "<<temp->data<<"\n";
  }
  print(q);
  DeleteHighPriority(q, temp1);
  print(q);
  enqueue(q, 13, 22);
  enqueue(q, 44, 100);
  enqueue(q, 5, 70);
  enqueue(q, 1, 19); 
  print(q);
  Node *temp2 = dequeue(q);
  if( temp2!= NULL) {
     cout<<"dequeue value is "<<temp2->data<<"\n";
  }
  print(q);
  temp1 = gethighpriority(q);
  cout<<" Highest priority is "<< temp1->pri<<"\n";
  DeleteHighPriority(q, temp1);
  print(q);
  return 0;
}
