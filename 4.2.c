//���ı���

typedef struct TreeNode *BinTree;
typedef BinTree Position;
struct TreeNode{
	ElementType Data;
	BinTree Left;
	BinTree Rgiht;
};

//1.�������
void PreOrederTraversal(BinTree BT)
{
	if(BT){
		printf("%d",BT->Data);
		PreOrderTraversal(BT->Left);
		PreOrderTraversal(BT->Right);
	}	
} 

//2.�������
void InOrderTraversal(BinTree BT)
{
	if(BT){
		InOrderTraversal(BT->Left);
		printf("%d",BT->Data);
		InOrderTraversal(BT->Rgiht);
	}	
} 

//3.�������
void PostOrderTraversal(BinTree BT)
{
	if(BT){
		PostOrderTraversal(BT->Left);
		PostOrderTraversal(BT->Rgiht);
		printf("%d",BT->Data);
	}
}

//4.��������ǵݹ��㷨����ջ��
//����һ����㣬�Ͱ���ѹջ����ȥ����������������
//�����������������󣬴�ջ�����������㲢��������
//Ȼ������ָ����ȥ��������ý�����������
void InOrderTraversal(BinTree BT)
{
	BinTree T = BT;
	Stack S = CreatStack(MaxSize);	 //��������ʼ����ջ S
	while (T || !IsEmpty(S)){
		//һֱ���󲢽���;���ѹ���ջ 
		while(T){
			Push(S,T);
			T = T->Left;	
		}
		if(!IsEmpty(S)){
			T = Pop(S);		//��㵯����ջ
			printf("%d",T->Data);
			T = T->Rgiht;	//ת�������� 
		}
	} 
} 

//5.�������������ʵ�֣� 
//�Ӷ�����ȡ��һ��Ԫ�أ�
//���ʸ�Ԫ�ص���ָ��㣻
//����Ԫ����ָ�������ҽ��ǿգ��������Һ��ӵ�ָ��˳����ӡ�
void LevelOrderTraversal(BinTree BT)
{
	Queue Q;
	BinTree T;
	//����Ƿ���� 
	if(!BT)
		return ; 	
	Q = CreatQueue(MaxSize);	//��������ʼ������ Q
	Add(Q,BT);
	while (!IsEmptyQ(Q)){
		T = DeleteQ(Q);
		printf("%d\n",T->Data);		//����ȡ�����еĽ�� 
		if(T->Left)
			Add(Q,T->Left);
		if(T->Rgiht)
			Add(Q,T->Rgiht);	
	} 
} 

//6.����������е�Ҷ�ӽ��
void PreOrderPrintLeaves(BinTree BT)
{
	if(BT){
		if(!BT->Left && !BT->Rgiht)
			printf("%d",BT->Data);
		PreOrderPrintLeaves(BT->Left);
		PreOrderPrintLeaves(BT->Rgiht);	
	}
} 

