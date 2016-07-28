// Linked List
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 20
#define ERROR -1
typedef int Position;
struct LNode{
	int Data[MAXSIZE];
	Position Last;
};
typedef struct LNode *List;

//初始化
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;	
	return L;
} 
//查找给定L中的元素 
Position Find(List L, int X)
{
	Position i = 0;
	while (i <= L->Last && L->Data[i] != X)
		i++;
	if(i > L->Last)
		return ERROR;
	else
		return i;			
} 
//插入 在L的指定位置P前插入一个新元素X 
int Insert(List L, int X, Position P)
{
	Position i;
	//判断表L能否插入 
	if(L->Last == MAXSIZE-1){
		printf("overflow");
		return ERROR;
	}
	//判断插入点是否在链表范围内 
	if(P < 0 || P > L->Last+1){
		printf("uncorrect position");
		return ERROR;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i];		//将表中位置P之后元素向后移动 
	L->Data[P] = X;		//新元素插入 
	L->Last++;		//Last长度+1 
	return P;
} 
//删除
int Delete(List L, Position P)
{
	Position i;
	//判断插入点是否在链表范围内 
	if(P < 0 || P > L->Last){
		printf("uncorrect position in %d",P);
		return ERROR;
	}
	for (i = P+1; i < L->Last; i++)
		L->Data[i-1] = L->Data[i];		//将位置P+1之后的元素往前移动 
	L->Last--;
	free(L);		
	return P;
} 

