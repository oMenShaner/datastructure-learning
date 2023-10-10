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

int main(void)
{
  //TestInsert();
  TestShell();

  return 0;
}
