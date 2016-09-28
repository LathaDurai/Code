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

Node* createMirror(Node* root) {
  if(root == NULL) {
      return NULL;
  }
  Node* temp = newNode(root->data);
  temp->left = createMirror(root->right);
  temp->right = createMirror(root->left);
  return temp;
}
int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   inorder(root);
   cout<<"\n";
   Node* ret = createMirror(root);
   inorder(ret);
   return 0;
}


