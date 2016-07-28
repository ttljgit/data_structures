//һ�����ܸ��õ��������
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

//�����Ƿ�Ϊ������
int IsEmpty(List L)
{
	return L->Next == NULL;	
} 
//���Ե�ǰλ���Ƿ�������ĩβ
int IsLast(Position p, List L) 
{
	return p->Next == NULL;
}
//����
Position Find(int x, List L)
{
	Position p;
	p = L->Next;
	while (p != NULL && p->Element != x)
		p = p->Next;	
	return p;
} 
//����ǰ��Ԫ��������ͷ��㣩
Position FindPrevious(int x, List L)
{
	Position p;
	p = L;
	while (p->Next != NULL && p->Next->Element != x)
		p = p->Next;
	return p;	
} 
//ɾ����������ͷ��㣩 
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
//ɾ����������ͷ��㣩 
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






