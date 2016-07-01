#include<iostream>
using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void insertion(int arr[], int size) {
   cout<<"Inside Insertion \n";
   int value = 0, hole = 0,count = 0;
   for (int i=0; i<size; ++i) {
      count++;
      cout<<"Inside for "<< i<<" \n";
      hole = i+1;
      value = arr[i+1];
      while ((hole > 0) && (arr[hole -1] > value)) {
      count++;
          cout<<" value and hole-1 and hole "<<value<<" "<<arr[hole-1]<<" "<< arr[hole] <<"\n"; 
          cout<<"Inside while "<< hole <<" \n";
          arr[hole] = arr[hole -1];
          hole --;
          arr[hole] = value;
      }
      print(arr, size);
   }
   cout <<"count is "<<count<<"\n";
}
int main() {
  int arr[9] = {1,2,3,4,5,6,7,8,9};
  int size = 9;
  print(arr, size);

  insertion(arr, size);
  print(arr, size);
  return 0;
}
