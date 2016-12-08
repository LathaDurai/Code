#include<iostream>
#include<ctime>
#include<time.h>
using namespace std;

int main() {

  int due_day, due_month, due_year;
  int ret_day, ret_month, ret_year;
  cin>>due_day >>due_month>>due_year;
  cin>>ret_day >>ret_month>>ret_year;

  struct tm a = {0,0,0, due_day, due_month, due_year};
  struct tm b = {0,0,0, ret_day, ret_month, ret_year};
  int fine = 0;

  time_t at = mktime(&a);
  time_t bt = mktime(&b);

  int diff = difftime(bt, at)/(24*60*60);
  cout<<"Diff is "<<diff<<"\n";

  int diff_year = ret_year-due_year;
  if(diff_year > 0) {
    fine =10000;
    cout<<fine<<"\n";
    return 0;
  }
  int diff_month = ret_month - due_month;
  if(diff_month>0) {
     fine = 500*diff;
  } else {
    fine = 15*diff;
  }

  cout<<fine<<"\n";
  return 0;
}

