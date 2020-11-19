#include <stdio.h>
#include <stdlib.h>
#define n 11
#define m 3
typedef int Datatype;
typedef struct node_{
	Datatype data;
	struct node_*next;
}Node;

typedef struct List_{
	Node*head;
	Node*tail;
	Node*current;
}List;
void InitList(List*);
int Isempty(List*);
Node* Get(List*,int);
void addhead(List*,Datatype);
void addtail(List*,Datatype);
void Insert(List*,int,Datatype);
Datatype Delete(List*,int);
void Display(List*);
void Clear(List*);


void InitList(List*list)
{
	list->head = NULL;
	list->tail = NULL;
	list->tail = NULL;
	list->current = NULL;
}
int Isempty(List*list)
{
	if(list->head == NULL&&list->tail ==NULL)
		return 1;
	else{
		return 0;}
}
Node* Get(List*list,int i)
{
	if(Isempty(list)&&i<=0)
		exit(1);
	int x = 1;
	Node*node;
	node = list->head;
	if(i == 1);
	return node;
	while(x<i)
	{
		x++;
		node = node->next;
	}
	return node;
}
void Insert(List*list,int i,Datatype x)
{
	if(Isempty(list)&&i>0)
		exit(1);
	if(i<1) exit(1);
	Node *node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	if(i==1)
	{node->next = list->head;
		list = NULL;
	}
	if(i>1)
	{
		Node*prev = Get(list,i-1);
		node->next = prev->next;
		prev->next = node;
	}
}
Datatype Delete(List*list,int i)                      //删除链表的第i的元素
{
	int x;;
	if(Isempty(list))
		exit(1);
	if(i==1)
		list->head = list->head->next;
	else{
		Node*node = Get(list,i-1);
		x = node->next->data;
		node->next = node->next->next;
		return x;}
}
void Clear(List*list)                               //清空链表
{
	Node *p,*q;
	p = list->head;
	while (p){
		q = p;
		p = p->next;
		free (q);
	}
	list->head = NULL;
}
void Display(List*list)                           //打印这个链表
{
	Node*node;
	node = list->head;
	int num = 1;
	if(Isempty(list))
		printf("该链表为空！");
	while(node!=NULL)
	{
		printf("第%d个元素是%d\n",num,node->data);
		num++;
		node = node->next;
	}
}
void addhead(List*list,Datatype x)              
{
	Node*node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	if(Isempty(list))
	{list->tail = node;
		list->head = node;}
	else{
		node->next = list->head;
		list->head = node;}
}
void addtail(List*list,Datatype x)            
{
	Node*node = (Node*)malloc(sizeof(Node));
	node->data = x;
	node->next = NULL;
	if(Isempty(list))
	{list->tail = node;
		list->head = node;}
	else{
		list->tail->next = node;
		list->tail = node;}
}
int main(){
{
	List *list = (List*)malloc(sizeof(List));
	InitList(list);                       
	addhead(list,1);
	addtail(list,3);
	Insert(list,2,2);
//	Clear(list);
	Display(list);
	return 0;
}

	int k = 0;
	Node *p,*q,*r;
	p = q = (Node*)malloc(sizeof(Node));   //创建第一个节点
	p -> data = 1;
	for (int i=2; i<=n; i++) {             //建立链表
		r = (Node*)malloc(sizeof(Node));
		r->data = i;
		q->next = r;
		q = r;
	}
	q -> next = p;

	q = p;
	while (q->next != q) {
		k++;
		if (k == m) {
			p->next = q->next;
			free(q);
			q = p->next;
			k = 0;
		} else {
			p = q;
			q = q->next;
		}
	}
	printf("最后一个获胜者的编号是：%d\n", q->data);
	}
