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

  int a[] = {7, 8, 6, 4, 9, 2, 1, 0};
  HeapArrayInit(&heap, a, 8);
  HeapPrint(&heap);

  HeapPop(&heap);
  HeapPrint(&heap);
}

//升序
void HeapSort1(int* a, int n)
{
  int i = 0;
  //建大堆
  for (i = 0; i < n; i++)
  {
    AdjustUp(a, i);
  }

  //不断将根元素放置最后一个,让前面的元素向下调整
  for (i = 0; i < n; i++)
  {
    Swap(&a[0], &a[n - 1 - i]);
    AdjustDown(a, n - 1 - i, 0);
  }
}

//升序
void HeapSort(int* a, int n)
{
  int i = 0;
  //建大堆,从最后一个分支结点开始向下调整
  for (i = (n-1-1)/2; i>=0; i--)
  {
    AdjustDown(a, n, i);
  }

  //将堆顶元素与堆底元素交换后,向下调整
  int end = n - 1;
  while (end > 0)
  {
    Swap(&a[0], &a[end]);
    AdjustDown(a, end, 0);
    --end;
  }

}

int main(void)
{
  //HeapTest1();
  //HeapTest2();
  HeapTest3();
  
  int a[] = {3,4,5,6,9,10,2};
  HeapSort(a, sizeof(a) / sizeof(a[0]));

  int i = 0;
  for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  {
    printf("%d ", a[i]);
  }
  printf("\n");
  return 0;
}
