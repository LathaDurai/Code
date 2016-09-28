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

int diameter(Node* root, int *height) {
  int h, hleft, hright, ldiameter, rdiameter;

  if(root == NULL) {
    height = 0;
    return 0;
  }
  hleft = 0;
  hright = 0;

  ldiameter = diameter(root->left, &hleft);
  rdiameter = diameter(root->right, &hright);
  *height = max(hleft, hright)+1;
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
  int *i = new int;;
  int ret = diameter(root, i);
  cout<<"diameter is "<<ret<<"\n";
  return 0;
}
