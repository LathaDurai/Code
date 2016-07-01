#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
};

struct Queue {
  Node *front;
  Node *rear;
};

Node* createNode(int n) {

  cout<<"Inside "<<__func__<<endl;
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}

Queue* createQueue() {
  cout<<"Inside "<<__func__<<endl;
  Queue *q = new Queue;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void enqueue(Queue *q, int n) {
  cout<<"Inside "<<__func__<<endl;

  Node *temp = createNode(n);

  if(q->rear == NULL) {

    q->rear=q->front = temp;
    return;
  }

  q->rear->next = temp;
  q->rear = temp;
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

int main() {

  Queue *q = createQueue();
  enqueue(q, 10);
  enqueue(q, 20);
  enqueue(q, 30);
  enqueue(q, 40);
  enqueue(q, 50);
  enqueue(q, 50); 
  Node *temp = dequeue(q);
  if( temp!= NULL) {
     cout<<"dequeue value is "<<temp->data<<"\n";
  }
  return 0;
}
