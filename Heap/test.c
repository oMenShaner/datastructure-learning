#include "Heap.h"
#include <time.h>

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

//小堆向下调整
void AdjustDown_small(HPDatatype* a, int n, int parent)
{
  assert(a);
  
  int child = parent * 2 + 1;

  while (child < n)
  {
    if (child + 1 < n && a[child + 1] < a[child])
    {
      child++;
    }

    if (a[parent] > a[child])
    {
      Swap(&a[parent], &a[child]);
      parent = child;
      child = parent * 2 + 1;
    }
    else 
    {
      break;
    }
  }
}

//得到n个数中的最大k个
void PrintTopK(const char* filename, int k)
{
  //打开文件
  FILE* fout = fopen(filename, "r");
  if (fout == NULL)
  {
    perror("fopen");
  }

  //申请一个大小为k的数组空间
  int* a = (int*)malloc(sizeof(int) * k);

  //先将前k个数据建小堆
  int i = 0; 
  for (i = 0; i < k; i++)
  {
    fscanf(fout, "%d", &a[i]);
  }

  for (i = (k-2)/2; i>=0; i--)
  {
    AdjustDown_small(a, k, i);
  }

  //遍历剩余的数，如果有比堆顶大的数，入堆并向下调整
  int num = 0;
  while (fscanf(fout, "%d", &num) != EOF)
  {
    //如果num大于堆顶元素，入堆并向下调整
    if (num > a[0])
    {
      a[0] = num;
      AdjustDown_small(a, k, 0);
    }
  }

  fclose(fout);

  for (i = 0; i < k; i++)
  {
    fprintf(stdout, "%d\n", a[i]);
  }

  free(a);
}

void CreateData()
{
  //打开文件
  FILE* fout = fopen("data", "w+");
  if (fout == NULL)
  {
    perror("fopen");
  }

  //随机放数
  srand(time(0));
  int i = 0;
  int n = 10000000;

  for (i = 0; i < 10000; i++)
  {
    int num = (rand() + i) % n; 
    fprintf(fout, "%d\n", num);
  }

  fclose(fout);

}

int main(void)
{
  //HeapTest1();
  //HeapTest2();
  //HeapTest3();
  
  //int a[] = {3,4,5,6,9,10,2};
  //HeapSort(a, sizeof(a) / sizeof(a[0]));

  //int i = 0;
  //for (i = 0; i < sizeof(a) / sizeof(a[0]); i++)
  //{
  //  printf("%d ", a[i]);
  //}
  //printf("\n");
 
  //CreateData();
  PrintTopK("data", 10);

  return 0;
}
