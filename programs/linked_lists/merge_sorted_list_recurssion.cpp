#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* initnode(int n) {

  cout<<"Inside initnode\n";
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;
  return newnode;
}

void  insertnode (Node *head, int n) {

  cout<<"Inside insert node\n";
  Node *current = head;
  Node *newnode = new Node;
  newnode->data = n;
  newnode->next = NULL;

  while(current) {
    if (current->next == NULL) {
      current->next = newnode;
      return;
    }
    current = current->next;
  }

}

void print(Node *head) {

  cout<<"Inside print node\n";
  Node *current = head;
  while(current) {
      cout <<current->data<<"\n";
    current = current->next;
  }
}


Node *  merge( Node *head1, Node *head2) {
  cout<<"Inside merge \n";

  Node* result;

    if(head1 == NULL && head2 == NULL ) {
       cout<<"both are NULL \n";
       return 0;
    }
    if(head1 == NULL) {
      cout<<"head1 is NULL \n";
      return head2;
    }
    if(head2 == NULL) {
      cout<<"head2 is NULL \n";
      return head1;
    }
    if(head1->data >= head2->data ) {
      cout<<"head1 is greater than head2 " <<head1->data<<" "<<head2->data<<" \n";
      result = head2;
      result->next = merge(head1, head2->next);
    }
    if(head1->data <= head2->data) {
      cout<<"head1 is lesser than head2 " <<head1->data<<" "<<head2->data<<" \n";
      result = head1;
     result->next = merge(head1->next, head2);
    }
   return result;
}


int main() {

  Node *head1 = initnode(1);
  Node *head2 = initnode(2);
  insertnode(head1,4);
  insertnode(head1,6);
  insertnode(head1,8);
  insertnode(head2,3);
//  insertnode(head2,5);
 // insertnode(head2,7);

  cout<<"printing list 1 \n";
  print(head1);
  cout<<"printing list 2 \n";
  print(head2);
  Node *result = NULL;
  result = merge(head1,head2);
  print(result);
}
