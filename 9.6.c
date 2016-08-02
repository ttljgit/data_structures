//�ڽӱ�洢 Kruskal��С�������㷨

//���㲢�鼯����
typedef Vertex ElementType;	//Ĭ��Ԫ�ؿ����÷Ǹ�������ʾ 
typedef SetName;	//Ĭ���ø������±���Ϊ�������� 
typedef ElementType SetType[MaxVertexNum]; 	//���輯��Ԫ���±��0��ʼ

void InitializeVSet(SetType S, int N)
{
	ElementType X;
	
	for(X = 0; X < N; X++)
		S[X] = -1;
} 

//����Ĭ��Root1��Root2�ǲ�ͬ���ϵĸ���� 
void Union(SetType S, SetName Root1, SetName Root2)
{
	//��֤С���ϲ���󼯺� 
	if(S[Root1] < S[Root2]){
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

//�������V1��V2�ı��Ƿ������е���С�������Ӽ��й��ɵĻ�· 
bool CheckCycly(SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;
	
	//�õ���ͨ�������� 
	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);
	
	//���Ѿ���ͨ������Ҫ������ñ߿��Ա��ռ� 
	if(Root1 == Root2)
		return false;
	else{
		Union(VSet, Root1, Root2);
		return true;
	}	
}

//�ߵ���С�Ѷ���
void PerDown(Edge ESet, int p, int N)
{
	int Parent, Child;
	struct ENode X;
	
	X = ESet[p];	//ȡ��������ŵ�ֵ
	for (Parent = p; (Parent*2 +1) < N; Parent = Child){
		Child = Parent * 2 + 1;
		if ((Child != N-1) && (ESet[Child].Weight > ESet[Child+1].Weight))
			Child++;
		if(X.Weight <= ESet[Child].Weight)
			break;	
		else
			Eset[Parent] = Eset[Child];
	} 	
	ESet[Parent]  = X;
} 

//��ͼ�ıߴ�������ESet�����ҳ�ʼ��Ϊ��С��
void InitializeESet(LGraph Graph, Edge ESet)
{
	Vertex V;
	PtrToAdjVNode W;
	int ECount;
	
	//��ͼ�ıߴ�������ESet
	ECount = 0;
	for(V = 0; V < Graph->Nv V++)
		for (W = Graph->G[V].FirstEdge; W; W= W->Next)
			//�����ظ�¼������ͼ�ıߡ� ֻ��V1 < V2�ı� 
			if(V < W->AdjV){
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}		
	//��ʼ��Ϊ��С��
	for (ECount = Graph->Ne/2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);		 
} 

//������ǰ�ѵĴ�СCurrentSize������ǰ��С��λ�õ����������� 
int GetEdge(Edge ESet, int CurrentSize)
{
	//����Ц���뵱ǰ�Ե����һ��λ�õı߽��� 
	Swap(&ESet[0], &ESet[CurrentSize-1]);
	//��ʣ�µı߼�����������С��
	PercDown(ESet, 0, CurrentSize-1);
	
	return CurrentSize-1; 
}

//����С����������Ϊ�ڽӱ�洢��ͼMST�� ������СȨ�غ� 
int Kruskal(LGraph Graph, LGraph MST)
{
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;
	Edge ESet;
	
	InitializeVSet(VSet, Graph->Nv);	//��ʼ�����㲢�鼯
	while (ECount < Graph->Nv-1){
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge < 0)
			break;
		//����ñߵļ��벻���ɻ�·�� �����˽�㲻����ͬһ��ͨ��
		if(CheckCycly(VSet, ESet[NextEdge].V1, Eset[NextEdge].V2) == true){
			InsertEdge(MStT, ESet+NextEdge);
			TotalWeight += ESet[NextEdge].Weight;
			ECount++;
		} 
	}
	if(ECount < Graph->Nv-1)
		TotalWeight = -1;
	return TotalWeight;	
}
