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

/*void insert(Node *head, int n) {
  Node *current = head;
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;

  if(current->next == NULL) {
     current->next = newnode;
     return;
  }
   
  while(current) {
    if(current->next == NULL) {
       current->next = newnode;
       return;
    }
    current = current->next; 
  }
}


void removeLoop(Node *head, Node *slow) {
  cout <<"Inside removeloop ...........\n";
  Node *p1 = head;
  Node *p2 = slow;
  while(p1) {
    cout<< p1->data<< p2->data<< "\n";
    iif (p1 == p2->next) {
       p2->next = NULL;
       return;
    }
    p1 = p1->next;
    p2 = p2->next;
  }
  return;
}
*/
void findLoop(Node *head) {
  cout <<"Inside Findloop ...........\n";
  Node *fast = head->next;
  Node *slow = head;
  
  while(slow) {
    cout<<"Inside While of findloop \n";
       if(slow== fast) {
           cout<<"Loop is found\n";
           break;
       }
      slow = slow->next;
      fast = fast->next->next;
  }
  cout<< slow->data<< fast->data<< "\n";

  if (slow == fast) {
    cout<<"both nodes are equal\n";
    slow = head;
      cout<<" loop "<<slow->data << (fast->next)->data<<"\n";
      while( slow != fast->next) {
         slow = slow->next;
         fast = fast->next;
     }
    fast->next = NULL;
  }
}  



int main() {

  cout<<"In Main() \n";
  struct Node *head = newnode(10);
  head->next = newnode(20);
  head->next->next = newnode(30);
  head->next->next->next = newnode(40);
  head->next->next->next->next = newnode(50);

  print(head);
  head->next->next->next->next->next = head;
  
  findLoop(head);
  //removeLoop(head);
  print(head);
  return 0;
}
