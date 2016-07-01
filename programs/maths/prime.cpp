#include<iostream>
#include <math.h>
using namespace std;

int main () {

  int prime = 39601;
  cout << sqrt(prime);
  for (int i = 2; i<= sqrt(prime); ++i) {

    if (  (prime % i) ==0 ) {
      cout <<prime<< " is not a prime\n";
    }
  }
  cout <<prime << "is a prime\n";
}

