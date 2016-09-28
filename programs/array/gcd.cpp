#include<iostream>
#include"gcd.h"
using namespace std;


int gcd(int a, int b) {

  if (b == 0) {
    cout<<"GCD is "<< a<<"\n";
    return a;
  } else { 
   return  gcd(b, a%b);
  }
 
}

/*int main() {

  int a, b;

  a = 24;
  b = 60;

  int res = gcd(a, b);

} */

