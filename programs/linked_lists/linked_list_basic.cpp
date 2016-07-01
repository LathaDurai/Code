#include<iostream>

using namespace std;

struct node {

  int data;
  node *next;
};

void display(node* n) {
  cout<<"inside Display Function\n";
  node * temp = n;
  while (temp) {
   cout<<"data is "<<temp->data<<"\n";
   temp= temp->next;
  } 
}

void addnode(node *head,int num) {
  cout<<"inside addnode Function\n";
  node *newnode = new node;
  newnode->data =num;
  newnode->next=NULL;
  node *cur=head;
  while(cur) {
  cout<<"inside while addnode\n";
    if(cur->next == NULL) {
      cout<<"inside addnode if\n";
      cur->next=newnode;
      return;
    }
    cur = cur->next;
  }
}

void insert(node *head,int pos, int num) {
  cout<<"Inside insert\n";
  node *newnode = new node;
  newnode->data =num;
  newnode->next=NULL;
  int count = 1;
  node *cur = head;
  if(cur->next == NULL) {
    cout<<"Inside head is NULL\n";
    cur->next = newnode;
    return;
  }
  while(cur) {
    cout<<"Inside while " << count <<"\n";
    if(cur->next == NULL) {
    cout<<"Inside while if null\n";
      cur->next = newnode;
      return;
    }
    if(count == pos) {
    cout<<"Inside while pos "<<pos<<"\n";
      node *temp = NULL;
      temp = cur->next;
      cur->next = newnode;
      newnode->next= temp;
      return;
    }
    cur = cur->next;
    count++;
  }

}

void deletenode( node *head, int pos) {
  cout << "Inside deletenode\n";
  node * cur = head;
  int count =1;
  node *temp =NULL;
  while(cur) {
  cout << "Inside deletenode while "<<count <<"\n";
    if(count == (pos-1)) {
     cout << "Inside deletenode if "<<pos-1<<"\n";
      temp = cur;
    }
    if(count == pos) {
      cout << "Inside deletenode if "<<pos<<"\n";
      temp->next=cur->next;
      delete cur;
      return;
    }
    cur = cur->next;
    count++;
  }

}

node* searchnode(node **head, int num) {
  cout<<"Inside Search node "<< num<<"\n";
  node *cur = *head;
  while (cur) {
    cout<<"inside searchnode while \n";
    if(cur->data == num) {
      cout<<"inside searchnode if \n";
      return cur;
    }
    cur = cur->next;
  }
  return cur;
}

void initnode(struct node *head, int num) {
  cout<<"Inside Initnode Fun\n";
  head->data = num;
  head->next = NULL;
}
 
void reverse( node **head) {
  cout<<"Inside reverse Fun\n";
  node * prev = NULL;
  node * cur = *head;
  node *nnxt ; // 
  while(cur) {
  cout<<"Inside reverse while  Fun\n";
    nnxt = cur->next;
    cur->next=prev;
    prev = cur;
    cur = nnxt;
  }
  *head = prev;
  return;
}


void copylinkedlist( node *head, node **newnode) {
  cout<<"Inside copy linked list \n";

    if ( head != NULL) {
       cout<<"Inside copy linked list if  \n";
       *newnode = new node;
       (*newnode)->data = head->data;
       (*newnode)->next = NULL;
       copylinkedlist(head->next, &(*newnode)->next);
    }
}

void comparelinkedlist( node *head, node *newnode) {
   cout<<"Inside Compare fun \n";
   if ((head == NULL) && (newnode == NULL)) {
     cout<<"Both are Equal\n";
     return;
   }
   if ((head == NULL) || (newnode == NULL)) {
     cout<<"Both are not equal\n";
   } else if (head->data != newnode->data) {
     cout<<"Both are not equal, Values are diff\n";
   } else 
     comparelinkedlist(head->next, newnode->next);

}

int main() {
  cout<<"inside Main Function\n";
  node *head = new node;

  cout<<"Calling initnode\n";
  initnode(head, 10);

  cout<<"\n\nAdding nodes\n";
  addnode(head,20);
  addnode(head,30);
  addnode(head,40);
  addnode(head,50);
  display(head);

  cout<<"\n\nInserting node\n";
  insert(head, 3, 5);
  display(head);

  cout<<"\n\nSearching a  node\n";
  node *search = searchnode(&head,5);
  search->data = 10;
  
  cout<<"\n\nDeleting node\n";
  deletenode(head,3);
  display(head);

  cout<<"\n\nReversing node\n";
  reverse(&head);
  display(head);

  cout<<"\n\n copying linked list\n";
  node *newone = new node;
  copylinkedlist(head,&newone);
  display(head);
  display(newone);

  comparelinkedlist(head, newone);
  
  cout<<"\n\nInserting node\n";
  insert(newone, 3, 15);
  display(newone);
  
  comparelinkedlist(head, newone);

}

