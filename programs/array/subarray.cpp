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
  for (int i =0 ; i<size;++i) {
    for(int j =i  ; j<size; j++)  {
      for(int k = i; k<=j ; k++) {
          cout<< arr[k]<<" ";
       }
        cout<<"\n";
    }
  }
}

int main() {

  int arr[] = {1, 2, 3, 4};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  subarray(arr, size);
  return 0;
}
