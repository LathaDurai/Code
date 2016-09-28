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

                 print_hour_glass(arr,i, j);
                 int m = i+2;
                 int n = j+2;

             for (int a  = i ; a<= m; a++) {
               for (int b = j; b<= n; b++) {
    
                 //cout<<"count is "<<count <<"\n";
                 if((count == 3 || count == 5)) {
                 cout<<"count is "<<count <<"\n";
                   count ++;
                   continue;
                 }
                 cout<<"values are " <<arr[a][b];
                 sum += arr[a][b];
                 count++;
               }


          }
          cout<<"sum is "<<sum<<"\n";
          if(first == 0 ) {
              max = sum;
              first ++;
          }
          if(sum >=  max) {
            max = sum;
            x = i;
            y = j;
          }
          count  = 0;
          sum = 0;
     } 
     cout<<"\n";
   }
  
  cout<<"Hourglass with maximum sum ( "<<max<<" ) is \n";
  print_hour_glass(arr,x, y);
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

