#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

const int nthreads=32;

void *print (void *id) {
  long tt;
  tt = (long)id;
  sleep(2);
  cout<<"Iam Thread "<<tt<<"\n";
  pthread_exit(NULL);
};
int main() {

  pthread_t t[nthreads];
  int rc;
  for (int i=0; i<nthreads; ++i) {
    rc=  pthread_create(&t[i],NULL,print,(void *)i);
    if(rc) {
      cout<<"ERROR";
      exit(-1);
    }
  }
  pthread_exit(NULL);
}

