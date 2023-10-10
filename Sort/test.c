#include"Sort.h"

void TestInsert()
{
  int a[] = {9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3};
  InsertSort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}

void TestShell()
{
  int a[] = {9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3};
  ShellSort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}

void TestBubble()
{
  int a[] = {9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3};
  BubbleSort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}


void TestHeap()
{
  int a[] = {9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3};
  HeapSort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}

void TestSelect()
{
  int a[] = {9,1,2,5,7,4,8,6,3,5,1,2,3,5,1,8,3};
  SelectSort(a, sizeof(a)/sizeof(int));
  PrintArray(a, sizeof(a)/sizeof(int));
}

void TestOP()
{
  srand(time(0));
  const int N = 100000;
  int* a1 = (int*)malloc(sizeof(int) * N);
  int* a2 = (int*)malloc(sizeof(int) * N);
  int* a3 = (int*)malloc(sizeof(int) * N);
  int* a4 = (int*)malloc(sizeof(int) * N);
  int* a5 = (int*)malloc(sizeof(int) * N);
  int* a6 = (int*)malloc(sizeof(int) * N);
  int* a7 = (int*)malloc(sizeof(int) * N);

  int i = 0;
  for (i = 0; i < N; i++)
  {
     a1[i] = rand();
     a2[i] = a1[i];
     a3[i] = a1[i];
     a4[i] = a1[i];
     a5[i] = a1[i];
     a6[i] = a1[i];
     a7[i] = a1[i];
  }  
   
  clock_t begin1 = clock();
  InsertSort(a1, N);
  clock_t end1 = clock(); 
    
  clock_t begin2 = clock();
  ShellSort(a2, N);
  clock_t end2 = clock();

  clock_t begin3 = clock();
  BubbleSort(a3, N);
  clock_t end3 = clock();

  clock_t begin4 = clock();
  HeapSort(a4, N);  
  clock_t end4 = clock(); 

  clock_t begin5 = clock();  
  SelectSort(a4, N);   
  clock_t end5 = clock();  
 
  clock_t begin6 = clock();
  //QuickSort(a6, N);   
  clock_t end6 = clock();  

  clock_t begin7 = clock();
  //MergeSort(a7, N);   
  clock_t end7 = clock();  

  printf("InsertSort:%.3lf\n",(double)(end1 - begin1)/CLOCKS_PER_SEC);
  printf("ShellSort:%.3lf\n", (double)(end2 - begin2)/CLOCKS_PER_SEC);  
  printf("BubbleSort:%.3lf\n", (double)(end3 - begin3)/CLOCKS_PER_SEC);  
  printf("SelectSort:%.3lf\n", (double)(end5 - begin5)/CLOCKS_PER_SEC);  
  printf("HeapSort:%.3lf\n", (double)(end4 - begin4)/CLOCKS_PER_SEC);  
  printf("QuickSort:%.3lf\n", (double)(end6 - begin6)/CLOCKS_PER_SEC);  
  printf("MergeSort:%.3lf\n", (double)(end7 - begin7)/CLOCKS_PER_SEC);

  free(a1);
  free(a2);
  free(a3);
  free(a4);
  free(a5);
  free(a6);
  free(a7);

}


int main(void)
{
  //TestInsert();
  //TestShell();
  //TestBubble();
  //TestHeap();
  //TestSelect();
  TestOP();

  return 0;
}
