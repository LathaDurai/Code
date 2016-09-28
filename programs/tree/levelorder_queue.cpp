#include<iostream>

using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* newnode(int n) {
  Node* newNode = new Node;
  newNode->data =n;
  newNode->left = NULL;
  newNode->right= NULL;
  return newNode;
}

Node** createqueue(int *front, int* rear) {
  Node **q = new Node*[10];
  *front = *rear = 0;
  return q;
}

void enqueue(Node** q, Node *temp, int* rear) {
     q[*rear]= temp;
     (*rear)++;
}

Node* dequeue(Node** q, int* front) {  
  Node* temp = q[*front];
  (*front)++;
  return temp;
}



void printorder(Node* root) {
  int front, rear;
  Node* temp= root;;
  Node** q = createqueue(&front, &rear);

  if(root == NULL) {
    return ;
  }
  while (temp !=NULL) {
    cout<<temp->data<<" ";
    enqueue(q, temp->left, &rear);
    enqueue(q,temp->right, &rear);
    temp = dequeue(q, &front);
  }
}

int main() {
  Node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->left->right = newnode(5);
  root->right->right = newnode(6);
  root->right->left = newnode(7);
  printorder(root);
}

  

