#include<iostream>
using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void merge_sort (int left[], int right[], int arr[], int ll, int rr, int size) {
   cout<<"Inside merge_sort \n";
   int i = 0, j=0, k=0;
   while ( (i < ll) && (j < rr)) {
      if (left[i] < right[j]) {
         arr[k] = left[i];
         i++;
      } else {
          arr[k] = right[j];
          j++;
      }
      k++; 
   }
   while(i < ll) {
     arr[k] = left[i];
     i++;
     k++;
   }
   while(j < rr) {
      arr[k] = right[j];
      j++;
      k++;
   }
}
void merge(int arr[], int size) {
   if (size < 2) {
     return;
   }
   
   int mid = 0, rr =0;
   mid = size/2;
   rr = size - mid;
   int left[mid], right[rr];
   for (int i = 0; i< mid; ++i) {
      left[i] = arr[i];
   }
   for (int i = mid, j =0; i< size; ++i, ++j) {
       right[j] = arr[i];
   }
   merge(left, mid);
   merge(right, rr);
   merge_sort(left, right, arr, mid, rr, size);
}


int main() {
  int arr[12] = {11,4,2,6,8,3,9,1,23,0,1,14};
  int size = 12;
  print(arr, size);

  merge(arr, size);
  print(arr, size);
  return 0;
}
