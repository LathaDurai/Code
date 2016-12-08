#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {
  int num, r;
  cin>>num;
  int count = 0;
  int res = 0;
  int i = 0;
  while(num!=0) {
    if(num %2 == 0) {
      res = res+0*pow(10, i);
      count = 0;
    } else {
      res = res+1*pow(10, i);
      count ++;
      if(count > r) {
         r = count;
      }
    }
    i++;
    num = num/2;
  }
  cout<<res<<"\n" << r<<"\n";
  return 0;
}

