#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
};

Node* newNode(int n) {
  Node* newnode = new Node;
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;
  return newnode;
}

void distance(Node* root, int k) {

  static int count = 0;
  if(root == NULL) {
    return;
  }
  if(k == 0) {
    cout<< root->data;
  }
  distance(root->left, k-1);
  distance(root->right, k-1);
}

int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   distance(root, 1);
   return 0;
}


