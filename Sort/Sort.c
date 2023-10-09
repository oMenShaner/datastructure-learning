#include"Sort.h"

void Swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void PrintArray(int* a, int n)
{
  int i = 0;

  for (i = 0; i < n; i++)
  {
    printf("%d ", a[i]);
  }

  printf("\n");
}

void InsertSort(int* a, int n)
{
  // 将有序数组的最后一个元素的下标定义为end
  // 每次将end+1 的元素插入到有序数组中,从end一直比较到0
  //        如果比有序数组中的元素小  则将有序数组中的元素向后移动一位  接着向前比较
  //        如果比有序数组中的元素大  则直接break
  // 跳出循环后将元素插入到end+1位置
  // 一共进行ｎ－1轮  end从0到n-2
  
  int i = 0;
  for (i = 0; i < n - 1; i++)
  {
    int end = i;         // 有序数组的最后一个元素
    int tmp = a[end+1];  // 记录无序数组第一个元素
    while (end >= 0)
    {
      if (tmp < a[end])
      {
        a[end+1] = a[end];
        end--;
      }
      else 
      {
        break;
      }
    }
    // 将无序数组第一个元素插入已经空好的位置上
    a[end+1] = tmp;
  }
}

void ShellSort(int* a, int n)
{
  // 1.预排序:将数组分组  间隔为gap为一组
  //          按组进行插入排序  即隔着间隔插入排序
  //          gap = gap / 3 + 1
  // 2.直接插入排序:gap==1时  即为直接插入排序  结束后数组即有序
  
  int gap = n;

  while (gap > 1)
  {
    gap = gap/3 + 1;
    int i = 0;
    // 每组依次排序 从0一直排到n-gap-1
    for (i = 0; i < n-gap; i++)
    {
      int end = i;
      int tmp = a[end+gap]; // 由于分组 无序数组第一个元素为end+gap 
      while (end >= 0)
      {
        if (tmp < a[end])
        {
          a[end+gap] = a[end];
          end -= gap;
        }
        else 
        {
          break;
        }
      }
      a[end+gap] = tmp;
    }
  }
}

void BubbleSort(int* a, int n)
{
  int i = 0;
  int exchange = 0;
  for (i = 0; i < n-1; i++)
  {
    int j = 0;
    for (j = 0; j < n-i-1; j++)
    {
      if (a[j] > a[j+1])
      {
        Swap(&a[j], &a[j+1]);
        exchange = 1;
      }
    }
    if (exchange == 0)
    {
      break;
    }
  }
}


















