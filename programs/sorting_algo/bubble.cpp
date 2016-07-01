#include<iostream>

using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void bubble( int arr[], int n) {
  int temp = 0;
  int count = 0;
  for (int i= 0; i<n; ++i) {
     count++;
     for(int j =0; j< n-1; ++j) {
     count++;
        if (arr[j] >arr[j+1]) {
            cout<<"swapping\n";
            temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
        }
      }
      print(arr, n);
  }
  cout<<"count = "<<count<<"\n";
  print(arr, n);
}

int main() {

int size = 5;
int arr[5] = {2,3,1,5,4};

print(arr, size);

bubble(arr, size);

print(arr, size);

return 0;
} 
