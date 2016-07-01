#include <iostream>
#include <pthread.h>
#include <unistd.h>

using namespace std;



int const num_thread = 5;

struct data {

  int thread_id;
  const  char * msg;
};

void *print( void * info) {

  struct data *data1;
  data1 = (struct data *)info;
  cout<<"Hi Iam Thread "<<data1->thread_id<<"\t \t";
  cout<<"Thread Message is "<<data1->msg<<"\n";
  sleep(1);
  pthread_exit(NULL);
}

int main() {

  pthread_t thread[num_thread];
  int rc = 0;

  struct  data st_thrd[num_thread];

  void *status;
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

  for (int i = 0; i< num_thread; ++i) {
    cout<<"Creating Thread ---"<<i<<"\n";

    st_thrd[i].thread_id = i;
    st_thrd[i].msg = "This is me";

    //rc = pthread_create(&thread[i], NULL, print, (void *) &st_thrd[i]);
    rc = pthread_create(&thread[i], &attr, print, (void *) &st_thrd[i]);

   if (rc) {
      cout<<"Problem in Creating Thread[ " << i << "] =" << rc << "\n";
      exit(-1);
   } 
  }

  pthread_attr_destroy(&attr);
  for (int i=0; i<num_thread; ++i) {
    rc = pthread_join(thread[i], &status);

    if (rc) {
      cout<<"Problem in Joining thread " <<i << rc<<"\n";
    }
      cout<<"Status is "<<(long)status<<"\n";
  }

  pthread_exit(NULL);
}

