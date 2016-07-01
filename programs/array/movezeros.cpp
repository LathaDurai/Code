#include<iostream>
using namespace std;

void print(int arr[], int size) {
  cout<<"Inside Printing... \n";
  for(int i = 0; i< size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

/*void movezeros( int *arr, int size) {
  cout<<"Inside movezero \n";
  int temp = arr[0];
  int count = 0;
  for(int i = 1; i<size; ++i ) {
    if(temp  == 0) {
         count++;
         cout<<"count is "<<count<<"\n";
         if(arr[i] == 0) {
         }
         if(arr[i] > 0) {
           arr[i-count] = arr[i];
           arr[i] = 0;
           count --;
         }
    }
    temp = arr[i];
  }
 } */

void movezeros( int *arr, int size) {
  cout<<"Inside movezero \n";
  int count = 0;
  for(int i = 0; i<size; ++i ) {
         if(arr[i] == 0) {
          cout<<"count is "<<count<<"\n";
          count ++;
         }
         if(arr[i] > 0) {
           arr[i-count] = arr[i];
           if(count !=0) 
              arr[i] = 0;
         }
        print(arr, size);
    }
}
int main() {

  int arr[] ={1,0,2,0,3,0,4,0,5,0,7,0,6,0};
 // int arr[] ={6,8,0,0,4,0,5,0,2,3,0,0};
 // int arr[] ={1,1,1,1,0};
  //int arr[] ={14,0,0,0,0,0,14};
  //int arr[] ={0,0,0,0,0,1};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  movezeros(arr, size);
  print(arr, size);
  return 0;
}
