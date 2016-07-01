#include<iostream>
#include<thread>
#include<unistd.h>

using namespace std;

const int nthread = 8;
const int arraysize =5000;
const int extra = 5000;
  pthread_attr_t attr;

void *print(void *id)
{
   double A[arraysize];
   long tid;
   size_t mystacksize;

   tid = (long)id;
   sleep(3);
   for (int i=0; i<arraysize; i++) {
      A[i] = i * 1.0;
   }
   cout<<tid<<" Hello World!"<< A[arraysize-1]<<"\n";
   pthread_attr_getstacksize (&attr, &mystacksize);
   cout<<tid<<"Thread stack size = "<< mystacksize<<"\n";
   pthread_exit(NULL);
}

int main() {

  int rc;

  pthread_t t1[nthread];
  size_t stacksize;
  pthread_attr_init(&attr);
  stacksize = sizeof(double) * arraysize + extra;

  pthread_attr_setstacksize(&attr, stacksize);
  pthread_attr_getstacksize(&attr, &stacksize);

  for(long i = 0; i<nthread; ++i) {
    
     rc = pthread_create(&t1[i],&attr, print, (void *) i);

     if(rc) {
      cout<<"Error \n";
      exit(-1);
     }
  }
  pthread_exit(NULL);
}

 

