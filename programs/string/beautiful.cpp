#include<iostream>
using namespace std;

void beauty(string s) {
   int count = 0;
   for(int i = 0; i<s.size(); i++) {
     if(i+2 < s.size() ) {
        if((s[i] == '0') && (s[i+1] == '1') && (s[i+2] == '0')) {
           s[i+2]= 1;
           i = i+2;
           count++;
           cout<<s<<"\n";
        }
     }
   }
   cout<<count<<"\n";
}

int main(){
    int n;
    cin >> n;
    string B;
    cin >> B;
    beauty(B);
    return 0;
}
