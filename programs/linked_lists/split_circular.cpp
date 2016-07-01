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
  newnode->next  = newnode;
  return newnode;
}

void addnode(Node *head, int n) {

  cout<<"Inside" <<__func__<< "\n";
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = head;
  Node *current = head;
  while(current) {
    cout<<"Inside while \n";
    if(current->next == head) {
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
    if(current->next == head) {
       return;
    }
    current= current->next;
  }while(current);

}

void split(Node *head, Node** head1, Node **head2) {

  cout<<"inside split func \n";
  Node *current = head;
  Node *fast = head;
  Node *slow = head;

  if(slow == NULL) {
    return;
  }

  while( fast->next != head && fast->next->next  != head) { 
    cout<<"inside split func whileee \n";
    slow = slow->next;
    fast = fast->next->next;
  }

  if(fast->next->next == head) {
    fast = fast->next;
  }

  *head1 =head;

  *head2 = slow->next;

  slow->next = *head1;

  fast->next = *head2;

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
  Node *head1, *head2;
  split(head, &head1, &head2);
  print(head1);
  print(head2);
}

