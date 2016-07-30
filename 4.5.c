//AVL树
#include <stdio.h>
#include <stdlib.h>

struct AvlNode;
typedef struct AvlNode *Position;
typedef struct AvlNode *AvlTree;
typedef ElementType int;
struct AvlNode{
	ElementType Element;
	AvlTree Left;
	AvlTree Right;
	int Height;
}; 

//计算Avl节点的高度
static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height; 		
} 

//向Avl树插入节点
AVlTree Insert(ElementType X, AvlTree T)
{
	//Create and return a one-node tree
	if (T == NULL){
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
			printf("Out of space!");
		else{
			T->Element = X;
			T->Height = 0;
			T->Left = T->Right = NULL;
		}	
	}
	else if (X < T->Element){
		T->Left = Insert(X,T->Right);
		if(Height(T->Left) - Height(T->Right) == 2){
			if (X < T->Left->Element)
				T = SingleRotateWithLeft(T);
			else 
				T = DoubleRotateWithLeft(T);	
		}
	}
	else if(X > T->Element){
		T->	Right = Insert(X, T->Right);
		if(Height(T->Right) - Height(T->Left) == 2){
			if(X > T->Right->Element)
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);	
		}
	}
	//Else X is in the tree already, we will do nothing
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
} 
//单旋转情况一 
static Position SingleRotateWithLeft(Position K2)
{
	Position K1;
	//书本P89参照例图 
	K1 = K2->Left;
	K2->Left = K1->Right;
	K1->Right = K2;
	
	K2->Height = Max(Height(K2->Left), Height(K2->Right)) + 1;
	K1->Left = Max(Height(K1->Left), Height(K1->Right))	+ 1;
	return K1;
}
//双旋转情况一
static Position DoubleRotateWithLeft(Position K3)
{
	//参照书本P89 
	K3->Left = SingleRotateWithRight(K3->Left);
	return	SingleRotateWithLeft(K3);
} 
