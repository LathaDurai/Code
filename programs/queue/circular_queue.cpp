#include<iostream>


struct Queue {

  int *arr;
  int size;
  int capacity;
  int front;
  int rear;
};

Queue* createQueue(int n) {
  std::cout<<"inside CreateQueue \n";
  Queue *queue = new Queue;
  queue->arr = new int[n];
  queue->size = 0;
  queue->capacity = n;
  queue->front = 0;
  queue->rear = queue->capacity-1;
  return queue;
}

bool is_empty(Queue* queue) {

  if(queue->size == 0) {
     std::cout<<"Queue is Underflow \n";
     return 1;
  }
  return 0;
}


bool is_full(Queue* queue) {

  if(queue->size == queue->capacity) {
    std::cout<<"Queue is Overflow \n";
    return 1;
  }
  return 0;
}

void enqueue(Queue* queue, int n) {

  std::cout<<"Inside Enqueue "<<n<<" \n";

  if(is_full(queue)) {
    return ;
  }

  queue->rear = (queue->rear+1)%queue->capacity;
  queue->arr[queue->rear] = n;
  queue->size = queue->size+1;
  return;
}

void dequeue(Queue* queue) {
  std::cout<<"Inside dequeue \n";

  if(is_empty(queue)) {
    return ;
  }

  std::cout<<"dequeue element is "<<queue->arr[queue->front]<<"\n";
  queue->front = (queue->front+1)%queue->capacity;
  queue->size = queue->size -1;
}

int front(Queue* queue) {

  std::cout<<"Inside front \n";

  if(is_empty(queue)) {
    return 0;
  }

  int temp = queue->arr[queue->front];
  return temp;
}

int rear(Queue* queue) {
  std::cout<<"Inside rear \n";

  if(is_empty(queue)) {
    return 0;
  }

  int temp =  queue->arr[queue->rear];
  return temp;
}




int main() {

  Queue* queue = createQueue(6);
  enqueue(queue, 10);
  enqueue(queue, 20);
  enqueue(queue, 30);
  enqueue(queue, 40);
  enqueue(queue, 50);
  enqueue(queue, 60);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  dequeue(queue);
  enqueue(queue, 70);
  std::cout<<"Value in front is "<<front(queue)<<"\n";
  std::cout<<"Value in rear is "<<rear(queue)<<"\n";

  return 0;
}
