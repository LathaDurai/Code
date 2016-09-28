#include<iostream>
#include<vector>
using namespace std;


void print_hour_glass(vector<vector <int> > arr, int a, int b) {

  int count =0;
  int m = a+2;
  int n = b+2;
  for (int i   = a; i<=  m; i++) {
    for (int j = b; j<=n ; j++) {
        if(count  == 3 || count == 5) {
             count ++;
             cout<<"  ";
             continue;
        }
        cout<< arr[i][j] <<" ";
        count ++;
    }
   cout<<" \n";
  }
} 

void hourglass_sum( vector<vector <int> > arr ) {

  cout<<"Inside hourglass_sum \n";

   int max = 0;
   int count  = 0;
   int sum =0;
   int x, y;
   int first = 0;

   for(int i = 0; i< 4; i++) {

     for (int j = 0; j< 4; j++) {

       print_hour_glass(arr, i, j);

       sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+ arr[i+1][j+1]+ arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];

       cout<<"sum is "<<sum<<"\n";
       if(first == 0 ) {
           max = sum;
           first ++;
       }
       if(sum >=  max) {
          max = sum;
       }
       sum = 0;
     }
   }
  cout<<"Hourglass with maximum sum ( "<<max<<" ) is \n";
}
int main() {

  vector< vector<int> > arr(6, vector<int> (6) );

  for (int i = 0; i<6; i++) {
     for(int j = 0; j< 6; j++) {

       cin >>arr[i][j];
     }
  }


  for (int i = 0; i<6; i++) {
     for(int j = 0; j< 6; j++) {

       cout << arr[i][j] <<"  ";
     }
     cout<<"\n";
  }
  hourglass_sum(arr);

  return 0;
}

