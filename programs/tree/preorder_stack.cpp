#include<iostream>
#include<stack>
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

void preorder(Node* root) {
  stack<Node*> s;
  Node* temp = root;
  while(true) {
    while(temp) {
     cout<<temp->data<<" ";
      s.push(temp);
      temp = temp->left;
    }
    if(s.empty()) {
      return ;
    }

    temp = s.top();
    s.pop();
    temp = temp->right;
  }
}


int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->left->left->left  = newNode(10);
   root->left->left->right = newNode(8);
   root->left->right->left = newNode(6);
   root->left->right->right = newNode(7);
   root->left->right->right->left = newNode(11);
   root->left->right->left->right= newNode(14);
   root->left->right->left->left = newNode(12);
   root->left->right->left->right->left= newNode(13);
   preorder(root);
   return 0;
}


