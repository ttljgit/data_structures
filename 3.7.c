//���ӣ�����һ������ʵ��������ջ��
//Ҫ��������������ռ䣬
//ʹ����ֻҪ�пռ���ջ�����Ϳ��Գɹ���
#include <stdio.h>
 
#define MaxSize 100
struct DStack{
	int Data[MaxSize];
	int Top1;	//��ջ1��ջ�� 
	int Top2;	//��ջ2��ջ�� 
}S;

//��ջ
//Tag������������ջ���ı�־,1Ϊ��ջ1��2Ϊ��ջ2 
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
//��ջ
//��Ҫ��֤ջ�Ƿ�Ϊ��
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
