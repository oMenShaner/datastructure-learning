#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

typedef int HPDatatype;

// 堆的结构
typedef struct Heap
{
  HPDatatype* a;    //堆底层用数组存储
  int size;         //堆的元素个数
  int capacity;     //堆的容量
}Heap;

void AdjustUp(HPDatatype* a, int child);
void AdjustDown(HPDatatype* a, int n , int parent);

void Swap(HPDatatype* p1, HPDatatype* p2);
void HeapInit(Heap* hp);
void HeapPrint(Heap* hp);
void HeapArrayInit(Heap* hp, HPDatatype* a, int n); 
void HeapDestroy(Heap* hp);
void HeapPush(Heap* hp, HPDatatype x);
void HeapPop(Heap* hp);
HPDatatype HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
