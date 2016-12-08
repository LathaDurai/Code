#include<iostream>
#include<ctime>
#include<time.h>
using namespace std;

int main() {

  int due_day, due_month, due_year;
  int ret_day, ret_month, ret_year;
  cin>>due_day >>due_month>>due_year;
  cin>>ret_day >>ret_month>>ret_year;

  int fine  = 0;
  int diff_year = ret_year-due_year;
  if(diff_year > 0) {
    fine =10000;
    cout<<fine<<"\n";
    return 0;
  }

int arr[12] = {31,59, 90, 120, 151, 181,
             212, 243, 273, 304, 334, 365};

  int d1 = due_day+arr[due_month];
  int d2 = ret_day+arr[ret_month];
  cout<<d1 << "  "<<d2<<"\n";
  if((due_year%4) == 0) {
      if(due_year%100 == 0) {
        if(due_year%400 == 0) {
            cout<<"leap year\n";
            d1 = d1+1;
            d2 = d2+1;
        }
     }
  }
   
  int diff = d2 - d1;
  cout<<"Diff is "<<diff<<"\n";
  int diff_month = ret_month - due_month;
  if(diff_month>0) {
     fine = 500*diff;
  } else {
    fine = 15*diff;
  }

  cout<<fine<<"\n";
  return 0;
}

