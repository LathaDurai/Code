#include<iostream>
using namespace std;

/* panagram - sentence contains all
 * 26 alaphabets atleast once;
 */

void pangram(string s) {

  int count[26] = {0};
  int sum  = 0;
  for(int i = 0; i<s.size();i++) {
    if(((int)s[i] >= 65) && ((int)s[i] <= 90)) {

        if(count[s[i] - 'A'] == 0) {
          count[s[i]-'A']++;
          sum += count[s[i]-'A'];
        }
    }
    if (((int)s[i] >= 97 ) && ((int)s[i] <= 122)) {
        if(count[s[i]-'a'] == 0) {
          count[s[i]-'a']++;
          sum += count[s[i]-'a'];
        }
    }
  }
  if(sum == 26) {
    cout<<"is panagram \n";
  } else {
    cout<<"no panagram \n";
  }
}


int main() {
   string s;
   getline(cin, s);
   pangram(s);
   return 0;
}
