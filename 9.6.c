//邻接表存储 Kruskal最小生成树算法

//顶点并查集定义
typedef Vertex ElementType;	//默认元素可以用非负整数表示 
typedef SetName;	//默认用根结点的下标作为集合名称 
typedef ElementType SetType[MaxVertexNum]; 	//假设集合元素下标从0开始

void InitializeVSet(SetType S, int N)
{
	ElementType X;
	
	for(X = 0; X < N; X++)
		S[X] = -1;
} 

//这里默认Root1和Root2是不同集合的根结点 
void Union(SetType S, SetName Root1, SetName Root2)
{
	//保证小集合并入大集合 
	if(S[Root1] < S[Root2]){
		S[Root2] += S[Root1];
		S[Root1] = Root2;
	}
	else{
		S[Root1] += S[Root2];
		S[Root2] = Root1;
	}
}

//检查连接V1和V2的边是否在现有的最小生成树子集中构成的回路 
bool CheckCycly(SetType VSet, Vertex V1, Vertex V2)
{
	Vertex Root1, Root2;
	
	//得到连通集的名称 
	Root1 = Find(VSet, V1);
	Root2 = Find(VSet, V2);
	
	//若已经连通，则不能要，否则该边可以被收集 
	if(Root1 == Root2)
		return false;
	else{
		Union(VSet, Root1, Root2);
		return true;
	}	
}

//边的最小堆定义
void PerDown(Edge ESet, int p, int N)
{
	int Parent, Child;
	struct ENode X;
	
	X = ESet[p];	//取出根结点存放的值
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

//将图的边存入数组ESet，并且初始化为最小堆
void InitializeESet(LGraph Graph, Edge ESet)
{
	Vertex V;
	PtrToAdjVNode W;
	int ECount;
	
	//将图的边存入数组ESet
	ECount = 0;
	for(V = 0; V < Graph->Nv V++)
		for (W = Graph->G[V].FirstEdge; W; W= W->Next)
			//避免重复录入无向图的边。 只收V1 < V2的边 
			if(V < W->AdjV){
				ESet[ECount].V1 = V;
				ESet[ECount].V2 = W->AdjV;
				ESet[ECount++].Weight = W->Weight;
			}		
	//初始化为最小堆
	for (ECount = Graph->Ne/2; ECount >= 0; ECount--)
		PercDown(ESet, ECount, Graph->Ne);		 
} 

//给定当前堆的大小CurrentSize，将当前最小边位置弹出并调整堆 
int GetEdge(Edge ESet, int CurrentSize)
{
	//将嘴笑边与当前对的最后一个位置的边交换 
	Swap(&ESet[0], &ESet[CurrentSize-1]);
	//将剩下的边继续调整成最小堆
	PercDown(ESet, 0, CurrentSize-1);
	
	return CurrentSize-1; 
}

//将最小生成树保存为邻接表存储的图MST， 返回最小权重和 
int Kruskal(LGraph Graph, LGraph MST)
{
	WeightType TotalWeight;
	int ECount, NextEdge;
	SetType VSet;
	Edge ESet;
	
	InitializeVSet(VSet, Graph->Nv);	//初始化顶点并查集
	while (ECount < Graph->Nv-1){
		NextEdge = GetEdge(ESet, NextEdge);
		if (NextEdge < 0)
			break;
		//如果该边的加入不构成回路， 即两端结点不属于同一连通集
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
