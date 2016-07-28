//一个可能更好的链表程序
#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
struct Node{
	int Element;
	Position Next;
}; 

//测试是否为空链表
int IsEmpty(List L)
{
	return L->Next == NULL;	
} 
//测试当前位置是否是链表末尾
int IsLast(Position p, List L) 
{
	return p->Next == NULL;
}
//查找
Position Find(int x, List L)
{
	Position p;
	p = L->Next;
	while (p != NULL && p->Element != x)
		p = p->Next;	
	return p;
} 
//查找前驱元（假设有头结点）
Position FindPrevious(int x, List L)
{
	Position p;
	p = L;
	while (p->Next != NULL && p->Next->Element != x)
		p = p->Next;
	return p;	
} 
//删除（假设有头结点） 
void Delete(int x, List L)
{
	Position p, tmp;
	p = FindPrevious(x, L);
	if(!IsLast(p, L)){
		tmp = p->Next;
		p->Next = tmp->Next;
		free(tmp);
	}
	else{
		free(p->Next);
	}
}
//删除表（假设有头结点） 
void DeleteList(List L)
{
	Position p, tmp;
	p = L->Next;
	L->Next = NULL;
	while (p != NULL){
		tmp = p->Next;
		free(p);
		p = tmp;
	}
}






