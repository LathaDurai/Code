#include<iostream>
#include<vector>
using namespace std;


void alternate(vector<string> s) {
   for(int i = 0; i<s.size(); i++) {
     string str = s[i];
     char temp = str[0];
     int count =0;
     for(int j = 1; j<str.size(); j++) {
        if(str[j] == temp) {
          str.erase(j, 1);
          j = j-1;
          count++;
          continue;
        }
        temp = str[j];
     }
     cout<<count<<"\n";
   }   
}

int main() {
  int n;
  cin>>n;
  string check;
  vector<string> s;
  for(int i = 0; i<n; i++) {
      cin>>check;
      s.push_back(check);
  }
   alternate(s);
  return 0;
}
