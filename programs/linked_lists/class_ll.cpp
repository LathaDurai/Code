#include <iostream>
#include <cstddef>
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
     Node* insert(Node *head,int data)
      {
          cout<<"inside insert \n";
          Node *newnode = new Node(data);
          //Complete this method
          if(head == NULL) {
               cout<<"head is null \n";
               head = newnode;
               return head;
          }          
         Node *temp = head;
          while(temp) {
              cout<<"inside while\n";
              if(temp->next == NULL) {
                 cout<<"isnide if \n";
                 temp->next = newnode;
                 cout<<"newdata "<<newnode->data<<"\n";
                  return head;
              } 
              temp = temp->next;
          }
          
          return NULL;
      }

    void display(Node *head)
      {
         cout<<"\n\n\n";
          Node *start=head;
          while(start)
          {
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
 mylist.display(head);
  
}
