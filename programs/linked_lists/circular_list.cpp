#include<iostream>

using namespace std;

struct node {
   int data;
   node* next;
};

node *head = new node;

void initnode(int num) {
   cout<<"Inside Initnode \n";
   head->data = num;
   head->next = head;
}

void addnode(int num) {
  cout<<"Inside Addnode \n";
  node *current = head;
  node *newnode = new node;
  newnode->data = num;
  newnode->next = head;
  while(current) {
    if (current->next == head) {
      current->next = newnode;
      return;
    }
    current = current->next;
  }
}

void display() {
   cout<<"Inside display \n";
   node *current = head;
   if(current) {
     do {
       cout<<"values are "<<current->data<<"\n";
       current = current->next;
     }while(current != head);
   }
}


int main() {

  initnode(10);
  addnode(20);
  addnode(30);
  addnode(40);
  addnode(50);
  display();

}

