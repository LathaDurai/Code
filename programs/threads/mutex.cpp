#include<iostream>
#include<thread>

//using namespace std;

const int nthreads = 8;

 int count = 0;
pthread_mutex_t mut;

void *countfun(void * id) {

  long tid  = (long) id;

  pthread_mutex_lock(&mut);
  count++;
  std::cout<<"Count is "<<count<<std::endl;
  pthread_mutex_unlock(&mut);
  pthread_exit((void *) id);
}

int main() {

  pthread_t t1[nthreads];
  int rc = 0;
  pthread_mutex_init(&mut, NULL);
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  void * status;
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for(int i = 0; i< nthreads; ++i) {
   rc = pthread_create(&t1[i], &attr, countfun, (void *) i);
   if (rc) {
     std::cout<<"Error\n";
     exit(-1);
    }
  }

   pthread_attr_destroy(&attr);
   for (int i =0; i< nthreads; ++i) {
     rc = pthread_join(t1[i], &status);
     if (rc){
       std::cout<<"error in join "<<std::endl;
       exit(-1);
     }
     std::cout<<"Status is "<< (long)status<<std::endl;
   }
     pthread_mutex_destroy(&mut);
   pthread_exit(NULL);
}
