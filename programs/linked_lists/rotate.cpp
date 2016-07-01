#include<iostream>

using namespace std;

struct Node {

  int data;
  Node *next;
};

void print (Node *head) {

  cout<<"Inside Print function \n";
  Node *current = head;
  while(current) {
    cout<<current->data<<endl;
    current = current->next;
  }
}

Node* initnode( int n) {

  cout<<"inside initnode \n";
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}

void insertnode(Node *head, int n) {

  cout<<"inside insertnode \n";
  Node *current = head;
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;

  while(current) {
    if(current->next == NULL) {
      current->next = newnode;
      return;
    }
    current = current->next;
  }
} 

void rotate (Node **head, int K) {

  cout<<"inside Rotate \n";
  Node *current = *head;
  Node *prev, *next, *start;
  int count = 0;
  while(current) {
    if ((current->next == NULL) && (count < K)) {
      break;
    }
    count++;
    if(count == K) {
       cout<<" count and K are equal " << count<< "\n";
       prev = current;
       start = current->next;
    }
  
    if((current->next == NULL) && (count > K)) {
       cout<<"Current->next is NULL "<<count<<" "<<current->data<<"\n";
       current->next = *head;
       prev->next = NULL;
       *head = start;
       break;
    }
    current = current->next;
  }
  return;
}

int main() {

  Node *head = initnode(10);

  insertnode(head, 20);
  insertnode(head, 30);
  insertnode(head, 40);
  insertnode(head, 50);
  insertnode(head, 60);
  insertnode(head, 70);
  insertnode(head, 80);
  print(head);

  rotate(&head, 1);
  print(head);

}
