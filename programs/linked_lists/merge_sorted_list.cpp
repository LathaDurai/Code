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
 
  Node *res_head;
  Node *tail = res_head;
  if((head1 ==NULL) && (head2 == NULL)) {
    return 0;
  }
  
  while (1) {
      if (head1 == NULL) {
         cout<<"head1 is NULL \n";
         tail->next = head2;
         return res_head->next;
      }
      if (head2 == NULL) {
         cout<<"head2 is NULL \n";
         tail->next = head1;
         return res_head->next;
      }
      if(head1->data <= head2->data ) {
        cout<<"head1 is less than head2 is "<<head1->data <<" "<<head2->data <<"\n";
        Node *newnode = head1;
        head1 = head1->next;
        tail->next = newnode;
        tail = tail->next;
      } else if (head1->data >= head2->data) {
        cout<<"head1 is greater than head2 is "<<head1->data <<" "<<head2->data <<"\n";
        Node *newnode = head2;
        head2 = head2->next;
        tail->next = newnode;
        tail = tail->next;
      }
   }
      return res_head->next;
}
int main() {

  Node *head1 = initnode(1);
  Node *head2 = initnode(2);
  insertnode(head1,4);
  insertnode(head1,6);
  insertnode(head1,8);
  insertnode(head1,13);
  insertnode(head1,22);
  insertnode(head1,90);
  insertnode(head2,3);
  insertnode(head2,13);
  insertnode(head2,55);
  insertnode(head2,67);
  insertnode(head2,100);
  insertnode(head2,117);

  cout<<"printing list 1 \n";
  print(head1);
  cout<<"printing list 2 \n";
  print(head2);
  Node *result = NULL;
  result = merge(head1,head2);
  print(result);
}
