#include<iostream>

struct Node {
  int pet;
  int dis;
  Node* next;
};

void initnode(Node *head, int m, int n) {

   head->pet = m;
   head->dis = n;
   head->next = head;
     
}
void insertnode(Node *head, int m, int n) {

   Node *current = head;
   Node *newnode = new Node;
   newnode->pet = m;
   newnode->dis = n;
   newnode->next = head;

   if(current == NULL) {
      return;
   }
     

  while(current != NULL) {
     if(current->next == head) {
       current->next = newnode;
       return;
     }
     current = current->next;
  }
}

void display(Node *head) {
  Node *current = head;
  if(current) {
    do {
      std::cout<<current->pet<<" "<<current->dis<<"\n";
      current = current->next;
    }while(current!=head);
  }
}

bool find (Node* head, int sum, Node* start) {

  std::cout<<"Inside find \n";
  bool stat = true;
  Node* current = head;
  while((current->next != start) && (stat == true)) {
      int diff = current->next->pet - current->next->dis;
      sum = sum+diff;
      if(sum <=0) {
        std::cout<<" sum is negative or zero "<<sum <<"\n";
         stat = 0;
         return stat;
       }
       current = current->next;
    }
   return stat;
}

void calculate (Node* head) {
 
  std::cout<<"Inside calculate \n";
  Node *current = head;
  int sum = 0;
  int count = 0;
  if(current == NULL) {
    return;
  }
  do {
    std::cout<<"current pet is "<<current->pet<<"\n";
    Node *start = current;
    sum = current->pet - current->dis;
    if(sum <=0) {
       current = current->next;
       continue;
    }
    if(find(current, sum, start)) {
      std::cout<<" you can start from "<< current->pet<<" "<<current->dis<<"\n";
      count++;
    }
    current = current->next;
  } while(current != head);

  std::cout<<" there are totally "<<count <<" no of node to start \n";
}



int main() {

  Node *node = new Node;
  initnode(node,  3,4 );
  insertnode(node, 5 ,7 );
  insertnode(node, 3, 4);
  insertnode(node, 8,8 );
  insertnode(node, 6,1 );


  display(node);

  calculate(node);
  return 0;
}

