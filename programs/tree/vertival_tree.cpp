#include<iostream>

using namespace std;


struct Node {
  int data;
  Node *left;
  Node *right;
};

Node * newNode(int n) {

  Node *newnode = new Node;
  newnode->data = n;
  newnode->right =NULL;
  newnode->left = NULL;
  return newnode;
}

void printvertical(Node *root) {

int main() {

   Node *root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->right->left = newNode(6);
   root->right->right = newNode(7);
   root->right->left->right = newNode(8);
   root->right->right->right = newNode(9);

   printvertical(root);
   return 0;
}
