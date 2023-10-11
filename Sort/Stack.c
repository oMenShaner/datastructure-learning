#include "Stack.h"

// 初始化栈
void StackInit(Stack* ps)
{
  assert(ps);
  
  ps->a = NULL;     
  ps->top = 0;
  ps->capacity = 0;
}

//入栈
void StackPush(Stack* ps, STDataType data)
{
  assert(ps);       //确保ps合法

  //如果容量不够则扩容
  if (ps->capacity == ps->top)
  {
    int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;   //定义新的容量
    STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);  //开辟新的空间
    if (tmp == NULL)
    {
      perror("malloc error");
      exit(-1);
    }
    else 
    {
      ps->a = tmp;
      ps->capacity = newCapacity;
    }
  }

  //将数据入栈
  ps->a[ps->top] = data;
  ps->top++;
}

// 出栈
void StackPop(Stack* ps)
{
  assert(ps); //确保ps合法

  assert(!StackEmpty(ps));  //确保栈不为空
  ps->top--;

}

// 检测栈是否为空, 如果为空返回非零结果, 如果不为空返回 0
int StackEmpty(Stack* ps)
{
  assert(ps); //确保ps合法
  
  if (ps->top > 0)
  {
    return 0;
  }
  else 
  {
    return 1;
  }
}

// 获取栈顶元素
STDataType StackTop(Stack* ps)
{
  assert(ps);   //确保ps合法
  assert(!StackEmpty(ps));  //确保栈不为空

  return ps->a[ps->top - 1];
}

// 获取栈中有效元素个数
int StackSize(Stack* ps)
{
  assert(ps);   //确保ps合法
  return ps->top;
}

// 销毁栈
void StackDestroy(Stack* ps)
{
  assert(ps); //确保ps合法

  free(ps->a);
  ps->a = NULL;
  ps->capacity = 0;
  ps->top = 0;
}
