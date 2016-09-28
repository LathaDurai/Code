#include<iostream>
#include<vector>
using namespace std;

// gemstone
void common(vector<string> s) {
  int count[26] = {0};
  int count1 = 0;
  for (int i = 0; i<s.size(); i++) {
    string str = s[i];
    char temp = str[0];
    for(int j = 0; j<str.size(); j++) {
      if(count[str[j]- 'a'] == i) {
        count[str[j]-'a']++;
        if(count[str[j]-'a'] == s.size()) {
         cout<<str[j]<<"\n";
         count1++;
        }
      }
    }
  }
  cout<<count1<<"\n";
}
    

int main() {
  int n;
  cin>>n;
  vector<string> s;
  string input;
  for(int i = 0; i<n; i++) {
    cin>>input;
    s.push_back(input);
  }
  common(s);
  return 0;
}

