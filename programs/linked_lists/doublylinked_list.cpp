#include<iostream>
using namespace std;


struct node {
  int data;
  node *prev;
  node *next;
};

node *head = new node;

void initnode(int num) {
  cout<<"Inside Initnode \n";
  head->data = num;
  head->prev = NULL;
  head->next = NULL;
}

void addnode(int num) {
  cout<<"Inside Addnode \n";
  
  node *current = head;
  node *newnode = new node;
  newnode->data = num;
  while(current) {
    if (current->next == NULL) {
      newnode->prev = current;
      newnode->next = NULL;
      current->next = newnode;
      return;
    }
    current = current->next;
  }

}

void reverse (node **head) {

  cout<<"Inside reverse function \n";
  node *current = *head;
  node *temp = NULL;

  while(current!= NULL) {
      cout<<"inside while of reverse \n";
      temp = current->prev;
      current->prev = current->next;
      current->next = temp;
      current = current->prev;
  }

  if(temp != NULL) {
    cout<<"Inside temp \n";
     *head = temp->prev;
     cout<<"head->data "<<(*head)->data<<"\n";
  }
} 
void display() {

  cout<<"Inside Display \n";
  node *current = head;
  while (current) {
    cout<<"Values are "<<current->data<<"\n";
    current = current->next;
  }
}

int main() {
  initnode(10);
  addnode(20);
  addnode(30);
  addnode(40);
  addnode(50);
  display();
  reverse(&head);
  display();

}
