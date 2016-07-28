//树的遍历

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Rgiht;
};

//1.先序遍历
void PreOrederTraversal(BinTree BT)
{
	if(BT){
		printf("%d",BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}	
} 

//2.中序遍历
void InOrderTraversal(BinTree BT)
{
	if(BT){
		InOrderTraversal(BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal(BT->Rgiht);
	}	
} 

//3.后序遍历
void PostOrderTraversal(BinTree BT)
{
	if(BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Rgiht);
		printf("%d",BT->Data);
	}
}

//4.中序遍历非递归算法（堆栈）
//遇到一个结点，就把它压栈，并去遍历它的左子树；
//当左子树遍历结束后，从栈顶弹出这个结点并访问它；
//然后按其右指针再去中序遍历该结点的右子树。
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);	 //创建并初始化堆栈 S
	while (T || !IsEmpty(S)){
		//一直向左并将沿途结点压入堆栈 
		while(T){
			Push(S,T);
			T = T->Left;	
		}
		if(!IsEmpty(S)){
			T = Pop(S);		//结点弹出堆栈
			printf("%d",T->Data);
			T = T->Rgiht;	//转向右子树 
		}
	} 
} 

//5.层序遍历（队列实现） 
//从队列中取出一个元素；
//访问该元素的所指结点；
//若该元素所指结点的左、右结点非空，则将其左、右孩子的指针顺序入队。
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	//检测是否空树 
	if(!BT)
		return ; 	
	Q = CreatQueue(MaxSize);	//创建并初始化队列 Q
	Add(Q,BT);
	while (!IsEmptyQ(Q)){
		T = DeleteQ(Q);
		printf("%d\n",T->Data);		//访问取出队列的结点 
		if(T->Left)
			Add(Q,T->Left);
		if(T->Rgiht)
			Add(Q,T->Rgiht);	
	} 
} 

//6.输出二叉树中的叶子结点
void PreOrderPrintLeaves(BinTree BT)
{
	if(BT){
		if(!BT->Left && !BT->Rgiht)
			printf("%d",BT->Data);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Rgiht);	
	}
} 

