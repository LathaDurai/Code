#include <iostream>

using namespace std;

class A

{

  public: A()

          {

            cout << "a\n";

          }

          ~A()

          {

            cout << "A\n";

          }

};

int i = 1;

int main()

{

label: A a;

if(i--) {
  cout<<"execute 1\n";
  goto label;
}

}
