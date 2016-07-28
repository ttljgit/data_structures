//结构数组表示二叉树：静态链表
//判断二叉树是否同构
#include <stdio.h>
 
#define MaxTree 10
#define ElementType char
#define Tree int 
#define Null -1
 
struct TreeNode{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

//建立二叉树
Tree BuildTree(struct TreeNode T[]) 
{
	int i, N;
	Tree Root;
	char cl, cr;
	
	scanf("%d\n",&N);
	if(N){
		int check[N];
		//为了判别Root（若有人指向结点，则令其为1） 
		for(i=0; i<N; i++)
			check[i] = 0;
		//输入结构数组 
		for(i=0; i<N; i++){
			scanf("%c%c%c\n",&T[i].Element,&cl,&cr);
			//处理左子树 
			if(cl!='-'){
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;
			//右子树 
			if(cr!='-'){
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}
		//当没有谁指向该结点，其为根结点 
		for(i=0; i<N; i++){
			if(!check[i])
				break;
		}
		Root = i;
	}
	return Root;
}
//判别两二叉树同构
int Isomorphic(Tree R1, Tree R2)
{
	if (R1==Null && R2==Null)		// both empty
		return 1;	
	if ((R1==Null && R2!=Null) || (R1!=Null && R2==Null))	//one of them is empty
		return 0;
	if (T1[R1].Element != T2[R2].Element)	//roots are different
		return 0;
	if (T1[R1].Left==Null && T2[R2].Left==Null)		//both have no left subtree
		return Isomorphic(T1[R1].Right, T2[R2].Right);
	if (T1[R1].Right==Null && T2[R2].Right==Null)		//both have no right subtree
		return Isomorphic(T1[R1].Left, T2[R2].Left);
	if ((T1[R1].Left!=Null && T2[R2].Left!=Null) && (T1[T1[R1].Left].Element == T2[T2[R2].Left].Element))
		// no need to swap the left and the right
		return (Isomorphic(T1[R1].Left,T2[R2].Left) && Isomorphic(T1[R1].Right, T2[R2].Right));
	else
		// need to swap the left and the right
		return (Isomorphic(T1[R1].Left, T2[R2].Right) && Isomorphic(T1[R1].Right, T2[R2].Left));						
} 	


int main()
{
	Tree R1, R2;
	R1 = BuildTree(T1);
	R2 = BuildTree(T2);
	if(Isomorphic(R1, R2))
		printf("Yes\n");
	else
		printf("No\n");
		
	return 0;	
} 

