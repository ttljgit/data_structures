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
//���� 
Position Find (List L, int X)
{
	Position p = L;		//Pָ��L�ĵ�һ�����
	while ( p && p->Data != X)
		p = p->Next;
	if (p)
		return p;
	else 
		return ERROR; 
	
}

//���루��ͷ���, ����Ĭ����ͷ��㣩
int Insert(List L, int X, Position p)
{
	Position tmp, pre;
	//����P��ǰһ����� 
	for (pre = L; pre && pre->Next != p; )
		pre = pre->Next; 
		if (pre == NULL){
			// P��ָ�Ľ�㲻��L�� 
			printf("uncorrect position");
			return -1;
		}
			//�ҵ�P��ǰһ�����pre,��p֮ǰ�����½�� 
		else{
			tmp = (Position)malloc(sizeof(struct LNode));
			tmp->Data = X;
			tmp->Next = p;
			pre->Next = tmp;
			return 1; 
		}
}
//ɾ��������Ĭ�ϵ�ͷ��㣩
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
