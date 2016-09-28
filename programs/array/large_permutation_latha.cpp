#include<iostream>

using namespace std;

void print(int arr[], int n) {

  for(int i =0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}


int findmax(int arr[],int j, int n) {

  int pos = 0;
  int max = arr[j];
  for (int i = j; i<n ;i++) {
    cout<<"arr[i] "<<arr[i]<< "\n";
    if (arr[i] > max) {
       
      cout<<" inside if \n";
      max = arr[i];
      pos = i;
    }
  }
  cout<<"Max is "<<max <<endl;
  return pos;
}

void swap( int *arr, int i, int pos) {

  int temp;
  temp = arr[i];
  arr[i] = arr[pos];
  arr[pos] = temp;
}

void lp(int *arr, int n, int d){

 
 int pos  =0;
 for(int i = 0; i<d; i++) {
     pos = findmax(arr, i, n);

     cout<<" i is "<<i<<"pos is "<<pos<<"\n";
     if (pos != i) {
        swap(arr, i, pos);
     }
  print(arr, n);
 }
}

int main() {


  int n, d;
  n = 8;
  d = 10;
  //cin >> n;
  //cin>>d;
  int arr[8] = { 3, 11, 5, 2, 4, 6, 8, 1};
  //for(int i =0; i<n; i++) {
    //cin>>arr[i];
 // }

  print(arr, n);
  lp(arr,n,d);
  print(arr, n);
  }
