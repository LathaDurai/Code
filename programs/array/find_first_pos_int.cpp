#include<iostream>
#include<vector>
using namespace std;

void print(vector<int>  arr) {
  for(int i = 0; i<arr.size(); i++) {
        cout<< arr[i]<<" ";
  }
  cout<<"\n";
}

int main() {
  vector<int>  arr;
  int m, input;
  cout<<"enter no of inputs n thier values \n";
  cin>>m;
  for(int  i = 0; i<m; i++) {
      cin>>input;
      arr.push_back(input);
  }
  cout<<"***************************\n";
  print(arr);

int check = 1;
  for(int i = 0; i< m ;i++) {
    cout<<arr[i]<<"\n";
    if(arr[i] <= 0) {
       continue;
    }
    if(arr[i]> 0) {       
       if(arr[i] == check) {
           cout<<"check is "<<check<<"\n";
           check++;
       }
    }
  }
  cout<<"First missing positive interger is  "<<check <<"\n";
}


      
