//����__����ʵ�֣�ѭ�����飩 
 
 #include <stdio.h>
 #include <stdlib.h>
 #define MaxSize 10
 typedef struct {
	int Data[MaxSize];
	int rear;
	int front;
 }Queue;

//��� front��rear�ƶ����ü�1ȡ�෨��������˳��洢��ѭ������
void AddQ(Queue *PtrQ, int x)
{
	if((PtrQ->rear+1) % MaxSize == PtrQ->front)
		printf("Full Queue");
	else
		PtrQ->rear = (PtrQ->rear+1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = x;	
}
//����
int DeleteQ(Queue *PtrQ)
{
	//������֤�����д��Ľ�
	//��������Size�����ǿն��л��������� 
	if(PtrQ->front == PtrQ->rear){
		printf("Empty Queue");
		return -1;
	}
	else{
		PtrQ->front = (PtrQ->front+1) % MaxSize;
		return PtrQ->Data[PtrQ->front];
	}
} 
int main()
{
	return 0;
}
