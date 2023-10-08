#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char BTDataType;
typedef struct BinaryTreeNode
{
  BTDataType data;  
  struct BinaryTreeNode* left;  //指向左孩子
  struct BinaryTreeNode* right; //指向右孩子
}BTNode;  //二叉树结点

//////////////////////////////////////////////////////////////队列///////////////////////////////////////////////////////
typedef BTNode* QDataType;

// 链式结构表示队列
typedef struct QListNode
{
  struct QListNode* next;
  QDataType data;
}QNode;

// 队列的结构
typedef struct Queue
{
  QNode* front;    //指向队列头
  QNode* rear;     //指向队列尾
  int size;        //记录队列的元素个数
}Queue;

// 初始化队列
void QueueInit(Queue* q);
// 队尾入队列
void QueuePush(Queue* q, QDataType x);
// 队头出队列
void QueuePop(Queue* q);
// 获取队列头部元素
QDataType QueueFront(Queue* q);
// 获取队列尾部元素
QDataType QueueBack(Queue* q);
// 获取队列有效元素个数
int QueueSize(Queue* q);
// 检测队列是否为空, 如果为空返回非零结果, 如果非空返回0
int QueueEmpty(Queue* q);
// 销毁队列
void QueueDestroy(Queue* q);

// 初始化队列
void QueueInit(Queue* q)
{
  assert(q);  //确保q合法

  q->front = q->rear = NULL;  //将头和为置为 NULL 
  q->size = 0;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType x)
{
  assert(q);  //确保q合法

  //创建新结点
  QNode* newNode = (QNode*)malloc(sizeof(QNode));
  newNode->data = x;
  newNode->next = NULL;

  //入队列
  if (QueueEmpty(q))
  {
    //如果队列为空,直接赋值
    q->front = q->rear = newNode;
  }
  else 
  {
    //如果队列不为空,直接尾插
    q->rear->next = newNode;
    q->rear = newNode;
  }

  q->size++;
}

// 队头出队列
void QueuePop(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  if (q->size == 1)
  {
    //如果只有一个元素,头删的同时还要将尾指针置空
    free(q->front);
    q->front = q->rear = NULL;
  }
  else 
  {
    //如果不止一个元素,则只头删
    QNode* nextNode = q->front->next;
    free(q->front);
    q->front = nextNode;
  }

  q->size--;
}

// 获取头部元素
QDataType QueueFront(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  return q->front->data;
}

// 获取尾部元素
QDataType QueueBack(Queue* q)
{
  assert(q);  //确保q合法
  assert(!QueueEmpty(q)); //确保队列不为空

  return q->rear->data;
}

// 获取队列元素个数
int QueueSize(Queue* q)
{
  assert(q);  //确保q合法

  return q->size;
}

// 判断队列是否为空, 如果为空返回非0, 非空返回0
int QueueEmpty(Queue* q)
{
  assert(q);  //确保q合法

  if (q->size == 0)
  {
    return 1;
  }
  else 
  {
    return 0;
  }
}

// 销毁队列
void QueueDestroy(Queue* q)
{
  assert(q);

  while(!QueueEmpty(q))
  {
    QNode* nextNode = q->front->next;
    free(q->front);
    q->front = nextNode;
  }

  q->front = q->rear = NULL;
  q->size = 0;
}
/////////////////////////////////////////////////////////队列////////////////////////////////////////////////////

// 创建结点
BTNode* BuyNode(BTDataType x)
{
  BTNode* node = (BTNode*)malloc(sizeof(BTNode));
  if (node == NULL)
  {
    perror("malloc");
  }

  node->data = x;
  node->left = NULL;
  node->right = NULL;

  return node;
}

// 手动创建二叉树
BTNode* CreateBinaryTree()
{
  BTNode* node1 = BuyNode('A');
  BTNode* node2 = BuyNode('B');
  BTNode* node3 = BuyNode('C');
  BTNode* node4 = BuyNode('D');
  BTNode* node5 = BuyNode('E');
  BTNode* node6 = BuyNode('F');

  node1->left = node2;
  node1->right = node3;
  node2->left = node4;
  node3->left = node5;
  node3->right = node6;
  
  //验证是否是完全二叉树而添加的结点
  //node2->right = BuyNode('G');
  return node1;
}

// 二叉树前序遍历
void PreOrder(BTNode* root)
{
  // 如果是空结点, 直接返回
  if (root == NULL)
  {
    printf("NULL ");
    return;
  }

  // 根 左 右
  printf("%c ", root->data);  //访问根结点,就把该结点的值打印出来
  PreOrder(root->left);
  PreOrder(root->right);
}

// 二叉树中序遍历
void InOrder(BTNode* root)
{
  if (root == NULL)
  {
    printf("NULL ");
    return;
  }

  // 左 根 右
  InOrder(root->left);
  printf("%c ", root->data);
  InOrder(root->right);
}

// 二叉树后序遍历
void PostOrder(BTNode* root)
{
  if (root == NULL)
  {
    printf("NULL ");
    return;
  }

  // 左 右 根
  PostOrder(root->left);
  PostOrder(root->right);
  printf("%c ", root->data);
}

