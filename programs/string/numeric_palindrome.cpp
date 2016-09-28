#include<iostream>
using namespace std;

void num_palindrome(string arr,int n, int k) {
  int end = n-1;
  int total = 0;
  int count = 0;
  int temp = 0;
  if(n/2 <= 0) {
      arr= '9';
      cout<<arr;
      return;
  }
  if(n%2 == 0) {
     total = n/2;
  } else {
    total = ((n/2)-1);
  }

  for(int i = 0; i< total; i++, end--) {
    cout<<i<<" "<< arr[i]<<" "<<arr[end]<<"\n";
    if(arr[i] == arr[end]) {
       continue;
    } else {
       if(arr[i] == '9') {
          arr[end] = '9';
          count++;
          cout<<count<<"\n";
          temp--;
          continue;
        } else if(arr[end] == '9') {
           arr[i] = '9';
           count++;
          cout<<count<<"\n";
           temp--;
           continue;
       }
       count++;
          cout<<count<<"\n";
    }
  }
  temp = count+temp;
  cout<<"temp is "<<temp<<" count is "<<count<<"\n";

/*  for(int i = 0; i< total; i++, end--) {
    cout<<i<<" "<< arr[i]<<" "<<arr[end]<<"\n";
    if(arr[i] == arr[end]) {
       continue;
    } else {
          if(arr[i] == '9') {
             arr[end] = '9';
             count++;
          } else if(arr[end] == '9') {
             arr[i] = '9';
             count++;
          }
          if(count<= k) {

          
    }
  }
*/
  cout<<"arr is "<<arr<<"\n"; 
  if(count <= k) {
    cout<<count<<"\n";
  } else {
    cout<< "-1 \n";
  }
}

/*void num_palindrome(string arr,int n, int k) {
  int end = n-1;
  int count = 0;
  int temp = 0;
  cout<<"n/2 "<<n/2<<"\n";
  if(n/2 <= 0) {
      arr= '9';
      cout<<arr;
      return;
  }
  for(int i = 0; i<=n/2; i++, end--) {
    if(arr[i] == arr[end]) {
       continue;
    } else {
      cout<<"no match "<< arr[i]<<" "<<arr[end]<<"\n";
      if(arr[i] == '9') {
          arr[end] = '9';
          count++;
      } else if (arr[end] == '9') {
           arr[i] = '9';
          count++;
       } else {
          arr[i] = '9';
          arr[end] = '9';
          count = count+2;
       }
       
    }
      cout<<arr<<" "<<count<<"\n";;
  }
  end = n-1;
  cout<<"count is "<<count<<"\n"; 
  if(count <= k) {
      temp = k - count;
      cout<<"temp is "<<temp<<"\n"; 
      for (int i= 0, count1 = 0; count1<temp;end--, i++) {
        if(arr[i] < '9') {
           arr[i] = '9';
           arr[end] = '9';
           count1 = count1+2;
         }
     }
      cout<<arr<<" "<<count<<"\n";;
  } else {
    cout<< "-1 \n";
  }
} */
int main() {
  int n, k;
  cin>>n;
  cin>>k;
  string arr;
  cin>>arr;
  num_palindrome(arr, n, k);
  return 0;
}
