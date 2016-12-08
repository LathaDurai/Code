#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std; 
class Node
{
    public:
        int data;
        Node *next;
        Node(int d){
            data=d;
            next=NULL;
        }
};
class Solution{
    public:        
      Node* removeDuplicates(Node *head)
          {
              cout<<"Inside Remove\n";
              if(head == NULL) {
                  return NULL;
              }
              Node* temp = head;
              Node* tn = temp->next;
              while(temp && tn) {
                  cout<<temp->data<<"\n";
                  if(temp->data == tn->data) {
                     cout<<temp->data<<"\n";
                     temp->next = tn->next;
                     tn = temp->next;
                     continue;
                  }
                  temp = temp->next;
                  tn = temp->next;
              }
              return head;
          }          



Node* insert(Node *head,int data)
          {
               Node* p=new Node(data);
               if(head==NULL){
                   head=p;  

               }
               else if(head->next==NULL){
                   head->next=p;

               }
               else{
                   Node *start=head;
                   while(start->next!=NULL){
                       start=start->next;
                   }
                   start->next=p;   

               }
                    return head;
                
            
          }
          void display(Node *head)
          {
                  Node *start=head;
                    while(start)
                    {
                        cout<<"Displaying.. \n";
                        cout<<start->data<<" ";
                        start=start->next;
                    }
           }
};
   
int main()
{
 Node* head=NULL;
   Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    } 
    head=mylist.removeDuplicates(head);

 mylist.display(head);
  
}
