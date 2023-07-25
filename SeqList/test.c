#include "SeqList.h"

void SeqListTest1()
{
	SeqList sl;
	SeqListInit(&sl);
	
	SeqListPrint(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPopBack(&sl);	
	SeqListPrint(&sl);
	
	SeqListDestroy(&sl);
}

void SeqListTest2()
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPushFront(&sl, 5);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	SeqListDestroy(&sl);
}

void SeqListTest3()
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);
	
	int pos = 0;
	pos = SeqListFind(&sl, 2);
	printf("%d\n", pos);
	pos = SeqListFind(&sl, 10);
	printf("%d\n", pos);
	pos = SeqListFind(&sl, 11);
	printf("%d\n", pos);
		
	pos = 2;
	SeqListPrint(&sl);
	SeqListInsert(&sl, pos, 100);
	SeqListPrint(&sl);

	pos = 10;
	SeqListPrint(&sl);
	SeqListInsert(&sl, pos, 100);
	SeqListPrint(&sl);

	pos = sl.size + 1;
	SeqListInsert(&sl, pos, 100);
	SeqListDestroy(&sl);
}

void SeqListTest4()
{
	SeqList sl;
	SeqListInit(&sl);

	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);
	SeqListPushBack(&sl, 7);
	SeqListPushBack(&sl, 8);
	SeqListPushBack(&sl, 9);
	SeqListPushBack(&sl, 10);
	
	int pos;
	pos = 1;
	SeqListErase(&sl, pos);
	SeqListPrint(&sl);

	pos = 3;
	SeqListErase(&sl, pos);
	SeqListPrint(&sl);
	SeqListDestroy(&sl);	
	}
int main(void)
{
	//SeqListTest1();
	//SeqListTest2();
	//SeqListTest3();
	SeqListTest4();

	return 0;
}

