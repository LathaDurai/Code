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

int getmax(int a, in b) {
  return (a>b)?a:b;
}

int height(Node* root) {
  if(root == NULL) {
    return 0;
  }
  int lh = height(root->left);
  int rh = height(root->right);
  return getmax(lh,rh)+1;
}

void get_width(Node* root) {
  int count[] = new int [10];
  int h = height(root);
  


int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   get_width(root);
   return 0;
}


