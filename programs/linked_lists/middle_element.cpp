#include<iostream>

using namespace std;


struct Node {
  int data;
  Node *next;
};

Node *newnode (int n) {
  cout<<"Inside" <<__func__<< "\n";
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next  = NULL;
  return newnode;
}

void addnode(Node *head, int n) {

  cout<<"Inside" <<__func__<< "\n";
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;
  Node *current = head;
  while(current) {
    cout<<"Inside while \n";
    if(current->next == NULL) {
      cout<<"Current->next is head \n";
      current->next = newnode;
      return;
    }
    current = current->next;
  }
}
 
void print(Node *head) {

  cout<<"Inside" <<__func__<< "\n";
  Node *current = head;
  if(current == NULL) {
    return;
  }
  do {
    cout<<current->data<<"\n";
    if(current->next == NULL) {
       return;
    }
    current= current->next;
  }while(current);

}

void middle (Node *head) {

  cout<<"inside finding middle func \n";
  Node *current = head;
  Node *fast = head;
  Node *slow = head;

  if(slow == NULL) {
    return;
  }

  while( fast->next != NULL && fast->next->next  != NULL) { 
    cout<<"inside middle func whileee \n";
    slow = slow->next;
    fast = fast->next->next;
  }
  if( slow->next == NULL) {
    cout<<"Something wrong \n";
  }
  cout<<"Middle element is "<<slow->data <<"\n";

}



int main() {

  Node *head = newnode(10);
  addnode(head, 20);
  addnode(head, 30);
  addnode(head, 40);
  addnode(head, 50);
  addnode(head, 60);
  addnode(head, 70);
  addnode(head, 80); 
  print(head);
  middle(head);
}

