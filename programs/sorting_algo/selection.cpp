#include<iostream>

using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i< size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void selection(int arr[], int size) {
  int temp = 0, min = 0, count = 0;
  for (int i=0; i<size; ++i) {
      count++;
      min = i; 
      for(int j=i; j< size-1; ++j) {
         count++;
         if(arr[min] > arr[j+1]) {
             min = j+1;
         }
      }
      if (i !=min) {
         temp = arr[min];
         arr[min] = arr[i];
         arr[i] = temp;
      }
   }//first for
   cout<<"Count is  = "<<count<<"\n";
}
// *********std code from internet***********  
/*void selection(int arr[], int n) {
      int i, j, minIndex, tmp;    
      for (i = 0; i < n - 1; i++) {
            minIndex = i;
            for (j = i + 1; j < n; j++)
                  if (arr[j] < arr[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  tmp = arr[i];
                  arr[i] = arr[minIndex];
                  arr[minIndex] = tmp;
            }
      }
} */

// for negative numbers
void selection_neg(int arr[], int size) {
  int temp = 0, min = 0, count=0;
  for (int i=0; i<size; ++i) {
      count++;
      min = i; 
      for(int j=i; j< size-1; ++j) {
         count++;
         if((arr[min]<0) && (arr[j+1]<0)) {
            if (arr[min]<arr[j+1]) {
               min = j+1;
            }
         } else if(arr[min] > arr[j+1]) {
             min = j+1;
         }
      }
      if (i !=min) {
         temp = arr[min];
         arr[min] = arr[i];
         arr[i] = temp;
      }
   }//first for
   cout<<"Count is  = "<<count<<"\n";
} 

int main() {

  int arr[13] = {-5,50,11,7,3,-44,4,2,-3,70,6,1,-4};
  int size = 13;
  print(arr, size);

  selection(arr, size);
  print(arr, size);
  selection_neg(arr, size);
  print(arr, size);
  return 0;
}
