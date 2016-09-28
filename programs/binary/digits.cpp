#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {

  vector<int> v1;
  int n;
  cin>> n;
  int num;

  for(int i  = 0; i<n ; i++) {
    cin >> num;
    v1.push_back(num);
  }

  int res ;
  int place = n-1;
  for(int i = 0; i<n; i++) {

    res =  res+v1[i]*pow(10,place);
    place--;
  }
  cout<<res<<"\n";;
  return 0;
}

