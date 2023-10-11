#include"Sort.h"

void Swap(int* a, int* b)
{
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void AdjustDown(int* a, int n, int parent)
{
  int child = parent * 2 + 1;

  while (child < n)
  {
    if (child + 1 < n && a[child] < a[child+1])
    {
      child++;
    }

    if (a[parent] < a[child])
    {
      Swap(&a[parent], &a[child]);
      parent = child;
      child = parent * 2;
    }
    else 
    {
      break;
    }
  }
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

void HeapSort(int* a, int n)
{
  // 在原有的数组基础上 从后往前向下调整建堆
  // 将堆顶元素与堆底元素交换后 在不包括最后一个元素的情况下向下调整
  
  int i = 0;
  for (i = (n-1-1)/2; i >= 0; i--)
  {
    AdjustDown(a, n, i);
  }

  for (i = n - 1; i > 0; i--)
  {
    Swap(&a[0], &a[i]);
    AdjustDown(a, i, 0);
  }
}


void SelectSort(int* a, int n)
{
  // 每轮选出数组中最大数和最小数的下标
  // 将最大数放在数组最后 将最小数放在数组最前
  int begin = 0;
  int end = n - 1;

  while (begin < end)
  {
    int maxi = begin;
    int mini = begin;
    int i = 0;
    
    // 找到最大和最小下标
    for (i = begin+1; i <= end; i++)
    {
      if (a[i] > a[maxi])
      {
        maxi = i;
      }

      if (a[i] < a[mini])
      {
        mini = i;
      }
    }

    // 交换 注意可能会出现最大或最小数已经被交换了的情况
    Swap(&a[begin], &a[mini]);

    if (maxi == begin)
    {
      maxi = mini;
    }
    Swap(&a[end], &a[maxi]);

    begin++;
    end--;
  }
}

// 三数取中
int getMidi(int* a, int left, int right)
{
  int mid = (left + right) / 2;
  if (a[mid] > a[left])
  {
    if (a[left] > a[right]) //此时mid是最大值
    {
      return left;
    }
    else if (a[right] > a[mid]) 
    {
      return mid;
    }
    else 
    {
      return right;
    }
  }
  else // a[left] > a[mid]
  {
    if (a[right] > a[left]) //此时mid是最小值
    {
      return left;
    }
    else if (a[right] < a[mid])
    {
      return mid;
    }
    else 
    {
      return right;
    }
  }
}

// hoare版本
int PartSort1(int* a, int left, int right)
{
  // 每次定下基准元素key, 将key元素放在此部分首元素
  // 先从right向前找比key小的值, 如果找到记录下标
  // 再从left向后找比key大的值, 如果找到记录下标
  // 将找到的两个数进行交换, 重复两次寻找, 直至相遇
  // 记录相遇的下标, 将此部分首元素和相遇下标元素进行交换
  // 以上是一躺排序
  
  int mid = getMidi(a, left, right);
  Swap(&a[left], &a[mid]);

  int keyi = left;
  while (left < right)
  {
    // 先从right开始向前找比key小的值
    while (left < right && a[right] >= a[keyi])
    {
      right--;
    }

    // 再从left开始向后找比key大的值
    while (left < right && a[left] <= a[keyi])
    {
      left++;
    }
    Swap(&a[left], &a[right]);
  }
  Swap(&a[keyi], &a[left]);

  return left;
}

// 挖坑法
int PartSort2(int* a, int left, int right)
{
  int mid = getMidi(a, left, right);
  Swap(&a[left], &a[mid]);

  int key = a[left];
  int hole = left;
  while (left < right)
  {
    // 先找小
    while (left < right && a[right] >= key)
    {
      right--;
    }
    //找到直接赋值到坑位, 同时将此时的right位置当作坑
    a[hole] = a[right];
    hole = right;

    // 再找大
    while (left < right && a[left] <= key)
    {
      left++;
    }
    //找到直接赋值到坑位, 同时将此时的left位置当作坑
    a[hole] = a[left];
    hole = left;
  }
  a[hole] = key;
  return left;
}

// 前后指针
int PartSort3(int*a, int left, int right)
{
  // prev 和 cur  prev = left   cur = left+1
  // cur向后遍历  如果遇到比key值小的值 将cur位置的值与prev指向后一位置的值进行交换
  int mid = getMidi(a, left, right);
  Swap(&a[left], &a[mid]);
  
  int keyi = left;
  int prev = left;
  int cur = prev + 1;
  
  while (cur <= right)
  {
    if (a[cur] < a[keyi] && ++prev != cur)
    {
      Swap(&a[cur], &a[prev]);
    }
    cur++;
  }
  Swap(&a[keyi], &a[prev]);

  return prev;
}

void QuickSort1(int* a, int left, int right)
{
  // 每一次排序可以确认一个数的位置, 再在这个数左右进行二分继续排序
  
  if (left >= right)
    return ;

  int keyi = PartSort1(a, left, right);
  QuickSort1(a, left, keyi-1);
  QuickSort1(a, keyi+1, right);
}

void QuickSort2(int* a, int left, int right)
{
  if (left >= right)
    return ;

  int keyi = PartSort2(a, left, right);
  QuickSort2(a, left, keyi-1);
  QuickSort2(a, keyi+1, right);
}

void QuickSort3(int* a, int left, int right)
{
  if (left >= right)
    return ;

  int keyi = PartSort3(a, left, right);
  QuickSort2(a, left, keyi-1);
  QuickSort2(a, keyi+1, right);
}









