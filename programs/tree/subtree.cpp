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

bool identical(Node* root1,Node* root2) {
  if(root1 == NULL && root2 == NULL) {
    return true;
  }

  if(root1 == NULL || root2 == NULL) {
    return false;
  }
  if(root1->data == root2->data) {
      return (identical(root1->left, root2->left) &&
      identical(root1->right, root2->right));
  }
  else { 
    return false;
  }
}

bool subTree(Node* root1, Node* root2) {
  if(root1 == NULL || root2 == NULL) {
    return false;
  }
  if(identical(root1, root2)) {
    return true;
  } else {
    if(subTree(root1->left, root2)) {
      return true;
    }
    if(subTree(root1->right, root2)) {
      return true;
    }
  }
  return false;
}
int main() {
   Node* root1= newNode(1);
   root1->left = newNode(2);
   root1->right = newNode(3);
   root1->left->left = newNode(4);
   root1->left->right = newNode(5);
   root1->left->left->left = newNode(6);
   root1->left->left->right = newNode(7);

   Node* root2= newNode(2);
   root2->left = newNode(4);
   root2->right = newNode(5);
   root2->left->left = newNode(6);
   root2->left->right = newNode(7);
   bool ret = subTree(root1, root2);
   if(ret) {
     cout<<" root2 is subtree \n";
   } else {
     cout<<" root2 is not subtree \n";
   }
     return 0;
}


