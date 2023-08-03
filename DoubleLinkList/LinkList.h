#pragma once 

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int LTDataType;
typedef struct ListNode
{
  LTDataType data;        //数据域
  struct ListNode* prev;  //指向前一个结点
  struct ListNode* next;  //指向后一个结点
}ListNode;

// 创建并返回链表的头结点
ListNode* ListCreate();
// 双向链表销毁
void ListDestroy(ListNode* phead);
// 双向链表打印
void ListPrint(ListNode* phead);
// 双向链表尾插
void ListPushBack(ListNode* phead, LTDataType x);
// 双向链表尾删
void ListPopBack(ListNode* phead);
// 双向链表头插
void ListPushFront(ListNode* phead, LTDataType x);
// 双向链表头删
void ListPopFront(ListNode* phead);
// 双向链表查找
ListNode* ListFind(ListNode* phead, LTDataType x);
// 双向链表在 pos 的前面进行插入
void ListInsert(ListNode* pos, LTDataType x);
// 双向链表删除 pos 位置的结点
void ListErase(ListNode* pos);
