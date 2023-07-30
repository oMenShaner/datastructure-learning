#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLTDataType;
//单链表结点结构体
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;
}SListNode;

//动态申请一个结点
SListNode* BuySListNode(SLTDataType x);
//单链表打印
void SListPrint(SListNode* pHead);
//单链表尾插
void SListPushBack(SListNode** ppHead, SLTDataType x);
//单链表头插
void SListPushFront(SListNode** ppHead, SLTDataType x);
//单链表尾删
void SListPopBack(SListNode** pHead);
//单链表头删
void SListPopFront(SListNode** pHead);
//单链表查找
SListNode* SListFind(SListNode* pHead, SLTDataType x);
//单链表在 pos 位置之前插入
void SListInsert(SListNode** ppHead, SListNode* pos, SLTDataType x);
//单链表在 pos 位置上删除
void SListErase(SListNode** ppHead, SListNode* pos);
//单链表在 pos 位置之后插入
void SListInsertAfter(SListNode* pos, SLTDataType x);
//单链表在 pos 位置之后删除
void SListEraseAfter(SListNode* pos);
//单链表的销毁
void SListDestroy(SListNode** ppHead);

