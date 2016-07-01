#include<iostream>
using namespace std;

void print(int arr[], int size) {
  cout<<"Inside Printing... \n";
  for(int i = 0; i< size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

int partition(int *arr, int start, int end) {
  int pivot = arr[end];;
  int pIndex = start;
  int temp;
  for(int i= start; i<end; ++i) {
    if(arr[i] <= pivot) {
        temp = arr[i];
         arr[i] = arr[pIndex];
         arr[pIndex] = temp;
         pIndex++;
     }
   }
      // swap( arr[pindex], arr[end])
   temp = arr[pIndex];
   arr[pIndex] = arr[end];
   arr[end] = temp;
   return pIndex;
}

void quicksort(int *arr, int start, int end) {
  if(start< end) {
    int pindex = 0;
     pindex = partition(arr, start, end);
     quicksort(arr, start, pindex-1);
     quicksort(arr, pindex+1, end);
  }
}

int formdigit(int *arr, int size) {
  cout<<"isnide formdigits....\n";
  // sort array
  quicksort(arr, 0, size-1); 
  print(arr, size);
  /*smaller number should contains more number
  int digits = size/2;
  int temp = size-digits;
  cout<<"digit is  "<<digits<<"\n";
  int arr1[temp];
  int arr2[digits]; */

  //let be variables
  int a = 0;
  int b = 0;
  for(int i = 0; i<size; ++i) {
        if((i%2) == 0) {
            a = (a*10)+ arr[i];
        }
         if((i%2) !=0) {
            b = (b*10)+arr[i];
        }
  }
  int sum = a+b;
  return sum;;
}

int main() {

  //int arr[7] = {7, 4, 2, 3, 6, 0, 1};
  int arr[] = {6, 8, 4, 5, 2, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  int result  = formdigit(arr, size);
  cout<<"sum is "<<result<<"\n";
  return 0;
}
