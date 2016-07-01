#include<iostream>
using namespace std;

void print(int arr[], int size) {
  for (int i = 0; i<= size; ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void swap(int &a, int &b) {
  cout<<"Swap Function \n";
  int temp = 0;
  temp = a;
  a = b;
  b = temp;
}


void  partition(int arr[], int start, int end, int &i, int &j ) {
  cout<<"In Partion Function \n";
  int pindex =0, pivot = 0;
  pindex = start;
  pivot = arr[end];

  // two elemexts
  if ((end - start) <1) {
     if (arr[end] <arr[start]) {
      swap(arr[end], arr[start]);
     }
    i = start;
   j = end;
  } 
  for (int t= start; t< end; ++i) {
    cout <<"In For of "<<__func__<<"\n";
    cout << arr[t] <<"  " << pivot<< " " <<start<<" "<<end<<"\n";
      if (arr[start] <  pivot) {
         cout<<"Something wrong 1 "<< start<<" "<<pivot<<"\n";
          swap( arr[start++], arr[pindex++]);
  print(arr, end);
      } else if (arr[start] == pivot) {
         cout<<"Something wrong 2"<< start<<" "<<pivot<<"\n";
           pindex++;
      } else if (arr[i] > pivot) {
         cout<<"Something wrong 3"<< pindex<<" "<<end<<"\n";
         swap(arr[pindex], arr[end--]);
  print(arr, end);
      } 
   }
   i = start;
   j = pindex;
}
void quick_sort(int *arr, int start, int end) {
     cout<<"Inside qucik_sort \n";
     if ( start < end) {
        int i, j;
        partition(arr, start, end, i, j);
        quick_sort(arr, start, i);
        quick_sort(arr, j, end);
     }
}

int main() {
  int arr[12] = {11,4,2,6,8,3,9,1,23,0,1,14};
//  int arr[7] = {7,5,3,9,10,1,8};
  int size = (sizeof(arr)/sizeof(arr[0]));
   cout<<"Size is "<<size<<"\n";
  print(arr, (size-1));

  quick_sort(arr, 0,(size-1));
  print(arr, size);
  return 0;
}
