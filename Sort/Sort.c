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
  
  // 小区间情况 right-left+1 <= 10, 直接插入排序可以省去87.5%的递归子树
  int size = right - left + 1;
  if (size <= 10)
  {
    InsertSort(a, size);
  }
  else 
  {
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

  // 小区间情况 right-left+1 <= 10, 直接插入排序可以省去87.5%的递归子树
  int size = right - left + 1;
  if (size <= 10)
  {
    InsertSort(a, size);
  }
  else 
  {
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

void QuickSortNorR(int*a, int left, int right)
{
  // 创建栈 并按照先left后right的顺序入栈
  Stack stack;
  StackInit(&stack);
  StackPush(&stack, left);
  StackPush(&stack, right);

  // 将栈顶两个元素出栈 进行一轮排序
  // 每次排序后 按照先右后左的顺序将区间的left和right入栈
  // 如果right<=left 不入栈
  while (!StackEmpty(&stack))
  {
    int right = StackTop(&stack);
    StackPop(&stack);
    int left = StackTop(&stack);
    StackPop(&stack);

    // 这里使用挖坑法
    int keyi = PartSort2(a, left, right);
    
    // 先右后左 先left后right入栈
    if (right > keyi+1)
    {
      StackPush(&stack, keyi+1);
      StackPush(&stack, right);
    }
    
    if (keyi-1 > left)
    {
      StackPush(&stack, left);
      StackPush(&stack, keyi-1);
    }
  }
  StackDestroy(&stack);
}

void Merge(int* a, int* tmp, int left, int mid, int right)
{
  int cur1 = left;  //数组1首元素下标
  int cur2 = mid + 1;   //数组2首元素下表
  int index = left; //tmp数组首元素下标

  while (cur1 <= mid && cur2 <= right)
  {//去两数组最小值尾插至tmp数组
    if (a[cur1] < a[cur2])
    {
      tmp[index++] = a[cur1++];   
    }
    else 
    {
      tmp[index++] = a[cur2++];
    }
  }

  while (cur1 <= mid)
  {//如果数组1没有遍历完
    tmp[index++] = a[cur1++];
  }

  while (cur2 <= right)
  {//如果数组2没有遍历完
    tmp[index++] = a[cur2++];
  }

  //拷贝tmp数组至a数组
  memcpy(a+left, tmp+left, sizeof(int) * (right - left + 1)); 
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
  if (right <= left)
    return;

  int mid = (left + right) / 2;
  _MergeSort(a, tmp, left, mid); 
  _MergeSort(a, tmp, mid+1, right);

  //归并
  Merge(a, tmp, left, mid, right);
}

void MergeSort(int* a, int n)
{
  // 先开辟一个tmp数组空间
  int* tmp = (int*)malloc(sizeof(int) * n);
  
  if (tmp == NULL)
  {
    perror("malloc");
  }

  int left = 0;
  int right = n-1;
  _MergeSort(a, tmp, left, right); //[left, right]

  free(tmp);
}

void MergeSortNorR(int* a, int n)
{
  int* tmp = (int*)malloc(sizeof(int) * n);
  if (tmp == NULL)
  {
    perror("malloc fail");
  }

  // 11归并->22归并->...
  int gap = 1;
  int i = 0;
  
  while (gap < n)
  {
    for (i = 0; i < n; i += 2*gap)
    {
      int mid = i + gap - 1;
      int left = i;
      int right = i + 2*gap - 1;
      
      if (mid+1 >= n)
      {//如果右子序列的左下标越界，直接返回
        break;
      }

      if (right >= n)
      {//如果右子序列的右下标越界，修改下标
        right = n-1;
      }
      Merge(a, tmp, left, mid, right);
    }
    gap *= 2;
  }

  free(tmp);
}

void CountSort(int* a, int n)
{
  int min = a[0];
  int max = a[0];
  int i = 0;
  
  // 得到序列的最大最小值
  for (i = 1; i < n; i++)
  {
    if (a[i] < min)
    {
      min = a[i];
    }

    if (a[i] > max)
    {
      max = a[i];
    }
  }

  // 得到序列的范围
  int range = max - min + 1;
  printf("range:%d\n", range);

  int* tmp = (int*)calloc(range, sizeof(int));
  if (tmp == NULL)
  {
    perror("malloc fail");
  }

  // 统计各数
  for (i = 0; i < n; i++)
  {
    tmp[a[i] - min]++;
  }

  // 从小到大重新copy到原数组
  int index = 0;
  for (i = 0; i < range; i++)
  {
    while (tmp[i])
    {
      a[index++] = i + min;
      tmp[i]--;
    }
  }
  
  free(tmp);
}

int getMax(int* a, int n)
{
  int i = 0;
  int max = a[0];
  for (i = 1; i < n; i++)
  {
    if (a[i] > max)
    {
      max = a[i];
    }
  }

  return max;
}

int getMin(int* a, int n)
{
  int i = 0; 
  int min = a[0];

  for (i = 1; i < n; i++)
  {
    if (a[i] < min)
    {
      min = a[i];
    }
  }

  return min;
}

int getMaxDigit(int* a, int n)
{
  // 得到最大数, 并取到其的位数
  int max = getMax(a, n);
  int max_digit = 1;
  while (max >= 10)
  {
    max_digit++;
    max /= 10;
  }
  
  return max_digit;
}

int getDigitNum(int num, int base)
{
  while (base > 1)
  {
    num /= 10;
    base--;
  }

  return num % 10;
}

// 将数组所有元素变为非负数, 返回最小值
int arrayToNonnegative(int*a, int n)
{
  int min = getMin(a, n);
  int i = 0;
  if (min < 0)
  {
    for (i = 0; i < n; i++)
    {
      a[i] -= min ; 
    }
  }
  
  return min;
}

//将数组恢复原来的状态
void arrayToPreliminary(int* a, int n, int min)
{
  int i = 0;
  
  if (min < 0)
  {
    for (i = 0; i < n; i++)
    {
      a[i] += min;
    }
  }
}

void RadixSort(int* a, int n)
{
  // 创建长度为10的队列数组
  Queue* count = (Queue*)malloc(sizeof(Queue) * 10);
  int i = 0;
  for (i = 0; i < 10; i++)
  {
    QueueInit(&count[i]); 
  }

  int min = arrayToNonnegative(a, n);

  int max_digit = getMaxDigit(a, n);

  // 1-个位 2-十位 3-百位
  int base = 1;
  // 从个位到最高位, 如果某数该位是i, 入i队列
  while (base <= max_digit)
  {
    for (i = 0; i < n; i++)
    {
      int digit_num = getDigitNum(a[i], base);  //得到每个数在该位的数字 
      QueuePush(&count[digit_num], a[i]);       //入对应下标序号的队列中
    }
    
    int index = 0;
    for (i = 0; i < 10; i++)
    {//按升序将每个队列的元素重新放回数组中
      while (!QueueEmpty(&count[i]))
      {
        a[index++] = QueueFront(&count[i]);
        QueuePop(&count[i]);
      }
    }
    base++;
  }
  
  arrayToPreliminary(a, n, min);

  // 释放数组空间
  for (i = 0; i < 10; i++)
  {
    QueueDestroy(&count[i]);
  }

  free(count);
}
















