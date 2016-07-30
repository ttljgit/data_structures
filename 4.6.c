//判断不同的序列是否是同一个二叉搜索树
#include <stdio.h>
#include <stdlib.h>
typedef struct TreeNode *Tree;
struct TreeNode{
	int v;
	Tree Left;
	Tree Right;
	int flag;
};

Tree Insert(Tree, int);
//建树的节点
Tree NewNode(int V)
{
	Tree T = malloc(sizeof(struct TreeNode));
	T->v = V;
	T->Left = T->Right = NULL;
	T->flag = 0;
	return T;
} 

//建树
Tree MakeTree(int N)
{
	Tree T;
	int i, V;
	
	scanf("%d",&V);
	T = NewNode(V);
	for(i=1; i<N; i++){
		scanf("%d",&V);
		T = Insert(T,V);
	}	
	return T;
}
 
//插入树的节点
Tree Insert(Tree T, int V)
{ 
	if(!T)
		T = NewNode(V);
	else{
		if(V > T->v)
			T->Right = Insert(T->Right, V);
		else
			T->Left = Insert(T->Right, V);	
	}		
	return T;
}
 
//判别__检查 
 int check(Tree T, int V)
 {
	if(T->flag){
		if(V < T->v)
			return check(T->Left, V);
		else if(V >T->v)
			return check(T->Right, V);
		else return 0;
	}
	else{
		if(V == T->v){
			T->flag = 1;
			return 1;
		}
		else return 0;
	}
 }
 
 //判别 
 int Judge(Tree T, int N)
 {
	int i, V, flag = 0;		//falg: 0代表目前还一致
	
	scanf("%d",&V); 
	if(V != T->v)
		flag = 1;
	else
		T->flag =1;
	for(i=1; i<N; i++){
		scanf("%d",&V);
		if(!flag && check(T, V))
			flag = 1;		
	}
	if(flag)
		return 0;
	else
		return 1;
 } 
 
 //清除T中各结点的flage标记
void ResetT(Tree T)
{
	if(T->Left)
		ResetT(T->Left);
	if(T->Right)
		ResetT(T->Right);
	T->flag = 0;		
} 
//释放T的空间
void FreeTree(Tree T)
{
	if(T->Left)
		FreeTree(T->Left);
	if(T->Right)
		FreeTree(T->Right);
	free(T);		
 } 
 
int main()
{
	int N, L, i;
	Tree T;	
	
	while(N){
		scanf("%d",&L);
		T = MakeTree(N);
		for(i=0; i<L; i++){
			if(Judge(T,N))
				printf("Yes\n");
			else
				printf("No\n");	
			ResetT(T);	//清除T中的标记flag	
		}
		FreeTree(T);
		scanf("%d",&N); 
	}
} 
