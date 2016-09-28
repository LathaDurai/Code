#include<iostream>

using namespace std;

void print(int arr[], int n) {

  for (int i =0; i< n; i++) {

    cout<<arr[i]<<" ";
  }
    cout<<" \n ";
}

void reverse(int *arr, int start, int n) {

  cout<<"inside rotate start "<<start<<" end "<<n<<"\n";

  int temp = 0;
  int j = n-1;
  for (int i =start; i<j  ; i++) {

         if(i == j) {
           return;
         }

         temp =  arr[i];
         arr[i]= arr[j];
         arr[j] = temp;
         j--;
    }
}


void  leftrotate(int arr[], int n, int d) {

  
  reverse (arr, 0, d);
  reverse(arr, d, n);
  reverse(arr, 0, n);
}

void  rightrotate(int arr[], int n, int d) {

  
  reverse(arr, 0, n);
  reverse (arr, 0, d);
  reverse(arr, d, n);
}

int main () {

    int n, d;
    cout<<"enter no of elements and no of posistion ";
    cin>> n;
    cin>> d;
    cout<<"enter elements \n";
    int arr[n];         
    for (int i =0; i<n; i++) {
       cin>>arr[i];
    }
  //int arr[10] = {1,2,3,4,5,6, 7, 8 ,9, 10};
  //int d = 4;
  //int n = sizeof(arr)/sizeof(arr[0]);
  print(arr, n);
  cout<<"Rotate "<<d <<" posistion left \n";
  leftrotate(arr, n, d);
  print(arr, n);
  int arr1[10] = {1,2,3,4,5,6,7,8,9,10};
  int d1 = 4;
  int n1 = sizeof(arr1)/sizeof(arr[0]);
  rightrotate(arr1, n1, d1);
  print(arr1, n);
}
