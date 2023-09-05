#include "Queue.h"

void QueueTest1()
{
  Queue queue;
  QueueInit(&queue);
  QueuePush(&queue, 1);
  QueuePush(&queue, 2);
  QueuePush(&queue, 3);
  QueuePush(&queue, 4);
  QueuePush(&queue, 5);
  QueuePop(&queue);
  QueuePop(&queue);
  QueuePop(&queue);
  QueuePop(&queue);
  QueuePop(&queue);
  QueuePop(&queue);
}

void QueueTest2()
{
  Queue queue;
  QueueInit(&queue);
  QueuePush(&queue, 1);
  QueuePush(&queue, 2);
  QueuePush(&queue, 3);
  QueuePush(&queue, 4);
  QueuePush(&queue, 5);
  QueuePush(&queue, 6);

  while (!QueueEmpty(&queue))
  {
    fprintf(stdout, "%d ", QueueFront(&queue));
    QueuePop(&queue);
  }
  printf("\n");

}
int main(void)
{
  //QueueTest1();
  QueueTest2();

  return 0;
}
