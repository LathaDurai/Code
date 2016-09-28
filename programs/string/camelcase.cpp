#include<iostream>
#include<ctype.h>
using namespace std;


/*saveChangesInTheEditor 
 * no of words are 
 * 5 */

void camelcase(string s) {
  int count = 0;
  char check = s[0];

  if(islower(check)) {
    cout<<s[0]<<" is Lower \n";
    count++;
  } else {
     return ;
  }
  for(int i = 1; i<s.size(); i++) {
    check = s[i];
     if(isupper(check)) {
          cout<<s[i]<<" is upper \n";
          count++;
     }
  }
  cout<<"No of words are "<<count<<"\n";
}

int main(){
    string s;
    cin >> s;
    camelcase(s);
    return 0;
}

