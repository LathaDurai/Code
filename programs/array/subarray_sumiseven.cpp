#include<iostream>
using namespace std;

void print(int arr[], int size) {
  cout<<"Inside Printing... \n";
  for(int i = 0; i< size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void subarray(int arr[], int size) {
  cout<<"inside Subarray \n";
  cout<< "size "<<size<<"\n";
  int result = 0;
  for(int i = 0; i<size; ++i) {
    int sum = 0;
    for (int j = i; j<size; j++) {
       sum = sum+arr[j];
       cout<<sum<<"\n";
       if((sum %2) == 0) {
         result++;
       }
    }
  }
  cout<< "no of sub arrays with sum as even is "<<result<<"\n";
}

int main() {

  int arr[] = {1, 2, 3, 4, 3,3, 6};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  subarray(arr, size);
  return 0;
}
