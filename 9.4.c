//�ڽӱ�洢 ��Ȩͼ�ĵ�Դ���·�㷨
//dist[]��path[]ȫ����ʼ��Ϊ-1
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
	Queue Q;
	Vertex V;
	PtrToAdjVNode W;
	
	Q = CreateQueue(Graph->Nv);		//�����ն��У�MaxSizeΪ�ⲿ����ĳ��� 
	dist[S] = 0;	//��ʼ��ԭ��
	AddQ(Q, S);
	
	while (!IsEmpty(Q)){
		V = Delete(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)		//��V��ÿ���ڽӵ�W->AdjV
			if(dist[W->Adj] == -1){		//��W-Adjδ�����ʹ� 
				dist[W->Adj] = dist[V] + 1;	//W->AdjV��S�ľ������
				path[W->Adj] = V;	//��Vj��¼��S��W->AdjV��·����
				Add(Q, W->AdjV); 
			}	 
	}	
} 

//�ڽӾ��󴢴棬��Ȩͼ�ĵ�Դ���·�㷨
//����δ����¼������dist��С��
Vertex FindMinDist(MGraph Graph, int dist[], int cellected[])
{
	Vertex MinV, V;
	int MinDist = INIFINITY;
	
	for(V = 0; V < Graph->Nv; V++){
		if(collected[V] == false && dist[V] < MinDist){
			//��VΪ����¼����dist[V]��С
			MinDist = dist[V];	//������С����
			MinV = V;	//���¶�Ӧ���� 
		}
	}	
	//���ҵ���Сdist�����ض�Ӧ�Ķ����±� 
	if (MinDist < INIFINITY)	 
		return MinV;
	else
		return ERROR;	
} 
bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S)
{
	int collected[MaxVertexNum];
	Vertex V, W;
	
	//��ʼ�����˴�Ĭ���ڽӾ����в����ڵı���INIFINITY��ʾ
	for (V = 0; V < Graph->Nv; V++){
		dist[V] = Graph->G[S][V];
		path[V] = -1;
		collected[V] = false;
	} 
	//�Ƚ�������뼯��
	dist[S] = 0;
	collected[S] = true;
	
	while(1){
		//V = δ����¼������dist��С��
		V = FinMinDist(Graph, dist, collected);
		if (V == ERROR)
			break;
		collected[V] = true;	//��¼V
		for (W = 0; W < Graph->Nv; W++)	//��ͼ��ÿ������W
			//��W��V�Ķ��㲢��δ����¼ 
			if(collected[W] == false && Graph->G[V][W] < INIFINITY){
				if(Graph->G[V][W] < 0)
					return false;	//���и��ߣ�������ȷ��������ش����� 			
				//����¼Vʹ��dist[W]��С 
				if(dist[V]+Graph->G[V][W] < dist[W]){
					dist[W] = dist[V]+Graph->G[V][W];	//����dist[W]
					path[W] = V;	//����S��W��·�� 
				}
		}
	} 
	return true; 
}

//�ڽӾ���洢 ��Դ����㷨
bool Floyed(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[MaxVertexNum])
{
	Vertex i, j, k;
	
	//��ʼ��
	for(i = 0; i < Graph->Nv; i++){
		for(j = 0; j < Graph->Nv; j++){
			D[i][j] = Graph->G[i][j];
			path[i][j] = -1;
		}
	}
		
	for(k = 0; k < Graph->Nv; k++)
		for(i = 0; i < Graph->Nv; i++)
			for(j= 0; j < Graph->Nv; j++)
				if(D[i][j] + D[k][j] < D[i][j]){
					//�����ָ�Ȧ��������ȷ��������ش����� 
					if(i == j && D[i][j] < 0)
						return false;
					path[i][j] = k;	
				}
	return true;			
} 
