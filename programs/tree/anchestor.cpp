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

bool anchestor(Node* root, int k) {

  if(root == NULL) {
    return false;
  }
  if(root->data == k) {
    return true;
  }
  if(anchestor(root->left, k) || anchestor(root->right, k)) {
    cout<<root->data;
    return true; 
  }
  return false;
}



int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->left->left->left  = newNode(7);
   bool res = anchestor(root, 7);
   return 0;
}


