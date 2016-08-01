//ͼ���ڽӾ����ʾ��

#define MaxVertexNum 100	//��󶥵���	 
#defiene INFINITY 65535		//������Ϊ˫�ֽ��޷������������ֵ65535 
typedef int Vertex;		//�����±� 
typedef int WeightType;		//�ߵ�Ȩֵ 
typedef char DataType; 		

//�ߵĶ���
typedef struct ENode *PtrToNode;
struct ENode{
	Vertex V1, V2;		//�����
	WeightType Weight;		//Ȩ�� 
}; 
typedef PtrToNode Edge;

//ͼ���Ķ���
typedef struct GNode *PtrToGNode;
struct GNode{
	int Nv;		//������ 
	int Ne;		//���� 
	WeightType G[MaxVertexNum][MaxVertexNum];	//�ڽӾ��� 
	DataType Data[MaxVertexNum];	//�涥������� 
}; 
typedef PtrToGNode MGraph;	//���ڽӾ���洢ͼ������
 
//��ʼ��һ����VertexNum�����㵫��û�бߵ�ͼ
MGraph CreateGraph(int VertexNum)
{
	Vertex V, W;
	MGraph Graph;
	
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	//��ʼ���ڽӾ���
	//ע�⣺����Ĭ�϶����Ŵ�0��ʼ����Graph->Nv-1
	for (V = 0; V < Graph->Nv; V++){
		for (W = 0; W < Graph->Nv; W++){
			Graph-G[V][W] = INIFINITY;
		}
	} 
	
	return Graph;
} 

//�����V1, V2 
void InerstEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	//��������ͼ����Ҫ�����V2, V1;
	Graph->G[E->V2][E->V1] = E->Weight; 
}

MGraph BuildGraph()
{
	MGraph Graph;
	Edge E;
	Vertex V;
	int Nv, i;
	
	scanf("%d",&Nv);	//���붥�����
	Graph = Create(Nv);	//��ʼ����Nv�����㵫û�бߵ�ͼ
	
	scanf("%d",&(Graph->Ne));	//�������
	if (Graph->Ne != 0){
		E = (Edege)malloc(sizeof(struct ENode));	//�����߽��
		//����ߣ���ʽΪ"��� �յ� Ȩ��"�� �����ڽӾ��� 
		for (i = 0; i < Graph->Ne; i++){
			scanf("%d %d %d",&E->V1; &E->V2; &E->Weight);
			InsertEdge(Graph, E);
		} 
	} 
	//������������ݵĻ��� ��������
	for (V = 0; V < Graph->Nv; V++)
		scanf("%c", &(Graph->Data[V])); 
	
	return Graph;	
}

