#include<iostream>

using namespace std;

void print (int arr[], int n) {

  for (int i =0; i<n; i++) {

    cout<<arr[i]<< " ";
  }
  cout<<"\n";
}

void rotate(int *arr, int n) {

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
    print(arr, n);
    }
    print(arr, n);

}

int main() {
  int arr[] = {0,3,2,0};
  int n = sizeof(arr)/sizeof(arr[0]);;

  print(arr, n);
  rotate(arr, n);
  print(arr, n);
}

