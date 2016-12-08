#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
  int num;
  cin>>num;
  int  r = 0;
  int count = 0;
  while(num!=0) {
    if(num %2 == 0) {
      count = 0;
    } else {
      count ++;
      if(count > r) {
         r = count;
      }
    }
    num = num/2;
  }
  cout<< r<<"\n";
  return 0;
}

