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

//��ʼ��
List MakeEmpty()
{
	List L;
	L = (List)malloc(sizeof(struct LNode));
	L->Last = -1;	
	return L;
} 
//���Ҹ���L�е�Ԫ�� 
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
//���� ��L��ָ��λ��Pǰ����һ����Ԫ��X 
int Insert(List L, int X, Position P)
{
	Position i;
	//�жϱ�L�ܷ���� 
	if(L->Last == MAXSIZE-1){
		printf("overflow");
		return ERROR;
	}
	//�жϲ�����Ƿ�������Χ�� 
	if(P < 0 || P > L->Last+1){
		printf("uncorrect position");
		return ERROR;
	}
	for (i = L->Last; i >= P; i--)
		L->Data[i+1] = L->Data[i];		//������λ��P֮��Ԫ������ƶ� 
	L->Data[P] = X;		//��Ԫ�ز��� 
	L->Last++;		//Last����+1 
	return P;
} 
//ɾ��
int Delete(List L, Position P)
{
	Position i;
	//�жϲ�����Ƿ�������Χ�� 
	if(P < 0 || P > L->Last){
		printf("uncorrect position in %d",P);
		return ERROR;
	}
	for (i = P+1; i < L->Last; i++)
		L->Data[i-1] = L->Data[i];		//��λ��P+1֮���Ԫ����ǰ�ƶ� 
	L->Last--;
	free(L);		
	return P;
} 

