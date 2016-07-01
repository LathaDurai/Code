#include <iostream>
#include<stdlib.h>

using namespace std;

const int ASCI = 256; 
void findMaxOccur(char *str) {

  int count[ASCI];
  int len = strlen(str);
  cout<<"Length is "<<len <<"\n";
  for(int i = 0; i<len; ++i) {
      count[str[i]]++;
  }
  int result;
  char result_char;
  int max = -1;
  for(int i=0;i<len; ++i) {
    if(max <count[str[i]]) {
    cout<<"Inside if for "<< str[i]<<"\n";
      max = count[str[i]];
      result = count[str[i]];
      result_char = str[i];
    }
  }
  cout<<"char is "<<result_char<<" no of occur is "<<result<<"\n";
}

int main() {

  char str[] = "max xe";

  findMaxOccur(str);
  return 0;
}
