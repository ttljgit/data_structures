//ͼ���ڽ������ʾ��
#define MaxVertex Num 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;

//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode{
	Vertex V1, V2;
	WeightType Weight;
}; 
typedef PtrToENode Edge;

//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode{
	Vertex AdjV;
	WeightType Weight;
	PtrToAdjVNode Next;
}; 

//���� ��ͷ���Ķ���
typedef struct Vnode{
	PtrToAdjVNode FirstEdge;	//�߱�ͷָ��
	DataType Data;		//�涥�������
	//ע�⣺ �ܶ�����£����������ݣ���ʱ��data���Բ��ó��� 
}AdjList[MaxVertexNum]; 

//ͼ���Ķ��� 
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToGNode LGraph;	//���ڽӱ�ʽ�洢��ͼ����

//��ʼ��һ����VertexNum�����㵫��û�бߵ�ͼ 
LGraph CreateGraph(int VertexNum) 
{
	Vertex V;
	LGraph Graph;
	
	Graph = (LGraph)mollac(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӱ�ͷָ��
	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ����Graph->Nv - 1
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	
	return Graph;	 
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	
	//�����<V1, V2> ΪV2�����µ��ڽӵ�
	NewNode = (PtrToAdjVNode)mollc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	//��V2����V1�ı�ͷ
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode; 
	
	///��������ͼ����Ҫ�����<V2, v1>
	//ΪV1�����µ��ڽӵ�	
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V1;
	NewNode->Weight = E->Weight;
	//��V1����V2�ı�ͷ
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
