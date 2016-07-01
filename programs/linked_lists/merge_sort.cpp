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

Node* merge_sort(Node *left, Node *right) {

  Node* result;
  cout<<"inside merging \n";
  if(left == NULL && right==NULL) {
    cout<<"left and right are NULL \n";
    return 0;
  }
  if(left == NULL) {
    cout<<"Left is NULL "<<right->data<<"\n";
    return right;
  }
  if(right == NULL) {
    cout<<"Right is NULL \n";
    return left;
  }

  if(left->data <= right->data) {
    cout<<"left data is less "<<left->data<<"  \n";
    result = left;
    result->next = merge_sort(left->next, right);
  }
  if(left->data > right->data) {
    cout<<"left data is greater  "<<left->data<<"\n";
    result = right;
    result->next = merge_sort(left, right->next);
  }
  cout<<"printing result \n";
  print(result);
  return result;
}

void  merge( Node **head) {
  cout<<"Inside merge \n";
   
  Node *current = *head;
  if (current == NULL || current->next == NULL) {
    cout<<"inside current NULL \n"; 
    return;
  }
  Node*  fast = current;
  Node* slow = current;
  Node* middle;
  Node *left;
  Node *right;
 
  while ((fast->next != NULL) &&  (fast->next->next!= NULL)) {
     cout<<"fast->data "<<fast->data <<" slow->data "<<slow->data<<"\t";
     cout<<"fast->next "<<fast->next->data<<" "<<"fast->next->next "<<fast->next->next->data<<"\n";
     slow = slow->next;
     fast = fast->next->next;
  }
  middle = slow;
  cout<<"middle element is "<<slow->data <<"\n";

  left = *head;
  right = slow->next;
  slow->next = NULL;
  cout<<"left->data "<<left->data<<"\n";
  cout<<"right->data "<<right->data<<"\n";
  cout<<"left dataaaa \n";
  print(left);
  cout<<"right dataaaa \n";
  print(right);
  merge(&left);
  merge(&right);
  *head  =  merge_sort(left, right);
}
int main() {

  Node *head = initnode(1);
  insertnode(head,4);
  insertnode(head,16);
  insertnode(head,11);
  insertnode(head,3);
  insertnode(head,2);
  insertnode(head,10);
  insertnode(head,5);
  insertnode(head,50);
  insertnode(head,33);
  insertnode(head,100);
  insertnode(head,1 );

  cout<<"printing list 1 \n";
  print(head);
  merge(&head);
  print(head);
}
