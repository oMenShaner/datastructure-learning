#include "LinkList.h"

// 创建一个新结点
static ListNode* BuyListNode(LTDataType x)
{
  ListNode* newNode = (ListNode*)malloc(sizeof(struct ListNode));

  if (newNode == NULL)
  {
    perror("malloc fail");
    exit(-1);
  }

  newNode->data = x;
  newNode->next = NULL;
  newNode->prev = NULL;

  return newNode;
}

// 创建返回链表的头结点
ListNode* ListCreate()
{
  // 动态开辟空间创建头结点, 如果开辟失败直接结束程序
  ListNode* head = BuyListNode(0);
  
  // 处理链表数据, 数据域随机值, 两个指针指向自己
  head->next = head;
  head->prev = head;

  return head;
}

// 双向链表打印
void ListPrint(ListNode* phead)
{
  assert(phead);  //确保哨兵结点存在

  printf("head <=> ");

  ListNode* cur = phead->next;  //从头结点开始遍历, 直到遇到哨兵结点结束
  while (cur != phead)
  {
    printf("%d <=> ", cur->data);
    cur = cur->next;
  }

  printf("\n");
}

// 双向链表销毁
void ListDestroy(ListNode* phead)
{
  assert(phead);  //确保哨兵结点存在

  ListNode* cur = phead->next;

  while (cur != phead)
  {
    ListNode* nextNode = cur->next;
    free(cur);
    cur = nextNode;
  }
  free(phead);
}

// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x)
{
  assert(phead);  //确保哨兵结点存在

  ListNode* newNode = BuyListNode(x); //创建新结点 
  ListNode* tail = phead->prev;       //找到尾结点
  
  //更改链接关系
  tail->next = newNode;
  newNode->prev = tail;
  phead->prev = newNode;
  newNode->next = phead;

}

// 双向链表尾删
void ListPopBack(ListNode* phead)
{
  assert(phead);                    //确保哨兵结点存在
  assert(phead->next != phead);     //确保有结点可删

  ListNode* tail = phead->prev;     //找到要删除的尾结点
  ListNode* tailPrev = tail->prev;  //找到新的尾结点

  //更改链接关系
  tailPrev->next = phead;
  phead->prev = tailPrev;

  free(tail); //释放空间
}

// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x)
{
  assert(phead);  //确保哨兵结点存在

  ListNode* newNode = BuyListNode(x); //创建新结点
  ListNode* first = phead->next;      //找到原来的头结点

  //更新链接关系
  phead->next = newNode;
  newNode->prev = phead;
  newNode->next = first;
  first->prev = newNode;

}

// 双向链表头删
void ListPopFront(ListNode* phead)
{
  assert(phead);  //确保哨兵结点存在
  assert(phead->next != phead); //确保链表不为空

  ListNode* first = phead->next;  //找到头结点位置
  ListNode* second = first->next; //找到头结点后一个结点的位置

  //更新链接关系
  phead->next = second;
  second->prev = phead;

  free(first); //释放空间
}

// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x)
{
  assert(phead);  //确保哨兵结点存在

  ListNode* cur = phead->next;

  while (cur != phead)
  {
    if (cur->data == x)
    {
      return cur;
    }
    cur = cur->next;
  }

  return NULL;
}

// 双向链表在 pos 之前插入
void ListInsert(ListNode* pos, LTDataType x)
{
  assert(pos);  //确保pos合法

  ListNode* newNode = BuyListNode(x); //创建新结点
  ListNode* posPrev = pos->prev;      //找到 pos 前一个结点的位置

  //更新链接方式
  posPrev->next = newNode;
  newNode->prev = posPrev;

  newNode->next = pos;
  pos->prev = newNode;
}
// 双向链表删除 pos 位置的结点
void ListErase(ListNode* pos)
{
  assert(pos);  //确保 pos 合法

  ListNode* posPrev = pos->prev;    //找到 pos 前一个结点的位置
  ListNode* posNext = pos->next;    //找到 pos 后一个结点的位置

  //更新链接方式
  posPrev->next = posNext;
  posNext->prev = posPrev;

  free(pos);  //释放空间
}
