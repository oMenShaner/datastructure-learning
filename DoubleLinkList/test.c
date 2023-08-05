#include "LinkList.h"

void LinkListTest1()
{
  ListNode* head = ListCreate();
  ListPushBack(head, 1);
  ListPushBack(head, 2);
  ListPushBack(head, 3);
  ListPushBack(head, 4);
  ListPushBack(head, 5);
  ListPrint(head);

  ListPopBack(head);
  ListPrint(head);

  ListPopBack(head);
  ListPrint(head);
  
  ListPopBack(head);
  ListPopBack(head);
  ListPopBack(head);
  ListPrint(head);
  
  ListPopBack(head);
  ListPrint(head);
  
  ListDestroy(head);
}

void LinkListTest2()
{
  ListNode* head = ListCreate();

  ListPushFront(head, 1);
  ListPushFront(head, 2);
  ListPushFront(head, 3);
  ListPushFront(head, 4);
  ListPushFront(head, 5);

  ListPrint(head);
  
  ListPopFront(head);
  ListPrint(head);

  ListPopFront(head);
  ListPopFront(head);
  ListPopFront(head);
  ListPopFront(head);
  ListPrint(head);

  ListPopFront(head);
  ListPrint(head);

  ListDestroy(head);
}

void LinkListTest3()
{
  ListNode* head = ListCreate();

  ListPushBack(head, 1);
  ListPushBack(head, 2);
  ListPushBack(head, 3);
  ListPushBack(head, 4);
  ListPushBack(head, 5);
  ListPrint(head);

  ListNode* pos;

  pos = ListFind(head, 1);
  ListInsert(pos, 0);
  ListErase(pos);
  ListPrint(head);

  pos = ListFind(head, 4);
  ListInsert(pos, 10);
  ListPrint(head);

  pos = ListFind(head, 11);
  ListInsert(pos, 12);
  ListPrint(head);

  ListDestroy(head);
}

void LinkListTest4()
{
  ListNode* head = ListCreate();

  ListPushBack(head, 1);
  ListPushBack(head, 2);
  ListPushBack(head, 3);
  ListPushBack(head, 4);
  ListPushBack(head, 5);

  ListNode* pos;

  pos = ListFind(head, 2);
  printf("pos <=> ");
  while (pos && pos != head)
  {
    printf("%d <=> ", pos->data);
    pos = pos->next;
  }
  puts("\n");

  pos = ListFind(head, 6);
  printf("pos <=> ");
  while (pos && pos != head)
  {
    printf("%d <=> ", pos->data);
    pos = pos->next;
  }
  puts("\n");
}

void LinkListTest5()
{
  ListNode* head = ListCreate();

  ListPushBack(head, 1);
  ListPushBack(head, 2);
  ListPushBack(head, 3);
  ListPushBack(head, 4);
  ListPushBack(head, 5);
  ListPrint(head);

  ListNode* pos;

  pos = ListFind(head, 1);
  if (pos)
  {
    ListInsert(pos, -1);
    ListPrint(head);
  }

  pos = ListFind(head, 4);
  if (pos)
  {
    ListInsert(pos, -4);
    ListPrint(head);
  }

  pos = ListFind(head, 6);
  if (pos)
  {
    ListInsert(pos, -6);
    ListPrint(head);
  }

  ListDestroy(head);
}

void LinkListTest6()
{
  ListNode* head = ListCreate();

  ListPushBack(head, 1);
  ListPushBack(head, 2);
  ListPushBack(head, 3);
  ListPushBack(head, 4);
  ListPushBack(head, 5);
  ListPrint(head);

  ListNode* pos;

  pos = ListFind(head, 1);
  if (pos)
  {
    ListErase(pos);
    ListPrint(head);
  }

  pos = ListFind(head, 4);
  if (pos)
  {
    ListErase(pos);
    ListPrint(head);
  }

  pos = ListFind(head, 6);
  if (pos)
  {
    ListErase(pos);
    ListPrint(head);
  }

  ListDestroy(head);
}

int main(void)
{
  //LinkListTest1();
  //LinkListTest2();
  //LinkListTest3();
  //LinkListTest4();
  //LinkListTest5();
  LinkListTest6();
  return 0;
}
