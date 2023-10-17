#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int QDataType;

// 链式结构表示队列
typedef struct QListNode
{
  struct QListNode* next;
  QDataType data;
}QNode;

// 队列的结构
typedef struct Queue
{
  QNode* front;    //指向队列头
  QNode* rear;     //指向队列尾
  int size;        //记录队列的元素个数
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType x);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列尾部元素
QDataType QueueBack(Queue* q);
// 获取队列有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空, 如果为空返回非零结果, 如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);
