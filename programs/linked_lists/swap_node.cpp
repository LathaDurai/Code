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

/*
void swap(Node *head, int x, int y) {

  cout<<"Inside SWAP\n";
  Node *current = head;
  Node *p1 = head;
  Node *p2 = head;
  Node *prev1 = NULL;
  Node *prev2= NULL ;
  Node *next1;
  Node *next2;
  int count = 0;

  while(current && current->next) {
    if (current->data == x) {
       cout <<" x matched "<<"\n";
       prev1 = current;
       p1 = current->next;
       count++;
    }
    if (current->data == y) {
      cout<<"y matched \n";
      prev2 = current;
      p2 = current->next;
      count++;
    }
    current = current->next;
  } 
  if (count == 2 ) {
     if (prev1 != NULL)
         prev1->next = p2;
     else 
          head = p2;
                         
     if (prev2 != NULL)
         prev2->next = p1;
     else 
       head = p1;


     cout <<"Swapping \n";
     next1 = p1->next;
     next2 = p2->next;
     p1->next = next2; 
     p2->next = next1;
   } else {
      cout <<" VAlues are not found \n";
      return;
  } 
} */


/* Function to swap nodes x and y in linked list by
 * changing links */
void swap( Node **head_ref, int x, int y)
{
  // Nothing to do if x and y are same
  if (x == y) return;
  
   // Search for x (keep track of prevX and CurrX
  struct Node *prevX = NULL, *currX = *head_ref;
  while (currX && currX->data != x) {
    prevX = currX;
    currX = currX->next;
  }

   // Search for y (keep track of prevY and CurrY
  struct Node *prevY = NULL, *currY = *head_ref;
  while (currY && currY->data != y)   {
     prevY = currY;
     currY = currY->next;
  }

     // If either x or y is not present, nothing to do
  if (currX == NULL || currY == NULL)
      return;

      // If x is not head of linked list
  if (prevX != NULL)
     prevX->next = currY;
  else // Else make y as new head
     *head_ref = currY; 

  // If y is not head of linked list
  if (prevY != NULL)
      prevY->next = currX;
  else // Else make x as new head
      *head_ref = currX;

  // Swap next pointers
  struct Node *temp = currY->next;
  currY->next = currX->next;
  currX->next = temp;
}

int main() {

  Node *head = initnode(1);
  insertnode(head,2);
  insertnode(head,3);
  insertnode(head,4);
  insertnode(head,5);
  insertnode(head,6);

  print(head);
  swap(&head, 1, 3);
  print(head);
}
