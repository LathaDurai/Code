#include<iostream>
#include <math.h>
using namespace std;

int primeornot ( int prime) {
  for (int i = 2; i<= sqrt(prime); ++i) {

    if (  (prime % i) ==0 ) {
      cout <<prime<< "-----primeornot is not a prime\n";
      return 0;
    }
  }
  cout <<prime << "-----primeornot is a prime\n";
  return 1;
}

int sum( int prime) {
  cout << "inside primesum \n";
  for( int i=2 ;i<=prime; ++i) {
     cout<<"inside for of primesum\n";
   int res = 0, remain = 0;
   res =  primeornot(i);
   if (res == 1) {
       remain = prime - i;
       int res1 = 0;
       res1 = primeornot(remain);
       if (res1 == 1) {
         cout<<" prime sum are" << i <<" "<< remain<<"\n";
         return 0;
       }
   } 

  }
  return 0;
}
int main () {

  int prime = 8;
  cout << sqrt(prime);
  int x = sum(prime);
}

