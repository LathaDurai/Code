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

void postorder(Node* root) {
  stack<Node*> s1;
  stack<Node*> s2;
  Node* temp = root;
  s1.push(temp);
  while(!s1.empty()) {
    temp = s1.top();
    s1.pop();
    s2.push(temp);
    if(temp->left != NULL) 
      s1.push(temp->left);
    if(temp->right != NULL)
      s1.push(temp->right);
  }

  while(!s2.empty()) {
    temp = s2.top();
    s2.pop();
    cout<<temp->data;
  }
}


int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   root->right->left = newNode(6);
   root->right->right = newNode(7);
   postorder(root);
   return 0;
}


