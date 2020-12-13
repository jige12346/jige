#ifndef _MAIN_
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct BTNode{
	int data;
	struct BTNode *lchild;
	struct BTNode *rchild;
}BiTNode,*BiTree;
//函数声明
void CreateBiTree(BiTNode **T);
void PreOrderBitree(BiTNode *T);
void MiddleOrderBitree(BiTNode *T);
void PostOrderBitree(BiTNode *T);
int TreeDeep(BiTNode *T);
int LeafCount(BiTNode *T);
#endif
