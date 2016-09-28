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

void inorder(Node* root) {
  if(root == NULL) {
    return;
  }
  inorder(root->left);
  cout<<root->data;
  inorder(root->right);
}

void preorder(Node* root) {
  if(root == NULL) {
    return;
  }
  cout<<root->data;
  preorder(root->left);
  preorder(root->right);
}
void postorder(Node* root) {
  if(root == NULL) {
    return;
  }
  postorder(root->left);
  postorder(root->right);
  cout<<root->data;
}
int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   inorder(root);
   cout<<"\n";
   preorder(root);
   cout<<"\n";
   postorder(root);
   return 0;
}


