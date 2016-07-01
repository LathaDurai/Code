#include<iostream>
#include<thread>
//#include<mutex>

using namespace std;

class count_fun {
  int id;
 public:
  count_fun(int x):id(x) {
  }
  void incr(int i);
};

void count_fun::incr(int i) {
  i++;
  cout<<"Id is "<<i<<"\n";
}

int main() {

  count_fun count1(5);
  thread t(&count_fun::incr(5),&count1);
//  if (t.joinable) {

    t.join();
 // }

}