int BinaryTreeSize1(BTNode* root)
{
  static int count = 0;
  if (root == NULL)
    return count;

  count++;  //遇到非空结点就++
  BinaryTreeSize1(root->left);
  BinaryTreeSize1(root->right);
}

int BinaryTreeSize2(BTNode* root, int* p)
{
  if (root == NULL)
  {
    return 0;
  }

  (*p)++;
  BinaryTreeSize2(root->left, p);
  BinaryTreeSize2(root->right, p);
}
// 二叉树结点个数
int BinaryTreeSize(BTNode* root)
{
  if (root == NULL)
  {
    return 0;
  }
  else 
  {
    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
  }
}

// 二叉树叶子结点个数
int BinaryTreeLeafSize(BTNode* root)
{
  if (root == NULL)
  {
    return 0;
  }

  if (root->left == NULL && root->right == NULL)
  {
    return 1;
  }

  return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);  //既不是空结点也不是叶子结点
}

// 二叉树第k层结点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
  assert(k > 0);

  if (root == NULL)
  {
    return 0;
  }

  if (k == 1)
  {
    return 1;
  }

  return BinaryTreeLevelKSize(root->left, k-1) + BinaryTreeLevelKSize(root->right, k-1);
}

// 二叉树查找值为x的结点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
  if (root == NULL)
  {
    return NULL;
  }

  if (root->data == x)
  {
    return root;
  }
 
  BTNode* ret;
  ret = BinaryTreeFind(root->left, x);
  if (ret)
  {
    return ret;
  }

  ret = BinaryTreeFind(root->right, x);
  if (ret)
  {
    return ret;
  }

  return NULL;
}

// 层序遍历
void levelOrder(BTNode* root)
{
  // 创建队列
  Queue que;
  QueueInit(&que);

  // 将根结点放入队列后, 如果队列不为空,弹出队列元素同时入该结点的左右孩子, 不存空结点
  if (root)
  {
    QueuePush(&que, root);
  }

  while (!QueueEmpty(&que)) 
  {
    //出队头元素, 并打印
    BTNode* front = QueueFront(&que);
    printf("%c ", front->data);
    QueuePop(&que);

    //如果刚才的front有左右孩子, 将左右孩子入队列
    if (front->left)
    {
      QueuePush(&que, front->left);
    }

    if (front->right)
    {
      QueuePush(&que, front->right);
    }
  }

  //销毁队列
  QueueDestroy(&que);
}  

// 判断二叉树是否为完全二叉树
int BinaryTreeComplete(BTNode* root)
{
  // 创建队列用来存放层序遍历的二叉树的结果
  Queue que;
  QueueInit(&que);

  // 层序遍历二叉树, 同样将NULL也存放进去
  if (root)
  {
    QueuePush(&que, root);
  }

  while(!QueueEmpty(&que))
  {
    // 得到此时队头元素,并将该元素出队列
    // 如果队头元素为空,直接break
    BTNode* front = QueueFront(&que);
    if (front == NULL)
    {
      break;
    }
    QueuePop(&que);

    // 将队头元素的左右结点入队列,NULL结点也入队列
    QueuePush(&que, front->left);
    QueuePush(&que, front->right);
  }

  // 遍历此时队列中剩余元素,如果有非空元素则不为完全二叉树
  QNode* cur = que.front;
  while (cur != que.rear)
  {
    if (cur->data != NULL)
    {
      return 0;
    }
    cur = cur->next;
  }

  // 如果运行到这,说明该树是完全二叉树
  return 1;
}

int main(void)
{
  BTNode* BinaryTree = CreateBinaryTree();
  printf("先序遍历: ");
  PreOrder(BinaryTree);
  printf("\n");

  printf("中序遍历: ");
  InOrder(BinaryTree);
  printf("\n");

  printf("后序遍历: ");
  PostOrder(BinaryTree);
  printf("\n");
	
  printf("二叉树结点个数: %d\n", BinaryTreeSize(BinaryTree));

  printf("二叉树结点个数: %d\n", BinaryTreeSize1(BinaryTree));
  printf("二叉树结点个数: %d\n", BinaryTreeSize1(BinaryTree));
  int result = 0;
  BinaryTreeSize2(BinaryTree, &result);
  printf("%d\n", result);

  result = 0;
  BinaryTreeSize2(BinaryTree, &result);
  printf("%d\n", result);
  
  printf("二叉树叶子结点个数: %d\n", BinaryTreeLeafSize(BinaryTree));
  printf("二叉树第%d层的个数: %d\n", 1, BinaryTreeLevelKSize(BinaryTree, 1));
  printf("二叉树第%d层的个数: %d\n", 2, BinaryTreeLevelKSize(BinaryTree, 2));
  printf("二叉树第%d层的个数: %d\n", 3, BinaryTreeLevelKSize(BinaryTree, 3));

  if (BinaryTreeFind(BinaryTree, 'A'))
    printf("A\n");
  if (BinaryTreeFind(BinaryTree, 'T'))
    printf("T\n");

  printf("层序遍历: ");
  levelOrder(BinaryTree);
  printf("\n");

  if (BinaryTreeComplete(BinaryTree))
  {
    printf("是完全二叉树\n");
  }
  else 
  {
    printf("不是完全二叉树\n");
  }

  return 0;
}
