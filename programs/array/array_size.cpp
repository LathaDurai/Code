#include<iostream>

using namespace std;

int main() {

  int arr[4] = {1,2,3,4};
  int *ptr;
  ptr = &arr[0];
  cout<<"sizeof(arr) = "<<sizeof(arr)<<"\n";
  cout<<"sizeof(arr[0]) = "<<sizeof(arr[0])<<"\n";
  cout<<"sizeof(int) = "<<sizeof(int)<<"\n";
  cout<<"sizeof(ptr) = "<<sizeof(ptr)<<"\n";
  return 0;
}

