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
  // 将根结点放入数组后, 如果数组不为空,弹出数组元素同时入该结点的左右孩子, 不存空结点
  
  // 创建数组当作队列
  int capacity = BinaryTreeSize(root);
  BTNode* a = (BTNode*)malloc(sizeof(BTNode) * capacity);
  int size = 0;

  if (root)
  {
    a[size++] = root;
  }
}  
int main(void)
{
  BTNode* BinaryTree = CreateBinaryTree();
  PreOrder(BinaryTree);
  printf("\n");

  InOrder(BinaryTree);
  printf("\n");

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
  return 0;
}
