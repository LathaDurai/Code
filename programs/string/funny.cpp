#include<iostream>
#include<ctype.h>

using namespace std;

int findfunny(string s) {
 int temp = 0;
 int n = s.size();
  for(int i = 1, j =n-1; i<s.size(); i++, j--) {
    if(abs(s[temp] - s[i]) == abs( s[j] - s[j-1])) {
      temp = i;
      continue;
    }
    else {
      return -1;
      break;
    }
  }
  return 1;
}

int main() {
  int n;
  cin>>n;
  string s;

  for (int i = 0; i<n; i++) {
    cin>>s;
    int ret = findfunny(s);
    if(ret == 1) {
      cout<<"Funny \n";
    } else {
      cout<<"Not Funny \n";
    }
  }
  return 0;
}
