#include<iostream>
using namespace std;

void sos(string s) {
  int count = 0;
  for(int i = 0; i+2<s.size(); ) {
   if(s[i] != 'S') {
       cout << i <<" "<<s[i] <<"\n";
       s[i] = 'S';
       count++;
    } 
    if(s[i+1] != 'O') {
       cout <<i+1<< " " <<s[i+1] <<"\n";
      s[i+1] = 'O';
      count++;
    }
    if(s[i+2] != 'S') {
       cout << i+2<<" "<<s[i+2] <<"\n";
      s[i+2] = 'S';
      count++;
    }
    i = i+3;
  }
  cout<<"count is "<<count<<"\n";
}
int main() {

  string s;
  cin>>s;
  sos(s);
  return 0;
}

