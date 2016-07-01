#include<iostream>
using namespace std;

class Spiral {
  int arr[10][10];
  int row, coloumn;
public:
  void getvalue();
  void printvalue();
  void spiral_print();
};

void Spiral::getvalue() {
  cout<<"Enter the dimension for 2d array\n";
  cout<<"Enter the row size\n";
  cin>>row;
  cout<<"\nEnter the coloumn size\n";
  cin>>coloumn;
  cout<<"\n Enter the Values\n";
  int count = 0;
  count = row*coloumn;
  for(int i=0; i< row; ++i) {
    for(int j=0; j< coloumn; ++j) {
       if (count) {
         cin>>arr[i][j];
         cout<<" ";
         count --;
       }
    }
    cout<<"\n";
  }
}

void Spiral::printvalue() {
  cout<<"\nValues in 2-d arrays are\n";
  for (int i=0; i<row; ++i) {
    for(int j=0; j<coloumn; ++j) {
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}
void Spiral::spiral_print() {
  cout<<"***Spiral Printing***\n";
  int t=0, b=(row-1);
  int l=0, r=(coloumn-1);
  int dir=0;
  while(t<=b && l<=r) {
    if(dir == 0) {
      for (int i=l; i<=r; ++i) {
        cout<<arr[t][i]<<",";
      }
      t++;
      dir=1;  
    }else if(dir==1) {
       for (int i=t; i<=b; ++i) {
         cout<<arr[i][r]<<",";
       }
       r--;
       dir=2;
     } else if(dir==2) {
      for( int i=r; i>=l; --i) {
        cout<<arr[b][i]<<",";
      }
      b--;
      dir=3;
    } else if(dir==3) {
      for(int i=b; i>=t; --i) {
        cout<<arr[i][l]<<",";
      }
      l++;
      dir=0;
    } 
  }
}
int main() {
  Spiral Sp;
  Sp.getvalue();
  Sp.printvalue();
  Sp.spiral_print();
  return 0;

}

