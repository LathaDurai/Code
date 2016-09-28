#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main() {

  int num;
  cin>>num;
int res = 0;
int i = 0;
  while(true) {
    if(num %2 == 0) {
      res = res+0*pow(10, i);
    } else {
      res = res+1*pow(10, i);
    }
    i++;
    num = num/2;
    if(num == 0) {
      break;
    }
  }
  cout<<"\n"<<res<<"\n";

  while(true) {
    if(num%2 == 1) {

  return 0;
}

