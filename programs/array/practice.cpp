#include<iostream>
#include<vector>

using namespace std;
void print (vector<vector<int> > arr) {
  for(int i = 0; i<arr.size(); i++) {
     for(int j = 0; j<arr[0].size(); j++) { 
        cout<< arr[i][j]<<" ";
     }
  cout<<"\n";
  }
}

int main() {
  vector<vector<int> > arr;
  int m, n, input;
  cout<<"enter no of inputs n thier values \n";
  cin>>m;
  cin>>n;
  for(int  i = 0; i<m; i++) {
    vector<int> v1;
    for(int j = 0; j<n; j++) {
      cin>>input;
      v1.push_back(input);
    }
    arr.push_back(v1);
  }
  cout<<"***************************\n";
  print(arr);
  cout<<"***************************\n";

/*  for(int i = 0; i< arr.size(); i++) {
    for(int j = 0; j<arr[0].size(); j++) {
      if(arr[i][j] == 0) {
          cout<<"i , j "<< i <<" "<< j<<"  "<<arr[i][j]<<"\n";
          int k = 0;
          while(k<arr[0].size()) {
            cout<< "i, k "<<i <<" "<< k<<" "<<arr[i][k]<<"\n";
             arr[i][k] = 0;
             k++;
          }
          int l = i; 
          while(l<arr.size()) {
            cout<< "l, j "<<l <<" "<< j<<" "<<arr[l][j]<<"\n";
             arr[l][j] = 0;
             l++;
          }
          i++;
      } else {
        continue;
      }
    }
  }
  print(arr);
}*/
  for(int i = 0; i< arr.size(); i++) {
    for(int j = 0; j<arr[0].size(); j++) { 
      if(arr[i][j] == 0) {
          arr[i][0] = 0;
          arr[0][j] = 0;
      }
    }
  }
  
 cout<<"******    marked  ******************\n"; 
  print(arr);
  for(int i = 0; i< arr.size(); i++) {
    if(arr[i][0] == 0) {
      for(int j = i; j<arr[0].size(); j++) {
        arr[i][j] = 0;
      }
    }
  }
 cout<<"***************************\n"; 
print(arr);
 for(int j = 0;j<arr[0].size(); j++) {
   if(arr[0][j] == 0) {
   for(int i = j; i< arr.size(); i++) {
     arr[i][j] = 0;
   }
   }
 }
     
 cout<<"***************************\n"; 
print(arr);
  }
