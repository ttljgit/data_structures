//二叉查找树
#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef int ElementType;
struct TreeNode{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
}; 

//建立空树
SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL){
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}	
	return NULL;
} 
//查找
Position Find(ElementType x, SearchTree T)
{
	if (T == NULL)
		return NULL;
	if (x < T->Element)
		return Find(x, T->Left);
	else if (x > T->Element)
		return Find(x, T->Right);
		//相等情况下 
		else
			return T;			
} 
//查找最小值：左叶结点（递归实现） 
//查找最大值：右叶结点（非递归实现） 
Position FindMin(SearchTree T)
{
	if (T == NULL)
		return NULL;
	else if(T->Left == NULL)
			return T;
		else
			return FindMin(T->Left);	
}
Position FindMax(SearchTree T)
{
	if (T != NULL){
		while (T->Right != NULL)
			T = T->Right;
	}
	return T;
	
}
//插入操作
SearchTree Insert(ElementType x, SearchTree T)
{
	if (T == NULL){
		//create and return a one-node tree
		T = malloc(sizeof(struct TreeNode));
		if(T == NULL){
			printf("Out of space!");
			return NULL;
		}
		else{
			T->Element = x;
			T->Left = T->Right = NULL;
		}
	}	
	else{
		if (x < T->Element)
			T->Left = Insert(x, T->Left);	//递归并插入左子树 
		else if (x > T->Element)
			T->Right = Insert(x ,T->Right);		//递归并插入右子树	
		//Else x is in the tree already, we'll do nothing	
	}
	return T;
} 
//删除操作
//用左子树中最大元素或右子树中最小元素代替该结点(其元素无儿子)
SearchTree Delete(ElementType x, SearchTree T)
{
	Position TmpCell;
	
	if (T == NULL){
		printf("Element not found");
		return NULL;
	}	
	else{
		if (x < T->Element)	//go left
			T->Left = Delete(x, T->Left);
		if (x > T->Element)	//go right
			T->Right = Delete(x, T->Right);
		else{	//Found element to be deleted
			if(T->Left && T->Right){		//Two children
				//Repalce with samllest in right subtree
				TmpCell = FindMin(T->Right);
				T->Element = TmpCell->Element;
				T->Right = Delete(T->Element, T->Right);
			}
			else{
				//one or zero children
				TmpCell = T;
				if (T->Left == NULL)	//also handles 0 children
					T = T->Right;
				else if (T->Right == NULL)
					T = T->Left;
				free(TmpCell);	
			}
		}
	}
	return T;
} 

int main()
{
	return 0;
}
