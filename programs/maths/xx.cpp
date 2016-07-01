#include<iostream>
#include <math.h>
using namespace std;
void primesum(int A) {
   // vector<int> v1;
  cout << "inside primesum \n";
      for( int i=2 ;i<=A; ++i) {
          cout <<" i is " <<i<<"\n";
          int remain = 0, res =1, res1 = 1;
          for (int j=2; j < sqrt(i); ++j) {
             if (  (i % j) ==0 ) {
                  cout << "inside A if \n";
                  res = 0;
             } 
             
          } 
          
          cout << " res is " << res<<"\n";
          if (res == 1) {
                  remain = A - i;
                 cout <<" remain is " <<remain<<"\n";
                  for (int j=0; j< sqrt(remain); ++j) {
                        if (  (remain % j) ==0 ) {
                            cout << "inside remain if \n";
                              res1 = 0;
                         }
                  }

                 cout << " res1 is " << res1<<"\n";
                  if (res1 !=0) {
   //                   v1.push_back(i);
     //                 v1.push_back(remain);
                        cout<< i<< remain;
                  }
           }
                       
//                      return v1;
     }
}
int main () {

  int prime = 8;
  cout << sqrt(prime);
   primesum(prime);
}

