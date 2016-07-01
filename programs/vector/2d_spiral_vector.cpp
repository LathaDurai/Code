#include<iostream>
#include <vector>
using namespace std;

class Spiral {
  //vector< vector<int> > arr(3,vector<int>(3,0));
  vector< vector<int> > arr;
  int row, coloumn;
public:
  void getvalue();
  void printvalue();
  void spiral_print();
};

void Spiral::getvalue() {
  int row=4, coloumn =4;
  int count=0;
  for(int i=0; i<row; ++i) {
    vector<int> temp;
    for(int j=0; j<coloumn; ++j) {
      //temp[j]=++count;
       temp.push_back(++count);
    }
    arr.push_back(temp);
  }  
}

void Spiral::printvalue() {
  cout<<"\nValues in 2-d arrays are\n";
  for (int i=0; i<arr.size(); ++i) {
    for(int j=0; j<arr[i].size(); ++j) {
      cout<<arr[i][j]<<" ";
    }
    cout<<"\n";
  }
}

void Spiral::spiral_print() {
  int row=4, coloumn =4;
  cout<<"***Spiral Printing***\n";
  vector<int> temp;
  temp.push_back(arr[0][0]);
  int i=0, j =0;
  int dir=0, layer =0;
  for(int S=1;S<(row*coloumn);++S) {
    switch(dir) {
    case 0:
        if (j == coloumn-1-layer) {
          dir = 1;
          i++;
        } else {
          j++;
        }
        break;
    case 1:
         if(i== row-1-layer) {
           dir=2;
           j--;
         }else {
           i++;
         }
      
         break;
    case 2:
        if(j==layer) {
          dir = 3;
          i--;
        } else {
          --j;
        }
         break;
    case 3:
        if(i == layer+1) {
           dir = 0;
           ++j;
           layer ++;
        } else {
          --i;
        }
         break;
    default:
         cout<<"Something Fishy\n";
    }
    temp.push_back(arr[i][j]);
  }
  
  for (int a=0; a<temp.size(); ++a) {
      cout<<temp[a]<<" ";
    }
  
}


int main() {
  Spiral Sp;
  Sp.getvalue();
  Sp.printvalue();
  Sp.spiral_print();
  return 0;

}

