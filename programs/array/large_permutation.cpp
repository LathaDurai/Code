#include<iostream>

using namespace std;

void print(int arr[], int n) {

  for(int i =0; i<n; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

/*
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
*/
void swap( int *arr, int i, int pos) {
cout<<"*********swaped ********\n";

  int temp;
  temp = arr[i];
  arr[i] = arr[pos];
  arr[pos] = temp;
}

void lp(int *arr, int n, int d){

 
 int pos  =0;
 int max = arr[0];
 bool check = false;
 for(int i = 0; i<d &&  i< n; i++) {
    if ( i< n) {
      max = arr[i];
    }

    for (int j = i; j<n ;j++) {
       cout<<"arr[j] "<<arr[j]<<" max "<<max <<"\n"; 
       if (arr[j] > max) {
       
         max = arr[j];
         pos = j;
         check = true;
      }
    }
    cout<<"Max is "<<max <<endl;
    cout<<" i is "<<i<<"pos is "<<pos<<"\n";
    if(check == true) {
      if (pos > i) {
        swap(arr, i, pos);
        check = false;
      }
    }
    print(arr, n);
 }
}

int main() {


  int n, d;
  //n = 14;
  //d = 50;
  cin >> n;
  cin>>d;
  int arr[n];
  //int arr[14] = { 33, 11, 55, 12, 4, 6, 8, 1, 45 ,23, 1, 2, 4, 2};
  for(int i =0; i<n; i++) {
    cin>>arr[i];
  }

  print(arr, n);
  lp(arr,n,d);
  print(arr, n);
  }
