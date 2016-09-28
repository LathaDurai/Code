#include<iostream>
using namespace std;

void find_erase(string str) {
  int pos = 0;
  char temp = str[pos];

  for (int i = 1; i<=str.size(); i++) {
    if(str[i] == temp) {
       pos = i-1;
       str.erase(pos, 2);
       temp = str[0];
       i = 0;
    } else {
       temp = str[i];
    }
  }
  if(str.empty()) {
    cout<<"Empty String \n";
    return;
  }
  cout<<"output is "<<str<<"\n";;
}

int main() {
  string str;
  cin>> str;
  find_erase(str);    
  return 0;

}



