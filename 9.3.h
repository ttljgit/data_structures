//图的邻接链表表示法
#define MaxVertex Num 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

//边的定义
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	WeightType Weight;
}; 
typedef PtrToENode Edge;

//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
}; 

//顶点 表头结点的定义
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;	//边表头指针
	DataType Data;		//存顶点的数据
	//注意： 很多情况下，顶点无数据，此时的data可以不用出现 
}AdjList[MaxVertexNum]; 

//图结点的定义 
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;	//以邻接表方式存储的图类型

//初始化一个有VertexNum个顶点但是没有边的图 
LGraph CreateGraph(int VertexNum) 
{
	Vertex V;
	LGraph Graph;
	
	Graph = (LGraph)mollac(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//初始化邻接表头指针
	//注意：这里默认顶点编号从0开始，到Graph->Nv - 1
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	
	return Graph;	 
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	
	//插入边<V1, V2> 为V2建立新的邻接点
	NewNode = (PtrToAdjVNode)mollc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//将V2插入V1的表头
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode; 
	
	///若是无向图，还要插入边<V2, v1>
	//为V1建立新的邻接点	
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	//将V1插入V2的表头
	NewNode->Next = Graph->G[E->V2].FirstEdge;'
	Graph->G[E->V2].FirstEdge = NewNode; 
}

LGraph BuildGraph()
{
	LGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d", &Nv);
	Graph = CreateGraph(Nv);
	
	scanf("%d",&(Graph->Ne));
	if (Graph->Ne != 0){
		E = (Edge)malloc(sizeof(struct ENode));
		for (i = 0; i < Graph->Ne; i++){
			scanf("%d %d %d", &E->V1, &E->V2, &E->Weight);
			InsertEdge(Graph, E);
		}
	}
	for (V = 0; V < Graph->Nv; V++)
		scanf("%c",&(Graph->G[V].Data));
		
	return Graph;	
}
