#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> arr, int size) {
  cout<<"Inside Printing... \n";
  for(int i = 0; i< size; i++) {
    cout<<arr[i]<<" ";
  }
  cout<<"\n";
}
    
void sparse(vector<string> arr_str, string input , int n, int n_check) {

     int count = 0;
     for(int j = 0; j<n; j++) {
          if(arr_str[j] == input) {
               count += 1;
          }
     }
    cout<<count <<"\n";
  }


int main() {

  int n;
  cout<<"enter no of element \n";
  cin >> n;
  string input1;
  vector<string> arr_str;
  cout<<"enter the elements \n";
  for(int i = 0; i<n; i++) {
      cin>>input1;
        arr_str.push_back( input1);
  }

  int n_check;
  cout<<"enter no of element \n";
  cin>>n_check;
  cout<<"enter the elements \n";
  for(int i = 0; i<n_check; i++) {
    cin>>input1;
    sparse(arr_str, input1, n, n_check);
  }

  print(arr_str, n);
  return 0;
}
