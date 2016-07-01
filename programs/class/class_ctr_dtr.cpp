#include<iostream>
using namespace std;

class A {
  public:
    A () {
       cout<<"Ctor of A called\n";
    }
    virtual void getname() {
      cout <<"********AAAAA********\n";
    };
    ~A() {
      cout<<"dtor of A called\n";
    }
};

class B:public A {
  public:
    B () {
       cout<<"Ctor of B called\n";
    }
    void getname() {
      cout <<"********BBBBB********\n";
    };
    ~B() {
      cout<<"dtor of B called\n";
    }
};

class C:public B {
  public:
    C () {
       cout<<"Ctor of C called\n";
    }
    void getname() {
      cout <<"********CCCCC********\n";
    };
    ~C() {
      cout<<"dtor of C called\n";
    }
};

int main() {
  cout <<"main start \n";
B b;
  cout <<"A *a  = &b \n";
A *a = &b;
a->getname();
  cout <<"C *c= new C \n";
C *c = new C;
  cout <<"B *b1 = c \n";
  c->getname();
B *b1 = c;
b1->getname();
  cout <<"main start \n";
delete c;

C *cc = new C;
B *bb = cc;

C cc1;
B &bb1 =cc1 ;

B *bb2 = new C;
A *aa1 = bb2;

B *bb3 = new C;
C *cc3 = dynamic_cast<C*> (bb3);
if (cc3 != NULL) 
  cout<<"works\n";
  else
    cout<<"fails\n";

  //type1
  A *aa4 = new B;
  aa4->getname();
  B bb5;
  A &aa5 = bb5;
  aa5.getname();

}

