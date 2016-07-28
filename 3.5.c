//栈__链表实现（有栈顶） 
#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node{
	int element;
	PtrToNode Next;
};
//测试是否空栈
int IsEmpty(Stack s)
{
	return s->Next == NULL;	
} 
//创建堆栈的头结点
Stack CreatStack()
{
	PtrToNode s;
	
	s = malloc(sizeof(struct Node));
	s->Next = NULL;
	return s;	
} 
//进栈
void Push(int x, Stack s)
{
	PtrToNode tmp;
	
	tmp = malloc(sizeof(struct Node));
	if(tmp == NULL){
		printf("Can't create a stack");
	}
	else{
		tmp->element = x;
		tmp->Next = s->Next;
		s->Next = tmp;
	}
} 
//出栈
void Pop(Stack s)
{
	PtrToNode FirstCell;
	
	if(IsEmpty(s))
		printf("Empty stack");
	else{
		FirstCell = s->Next;
		s->Next = s->Next->Next;
		free(FirstCell);
	}	
}
//创建空栈
void MakeEmpty(Stack s)
{
	if (s == NULL){
		printf("Must use CreateStack first");
	}	
	else{
		while (!IsEmpty(s))
			Pop(s);
	}
} 
int main()
{
	return 0;
}
