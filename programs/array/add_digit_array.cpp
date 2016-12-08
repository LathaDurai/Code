#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
void reverse(vector<int> &arr) {
  int j = arr.size()-1;
  for(int i = 0; i< j; i++, j--) {

    if(i == j) {
      break;
    }
    int temp = arr[j];
    arr[j] = arr[i];
    arr[i] = temp;
  }
}

void print (vector<int> arr) {
  for(int i = 0; i<arr.size(); i++) {
        cout<< arr[i]<<" ";
          }
    cout<<"\n";
}

int main() {

  vector<int> arr;
  int n, input;;
  cout<<"enter no of inputs n thier values \n";
  cin>>n;

  for(int  i = 0; i<n; i++) {
    cin>>input;
    arr.push_back(input);
  }
  print(arr);
  reverse(arr);
  print(arr);
  int carry = 1;
  int sum = 0;
  vector<int> res ; 
  for(int i = 0; i<arr.size(); i++) { 
    sum = carry+arr[i];;
    if(sum >= 10) {
      carry = sum/10;
      sum = sum%10;
    } else {
      carry = 0;
    }
    res.push_back(sum);
    if((i == arr.size()-1) &&  (carry != 0)) {
      res.push_back(carry);
    }
   }

  print(res);
   int i =res.size()-1;
   while(i > 0) {
     if(res[i] == 0) {
       res.pop_back();
       i--;
     } else {
       break;
     }
   }

  print(res);
  reverse(res);
  print(res);
 }


