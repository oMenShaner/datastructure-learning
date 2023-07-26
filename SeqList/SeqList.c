#include "SeqList.h"

//检查容量是否满,若满则扩容,失败返回0,成功或容量未满返回1
static int SeqListCheckCapacity(SeqList* ps)
{
	//如果容量已满,则进行尝试扩容
	if (ps->size == ps->capacity)
	{
		//使用realloc将原空间扩大为 2 倍
		SLDataType* tmp = (SLDataType*)realloc(ps->a, 2 * ps->capacity * sizeof(SLDataType));
		//如果开辟失败,则提示后返回 0
		if (tmp == NULL)
		{
			printf("realloc 扩容失败.\n");
			return 0;
		}
		
		//如果开辟成功,则更新容量
		ps->a = tmp;
		ps->capacity *= 2;
	}
	return 1;
}

//顺序表初始化
void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->a = (SLDataType*)malloc(4*sizeof(SLDataType));
	if (ps->a == NULL)
	{
		perror("SeqListInit");
		exit(-1);
	}

	ps->size = 0;
	ps->capacity = 4;
}

//顺序表销毁
void SeqListDestroy(SeqList* ps)
{
	assert(ps);
	free(ps->a);		//将空间还给操作系统
	ps->a = NULL;		//置空防止野指针
	ps->size = 0;		//空间置零
	ps->capacity = 0;
}

//顺序表打印
void SeqListPrint(const SeqList* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
	
//顺序表尾插
void SeqListPushBack(SeqList* ps, SLDataType x)
{
	assert(ps);
	//若容量不够且扩容失败, 直接结束程序
	if (SeqListCheckCapacity(ps) == 0)
	{
		exit(-1);
	}

	ps->a[ps->size] = x;
	ps->size++;
}	   

//顺序表尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	//确保顺序表有数据可删
	assert(ps->size > 0);

	//进行删除操作
	ps->size--;
}

//顺序表头插
void SeqListPushFront(SeqList* ps, SLDataType x)
{
	assert(ps);	
	//若容量不够且扩容失败, 直接结束程序
	if (SeqListCheckCapacity(ps) == 0)
	{
		exit(-1);
	}

	//从后开始将每个元素向后移动一个位置,直到下标到0
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	
	//第一个位置放入对应元素
	ps->a[0] = x;
	ps->size++;
}

//顺序表头删
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	//确保顺序表有数据可删
	assert(ps->size > 0);
	
	//从前向后将每个元素向前移动一个位置,直到下标为size-1
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	
	ps->size--;
}
		
//顺序表查找
int SeqListFind(const SeqList* ps, SLDataType x)
{	
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	
	return -1;
}

//在pos位置插入x
void SeqListInsert(SeqList* ps, int pos, SLDataType x)
{
	assert(ps);
	//确保插入在合法位置
	assert(pos >= 0 && pos <= ps->size);

	//若空间不够则进行扩容
	if (SeqListCheckCapacity(ps) == 0)
	{
		exit(-1);
	}
	
	//从后向前将pos后面的元素都移动一次
	int end = ps->size - 1;
	while (end >= pos)
	{
		ps->a[end + 1] = ps->a[end];
		--end;
	}
	
	//将pos位置的值设置
	ps->a[pos] = x;
	ps->size++;
}

//删除pos位置上的值
void SeqListErase(SeqList* ps, int pos)
{
	assert(ps);
	//确保pos值合法
	assert(pos >= 0 && pos < ps->size);
	//确保有空间可删
	assert(ps->size > 0);

	//从前将从pos+1的元素向前移动一次
	int begin = pos + 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		++begin;
	}
	
	ps->size--;
}
