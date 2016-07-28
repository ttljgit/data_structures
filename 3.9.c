//����__����ʵ��
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Data;
	struct Node* Next;
}QNode; 
typedef struct{		//�����нṹ 
	QNode *rear;	//ָ���β��� 
	QNode *front;	//ָ���ͷ��� 
}LinkQueue;

//����__����ͷ������ʽ���� 
int DeleteQ(LinkQueue *PtrQ)
{
	QNode *FrontCell;
	int FrontElem;
	
	if(PtrQ->front == NULL){
		printf("Void Queue");
		return -1;
	}
	FrontCell = PtrQ->front;
	//������ֻ��һ��Ԫ�� 
	if(PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
} 
//���
void AddQ(QNode *x,LinkQueue *PtrQ)
{
	PtrQ->rear->Next = x;
	x->Next = PtrQ->rear;
} 
int main()
{
	return 0;
}
