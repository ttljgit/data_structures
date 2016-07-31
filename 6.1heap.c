//Priority Queue
#include <stdio.h>
#include <stdlib.h>
#define MinData -1

struct HeapStruct;
typedef struct HeapStruct * PriorityQueue;
typedef int ElementType;
struct HeapStruct{
	int Capacity;
	int Size;
	ElementType *Elements;
}; 

//优先队列的声明
PriorityQueue Initialize(int MaxElements)
{
	PriorityQueue H;
	
	H = malloc(sizeof(struct HeapStruct));
	if(H == NULL){
		printf("Out of Space!");
		return ;
	}
	//Allocate the array plus one extra for sentinel
	H->Elements = malloc((MaxElements+1) * sizeof(ElementType));
	if(H->Elements == NULL){
		printf("Out of Sapce!");
	}
	H->Capacity = MaxElements;
	H->Size = 0;
	H->Elements[0] = MinData;
	
	return H;;
} 

//检查队列是否满 
int IsFull(PriorityQueue H)
{
	return H->Size == H->Capacity;
}

//插入操作
//H->Elements[0] is a sentinel
void Insert(ElementType X, PriorityQueue H)
{
	int i;
	
	if(IsFull(H)){
		printf("Priority queue is full");
		return;
	}
	for (i = ++H->Size; H->Elements[i/2] > X; i/=2){
		H->Elements[i] = H->Elements[i/2];
	}	
	H->Elements[i] = X;
} 

//检查队列是否为空
int IsEmpty(PriorityQueue H)
{
	return H->Elements[1];
} 

//删除操作
ElementType DeleteMin(PriorityQueue H)
{
	int i, Child;
	ElementType MinElement, LastElement;
	
	if(IsEmpty(H)){
		printf("Priority queue is empty");
		return H->Elements[0];
	}
	MinElement = H->Elements[1];
	LastElement = H->Elements[H->Size--];
	
	for(i = 1; i * 2 <= H->Size; i = Child){
		//Find smaller child
		Child = i * 2;
		if (Child != H->Size && H->Elements[Child+1] < H->Elements[Child])
			Child++;
		//Percolate one level
		if(LastElement > H->Elements[Child])
			H->Elements[i] = H->Elements[Child];	
		else
			break;				
	}
	H->Elements[i] = LastElement;
	return MinElement;		
} 
