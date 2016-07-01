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
int find_max_possible_count(int arr[], int size) {
  cout<<"Inside "<<__func__<<"\n";
  quicksort(arr, 0, size-1);
  print(arr, size);
  for(int i = 0; i<size; ++i) {
    cout<<" i "<<i<<" arr[i] "<<arr[i]<<"\n";
    if(arr[i] <=size) {
        cout<<"size "<<size<<" (size-i) "<<size-i<<"\n";
        if((size-i) == arr[i]) {
          return arr[i];
        }
    } else {
     cout<< arr[i-1]+1 <<"\n";
    }
  }


  return 1 ;

}



int main() {

  int arr[] = {6, 8, 5, 2, 3};
  int size = sizeof(arr)/sizeof(arr[0]);
  print(arr, size);
  int result = find_max_possible_count(arr, size);
  cout<<"result is "<<result<<"\n";
  return 0;
}
