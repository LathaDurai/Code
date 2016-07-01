#include<iostream>

using namespace std;

void print( int arr[], int size) {

  for (int i = 0 ; i< size ; ++i) {

    cout <<arr[i]<<" ";
  }
  cout <<"\n";
}

void binary ( int arr[], int start, int end, int x) {


 while ((end- start) >1 ) {

  int  mid = start +((end - start) / 2);
  if(arr[mid] < x) {
      cout <<" if less part "<< arr[mid]<<" \n";
      start = mid;
      cout <<" start is " << start <<"\n";
  }
  else {
    cout<<"greater part"<<arr[mid]<<" \n";
    end  = mid;
  }
 }
 if (arr[start] == x) 
   cout <<" match found "<<start<<"\n";
 else 
   cout <<" no  match found "<<start<<"\n";
 return;
}


int main() {

  int arr[6] = {1,2,3,4,7,9};
  int size = sizeof(arr)/sizeof(arr[0]);

  print(arr, size);
  binary(arr, 0, size-1, 7);

  print(arr, size);

}
