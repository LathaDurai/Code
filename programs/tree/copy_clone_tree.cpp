#include<iostream>
#include<map>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* random;
};

Node* newNode(int n) {
  Node* newnode = new Node;
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->random = NULL;
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
Node* copy_left_right(Node* root, map<Node*, Node*> *m1) {
  
  if(root == NULL) {
    return 0 ;
  }
  
  Node* clone  = newNode(root->data);
  (*m1)[root] = clone;
  clone->left = copy_left_right(root->left, m1);
  clone->right = copy_left_right(root->right, m1);
  return clone;
}

Node* copy_random(Node* root, Node* clone, map<Node*, Node*> m1) {
  if(root == NULL) {
    return 0;
  }
  clone->random = m1[root->random];
  copy_random(root->left, clone, m1);
  copy_random(root->right, clone, m1);
  return clone;
}

void clone(Node* root) {

  if(root == NULL) {
    return ;
  }
  map <Node*, Node*> m1;
  Node* clone = copy_left_right(root, &m1);
  inorder(clone);
}

int main() {
   Node* root;
   root = NULL;
   root = newNode(1);
   root->left = newNode(2);
   root->right = newNode(2);
   root->left->left = newNode(4);
   root->left->left->random = root;
   root->left->right = newNode(5);
   root->left->right->left = newNode(35);
   root->left->right->right = newNode(15);
   clone(root);

   return 0;
}


