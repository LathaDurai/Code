#include<iostream>

using namespace std;

struct Node {
  int data;
  Node *next;
  Node *prev;
};

struct Queue {
  Node *front;
  Node *rear;
};

Queue* createqueue() {

  Queue *q = new Queue;
  q->front = NULL;
  q->rear = NULL;
  return q;
}

void insertfront(Queue* q, int n) {

  cout<<"Inside insertfront "<<n<<"\n";

  Node *newnode = new Node;
  newnode->data = n;
  newnode->prev = NULL;
  newnode->next = NULL;

  if((q->front == NULL) && (q->rear == NULL)) {
    cout<<"queue is empty \n";
    q->front = newnode;
    q->rear = newnode;
    return;
  }

  newnode->next = q->front;
  q->front->prev = newnode;
  q->front = newnode;
  return;
}


void insertrear(Queue *q, int n) {

  cout<<"Inside insert rear "<<n<<"\n";

  Node *newnode = new Node;
  newnode->data = n;
  newnode->prev = NULL;
  newnode->next = NULL;

  if((q->front == NULL) && (q->rear == NULL)) {
    q->front = newnode;
    q->rear = newnode;
    return;
  }

  newnode->prev = q->rear;
  q->rear->next = newnode;
  q->rear = newnode;
  return;
}


Node* getrear(Queue* q) {
  cout<<"Inside getrear \n";

  Node *temp ;

  if(q->rear == NULL) {
    return 0;
  }

  temp = q->rear;
  return temp;
}

Node* getfront(Queue *q) {

  cout<<"Inside getfront \n";

  Node *temp ;

  if(q->front == NULL) {
    return 0;
  }

  temp = q->front;
  return temp;
}


void print(Queue *q) {

  cout<<"Inside printing.......\n";
  if((q->front == NULL) && (q->rear == NULL)) {
    cout<<"Nothing to print \n";
    return;
  }

  Node *current = q->front;
  while(current != NULL) {
    cout<<current->data<<"\n";
    current = current->next;
  }

}


void deleterear(Queue *q) {
  cout<<"inside delete Rear \n";

  if(q->front == NULL && q->rear == NULL) {
    return ;
  }

  Node *temp = q->rear->prev;
  temp->next = NULL;
  delete(q->rear);
  q->rear = temp;
  return; 
}

void deletefront(Queue *q) {
  cout<<"inside delete Front \n";

  if(q->front == NULL && q->rear == NULL) {
    return ;
  }

  Node *temp = q->front->next;
  temp->prev = NULL;
  delete(q->front);
  q->front = temp;
  return; 
}
int main() {

  Queue *q = createqueue();
  deletefront(q);
  deleterear(q);
  insertfront(q, 10);
  insertfront(q, 20);
  insertfront(q, 30);
  insertfront(q, 40);
  insertfront(q, 50);
  insertfront(q, 60);
  deleterear(q);
  insertrear(q, 70);
  insertrear(q, 80);
  print(q);
  
  Node* temp;
  temp = getfront(q);
  cout<<" front element is "<<temp->data<<"\n";
  temp = getrear(q);
  cout<<" rear element is "<<temp->data<<"\n";

  deletefront(q);
  print(q);
  deleterear(q);
  print(q);
  return 0;
}















