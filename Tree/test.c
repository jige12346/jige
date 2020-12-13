#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int main(int argc,const char *argv[]){
	BiTNode *T;
	int j;
	int depth,leafCount=0;
	printf("请输入第一个节点的值，-1表示没有叶节点：\n");
	CreateBiTree(&T);
	printf("先序遍历二叉树：");
	PreOrderBitree(T);
	printf("中序遍历二叉树：");
	printf("\n");
    MiddleOrderBitree(T);
	printf("\n");
	printf("后序遍历二叉树：");
	PostOrderBitree(T);
	printf("\n");
	depth=TreeDeep(T);
	printf("树的深度为：%d\n",depth);
	leafCount=LeafCount(T);
	printf("叶子结点个数为:%d\n",leafCount);
	scanf("%d",&j);
	return 0;
}
