#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node* nextright;
};

Node* newNode(int n) {
  Node* newnode = new Node;
  newnode->data = n;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->nextright = NULL;
  return newnode;
}

int getmax(int a, int b) {
  return (a>b)?a:b;
}

int height(Node* root) {
  if(root == NULL) {
    return 0;
  }
  int lh = height(root->left);
  int rh = height(root->right);
  return getmax(lh, rh)+1;
}

void fill(Node* root, int i) {

  if(root == NULL) {
    return;
  }
  if(i == 1) {
     root->nextright = NULL;
     return;
  }
  Node* temp = root;
  if(i<1) {
    while((count != i) && (temp ! == NULL)) {
      count++;
      temp = temp->left;
    }
   if(count == i) {
     temp = root->left;
     if
     temp->nextright = root->right;
     fill(root->right, i-1);




Node* connect(Node* root) {
  if(root == NULL) {
    return NULL;
  }
  int h = height(root);
  for(int i = 1; i<= h; i++) {
    fill(&root, i);
  }
  return root;  
}

void print(Node* temp) {
  if(temp == NULL) {
    return;
  }
  cout<<temp->nextright;
  print(temp->left);
  print(temp->right);
}
  
int main() {
   Node* root= newNode(1);
   root->left = newNode(2);
   root->right = newNode(3);
   root->right->right = newNode(6);
   root->left->left = newNode(4);
   root->left->right = newNode(5);
   Node* temp = connect(root);
   print(temp);
   return 0;
}


