#include<iostream>
#include<thread>
#include<unistd.h>

//using namespace std;

const int nthread = 3;
pthread_mutex_t mut;
pthread_cond_t cv;
const int tcount = 10;
int count = 0;
const int count_set = 15;
pthread_t t1[nthread];

void *incrcount(void * id) {

  long tid = (long) id;
  for (int i = 0; i< tcount ; i ++) {
    std::cout<<"Increameting count "<<tid<<std::endl;
    pthread_mutex_lock(&mut);
    count++;
    if (count == count_set) {
      std::cout<<"count reached "<<count<<std::endl;
      pthread_cond_signal(&cv);
    }
  pthread_mutex_unlock(&mut);
  } 
  sleep(3);
  pthread_exit(NULL);
}

void * watchcount(void * id) {
  long tid = (long) id;
  pthread_mutex_lock(&mut);
  while(count <count_set ) {
    std::cout<<"waiting to reach count "<<count<<tid<<std::endl;
    pthread_cond_wait(&cv, &mut);
    count = count+145;
    sleep(2);
      std::cout<<"count added "<<count<<std::endl;
  }
  pthread_mutex_unlock(&mut);
  pthread_exit(NULL);

}
int main() {

  pthread_mutex_init(&mut, NULL);
  pthread_cond_init(&cv, NULL);

  pthread_attr_t attr;
  pthread_attr_init(&attr);
//  void * status;
   int rc , rc1, rc2, rc3;
   long a1 = 1;
   long a2 = 2;
    long  a3 = 3;
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


  rc1 = pthread_create(&t1[0], &attr, watchcount, (void *) a1); 
     if (rc1){
       std::cout<<"error in Create1 "<<std::endl;
       exit(-1);
     }
  rc2 = pthread_create(&t1[1], &attr, incrcount, (void *) a2); 
     if (rc2){
       std::cout<<"error in Create2 "<<std::endl;
       exit(-1);
     }
  rc3 = pthread_create(&t1[2], &attr, incrcount, (void *) a3); 
     if (rc3){
       std::cout<<"error in Create3 "<<std::endl;
       exit(-1);
     }


   for (int i =0; i< nthread; ++i) {
     rc = pthread_join(t1[i], NULL);
     if (rc){
       std::cout<<"error in join "<<std::endl;
       exit(-1);
     }
     //std::cout<<"Status is "<< (long)status<<std::endl;
   }
   pthread_attr_destroy(&attr);
     pthread_mutex_destroy(&mut);
   pthread_cond_destroy(&cv);
   pthread_exit(NULL);
}
