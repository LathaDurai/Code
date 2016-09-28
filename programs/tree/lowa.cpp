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

Node*  lca(Node* root, int v1, int v2) {
  if(root == NULL) {
    return NULL;
  }
   if(root->data == v1 || root->data ==v2) {
      return    
    }
    if(root->data < v1 && root->data < v2) {
      root = root->right;
    }
    else 
      break;
  }
    return root;
}

int main() {
    Node* root= newNode(8);
   root->left = newNode(4);
   root->right = newNode(9);
   root->left->left = newNode(1);
   root->left->right = newNode(2);
   root->right->left = newNode(3); 
   root->right->right = newNode(6); 
   root->left->left->left = newNode(5); 
   Node* res = lca(root, 1, 2);
   cout<<" ans is "<<res->data<<"\n";
   return 0;
}


