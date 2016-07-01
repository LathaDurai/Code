#include<iostream>
using namespace std;

void print(int arr[], int size) {
  cout<<"Inside Printing... \n";
  for(int i = 0; i< size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}


int main() {

  int arr[] = {6, 8, 4, 5, 2, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  return 0;
}
