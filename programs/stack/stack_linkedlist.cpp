#include <iostream>

using namespace std;

struct Node {
   int data;
   Node *next;
};

bool isempty(Node *head) {
  cout<<"Is Empty \n";
  if(!head) {
    cout<<"List is empty\n";
    return 1;
  }
  return 0;
}

void push(Node **head, int n) {

  cout <<"Pushing Function \n";
  Node *current = new Node;
  current = *head;
  Node *temp = new Node;
  temp->data = n;
  temp->next = *head;
  *head = temp;

}

void pop( Node **head) {

  cout <<"Poping Function \n";
  bool res=  isempty(*head);
  if (res) {
    cout<<"List is empty\n";
    return;
  }
  Node *current  = *head;
 // Node *prev = NULL; 
 // Node *next = current->next;
  cout <<"POPOPOP \n";
    cout <<"Poped element is "<<current->data<<"\n";
    *head = current->next;
    delete current;
    return;

}
void peek( Node **head) {

  cout <<"Peeking Function \n";
  bool res=  isempty(*head);
  if (res) {
    cout<<"List is empty\n";
    return;
  }
  Node *current  = *head;
 // Node *prev = NULL; 
  //Node *next = current->next;
  cout <<"Peeeeeeeeeeek \n";
      cout <<"Peek element is "<<current->data<<"\n";
      return;
}
int main() {

  struct Node *head = NULL; 
  cout <<"Pushing elemets \n";
  push(&head, 10);
  push(&head, 20);
  push(&head, 30);
  push(&head, 40);
  cout <<"Poping elemets \n";
  pop(&head);
  cout <<"Peeking elemets \n";
  peek(&head);  
  cout <<"Poping elemets \n";
  pop(&head);
  return 0;
}
