#include "Heap.h"

void HeapTest1()
{ 
  int a[] = {60, 70, 80, 50, 40, 30}; 
  AdjustDown(a, 6, 0);

  int i = 0;

  for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void HeapTest2()
{
  Heap heap;

  HeapInit(&heap);
  HeapPush(&heap, 60);
  HeapPush(&heap, 70);
  HeapPush(&heap, 80);
  HeapPush(&heap, 50);
  HeapPush(&heap, 40);
  HeapPrint(&heap);
  HeapPush(&heap, 30);
  AdjustDown(heap.a, 6, 0);
  HeapPrint(&heap);
}

void HeapTest3()
{
  Heap heap;

  int a[] = {7, 5, 6, 4, 3, 2, 1, 0};
  HeapArrayInit(&heap, a, 7);
  HeapPrint(&heap);

  HeapPop(&heap);
  HeapPrint(&heap);
}
int main(void)
{
  //HeapTest1();
  //HeapTest2();
  HeapTest3();

  return 0;
}
