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

int height(Node* root) {
  int lh, rh;
  if(root == NULL){
    return 0;
  }
  lh= height(root->left);
  rh = height(root->right);
  if(lh<rh) 
    return lh+1;
  else 
    return rh+1;
}
int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->left->left->left = newNode(6);
   root->left->right->left = newNode(7);
   int ret = height(root);
   cout<<"maximum depth is " << ret;
   return 0;
}


