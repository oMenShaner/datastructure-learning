#include "SList.h"

void SListTest1()
{
	SListNode* pList = NULL;
	
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	
	SListPrint(pList);
	
	SListPushFront(&pList, -1);
	SListPushFront(&pList, -2);
	SListPushFront(&pList, -3);
	SListPushFront(&pList, -4);
	SListPushFront(&pList, -5);
	SListPushFront(&pList, -6);
	
	SListPrint(pList);

	SListDestroy(&pList);
}

void SListTest2()
{
    SListNode* pList = NULL;

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPushBack(&pList, 5);
    SListPushBack(&pList, 6);

    SListPrint(pList);

    SListPopBack(&pList);
    SListPopBack(&pList);

    SListPrint(pList);

    SListPopBack(&pList);
    SListPopBack(&pList);
    SListPopBack(&pList);

    SListPrint(pList);

    SListPopBack(&pList);

    SListPrint(pList);
	
	SListPopBack(&pList);
	
	SListPrint(pList);
	SListDestroy(&pList);
}

void SListTest3()
{
    SListNode* pList = NULL;

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPushBack(&pList, 5);
    SListPushBack(&pList, 6);

    SListPrint(pList);

    SListPopFront(&pList);
    SListPopFront(&pList);

    SListPrint(pList);

    SListPopFront(&pList);
    SListPopFront(&pList);
    SListPopFront(&pList);

    SListPrint(pList);  

    SListPopFront(&pList);      

    SListPrint(pList);

    SListPopFront(&pList);       //没有结点

    SListPrint(pList);
	SListDestroy(&pList);
}

void SListTest4()
{
    SListNode* pList = NULL;

    SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPushBack(&pList, 5);
    SListPushBack(&pList, 6);

    SListPrint(pList);

    SListNode* pos;
    pos = SListFind(pList, 3);
    SListPrint(pos);

    pos = SListFind(pList, 6);
    SListPrint(pos);

    pos = SListFind(pList, 8);
    SListPrint(pos);
	SListDestroy(&pList);
}

void SListTest5()
{
	SListNode* pList = NULL;
	
	SListPushBack(&pList, 1);
    SListPushBack(&pList, 2);
    SListPushBack(&pList, 3);
    SListPushBack(&pList, 4);
    SListPushBack(&pList, 5);
    SListPushBack(&pList, 6);

    SListPrint(pList);
	
	SListNode* pos;
	pos = SListFind(pList, 1);
	if (pos != NULL)
	{
		SListInsert(&pList, pos, -1);
	}
	SListPrint(pList);

	pos = SListFind(pList, 5);
	if (pos != NULL)
	{
		SListInsert(&pList, pos, -5);
	}
	SListPrint(pList);

	pos = SListFind(pList, 10);
	if (pos != NULL)
	{
		SListInsert(&pList, pos, -10);
	}
	SListPrint(pList);
	SListDestroy(&pList);
	
}

void SListTest6()
{
	SListNode* pList = NULL;
	
	SListPushBack(&pList, 1);
	SListPushBack(&pList, 2);
	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPrint(pList);

	SListNode* pos;
	pos = SListFind(pList, 1);
	if (pos != NULL)
	{
		SListErase(&pList, pos);
	}
	SListPrint(pList);

	pos = SListFind(pList, 5);
	if (pos != NULL)
	{
		SListErase(&pList, pos);;
	}
	SListPrint(pList);

	pos = SListFind(pList, 10);
	if (pos != NULL)
	{
		SListErase(&pList, pos);
	}
	SListPrint(pList);
	SListDestroy(&pList);
}

void SListTest7()
{
	SListNode* pList = NULL;
	
	SListPushBack(&pList, 1);	
	SListPushBack(&pList, 2);	
	SListPushBack(&pList, 3);	
	SListPushBack(&pList, 4);	
	SListPushBack(&pList, 5);	
	SListPushBack(&pList, 6);	
	SListPrint(pList);
	
	SListNode* pos;
//	pos = SListFind(pList, 1);
//	if (pos != NULL)
//	{
//		SListInsertAfter(pos, -1);
//	}
//	SListPrint(pList);	
//	
//	pos = SListFind(pList, 6);
//	if (pos != NULL)
//	{
// 		SListInsertAfter(pos, -6);
//	}
//	SListPrint(pList);
//
//	pos = SListFind(pList, 10);
//	if (pos != NULL)
//	{
//		SListInsertAfter(pos, -10);
//	}
//	SListPrint(pList);
	
	pos = SListFind(pList, 1);
	if (pos != NULL)
	{
		SListEraseAfter(pos);
	}
	SListPrint(pList);

	pos = SListFind(pList, 4);
	if (pos != NULL)
	{
		SListEraseAfter(pos);
	}
	SListPrint(pList);

	pos = SListFind(pList, 6);
	if (pos != NULL)
	{
		SListEraseAfter(pos);
	}
	SListPrint(pList); 
	SListDestroy(&pList);
}

int main(void)
{
	//SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();
	//SListTest5();
	//SListTest6();
	SListTest7();


	return 0;
}
