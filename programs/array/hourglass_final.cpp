#include<iostream>
#include<vector>

using namespace std;


void sum(vector< vector<int> > v1) {

  int sum = 0;
  int max = 0;

  for (int i = 0; i<4; i++) {
     for(int j = 0; j < 4; j++) {
       cout<<"\n";
       cout<< v1[i][j] <<" "<< v1[i][j+1]<<" "<< v1[i][j+2] <<"\n";
       cout<<"  " << v1[i+1][j+1] <<"\n";
       cout<< v1[i+2][j]<<" "<<v1[i+2][j+1]<<" "<<v1[i+2][j+2]<<"\n";
       sum = v1[i][j] + v1[i][j+1]+ v1[i][j+2] +
           v1[i+1][j+1] +
           v1[i+2][j]+v1[i+2][j+1]+v1[i+2][j+2];

       cout<<sum<<"\n";
       if(i == 0 && j == 0) {
         max = sum;
       }
       if(sum > max) {
          max = sum;
       }
     }
  }
    cout<<max<<"\n";
}


int main() {

  vector< vector<int> > v1(6, vector<int>(6));

  for(int i = 0; i< 6; i++) {
    for( int j = 0; j<6; j++) {
      cin>>v1[i][j];
    }
  }

  cout<<"\n\n\n";
  for(int i = 0; i< 6; i++) {
    for( int j = 0; j<6; j++) {
      cout<<v1[i][j]<<" ";
    }
    cout<<"\n";
  }

  sum(v1);
  return 0;
}
