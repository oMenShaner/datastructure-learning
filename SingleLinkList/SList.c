#include "SList.h"

// 动态申请一个结点
SListNode* BuySListNode(SLTDataType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));

    if (newNode == NULL)
    {
        perror("BuySListNode:");
        exit(-1);
    }

    newNode->data = x;
    newNode->next = NULL;

	return newNode;
}

// 单链表打印
void SListPrint(SListNode* pHead)
{
   SListNode* cur = pHead;  //定义一个局部变量指针用来访问链表

   //从头依次访问链表, cur不为空进入循环
   while(cur != NULL)
   {
        printf("%d -> ", cur->data);    //打印结构的数据域
        cur = cur->next;    //使cur指向下一结点
   }

   printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** ppHead, SLTDataType x)
{
	assert(ppHead);

    SListNode* newNode = BuySListNode(x);   //创建一个新结点

    if(*ppHead == NULL)    //没有结点, 直接将新结点的地址赋值
    {
        *ppHead = newNode;  //修改结构体指针, 需要用到二级指针
    }
    else    //有结点, 依次访问直到最后一个元素
    {
        SListNode* tail = *ppHead;  //tail 用于访问链表
        while (tail->next != NULL)
        {
            tail = tail->next;  
        }

        tail->next = newNode;   //修改结构体, 只要用到一级指针
    }
}

// 单链表的头插
void SListPushFront(SListNode** ppHead, SLTDataType x)
{
    SListNode* newNode = BuySListNode(x);   //创建新结点

    newNode->next = *ppHead;    //新结点指向原链表第一个结点
    *ppHead = newNode;          //更新头结点
}

// 单链表的尾删
void SListPopBack(SListNode** ppHead)
{
	assert(ppHead);
    assert(*ppHead);    //没有结点的情况

    if ((*ppHead)->next == NULL)  //只有一个结点的情况
    {
        free(*ppHead);
        *ppHead = NULL; //修改实参的值需要用到二级指针
    }
    else    //有两个结点以上的情况
    {
        SListNode* tail = *ppHead;   //tail用来访问结构体成员

        while (tail->next->next != NULL) //需要修改倒数第二个结点的值, 则访问到倒数第二个结点即停止
        {
            tail = tail->next;
        }

        free(tail->next);  //先释放最后一个结点的空间
        tail->next = NULL;  //倒数第二个结点指向NULL
    }
}

// 单链表头删
void SListPopFront(SListNode** ppHead)
{	
	assert(ppHead);
    assert(*ppHead);    //链表为空

    //链表非空
    SListNode* newNode = (*ppHead)->next;   //记录新的头结点
    free(*ppHead);      //释放原头结点空间
    *ppHead = newNode;  //更新头结点
}

// 单链表查找
SListNode* SListFind(SListNode* pHead, SLTDataType x) 
{
    SListNode* cur = pHead; //cur访问每个结点

    while (cur != NULL)
    {
        if (cur->data == x)
        {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

// 指定位置前插
void SListInsert(SListNode** ppHead, SListNode* pos, SLTDataType x)
{
	assert(ppHead);
	assert(pos);
	
	SListNode* newNode = BuySListNode(x);	//创建新结点
	
	if (*ppHead == pos)	//如果pos指向第一个结点
	{
		//头插
		newNode->next = *ppHead;
		*ppHead = newNode;
	}
	else
	{
		SListNode* prev = *ppHead;	//prev用于访问到pos前一个结点的位置
		
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		
		//插入
		newNode->next = pos;
		prev->next = newNode;
	}
}

// 单链表在 pos 位置上删除
void SListErase(SListNode** ppHead, SListNode* pos)
{	
	assert(ppHead);
	assert(pos);

	if (*ppHead == pos)	//如果 pos 指向第一个结点
	{				
		*ppHead = pos->next;
		free(pos);		//释放空间
	}
	else	//有两个及以上结点
	{
		SListNode* prev = *ppHead;	//prev 访问到pos之前的一个结点
		
		while (prev->next != pos)
		{	
			prev = prev->next;
		}
		
		//删除
		prev->next = pos->next;
		free(pos);
	}
}

// 单链表销毁
void SListDestroy(SListNode** ppHead)
{
	assert(ppHead);
	
	SListNode* cur = *ppHead;
	
	while (cur != NULL)
	{
		SListNode* next = cur->next;
		free(cur);
		cur = next;
	}
	
	*ppHead = NULL;
}

// 单链表在 pos 位置后插入
void SListInsertAfter(SListNode* pos, SLTDataType x)
{
	assert(pos);	//确保插入位置合法
	
	SListNode* newNode = BuySListNode(x);
	newNode->next = pos->next;
	pos->next = newNode;
}		 

// 单链表在 pos 位置之后删除
void SListEraseAfter(SListNode* pos)
{
	assert(pos);	//确保删除位置合法
	assert(pos->next);
	
	SListNode* deleteNode = pos->next;
	pos->next = deleteNode->next;
	free(deleteNode);
}	
