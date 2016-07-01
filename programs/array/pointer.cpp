#include<iostream>
using namespace std;

int main() {
  // ********** normal pointer
  int a = 5;
  int *ptr = new int;
   // initialize to zero
   //int *ptr = new int (0);
  ptr =&a;
  cout<< *ptr;
  cout<< a;

  // ********1-d array
  int arr[5];
  int *ptr1 = new int[5];
  arr[0] = 1;
  arr[1] = 2;
  arr[2] = 3;
  arr[3] = 4;
  arr[4] = 5;
  ptr1 = arr;

  cout<<"\n"<<*(ptr1+1)<<"\n";;
  cout<<"sizeof(arr)"<<sizeof(arr)<<"\n";
  cout<<"sizeof(arr[0])"<<sizeof(arr[0])<<"\n";
  cout<<"sizeof(ptr1)"<<sizeof(ptr1)<<"\n";

  //int ptr1 = (int*)malloc(sizeof(int)*5);


  int arr2[2][3];
  int **ptr2 = new int*[3];
  for(int i=0;i<3;++i) {
    ptr2[i]=  new int[2];
  }
  arr2[0][0] = 1;
  arr2[0][1] = 2;
  arr2[0][2] = 3;
  arr2[1][0] = 4;
  arr2[1][1] = 5;
  arr2[1][2] = 6;
   
  //ptr2 = arr2;
  for(int i=0;i<2;++i) {
    for(int j=0;j<3;++j) {
      cout<<arr2[i][j];
    }
    cout<<"\n";
  } 
  
  return 0;
}
