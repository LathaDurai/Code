#include<iostream>
using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int partition(int *arr, int start, int end) {
  int pIndex =0, pivot = 0, temp = 0;
  pIndex = start;
  pivot = arr[end];
  cout<<"Inside partition "<<pivot<<"\n";
  print(arr, end);
  for (int i= start; i< end; ++i) {
      if (arr[i] <=  pivot) {
         // swap( arr[i], arr[pindex])
         cout<<"arr[i] "<<arr[i]<<" "<<arr[pIndex]<<"\n";
         temp = arr[i];
         arr[i] = arr[pIndex];
         arr[pIndex] = temp;
         pIndex++;
      }
  print(arr, end);
   }
   // swap( arr[pindex], arr[end]) 
   cout<<"arr[pindex] "<<arr[pIndex]<<" "<<arr[end]<<"\n";
   temp = arr[pIndex];
   arr[pIndex] = arr[end];
   arr[end] = temp;
  print(arr, end);
  return pIndex;
}
void quick_sort(int *arr, int start, int end) {
     cout<<"Inside qucik_sort \n";
     if ( start < end) {
        int pIndex = 0;
        pIndex = partition(arr, start, end);
        print(arr, end);
        quick_sort(arr, start, pIndex-1);
        print(arr, end);
        quick_sort(arr, pIndex+1, end);
     }
}

int main() {
  int arr[12] = {11,4,2,6,8,3,9,1,23,0,1,14};
//  int arr[7] = {7, 4, 2, 3, 6, 0, 1};
  //int arr[7] = {7,5,3,9,10,1,8};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);

  quick_sort(arr, 0,size-1);
  print(arr, size);
  return 0;
}
