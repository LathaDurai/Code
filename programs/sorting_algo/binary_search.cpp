#include<iostream>

using namespace std;

void print( int arr[], int size) {

  for (int i = 0 ; i< size ; ++i) {

    cout <<arr[i]<<" ";
  }
  cout <<"\n";
}

void binary ( int arr[], int start, int end, int x) {


 while (start <= end) {

  int  mid = start +((end - start) / 2);
  if (arr[mid] ==  x) {
    cout << "Found in mid check "<<mid<<"\n";
    return;
  }
  else if(arr[mid] < x) {
      cout <<" if less part "<< arr[mid]<<" \n";
      start = mid;
      cout <<" start is " << start <<"\n";
  }
  else if (arr[mid] >x ) {
    cout<<"greater part"<<arr[mid]<<" \n";
    end  = mid;
  }
 }
 return;
}


int main() {

  int arr[6] = {1,2,3,4,7,9};
  int size = sizeof(arr)/sizeof(arr[0]);

  print(arr, size);
  binary(arr, 0, size-1, 7);

  print(arr, size);

}
