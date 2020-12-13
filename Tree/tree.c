#include "tree.h"
//先序遍历
void CreateBiTree(BiTNode **T){//指针的指针
	int ch;
	scanf("%d",&ch);
	if(ch==-1){
		*T=NULL;//叶子结点
		return;
	}else{
		*T=(BiTNode*)malloc(sizeof(BiTNode));
		if(*T==NULL){
			printf("内存分配失败!\n");
			exit(-1);
		}else{
			(*T)->data=ch;
			printf("输入%d的左子节点",ch);
			CreateBiTree(&((*T)->lchild));
			printf("输入%d的右子节点",ch);
			CreateBiTree(&((*T)->rchild));
		}

	}
}
//先序遍历二叉树
void PreOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		printf("%d",T->data);
		PreOrderBitree(T->lchild);
		PreOrderBitree(T->rchild);
	}
}
//中序遍历
void MiddleOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		MiddleOrderBitree(T->lchild);
		printf("%d",T->data);
		MiddleOrderBitree(T->rchild);
	}
	
}
//后续遍历
void PostOrderBitree(BiTNode *T){
	if(T==NULL){
		return;
	}else{
		PostOrderBitree(T->lchild);
		PostOrderBitree(T->rchild);
		printf("%d",T->data);
	}
}
//二叉树的深度
int TreeDeep(BiTNode *T){
	int deep=0;
	if(T==NULL){
		return deep;
	}else{
		int leftdeep=TreeDeep(T->lchild);
		int rightdeep=TreeDeep(T->rchild);
		deep=leftdeep>=rightdeep?leftdeep+1:rightdeep+1;
		return deep;
	}
}
//叶子结点个数
int LeafCount(BiTNode *T)
{
	static int count;
	if(T!=NULL){
		if(T->lchild==NULL&&T->rchild==NULL)
		{
			count++;
		}
		LeafCount(T->lchild);
		LeafCount(T->rchild);
	}
	return count;
}
