#include<iostream>

using namespace std;

/*void factorial(int fact) {
  cout<<"fact number is "<<fact<<"\n";
  int arr[] = {0};
  int count =0;
  for (int i=1; i<= fact; ++i) { 
    cout<<"inside for "<<i<<"\n";
    int num = (fact % i);
    if (num == 0) {
      cout<<" inside if "<<i<<"\n";
       arr[count] = i;
       count++;
    }
  }
  cout<<"Factorials are\n";
  for (int j=0; j<count; ++j) {
    cout<<arr[j]<<" ";
  }

} */

void factorial(int fact) {
  cout<<"fact number is "<<fact<<"\n";
  int arr[fact];
  int count = 0;
  for (int i=1; i<= fact; ++i) { 
    if (fact % i == 0) {
      arr[count] = i;
      count++;
    }
  }
  cout<<"Factorials are\n";
  for (int j=0; j<count; ++j) {
    cout<<arr[j]<<" ";
  }
}

int main() {

  int fact;
  cout<<"Enter the number to fnd factorial\n ";
  cin >> fact;
  factorial(fact);
  return 0;
}
