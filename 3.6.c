//栈__数组实现（有栈顶）
 
#include <stdio.h>
#include <stdlib.h>
#define MaxSize 10
typedef struct{
	int Data[MaxSize];
	int Top;
} Stack;

//进栈
void Push(Stack *PtrS, int x)
{
	if(PtrS->Top == MaxSize-1){
		printf("Stack overflow");
	}
	else{
		PtrS->Data[++(PtrS->Top)] = x;
	}
}
//出栈
int Pop(Stack *PtrS) 
{
	if(PtrS->Top == -1){
		printf("Void Stack");
		return -1;
	}
	else{
		return PtrS->Data[(PtrS->Top)--];
	}
}
