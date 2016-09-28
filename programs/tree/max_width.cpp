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

int getmax(int lh, int rh) {

  return (lh>=rh)?lh:rh;
}

int height(Node* root) {
  int lh, rh;
  if(root== NULL) {
    return 0;
  }
  lh = height(root->left);
  rh = height(root->right);
  int ret = getmax(lh, rh);
  return ret+1;
}

int width(Node* root, int h) {
  int count = 0;
  int res1 = 0, res2 =0;
  if(root==NULL) {
    return 0;
  }
  if(h == 1) {
    count++;
    return count;
  }
  if(h>1) {
     res1 = width(root->left, h-1);
     res2 = width(root->right, h-1);
  }
  return res1+res2;
}
void max_width(Node* root) {
  Node* temp = root;
  int h  = height(root);
  int max = 0;
  for(int i = 1; i<=h; i++) {
    int ret = width(root, i);
    if(ret >= max) {
      max = ret;
    }
  }
  cout<<"Maximum width is "<<max<<"\n";
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
   max_width(root);
   return 0;
}


