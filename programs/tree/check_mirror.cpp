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

bool checkMirror(Node* a, Node* b) {

  if(a == NULL && b == NULL) {
    return true;
  }
  if(a == NULL || b == NULL) {
    return false;
  }

  cout<<a->data<<" "<<b->data<<"\n";
  if(a->data == b->data) {
    if(checkMirror(a->left,b->right)) {
      if(checkMirror(a->right, b->left)) {
         cout<<"second check \n";
         return true;
      }
    }
  }
  return false;
}




int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->left->left = newNode(4);
   root->left->right = newNode(5);

   Node* b = newNode(1);
   b->left = newNode(3);
   b->right = newNode(2);
   b->right->left = newNode(5);
   b->right->right = newNode(4);
   bool ret  =  checkMirror(root, b);
   if(ret) {
     cout<<" trees are Mirror \n";
   } else {
     cout<<" trees are Not Mirror \n";
   }
   return 0;
}


