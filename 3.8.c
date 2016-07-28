//队列__数组实现（循环数组） 
 
 #include <stdio.h>
 #include <stdlib.h>
 #define MaxSize 10
 typedef struct {
	int Data[MaxSize];
	int rear;
	int front;
 }Queue;

//入队 front和rear移动采用加1取余法，体现了顺序存储的循环体现
void AddQ(Queue *PtrQ, int x)
{
	if((PtrQ->rear+1) % MaxSize == PtrQ->front)
		printf("Full Queue");
	else
		PtrQ->rear = (PtrQ->rear+1) % MaxSize;
	PtrQ->Data[PtrQ->rear] = x;	
}
//出队
int DeleteQ(Queue *PtrQ)
{
	//这里验证条件有待改进
	//可以设置Size来看是空队列还是满队列 
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
