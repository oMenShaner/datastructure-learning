#include "Queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
  assert(q);  //确保q合法

  q->front = q->rear = NULL;  //将头和为置为 NULL 
  q->size = 0;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType x)
{
  assert(q);  //确保q合法

  //创建新结点
  QNode* newNode = (QNode*)malloc(sizeof(QNode));
  newNode->data = x;
  newNode->next = NULL;

  //入队列
  if (QueueEmpty(q))
  {
    //如果队列为空,直接赋值
    q->front = q->rear = newNode;
  }
  else 
  {
    //如果队列不为空,直接尾插
    q->rear->next = newNode;
    q->rear = newNode;
  }

  q->size++;
}

// 队头出队列
void QueuePop(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  if (q->size == 1)
  {
    //如果只有一个元素,头删的同时还要将尾指针置空
    free(q->front);
    q->front = q->rear = NULL;
  }
  else 
  {
    //如果不止一个元素,则只头删
    QNode* nextNode = q->front->next;
    free(q->front);
    q->front = nextNode;
  }

  q->size--;
}

// 获取头部元素
QDataType QueueFront(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  return q->front->data;
}

// 获取尾部元素
QDataType QueueBack(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  return q->rear->data;
}

// 获取队列元素个数
int QueueSize(Queue* q)
{
  assert(q);  //确保q合法

  return q->size;
}

// 判断队列是否为空, 如果为空返回非0, 非空返回0
int QueueEmpty(Queue* q)
{
  assert(q);  //确保q合法

  if (q->size == 0)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

// 销毁队列
void QueueDestroy(Queue* q)
{
  assert(q);

  while(!QueueEmpty(q))
  {
    QNode* nextNode = q->front->next;
    free(q->front);
    q->front = nextNode;
  }

  q->front = q->rear = NULL;
  q->size = 0;
}
