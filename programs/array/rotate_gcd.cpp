#include<iostream>
#include "gcd.cpp"

using namespace std;

void print(int arr[], int n) {

  for (int i =0; i< n; i++) {

    cout<<arr[i]<<" ";
  }
    cout<<" \n ";
}
void reverse(int *arr, int n) {

  cout<<"inside rotate \n";

  int temp = 0;
  int j = n-1;
  for (int i =0; i<j  ; i++) {

         if(i == j) {
           return;
         }

         temp =  arr[i];
         arr[i]= arr[j];
         arr[j] = temp;
         j--;
    }
    print(arr, n);
}


void  rotate(int arr[], int n, int d) {

  int temp = 0;
  int gd =  gcd(n, d);
  int pair = n/ gd;
  
  for (int i =0; i<d ; i++) {
      cout<<"arr[i] = "<<arr[i]<<"\n";
      temp = arr[i];
  
      for (int j = i, k = 1; j<n; j =j+gd, k++) {
        if(k>= pair) {
          cout<<" j is "<<j <<endl;
          arr[j] = temp;
        } else {
          cout<<"j is "<<j <<endl;
          arr[j] = arr[j+gd];
        }
      print(arr, n);
      }
  } 
}

int main () {

  int arr[10] = {1,2,3,4,5,6, 7, 8 ,9, 10};
  int d = 4;
  int n = sizeof(arr)/sizeof(arr[0]);
  print(arr, n);
  cout<<"Rotate "<<d <<" posistion left \n";
  rotate(arr, n, d);
  print(arr, n);
}
