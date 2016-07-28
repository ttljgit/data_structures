//例子：请用一个数组实现两个堆栈，
//要求最大地利用数组空间，
//使数组只要有空间入栈操作就可以成功。
#include <stdio.h>
 
#define MaxSize 100
struct DStack{
	int Data[MaxSize];
	int Top1;	//堆栈1的栈顶 
	int Top2;	//堆栈2的栈顶 
}S;

//进栈
//Tag用来区别两个栈顶的标志,1为堆栈1，2为堆栈2 
void Push(struct DStack *PtrS, int x, int Tag)
{
	if (PtrS->Top2 - PtrS->Top1 == 1)
		printf("Full Stack");
	if (Tag == 1)
		PtrS->Data[++(PtrS->Top1)] = x;
	else{
		PtrS->Data[--(PtrS->Top2)] = x;
	}
} 
//出栈
//需要验证栈是否为空
int Pop(struct DStack *PtrS, int Tag)
{
	if(Tag == 1){
		if(PtrS->Top1 == -1){
			printf("Full Stack_1");
			return -1;
		}
		else
			return PtrS->Data[(PtrS->Top1)--];
	}	
	else{
		if (PtrS->Top2 == MaxSize){
			printf("Full Stack_2");
			return -1;
		}
		else
			return PtrS->Data[(PtrS->Top2)++];
	}
} 
