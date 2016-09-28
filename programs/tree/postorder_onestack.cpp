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
  stack<Node*> s;
  Node* temp = root;
  while(1) {
    while(temp) {
      cout<<"in second while "<<temp->data<<"\n";;
       s.push(temp);
       if(temp->right != NULL) 
         s.push(temp->right);
       temp = temp->left;
    }
    temp = s.top();
    s.pop();
    if(temp->right != NULL  ) {
      cout<<"Inside if \n";
      temp = temp->right;
    } else {
      cout<<"Inside else \n";
      cout<<temp->data;
      temp = NULL;
    }
    if(!s.empty()) {
      return;
    }
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


