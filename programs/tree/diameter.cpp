#include<iostream>
using namespace std;

struct Node {
  int data;
  Node *left;
  Node *right;
};

Node* newnode(int n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int max (int l, int r) {
  return (l>=r)? l : r;
}

int height(Node* root) {
  int left, right;
  if(root == NULL) {
    return 0;
  }
  left =  height(root->left);
  right = height(root->right);
  return max(left, right)+1;
}

int diameter(Node* root) {
  int h, hleft, hright, ldiameter, rdiameter;

  if(root == NULL) {
    return 0;
  }
  hleft = height(root->left);
  hright = height(root->right);

  ldiameter = diameter(root->left);
  rdiameter = diameter(root->right);

  return max(max(ldiameter, rdiameter), (1+hleft+hright)); 
}

int main() {
  Node *root = newnode(1);
  root->left = newnode(2);
  root->right = newnode(3);
  root->left->left = newnode(4);
  root->right->right = newnode(5);
  root->left->left->left = newnode(6);
  root->left->left->left->left = newnode(8);
  root->right->right->right = newnode(7);
  root->right->right->right->right = newnode(9);
  root->right->right->right->right->right = newnode(10); 
  int ret = diameter(root);
  cout<<"diameter is "<<ret<<"\n";
  return 0;
}
