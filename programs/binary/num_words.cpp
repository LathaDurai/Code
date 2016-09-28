#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {

  int n;
  string  res ;
  cin>> n;

  if(n < 0 || n>9999) {
    cout<<"please enter number between 0-9999\n";
    exit(1);
  }

  string singles[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  string doubles[] = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fivteen", "sixteen", "sevteen", "eighteen", "ninteen", "twenty"};
  
  string doub[] = {"","", "twenty", "thirty", "fourty", "fivty", "sixty", "seventy", "eighty", "ninty", "Hundered"};

  if(n <= 9) {
    cout<<singles[n]<<"\n";
  }
  
  if(n > 9 && n <= 20) {
     cout<<doubles[n-10]<<"\n";
  }

  if(n>20 && n <=99) {
      cout<<doub[n/10]<<" ";
      if(n%10!=0) {
        cout<<singles[n%10]<<" ";
      }
  }
  if(n>99 && n <=999) {
    cout<<singles[n/100]<<" hundered ";
    if(n%100!=0) {
      int temp = n%100;
      cout<<"and "<<doub[temp/10]<<" ";
      if(temp%10!=0) {
        cout<<singles[n%10]<<" ";
      }
    }
  }

  if(n>999 && n <=9999) {
    cout<<singles[n/1000]<<" thousand ";
    if(n%1000 != 0) {
      int tt = n%1000;
      cout<<"and "<<singles[tt/100]<<" hundered ";
       if(n%100!=0) {
         int temp = n%100;
         cout<<"and "<<doub[temp/10]<<" ";
         if(temp%10!=0) {
           cout<<singles[n%10]<<" ";
         }
      }
    }
  }
  cout<<"\n";    
  return 0;
}

