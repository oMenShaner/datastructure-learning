#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;
typedef struct SeqList
{
	SLDataType* a;
	size_t size;
	size_t capacity;
}SeqList;

// 对数据的管理:增删查改
void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);


void SeqListPrint(const SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType x);
void SeqListPushFront(SeqList* ps, SLDataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);	

// 顺序表查找
int SeqListFind(const SeqList* ps, SLDataType x);
// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDataType x);
// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, int pos);

