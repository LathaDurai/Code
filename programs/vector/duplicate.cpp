
#include<iostream>

using namespace std;

void print(vector <int > arr) {
  for (int i = 0; i< arr.size(); ++i) {
     cout<<arr[i]<<" ";
  }
  cout<<"\n";
}

void duplicate(vector <int> &arr) {

  for(int i = 0; i< arr.size(), ++i) {

  }

}

int main() {

  vector <int >  arr = {-5,50,11,7,3,-44,4,2,-3,70,6,1,-4};

  selection(arr);
  print(arr);
  return 0;
}
