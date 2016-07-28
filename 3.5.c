//ջ__����ʵ�֣���ջ���� 
#include <stdio.h>
#include <stdlib.h>
struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
struct Node{
	int element;
	PtrToNode Next;
};
//�����Ƿ��ջ
int IsEmpty(Stack s)
{
	return s->Next == NULL;	
} 
//������ջ��ͷ���
Stack CreatStack()
{
	PtrToNode s;
	
	s = malloc(sizeof(struct Node));
	s->Next = NULL;
	return s;	
} 
//��ջ
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
//��ջ
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
//������ջ
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
