#include<iostream>
#include<math.h>
using namespace std;
int main() {
  int arr[] = {0,1,2,3,6};
  int n = sizeof(arr)/sizeof(arr[0]);
  int sum = 0;
  int d = n-1;

  for(int i = 0; i<n; i++,d-- ) {
    if(arr[i] == 0 && sum == 0) {
          continue;
    }
    else {
        sum = sum + arr[i]* pow(10,d);
    }
  }
  sum = sum+1;
  cout<<"answer is "<< sum;
}
