#include "Stack.h"

void StackTest1()
{
  Stack st;

  StackInit(&st);
  StackPush(&st, 1);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));

  StackPush(&st, 2);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
 
  StackPush(&st, 3);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPush(&st, 4);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPush(&st, 5);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
  printf("%d\n", StackSize(&st));
  printf("%d\n", StackTop(&st));
  
  StackPop(&st);
}

int main(void)
{
  StackTest1();

  return 0;
}
