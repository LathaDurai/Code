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

int height(Node *root) {
  if(root ==NULL) {
    return 0;
  }
  int ret = 0;
  int left = 0;
  int right = 0;
  left = height(root->left);
  right = height(root->right);
  if(left>right) {
      ret = 1+left;
  } else {
      ret = 1+right;
  }
  return ret;
}
    
void levelprint(Node *root, int i) {

  if(root == NULL) {
    return;
  }
  if(i == 1) {
    cout<<root->data<<" ";
  } else if( i>1) {
     levelprint(root->left, i-1);
     levelprint(root->right, i-1);
  }
}

void printinorder( Node* root) {
    int h = height(root);
     for(int i= 1; i<= h; i++) {
       levelprint(root, i);
     }
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
  printinorder(root);
  return 0;

}
