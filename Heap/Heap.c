#include "Heap.h"

void AdjustUp(HPDatatype* a, int child)
{
  int parent = (child - 1) / 2;
  while (child > 0)
  {
    if (a[child] > a[parent])
    {
      Swap(&a[child], &a[parent]);
      child = parent;
      parent = (child - 1) / 2;
    }
    else
    {
      break;
    }
  }  
}

void AdjustDown(HPDatatype* a, int n, int parent)
{
  int child = parent * 2 + 1;

  while (child < n)
  {
    //找到更大的孩子
    if (child + 1 < n && a[child + 1] > a[child])
    {
      child++;
    }

    //如果孩子比父亲大,交换元素
    if (a[child] > a[parent])
    {
      Swap(&a[child], &a[parent]);
      parent = child;
      child = parent * 2 + 1;
    }
    else 
    {
      break;
    }
  }

}
void Swap(HPDatatype* p1, HPDatatype* p2)
{
  HPDatatype tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

void HeapInit(Heap* hp)
{
  assert(hp); //确保hp合法

  hp->a = NULL;
  hp->size = hp->capacity = 0;
}

void HeapArrayInit(Heap* hp, HPDatatype* a, int n)
{
  assert(hp); //确保hp合法

  hp->size = hp->capacity = n;
  HPDatatype* tmp = (HPDatatype*)malloc(sizeof(HPDatatype) * n);
  if (tmp == NULL)
  {
     perror("malloc");
  }

  hp->a = tmp;
  memcpy(hp->a, a, sizeof(HPDatatype) * n);
  
  int i = 0;
  //插入建堆
  //for (i = 0; i < n; i++)
  //{
  //  AdjustUp(hp->a,i);
  //}
  
  //从最后一个分支结点开始向下调整建堆
  for (i = (n-2)/2; i >= 0; i--)
  {
    AdjustDown(hp->a, n, i);
  }
}

void HeapPrint(Heap* hp)
{
  assert(hp); //确保hp合法

  int i = 0;
  for (i = 0; i < hp->size; i++)
  {
    printf("%d ", hp->a[i]);
  }
  printf("\n");
}

void HeapDestroy(Heap* hp)
{
  assert(hp); //确保hp合法

  free(hp->a);
  hp->a = NULL;
  hp->size = hp->capacity = 0;
}

void HeapPush(Heap* hp, HPDatatype x)
{
  assert(hp);

  //扩容
  if (hp->size == hp->capacity)
  {
    int newCapacity = hp->capacity == 0 ? 4 : 2 * hp->capacity;
    HPDatatype* tmp = (HPDatatype*)realloc(hp->a, sizeof(HPDatatype) * newCapacity);
    if (tmp != NULL)
    {
      hp->a = tmp;
      hp->capacity = newCapacity;
    }
    else 
    {
      perror("realloc");
    }
  }

  //先将元素未查到数组末尾
  hp->a[hp->size] = x;
  
  //向上调整
  AdjustUp(hp->a, hp->size);
  
  //修改大小
  hp->size++;
}

void HeapPop(Heap* hp)
{
  assert(hp); //确保hp合法
  assert(!HeapEmpty(hp)); //确保堆不为空
 
  //交换最后一个元素和首元素
  Swap(&hp->a[0], &hp->a[hp->size - 1]);
  hp->size--;

  //向下调整
  AdjustDown(hp->a, hp->size, 0);
}

HPDatatype HeapTop(Heap* hp)
{
  assert(hp);
  assert(!HeapEmpty(hp));

  return hp->a[hp->size-1];
}

int HeapEmpty(Heap* hp)
{
  assert(hp); //确保hp合法

  if (hp->size == 0)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}
