#include<iostream>
using namespace std;

struct Node {
  char data;
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

int search(char temp , char in[], int start, int end) {
  
  for(int i = start; i<=end; i++) {
    if(temp == in[i]) {
       return i;
    }
  }
  return 0;
}

Node*  createtree(char in[], char pre[], int start, int end) {

  if(start> end) {
    return NULL;
  }
  static int preindex = 0;
  Node* temp = newNode(pre[preindex]);
  preindex++; 
  if(start == end) {
    return temp;
  }
  int inindex = search(temp->data, in, start, end);
  cout<<"inindex is "<<inindex<<"\n";
  temp->left = createtree(in, pre, start, inindex-1);
  temp->right = createtree(in, pre, inindex+1, end);
  return temp; 
}

void printinorder(Node* temp) {
  if (temp == NULL) {
    return ;
  }
  printinorder(temp->left);
  cout<<temp->data;
  printinorder(temp->right);

}

int main() {

   char in[] = {'D', 'B', 'E', 'A', 'F', 'C'};
   char pre[] = {'A', 'B', 'D', 'E', 'C', 'F'};
   int size = sizeof(in)/sizeof(in[0]);
   Node* temp = createtree(in, pre, 0, size-1);
   printinorder(temp);
   return 0;
}


