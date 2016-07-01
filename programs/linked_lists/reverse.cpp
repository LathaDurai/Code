#include <iostream>

using namespace std;


struct Node {
  int data;
  Node* next;
};

void print(Node *head) {
  cout<<"Inside Printing.....\n";
  Node *current = head;
  while (current) {
      cout<< current->data<<endl;
      current = current->next;
  }
}

Node*  newnode ( int n) {

  cout<<"Inside Init function \n";
  Node *fast = new Node;
  fast->data = n;
  fast->next = NULL;
  return fast;
}


void reverse(Node **head) {

  cout<<"Inside reverse node \n";
  Node *prev = NULL;
  Node *next;
  Node *current = *head;
  while(current) {   
     cout<<"Inside while node \n";
     next = current->next;
     current->next = prev;
     prev = current;
     current = next;
  }
  *head = prev;
  print(*head);
  cout<<"End of reverse node \n";
  return;

}
int main() {

  cout<<"In Main() \n";
  struct Node *head = newnode(10);
  head->next = newnode(20);
  head->next->next = newnode(30);
  head->next->next->next = newnode(40);
  head->next->next->next->next = newnode(50);

  print(head);
  reverse(&head);
  print(head);
  return 0;
}
