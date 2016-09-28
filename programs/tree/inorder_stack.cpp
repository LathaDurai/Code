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

void inorder(Node* root) {
  stack<Node*> s;
  Node* temp = root;
  while(true) {
    while(temp) {
      s.push(temp);
      temp = temp->left;
    }
    if(s.empty()) {
      return ;
    }

    temp = s.top();
    cout<<temp->data<<" ";
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
   inorder(root);
   return 0;
}


