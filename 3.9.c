//队列__链表实现
#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
	int Data;
	struct Node* Next;
}QNode; 
typedef struct{		//链队列结构 
	QNode *rear;	//指向队尾结点 
	QNode *front;	//指向队头结点 
}LinkQueue;

//出队__不带头结点的链式队列 
int DeleteQ(LinkQueue *PtrQ)
{
	QNode *FrontCell;
	int FrontElem;
	
	if(PtrQ->front == NULL){
		printf("Void Queue");
		return -1;
	}
	FrontCell = PtrQ->front;
	//若队列只有一个元素 
	if(PtrQ->front == PtrQ->rear)
		PtrQ->front = PtrQ->rear = NULL;
	else
		PtrQ->front = PtrQ->front->Next;
	FrontElem = FrontCell->Data;
	free(FrontCell);
	return FrontElem;
} 
//入队
void AddQ(QNode *x,LinkQueue *PtrQ)
{
	PtrQ->rear->Next = x;
	x->Next = PtrQ->rear;
} 
int main()
{
	return 0;
}
