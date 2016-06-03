#include<iostream>
using namespace std;

// This is a good program
void mergesort(int arr[], int size) {

  if (size < 2) {
    return;
  }
  int mid, ll, rr;

  mid = size/2;
  ll = size -mid;
  rr = size - ll;
  
  int left[ll], right[rr];

  for (int i=0; i<ll; ++i ) {
    left[i] = arr[i];
  }

  for (int i= rr , j= 0; i<size; ++i, ++j) {
    right[j] = arr[i];
  }

  mergesort(left[], ll);
  mergesort(right, rr);


}
void findsum(int arr[], int size, int sum) {
  cout<<"Inside Findsum Function \n";
  int num = 0;
  mergesort(arr[],size);
  for (int i=0; i<size, ++i) {
    if (arr[i] > sum) {
      cout<<"No values\n";
      return;
    }
    num = sum - arr[i];
   for (int j = i; j< size ; ++j) {
     if (arr[j] == num) {
       cout<<"Values are " << arr[j]<<","<<arr[i] <<" \n";
       return; 
     }
   }
}


int main() {

  int arr[6] = {1,2,3,4,5,6};
  int size = 6;

  findsum(arr,6, 8);
}
