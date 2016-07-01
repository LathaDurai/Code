#include<iostream>

using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void bubble( int arr[], int n) {
  int temp = 0, j = 0, count = 0;
  bool swapped = 1;
  while (swapped) {
     count++;
     swapped = 0;  
     ++j;
     for(int i =0; i< n-j; ++i) {
     count++;
        if (arr[i] >arr[i+1]) {
            cout<<"swapping\n";
            temp = arr[i+1];
            arr[i+1] = arr[i];
            arr[i] = temp;
            swapped = true;
        }
      }
      print(arr, n);
  }
  cout<<"count "<<count<<"\n";
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
