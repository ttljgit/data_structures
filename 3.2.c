//Linked List with Head Node
#include <stdio.h>
#include <stdlib.h>
typedef struct LNode *PtrToNode;
struct LNode{
	int Data;
	PtrToNode Next;
};  
typedef PtrToNode Position;
typedef PtrToNode List;
#define ERROR NULL
//查找 
Position Find (List L, int X)
{
	Position p = L;		//P指向L的第一个结点
	while ( p && p->Data != X)
		p = p->Next;
	if (p)
		return p;
	else 
		return ERROR; 
	
}

//插入（有头结点, 这里默认有头结点）
int Insert(List L, int X, Position p)
{
	Position tmp, pre;
	//查找P的前一个结点 
	for (pre = L; pre && pre->Next != p; )
		pre = pre->Next; 
		if (pre == NULL){
			// P所指的结点不在L中 
			printf("uncorrect position");
			return -1;
		}
			//找到P的前一个结点pre,在p之前插入新结点 
		else{
			tmp = (Position)malloc(sizeof(struct LNode));
			tmp->Data = X;
			tmp->Next = p;
			pre->Next = tmp;
			return 1; 
		}
}
//删除（带有默认的头结点）
int Delete(List L, Position p)
{
	Position tmp, pre;
	for (pre = L; pre && pre->Next != p;)
		pre = pre->Next;
	if (pre == NULL || p == NULL){
		printf("uncorrect position");
		return -1;
	}
	else{
		pre->Next = p->Next;
		free(p);
		return 1;
	}	
} 
int main()
{
	return 0;
}
